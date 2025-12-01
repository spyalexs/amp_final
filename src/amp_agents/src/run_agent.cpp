#include <rclcpp/rclcpp.hpp>

#include "amp_agents/agent_backend.hpp"
#include "amp_agents/omni_agent_actor.hpp"

//run an agent
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OmniAgentActor>());
    rclcpp::shutdown();
    return 0;
}