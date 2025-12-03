#include "amp_agents/propagate_sst.hpp"

SstTree::SstTree(DynamicObject* Agent, BallCatchEnvironment* environment){
    agent = Agent;
    env = environment;

    //determine the number of times the dynamics should be steped before running a collision check
    samples_before_collision_check = COLLISION_CHECK_INTERVAL / SAMPLING_INTERVAL;
    if(samples_before_collision_check == 0){
        samples_before_collision_check = 1;
    }

    node_pile.push_back(SstNode(env->root_state));
    tree.push_back(&node_pile.back());
}

SstTree::SstTree(DynamicObject* Agent, BallCatchEnvironment* environment, std::string file_name, rclcpp::Node* ptr) : SstTree(Agent, environment){

    //load the tree from a file
    //help from Gemni here
    std::ifstream inputFile(file_name);

    node_ptr = ptr;

    std::string line;
    bool continue_parsing = true;
    while(std::getline(inputFile, line) && continue_parsing){
        continue_parsing = parse_line(line);
    }
}

//CHATGPT SPECIAL
bool SstTree::parse_line(std::string data){
    int n = 0;
    int p = 0;
    double d = 0.0;
    double c = 0.0;

    Eigen::Matrix<double,13,1> s;
    Eigen::Matrix<double,12,1> u;

    // Split by '|'
    std::stringstream ss(data);
    std::string part;

    while (getline(ss, part, '|')) {

        // Find key:value format
        size_t colon = part.find(':');
        if (colon == std::string::npos) continue;

        std::string key = part.substr(0, colon);
        std::string value = part.substr(colon + 1);

        if (key == "n") {
            n = stoi(value);
        }
        else if (key == "p") {
            p = stoi(value);
        }
        else if (key == "s") {
            parseEigenVector(value, s);
        }
        else if (key == "u") {
            parseEigenVector(value, u);
        }
        else if (key == "d") {
            d = stod(value);
        }
        else if (key == "c") {
            c = stod(value);
        }else if(key == "top_level"){
            std::vector<int> top_level_nodes = parseIntVectorFromLine(data);

            for(int i = 0; i < top_level_nodes.size(); i++){
                //get pointer to the top level node
                std::list<SstNode>::iterator it = node_pile.begin();
                std::advance(it, top_level_nodes.at(i));

                //add to the top level nodes and neighborhoods list
                tree.push_back(&(*it));
                neighborhoods.push_back(SstNeighborhood(&(*it)));
            }

            return false;
        }
    }

    //get the pointer to the parent
    std::list<SstNode>::iterator it = node_pile.begin();
    std::advance(it, p);
    if(p >= node_pile.size()){
        RCLCPP_WARN(node_ptr->get_logger(), "Setting pointer for node %d equal to non-existant parent %d", n, p);
    }

    //make a tree node
    SstNode new_node(s, c, &(*it));
    new_node.control_vector = u;
    new_node.duration = d;
    new_node.node_index = node_pile.size();

    //recreate the substates
    agent->state = new_node.parent->state;
    if(LOAD_SUBSTATES){
        propagate_agent(u,d,&(new_node.sub_states));
    }

    node_pile.push_back(new_node);

    return true;
}

std::vector<int> SstTree::parseIntVectorFromLine(const std::string& line) {
    std::vector<int> result;

    // Find the position of the colon (':')
    size_t colonPos = line.find(':');
    if (colonPos != std::string::npos) {
        // Get the part of the string after the colon
        std::string valuesStr = line.substr(colonPos + 1);
        
        // Create a stringstream to parse the values
        std::stringstream ss(valuesStr);
        std::string token;

        // Split the string by commas and convert each token into an integer
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) {  // Make sure the token is not empty
                try {
                    result.push_back(std::stoi(token));  // Convert token to int and add to vector
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid integer: " << token << std::endl;  // Error handling
                } catch (const std::out_of_range& e) {
                    std::cerr << "Out of range integer: " << token << std::endl;  // Error handling
                }
            }
        }
    }

    return result;
}

