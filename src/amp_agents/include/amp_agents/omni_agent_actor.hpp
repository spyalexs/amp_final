#pragma once

#include <rclcpp/rclcpp.hpp>

#include "amp_sim/agent_statuses.hpp"
#include "amp_sim/omni_agent.hpp"
#include "agent_backend.hpp"
#include "propagate_sst.hpp"

class OmniAgentActor : public AgentBackend {
    public:
        OmniAgentActor();
        ~OmniAgentActor();
    
        void generate_tree(int number_of_nodes) override;

};