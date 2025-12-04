#include "amp_agents/omni_agent_actor.hpp"


OmniAgentActor::OmniAgentActor() : AgentBackend(){

    //set the agent here
    agent = new OmniAgent(OMNI_AGENT_PROPERTIES);

    //init ball trajectory sub
    ball_trajectory_sub = create_subscription<amp_msgs::msg::BallTrajectory>("/ball_trajectory", 10, std::bind(&OmniAgentActor::selectPathForLanding, this, std::placeholders::_1));

    //configure the environment for the omni agent
    env.root_state = AGENT_INITIAL_STATE;
    env.agent_dim = AGENT_DIMENSIONS;
    env.duration_limits = {0.5, 2};
    env.control_limits = {{-2, 2}, {-2, 2}, {-2, 2}, {-2, 2}};

    RectPrism test (V3d(1.0, 1.0, 1.0), V3d(1.0, 0.0, 0.0), -1.57, 0.01);

    env.obstalces.push_back(RectPrism(V3d(.6, .6, 1.1), V3d(2.4, 0.0, 0.0), 0.00, 0.00));
    env.obstalces.push_back(RectPrism(V3d(.6, .6, 1.1), V3d(2.4, 0.0, 0.0), 1.57, 0.00));
    env.obstalces.push_back(RectPrism(V3d(.6, .6, 1.1), V3d(2.4, 0.0, 0.0), 3.14, 0.00));
    env.obstalces.push_back(RectPrism(V3d(.6, .6, 1.1), V3d(2.4, 0.0, 0.0), -1.57, 0.00));
    env.obstalces.push_back(RectPrism(V3d(1.6, 1.6, 1.1), V3d(-0.1, 2.3, 0.0), 0.00, 0.00));
    env.obstalces.push_back(RectPrism(V3d(1.6, 1.6, 1.1), V3d(-0.1, 2.3, 0.0), 1.57, 0.00));
    env.obstalces.push_back(RectPrism(V3d(1.6, 1.6, 1.1), V3d(-0.1, 2.3, 0.0), 3.14, 0.00));
    env.obstalces.push_back(RectPrism(V3d(1.6, 1.6, 1.1), V3d(-0.1, 2.3, 0.0), -1.57, 0.00));

    //set the tree's ptr for the sake of logging
    agent_tree.node_ptr = this;

    // //generate the tree
    // generate_tree(250);

    // //Help from gemni to get package path
    std::string package_name = "amp_agents";
    std::string share_directory = ament_index_cpp::get_package_share_directory(package_name);

    // agent_tree.save_tree_to_file(share_directory + "/tree.dat");
    // agent_tree.save_tree_stats_to_file(share_directory + "/tree_stats.csv");

    // generate_tree_stops();

    // agent_tree.save_tree_to_file(share_directory + "/tree_stops.dat");
    // agent_tree.runTreeStats();

     agent_tree = SstTree(agent, &env, std::string((share_directory + std::string("/trees/t1s.dat")).c_str()), this);
     agent_tree.node_ptr = this;
    
    // RCLCPP_INFO(get_logger(), "Loaded in %d into the pile, %d in the top level\n", agent_tree.node_pile.size(), agent_tree.tree.size());

    viz.displayTree((agent_tree.tree), agent_tree.neighborhoods);
}

void OmniAgentActor::selectPathForLanding(amp_msgs::msg::BallTrajectory msg){

    if(get_agent_status() == AGENT_GENERATING_STATUS || get_agent_status() == AGENT_LOADING_TREE){
        RCLCPP_WARN(get_logger(), "Cannot track ball, agent is still loading or generating the tree.");
        return;
    }

    double start_time = get_time_as_double();

    //determine where the ball will land
    TargetInformation info = determine_ball_landing_location(V3d(msg.current_pos_x, msg.current_pos_y, msg.current_pos_z),
    V3d(msg.current_vel_x, msg.current_vel_y, msg.current_vel_z),
    V3d(msg.current_damping_x, msg.current_damping_y, msg.current_damping_z),
        msg.current_mass, 0.15);

    info.time += start_time;

    //determine the best node to catch the ball
    SstNode* ideal_node = agent_tree.getLowestCostNodeWithinRange(V13d(info.location[0], info.location[1], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), 0.25);
    
    if(ideal_node == nullptr){
        RCLCPP_WARN(get_logger(), "No valid node found!");
        return;
    }

    //determine the agent past
    SstPath best_path(*ideal_node);

    //formulate the path into a message
    best_path.generate_msg();

    //determine when the agent starts to move
    best_path.path_msg.start_time = create_ros2_time_from_double(info.time - best_path.path_msg.run_time);

    //send the agent the path
    path_pub->publish(best_path.path_msg);

    //generate the stopped ball node
    // if(ideal_node->parent != nullptr){
    //     SstNode sub = agent_tree.subStoppedNode(ideal_node->parent, ideal_node->state);

    //     RCLCPP_INFO(get_logger(), "Found sub node %f %f", sub.state[0], sub.state[1]);
    // }

    RCLCPP_INFO(get_logger(), "Returned path in %f seconds!", get_time_as_double() - start_time);
    RCLCPP_INFO(get_logger(),"Ball Expected at %f %f in %f seconds", info.location[0], info.location[1], info.time - start_time);
    RCLCPP_INFO(get_logger(), "Final state pos: %f %f, vel %f %f, in %f seconds\n\n", ideal_node->state[0], ideal_node->state[1], ideal_node->state[7], ideal_node->state[8], best_path.path_msg.run_time);
}

void OmniAgentActor::generate_tree(double propagation_time) {

    agent_tree = SstTree(agent, &env);
    agent_tree.node_ptr = this;
    agent_tree.sample_d_maximums = ENVIRONMENT_UPPER_BOUND - ENVIRONMENT_LOWER_BOUND;
    agent_tree.sample_minimums = ENVIRONMENT_LOWER_BOUND;

    //send the message that the agent will begin generating
    update_agent_status(AGENT_GENERATING_STATUS);

    agent_tree.prop_begin_time = get_clock()->now().seconds();

    //generate the tree at the startup of the class
    bool added = false;
    double start_time = get_time_as_double();
    while(start_time + propagation_time > get_time_as_double()){

        added = agent_tree.processNewNode();

        if((agent_tree.tree.size() % 10 == 0) && added){
            RCLCPP_INFO(get_logger(), "Added node number %d! Pile size %d.", agent_tree.tree.size(), agent_tree.node_pile.size());
            agent_tree.runTreeStats();
        }
    }

    //send the message that the agent has finished generating
    update_agent_status(AGENT_READY_STATUS);
}

void OmniAgentActor::generate_tree_stops(){

    int tree_size = agent_tree.tree.size();
    int counter = 0;

    //generate a stoping node for node in the tree
    for(auto it = agent_tree.tree.begin(); it != agent_tree.tree.end(); it++){

        counter++;

        if((*it)->parent != nullptr){
            SstNode stopped_node = agent_tree.subStoppedNode((*it)->parent,(*it)->state);
            
            stopped_node.node_index = agent_tree.node_pile.size();
            agent_tree.node_pile.push_back(stopped_node);
            (*it) = &(agent_tree.node_pile.back());

            RCLCPP_INFO(get_logger(), "Added stopped node %d of %d", counter, tree_size);
        }
    }
}

OmniAgentActor::~OmniAgentActor(){
    delete agent;
}

