#include "amp_agents/omni_agent_actor.hpp"


OmniAgentActor::OmniAgentActor() : AgentBackend(){

    //set the agent here
    agent = new OmniAgent(OMNI_AGENT_PROPERTIES);

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


    //generate the tree
    generate_tree(400);

    //Help from gemni to get package path
    std::string package_name = "amp_agents";
    std::string share_directory = ament_index_cpp::get_package_share_directory(package_name);

    agent_tree.save_tree_to_file(share_directory + "/tree.dat");
    // agent_tree = SstTree(agent, &env, std::string((share_directory + std::string("/trees/small_tree.dat")).c_str()));
    // agent_tree.node_ptr = this;
    
    // RCLCPP_INFO(get_logger(), "Loaded in %d into the pile, %d in the top level\n", agent_tree.node_pile.size(), agent_tree.tree.size());

    viz.displayTree((agent_tree.tree), agent_tree.neighborhoods);
}

void OmniAgentActor::generate_tree(double propagation_time) {

    agent_tree = SstTree(agent, &env);
    agent_tree.node_ptr = this;
    agent_tree.sample_d_maximums = ENVIRONMENT_UPPER_BOUND - ENVIRONMENT_LOWER_BOUND;
    agent_tree.sample_minimums = ENVIRONMENT_LOWER_BOUND;

    //send the message that the agent will begin generating
    update_agent_status(AGENT_GENERATING_STATUS);

    //generate the tree at the startup of the class
    bool added = false;
    double start_time = get_time_as_double();
    while(start_time + propagation_time > get_time_as_double()){

        added = agent_tree.processNewNode();

        if((agent_tree.tree.size() % 10 == 0) && added){
            RCLCPP_INFO(get_logger(), "Added node number %d! Pile size %d.", agent_tree.tree.size(), agent_tree.node_pile.size());
        }
    }

    //send the message that the agent has finished generating
    update_agent_status(AGENT_READY_STATUS);
}

OmniAgentActor::~OmniAgentActor(){
    delete agent;
}