//CHATGPT SPECIAL
template<typename Derived>
void SstTree::parseEigenVector(const std::string &csv, Eigen::DenseBase<Derived> &vec){
    std::string token;
    std::stringstream ss(csv);
    int i = 0;

    while (getline(ss, token, ',') && i < vec.size()) {
        vec(i) = stod(token);
        i++;
    }
}


V13d SstTree::generate_random_sample(){

    V13d sampled;
    bool searching = true;

    while(searching){
        double yaw = rand() * 2 * (M_PI / RAND_MAX);

        Eigen::Quaterniond quat = getYawQuat(yaw);

        //generate a random sample node to further propagate the tree
        sampled = V13d(
            rand() * (sample_d_maximums[0] / RAND_MAX) + sample_minimums[0],
            rand() * (sample_d_maximums[1] / RAND_MAX) + sample_minimums[1],
            0, 
            quat.w(),
            quat.x(),
            quat.y(),
            quat.z(),
            0,
            rand() * (sample_d_maximums[7] / RAND_MAX) + sample_minimums[7],
            rand() * (sample_d_maximums[8] / RAND_MAX) + sample_minimums[8],
            0,
            0,
            rand() * (sample_d_maximums[11] / RAND_MAX) + sample_minimums[11]);

        //validate the sample
        RectPrism prism(env->agent_dim, v3d(sampled[0], sampled[1], sampled[2]), yaw, 0);
        
        searching = prism.checkPrismsCollision(env->obstalces);
    }

    return sampled;
}

double SstTree::evaluate_distance_full(V13d p1, V13d p2, V12d weights){

    //evaulate the distance between two states
    double dist = 0;

    dist += (p2[0] - p1[0]) * weights[0];
    dist += (p2[1] - p1[1]) * weights[1];
    dist += (p2[2] - p1[2]) * weights[2];
    dist += (p2[7] - p1[7]) * weights[6];
    dist += (p2[8] - p1[8]) * weights[7];
    dist += (p2[9] - p1[9]) * weights[8];
    dist += (p2[10] - p1[10]) * weights[9];
    dist += (p2[11] - p1[11]) * weights[10];
    dist += (p2[12] - p1[12]) * weights[11];

    return dist;
}

double SstTree::evalutate_distance_euclidean(V13d p1, V13d p2){
    return (p1.block<3,1>(0,0) - p2.block<3,1>(0,0)).norm();
}

double SstTree::evalutate_distance_euclidean(v3d p1, V13d p2){
    return (p1 - p2.block<3,1>(0,0)).norm();
}

double SstTree::evalutate_distance_euclidean_and_velocity(V13d p1, V13d p2, double velocity_weight){
    return (p1.block<3,1>(0,0) - p2.block<3,1>(0,0)).norm() + fabs(p1.block<3,1>(7,0).norm() - p2.block<3,1>(7,0).norm()) * velocity_weight;
}

Eigen::Quaterniond SstTree::getYawQuat(double yaw){
    return Eigen::Quaterniond(cos(yaw/2), 0, 0, sin(yaw/2));
}


SstNode* SstTree::getLowestCostNodeWithinRange(V13d reference, double range = SEARCHING_RANGE){

    //determine wether a node has been found within the range or not
    // if false, lowest node is the node closest to the other nodes
    //if true, lowest node is the lowest cost node 
    bool found_within_range = false;
    SstNode* lowest_node;
    double cost = -1;
    double d;

    for(std::list<SstNode*>::iterator it = tree.begin(); it != tree.end(); ++it){

        SstNode* tree_node_ptr = *it;

        d = evalutate_distance_euclidean(tree_node_ptr->state, reference);

        // RCLCPP_INFO(node_ptr->get_logger(), "Distance is %f to %f %f from reference %f %f", d, tree_node_ptr->state[0], tree_node_ptr->state[1], reference[0], reference[1]);

        if(found_within_range){
            //if the node is the lowest cost within the range
            if(d < range && tree_node_ptr->cost_from_source < cost){

                cost = tree_node_ptr->cost_from_source;
                lowest_node = tree_node_ptr;
            }
        } else {
            // if the node is withing the range
            if(d < range){
                cost = tree_node_ptr->cost_from_source;
                lowest_node = tree_node_ptr;

                found_within_range = true;

            //if the node is the closest but not in the range
            }else if(d < cost || cost == -1){
                lowest_node = tree_node_ptr;
                cost = d;

            }


        }


    }
    
    return lowest_node;
}


