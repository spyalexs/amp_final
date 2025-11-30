#include "amp_agents/omni_agent_actor.hpp"

OmniAgentActor::OmniAgentActor() : AgentBackend(){

    //set the agent here

    //generate the tree
    generate_tree(1000, env);
}

void OmniAgentActor::generate_tree(int number_of_nodes, BallCatchEnvironment env) {

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
