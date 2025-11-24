#pragma once

#include <vector>
#include <string>
#include <Eigen/Dense>
#include <cmath>
#include <boost/math/special_functions/lambert_w.hpp>

#include <rclcpp/rclcpp.hpp>

#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2/exceptions.h"

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "amp_msgs/msg/agent_control.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"

#define INVALID_TF_HEADER "invalid"
#define AGENT_NAME "omni_agent"
#define LANDING_HEIGHT 0.5

typedef Eigen::Matrix<double, 3, 1> V3d;

class TargetInformation{
    public:
        TargetInformation(V3d Location, double Time){
            time = Time;
            location = Location;
        }

        V3d location;
        double time; //seconds
};

// a class to contain all essential agent functionality
class AgentBackend : public rclcpp::Node{

    public:

        AgentBackend();// : Node("sim_node");


    protected:

        std::shared_ptr<tf2_ros::TransformListener> tf_listener{nullptr};
        std::unique_ptr<tf2_ros::Buffer> tf_buffer;

        rclcpp::Publisher<amp_msgs::msg::AgentControl>::SharedPtr control_pub;

        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr valid_balls_sub;

        void publish_control(std::vector<double> control);

        geometry_msgs::msg::TransformStamped getAgentTransform();
        geometry_msgs::msg::TransformStamped getTransform(std::string to_frame, std::string from_frame);
        geometry_msgs::msg::TransformStamped getBallTransform(int ball_index);

        std::vector<int> valid_ball_frames;

        TargetInformation determine_ball_landing_location(V3d current_position, V3d current_velocities, V3d current_damping, double mass, double landing_hieght);

    private:

        void valid_ball_frames_cb(std_msgs::msg::Int32MultiArray msg);
};