V12d SstTree::generate_random_controls(){
    
    V12d control;
    control.setZero();

    for(int i = 0; i < env->control_limits.size(); i++){
        control[i] = rand() * (env->control_limits.at(i).second - env->control_limits.at(i).first) / RAND_MAX + env->control_limits.at(i).first;
    }

    return control;
}

double SstTree::generate_random_duration(){
    return rand() * (env->duration_limits.second - env->duration_limits.first) / RAND_MAX + env->duration_limits.first;
}

bool SstTree::propagate_agent(V12d controls, double duration, std::vector<std::pair<double, V13d>>* substates){

    int ticks = std::floor(duration / SAMPLING_INTERVAL);
    double remainder =  duration - SAMPLING_INTERVAL * ticks;
    double tic_duration = SAMPLING_INTERVAL;

    agent->previous_tic = 0;

    while(ticks >= 0){

        if(ticks == 0){
            tic_duration = remainder;
        }
        
        agent->tic(controls, agent->previous_tic + tic_duration);

        if(ticks % samples_before_collision_check == 0){
            //check the agent for a collision

            //determine the yaw angle of the agent
            double yaw = atan2(2 *(agent->state[3] * agent->state[6] + agent->state[4] * agent->state[5]), 1 - 2 *(agent->state[5] * agent->state[5] + agent->state[6] * agent->state[6]));

            RectPrism prism(env->agent_dim, v3d(agent->state[0], agent->state[1], agent->state[2]), yaw, 0);

            if(prism.checkPrismsCollision(env->obstalces)){

                //fail as there is a collision
                return false;
            }

            if(SAVE_SUBSTATES){
                substates->push_back({agent->previous_tic, agent->state});
            }

        }

        ticks--;

    }

    //succeed with a collision free propagation
    return true;
}

void SstTree::runTreeStats(){
    double dd = get_average_distance_deviation();
    double cp = get_converage_percentage();
    double ev = get_tree_end_velocity();

    RCLCPP_INFO(node_ptr->get_logger(), "Distance Deviation %f, Coverage %f, Velocity %f", dd, cp, ev);

    //save data
    node_counts.push_back(tree.size());
    tree_distance_deviations.push_back(dd);
    tree_end_velocities.push_back(ev);
    tree_coverage_percentages.push_back(cp);
    tree_times.push_back(node_ptr->get_clock()->now().seconds() - prop_begin_time);
}

double SstTree::get_average_distance_deviation(){
    double total_deviation = 0;

    //loop through all high level nodes
    for(auto it = tree.begin(); it != tree.end(); ++it){

        SstNode* leaf = *it;
        
        double travelled_distance_sum = 0;

        if(fabs(leaf->state[0]) > 5 || fabs(leaf->state[1]) > 5){
            continue;
        }

        //dive down the node tree
        while(leaf->parent != nullptr){

            //loop through states and add dist
            V13d prev = leaf->parent->state;
            for(auto it2 = leaf->sub_states.begin(); it2 != leaf->sub_states.end(); ++it2){
                travelled_distance_sum += evalutate_distance_euclidean((*it2).second, prev);

                prev = (*it2).second;
            }

            //next node
            leaf = leaf->parent;

            //increment the total sum
            total_deviation += (travelled_distance_sum / (*it)->state.block<2,1>(0,0).norm());
        }

        
    }

    return total_deviation / tree.size();
}

