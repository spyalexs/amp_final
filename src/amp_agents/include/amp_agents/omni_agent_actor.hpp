#pragma once

#include <rclcpp/rclcpp.hpp>

#include "amp_sim/agent_statuses.hpp"
#include "agent_backend.hpp"
#include "propagate_sst.hpp"

class OmniAgentActor : public AgentBackend {
    public:
        OmniAgentActor();
    
        void generate_tree(int number_of_nodes, BallCatchEnvironment env) override;

};