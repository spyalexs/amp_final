#include <rclcpp/rclcpp.hpp>

#include "agent_backend.hpp"

//run an agent
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AgentBackend>());
    rclcpp::shutdown();
    return 0;
}