double SstTree::get_converage_percentage(){

    //create a coverage map
    Eigen::Matrix<bool, 10 * COVERAGE_MAP_SCALE, 10 * COVERAGE_MAP_SCALE> coverage_map;
    coverage_map.setZero();

    //covered spaces
    int covered_spaces = 0;

    for(auto it = tree.begin(); it != tree.end(); ++it){
        SstNode* leaf = *it;

        Eigen::Quaterniond quat(leaf->state[3], leaf->state[4], leaf->state[5], leaf->state[6]);
        
        for(int i = 0; i < COVERAGE_MAP_SCALE / env->agent_dim[0]; i++){
            for(int j = 0; j < COVERAGE_MAP_SCALE / env->agent_dim[1]; j++){

                //determine a point within the agent
                V3d pos = leaf->state.block<3,1>(0,0) + quat * (env->agent_dim.cwiseProduct(V3d(double(i) / (COVERAGE_MAP_SCALE / env->agent_dim[0]) - .5, double(j) / (COVERAGE_MAP_SCALE / env->agent_dim[1]) - .5, 0)));

                //determine the closest point on the coverage map
                int i1 = pos[0] * COVERAGE_MAP_SCALE + COVERAGE_MAP_SCALE * 5;
                int i2 = pos[1] * COVERAGE_MAP_SCALE + COVERAGE_MAP_SCALE * 5;

                if(i1 >= COVERAGE_MAP_SCALE * 10 || i2 >= COVERAGE_MAP_SCALE * 10){
                    continue;
                }

                if(i1 < 0 || i2 < 0){
                    continue;
                }

                if(!coverage_map(i1, i2)){
                    coverage_map(i1, i2) = true;
                    covered_spaces++;
                }
            }
        }

    }

    return double(covered_spaces) / (COVERAGE_MAP_SCALE * COVERAGE_MAP_SCALE * 100);
}

double SstTree::get_tree_end_velocity(){

    double total_velocity = 0;

    //loop through all high level nodes
    for(auto it = tree.begin(); it != tree.end(); ++it){

        SstNode* leaf = *it;

        total_velocity += leaf->state.block<2,1>(7,0).norm();
    }

    return total_velocity / tree.size();
}

SstNode SstTree::generateNewNode(){

    //generate a random node
    V13d sampled_node = generate_random_sample();

    // RCLCPP_INFO(node_ptr->get_logger(), "Sampled %f %f", sampled_node[0], sampled_node[1]);

    //determine the closest node
    SstNode* base_node = getLowestCostNodeWithinRange(sampled_node);

    V12d control;
    double duration;

    SstNode lowestCostNode(V13d(), 0, base_node);
    std::vector<std::pair<double, V13d>> substates;
    double lowest_distance = -1;

    int fail_counter = 0;

    for(int i = 0; i < NUM_PROPAGATIONS; i++){

        //generate random parameters
        duration = generate_random_duration();
        control = generate_random_controls();

        //clear the substates
        substates.clear();

        //configure the current state of the agent
        agent->state = base_node->state;

        //propagate the agent according to the controls
        if(!propagate_agent(control, duration, &(substates))){
            i--;
            fail_counter++;

            if(fail_counter > NUM_PROPAGATIONS){
                fail_counter = 0;
                i = 0;
                lowest_distance = -1;

                sampled_node = generate_random_sample();
                base_node = getLowestCostNodeWithinRange(sampled_node);
                lowestCostNode = SstNode(V13d(), 0, base_node);

            }

            continue;
        }

        //determine if this is the best propagation yet
        double dist = evalutate_distance_euclidean_and_velocity(sampled_node, agent->state, .4);
        if(lowest_distance < 0 || dist < lowest_distance){
            lowest_distance = dist;
            
            lowestCostNode.state = agent->state;
            lowestCostNode.control_vector = control;
            lowestCostNode.duration = duration;
            lowestCostNode.sub_states = substates;
        }
    }

    //determine the ndoe's cost from source
    lowestCostNode.cost_from_source = lowestCostNode.duration + base_node->cost_from_source;

    return lowestCostNode;
}

