#include "amp_agents/omni_agent_actor.hpp"
#include "amp_sim/agent_properties.hpp"
#include "amp_sim/environment_properties.hpp"

OmniAgentActor::OmniAgentActor() : AgentBackend(){

    //set the agent here
    agent = new OmniAgent(OMNI_AGENT_PROPERTIES);

    //configure the environment for the omni agent
    env.root_state = AGENT_INITIAL_STATE;
    env.agent_dim = AGENT_DIMENSIONS;
    env.duration_limits = {0.5, 5};
    env.control_limits = {{-2, 2}, {-2, 2}, {-2, 2}, {-2, 2}};

    //set the tree's ptr for the sake of logging
    agent_tree.node_ptr = this;

    RCLCPP_INFO(get_logger(), "here");

    //generate the tree
    generate_tree(100);

    
}

void OmniAgentActor::generate_tree(int number_of_nodes) {

    agent_tree = SstTree(agent, &env);
    agent_tree.node_ptr = this;

    //send the message that the agent will begin generating
    update_agent_status(AGENT_GENERATING_STATUS);

    //generate the tree at the startup of the class
    bool added = false;
    while(agent_tree.tree.size() < number_of_nodes){

        added = agent_tree.processNewNode();

        if(number_of_nodes % 10 && added){
            RCLCPP_INFO(get_logger(), "Added node number %d out of %d.", agent_tree.tree.size(), number_of_nodes);
        }
    }

    //send the message that the agent has finished generating
    update_agent_status(AGENT_READY_STATUS);
}

OmniAgentActor::~OmniAgentActor(){
    delete agent;
}

