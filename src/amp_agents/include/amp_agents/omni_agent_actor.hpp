#pragma once

#include <rclcpp/rclcpp.hpp>

#include "amp_sim/agent_statuses.hpp"
#include "amp_sim/omni_agent.hpp"
#include "amp_sim/agent_properties.hpp"
#include "amp_sim/environment_properties.hpp"
#include "agent_backend.hpp"
#include "propagate_sst.hpp"
#include "amp_agents/visualize_tree.hpp"

class OmniAgentActor : public AgentBackend {
    public:
        OmniAgentActor();
        ~OmniAgentActor();
    
        void generate_tree(double propagation_time) override;

        TreeVisualizer viz;


};