SstNode SstTree::subStoppedNode(SstNode* parent, V13d sub_state){
    //generate a node that ends in the same position as another node but stopped

    V12d control;
    double duration;

    SstNode lowestCostNode(V13d(), 0, parent);
    std::vector<std::pair<double, V13d>> substates;
    double lowest_distance = -1;

    double start_time = node_ptr->get_clock()->now().seconds();

    double max_vel = MAX_STOPPED_VELOCITY;

    for(int i = 0; i < NUM_SUB_PROPAGATIONS; i++){

        if(start_time + SUB_TIMEOUT < node_ptr->get_clock()->now().seconds()){
            max_vel += MAX_STOPPED_VELOCITY;
            start_time = node_ptr->get_clock()->now().seconds();
        }

        //generate random parameters
        duration = generate_random_duration() * 2;
        control = generate_random_controls();

        //clear the substates
        substates.clear();

        //configure the current state of the agent
        agent->state = parent->state;

        //propagate the agent according to the controls
        if(!propagate_agent(control, duration, &(substates))){
            i--;

            continue;
        } else if(agent->state.block<3,1>(7,0).norm() > max_vel){
            i--;
            
            continue;
        }

        //determine if this is the best propagation yet
        double dist = evalutate_distance_euclidean_and_velocity(sub_state, agent->state, 0);
        if(lowest_distance < 0 || dist < lowest_distance){
            lowest_distance = dist;
            
            lowestCostNode.state = agent->state;
            lowestCostNode.control_vector = control;
            lowestCostNode.duration = duration;
            lowestCostNode.sub_states = substates;
        }
    }

    //determine the ndoe's cost from source
    lowestCostNode.cost_from_source = lowestCostNode.duration + parent->cost_from_source;

    return lowestCostNode;
}


bool SstTree::processNewNode(){
    //returns true if the node count is increased

    //handle generating a new node
    SstNode node = generateNewNode();

    //determine the neighborhood of the node
    for(auto it = neighborhoods.begin(); it != neighborhoods.end(); ++it){

        if(evalutate_distance_euclidean(it->center, node.state) < it->radius){
            // RCLCPP_INFO(node_ptr->get_logger(), "Former cost: %f Current Cost %f", it->sst_node->cost_from_source, node.cost_from_source);
            // RCLCPP_INFO(node_ptr->get_logger(), "Former Center: %f %f Current Center %f %f", it->sst_node->state[0], it->sst_node->state[1], node.state[0], node.state[1]);

            if(it->subplant_node(&node)){
                node_pile.push_back(node);
                node_pile.back().node_index = node_pile.size() - 1;
                //tree.push_back(&node_pile.back());
            }

            return false;
        }

    }

    //RCLCPP_INFO(node_ptr->get_logger(), "increasing node count %d", tree.size());

    //not in a neighboorhood so make a new one
    node_pile.push_back(node);
    tree.push_back(&node_pile.back());
    node_pile.back().node_index = node_pile.size() - 1;
    neighborhoods.push_back(SstNeighborhood(&node_pile.back()));

    return true;
}


SstPath::SstPath(SstNode leaf){
    create_forward_path(leaf);
}

SstPath::SstPath(SstNode leaf, DynamicObject* agent, bool invert){

    create_forward_path(leaf);

    //no need to invert here
    if(invert == false){
        return;
    }
    
    //full duration
    double path_duration = states.back().first;

    //reverse the order of the durations and the states
    std::reverse(durations.begin(), durations.end());
    std::reverse(states.begin(), states.end());
    std::reverse(controls.begin(), controls.end());

    for(int i = 0; i < states.size(); i++){
        
        // the timestamp for each state needs reversed
        states.at(i).first = path_duration - states.at(i).first;
    }

    for(int i = 0; i < controls.size(); i++){

        // invert the control... this isn't nessicarily as simple 
        controls.at(i) = agent->invert_control(controls.at(i));
    }
}

