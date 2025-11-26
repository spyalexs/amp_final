#include "propagate_sst.hpp"

SstTree::SstTree(DynamicObject* Agent, BallCatchEnvironment environment){
    agent = Agent;
    env = environment;

    //determine the number of times the dynamics should be steped before running a collision check
    samples_before_collision_check = COLLISION_CHECK_INTERVAL / SAMPLING_INTERVAL;
    if(samples_before_collision_check == 0){
        samples_before_collision_check = 1;
    }

    node_pile.push_back(SstNode(env.root_state));
    tree.push_back(&node_pile.back());
}

V13d SstTree::generate_random_sample(){

    bool searching = false;

    while(searching){
        double yaw = rand() * 2 * (M_PI / RAND_MAX);

        Eigen::Quaterniond quat = getYawQuat(yaw);

        //generate a random sample node to further propagate the tree
        V13d sampled(
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
        RectPrism prism(env.agent_dim, v3d(sampled[0], sampled[1], sampled[2]), yaw, 0);
        
        searching = prism.checkPrismsCollision(env.obstalces);
    }
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

SstNode* SstTree::getLowestCostNodeWithinRange(V13d reference){

    //determine wether a node has been found within the range or not
    // if false, lowest node is the node closest to the other nodes
    //if true, lowest node is the lowest cost node 
    bool found_within_range = false;
    SstNode* lowest_node;
    double cost = -1;
    double d;

    for(auto it = tree.begin(); it != tree.end(); ++it){
        d = evalutate_distance_euclidean((*it)->state, reference);

        if(found_within_range){
            //if the node is the lowest cost within the range
            if(d < SEARCHING_RANGE || (*it)->cost_from_source < cost){
                cost = (*it)->cost_from_source;
                lowest_node = &(**it);
            }
        } else {
            // if the node is withing the range
            if(d < SEARCHING_RANGE){
                cost = (*it)->cost_from_source;
                lowest_node = &(**it);

            //if the node is the closest but not in the range
            }else if(d < cost || cost == -1){
                lowest_node = &(**it);
                cost = d;

            }
        }
    }

    return lowest_node;
}


V12d SstTree::generate_random_controls(){
    
    V12d control;
    control.setZero();

    for(int i = 0; i < env.control_limits.size(); i++){
        control[i] = rand() * (env.control_limits.at(i).second - env.control_limits.at(i).first) / RAND_MAX + env.control_limits.at(i).first;
    }

    return control;
}

double SstTree::generate_random_duration(){
    return rand() * (env.duration_limits.second - env.duration_limits.first) / RAND_MAX + env.duration_limits.first;
}

bool SstTree::propagate_agent(V12d controls, double duration){

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

            RectPrism prism(env.agent_dim, v3d(agent->state[0], agent->state[1], agent->state[2]), yaw, 0);

            if(prism.checkPrismsCollision(env.obstalces)){

                //fail as there is a collision
                return false;
            }

        }

    }

    //succeed with a collision free propagation
    return true;
}

SstNode SstTree::generateNewNode(){

    //generate a random node
    V13d sampled_node = generate_random_sample();

    //determine the closest node
    SstNode* base_node = getLowestCostNodeWithinRange(sampled_node);

    V12d control;
    double duration;

    SstNode lowestCostNode(V13d(), 0, base_node);
    double lowest_distance = -1;

    for(int i = 0; i < NUM_PROPAGATIONS; i++){

        //generate random parameters
        duration = generate_random_duration();
        control = generate_random_controls();

        //configure the current state of the agent
        agent->state = base_node->state;
        
        //propagate the agent according to the controls
        if(!propagate_agent(control, duration)){
            i--;
            continue;
        }

        //determine if this is the best propagation yet
        double dist = evalutate_distance_euclidean_and_velocity(sampled_node, agent->state, .4);
        if(lowest_distance < 0 || dist < lowest_distance){
            lowest_distance = dist;
            
            lowestCostNode.state = agent->state;
            lowestCostNode.control_vector = control;
            lowestCostNode.duration = duration;
        }
    }

    //determine the ndoe's cost from source
    lowestCostNode.cost_from_source = lowest_distance + base_node->cost_from_source;

    return lowestCostNode;
}

void SstTree::processNewNode(){
    //handle generating a new node
    SstNode node = generateNewNode();

    //determine the neighborhood of the node
    for(auto it = neighborhoods.begin(); it != neighborhoods.end(); ++it){

        if(evalutate_distance_euclidean(it->center, node.state) < it->radius){
            if(it->subplant_node(&node)){
                node_pile.push_back(node);
                tree.push_back(&node_pile.back());
            }

            return;
        }

    }

    //not in a neighboorhood so make a new one
    node_pile.push_back(node);
    tree.push_back(&node_pile.back());
    neighborhoods.push_back(SstNeighborhood(&node));
}