void SstPath::create_forward_path(SstNode leaf){

    SstNode* current = &leaf;

    if(current->parent == nullptr || current == nullptr){
        //leaf is root
        return;
    }

    bool tracing = true;
    while(tracing){

        controls.push_back(current->control_vector);
        durations.push_back(current->duration);

        for(int i = 0; i < current->sub_states.size(); i++){
            states.push_back(current->sub_states.at(i));
        }

        current = current->parent;

        if(current->parent == nullptr){
            tracing = false;
        }
    }

    std::reverse(controls.begin(), controls.end());
    std::reverse(durations.begin(), durations.end());
    std::reverse(states.begin(), states.end());
}

void SstTree::save_tree_to_file(std::string filename){
    //save an sst tree to a file as it can take some time to generate

    //little help from gemni here
    FILE* filePointer;
    filePointer = fopen(filename.c_str(), "w");


    if (filePointer == NULL) {
        RCLCPP_WARN(node_ptr->get_logger(), "Failed to open tree write file");
        return;
    } 

    //loop through node pile
    for(auto it = node_pile.begin(); it != node_pile.end(); ++it){
        
        if(it->parent == nullptr){
            continue;
        }

        //write out node information
        fprintf(filePointer, "n:%d|p:%d|s:%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f|d:%f|u:%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f|c:%f\n",
            it->node_index,
            it->parent->node_index,
            it->state[0],
            it->state[1],
            it->state[2],
            it->state[3],
            it->state[4],
            it->state[5],
            it->state[6],
            it->state[7],
            it->state[8],
            it->state[9],
            it->state[10],
            it->state[11],
            it->state[12],
            it->duration,
            it->control_vector[0],
            it->control_vector[1],
            it->control_vector[2],
            it->control_vector[3],
            it->control_vector[4],
            it->control_vector[5],
            it->control_vector[6],
            it->control_vector[7],
            it->control_vector[8],
            it->control_vector[9],
            it->control_vector[10],
            it->control_vector[11],
            it->cost_from_source);
    }

    fprintf(filePointer, "top_level:");
    for(auto it = tree.begin(); it != tree.end(); it++){
        fprintf(filePointer, "%d,", (*it)->node_index);
    }
    fprintf(filePointer, "\n");

    fclose(filePointer);
}

void SstTree::save_tree_stats_to_file(std::string filename){
    //little help from gemni here
    FILE* filePointer;
    filePointer = fopen(filename.c_str(), "w");


    if (filePointer == NULL) {
        RCLCPP_WARN(node_ptr->get_logger(), "Failed to open tree state write file");
        return;
    } 

    //loop through node pile
    for(int i = 0; i < node_counts.size(); i++){
        fprintf(filePointer, "%d,%f,%f,%f,%f\n", node_counts.at(i),tree_distance_deviations.at(i),tree_coverage_percentages.at(i),tree_end_velocities.at(i), tree_times.at(i));
    }

    fprintf(filePointer, "\n");

    fclose(filePointer);
}


void SstPath::generate_msg(){
    //generate a message from the path

    double time_sum = 0;
    for(int i = 0; i < controls.size(); i++){

        amp_msgs::msg::AgentControl control_msg;
        control_msg.u0 = controls.at(i)[0];
        control_msg.u1 = controls.at(i)[1];
        control_msg.u2 = controls.at(i)[2];
        control_msg.u3 = controls.at(i)[3];

        path_msg.control_array.push_back(control_msg);
        path_msg.duration_array.push_back(durations.at(i));

        time_sum += durations.at(i);
    }

    path_msg.run_time = time_sum;
}






