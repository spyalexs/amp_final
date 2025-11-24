//utilized plenty of info / code from https://docs.ros.org

#include <Eigen/Dense>
#include <string>
#include <cctype>

#include "dynamic_ball.hpp"
#include "dynamic_object.hpp"
#include "omni_agent.hpp"

#include <rclcpp/rclcpp.hpp>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"

#include "amp_msgs/msg/launch_ball.hpp"
#include "amp_msgs/msg/set_pose.hpp"
#include "amp_msgs/msg/agent_control.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"


#include <string>

using namespace std::chrono_literals;

#define TF_UPDATE_PERIOD .033 //sec

class SimNode : public rclcpp::Node
{
    public:
        SimNode() : Node("sim_node"){


            // Initialize the transform broadcaster
            tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

            //initialize subs
            launch_sub = create_subscription<amp_msgs::msg::LaunchBall>("/launch_ball", 10, std::bind(&SimNode::launch_ball_cb, this, std::placeholders::_1));
            set_pose_sub = create_subscription<amp_msgs::msg::SetPose>("/set_agent_pose", 10, std::bind(&SimNode::set_agent_pose_cb, this, std::placeholders::_1));
            agent_control_sub = create_subscription<amp_msgs::msg::AgentControl>("/agent_control", 10, std::bind(&SimNode::set_agent_control_cb, this, std::placeholders::_1));

            //initialize pubs
            ball_frames_pub = create_publisher<std_msgs::msg::Int32MultiArray>("/valid_ball_frames", 10);

            //initialize the ball damping
            ball_damping << 2.0, 2.0, 2.0, 2.0, 2.0, 2.0;

            lock_z.push_back(2);
            lock_z.push_back(3);
            lock_z.push_back(4);

            //for the time being - agent is assumed to be at position one of the dynamic objects
            dynamic_objects.push_back(new OmniAgent(ball_damping, 1, "omni_agent", lock_z));

            tic_timer = this->create_wall_timer(1ms, std::bind(&SimNode::tic_cb, this));
        }


    private:

        void tic_cb(){
            //tic all the dynamic objects

            //RCLCPP_INFO(this->get_logger(), ("Current time is: " + std::to_string(get_current_time())).c_str());
            double current_time = get_current_time();

            std::vector<std::list<DynamicObject*>::iterator> to_erase;

            for(auto it = dynamic_objects.begin(); it != dynamic_objects.end(); ++it){
                V12d control;

                if(it != dynamic_objects.begin()){
                    control.setZero();
                } else {
                    control = current_agent_control;
                }

                (**it).tic(control, current_time);

                //remove out of bounds objects
                if(!((**it).check_state_bounds())){
                    to_erase.push_back(it);
                }
            }

            for(int i = 0; i < to_erase.size(); i++){
                delete *(to_erase.at(i));

                dynamic_objects.erase(to_erase.at(i));
            }

            //republish the ball frame if an object is removed
            if(to_erase.size() > 0){
                publish_ball_frames();
            }

            if(previous_tf_update_time + TF_UPDATE_PERIOD < current_time){
                for(auto it = dynamic_objects.begin(); it != dynamic_objects.end(); ++it){
                    publish_tf_pose((**it).state, (**it).object_name);
                }

                previous_tf_update_time = current_time;
            }
        }

        void publish_ball_frames(){
            std_msgs::msg::Int32MultiArray msg;

            for(auto it = dynamic_objects.begin(); it != dynamic_objects.end(); ++it){
                int ball_number = getNumberAfterUnderscore((**it).object_name);

                if(ball_number > 0){
                    msg.data.push_back(ball_number);
                }
            }

            ball_frames_pub->publish(msg);

        }

        void launch_ball_cb(amp_msgs::msg::LaunchBall msg){

            //increment the ball id 
            ball_index++;

            //calculate the launch velocity
            V3d launch_vector(msg.ball_velocity, 0.0, 0.0);
            launch_vector = 
                Eigen::AngleAxisd(msg.ball_launch_heading, V3d::UnitZ()) * 
                Eigen::AngleAxisd(msg.ball_launch_angle, V3d::UnitY()) * 
                launch_vector;


            dynamic_objects.push_back(new DynamicBall(ball_damping, 1, "ball_" + std::to_string(ball_index), empty));
            dynamic_objects.back()->state[7] = launch_vector(0);
            dynamic_objects.back()->state[8] = launch_vector(1);
            dynamic_objects.back()->state[9] = launch_vector(2);

            publish_ball_frames();

        }

        void set_agent_pose_cb(amp_msgs::msg::SetPose msg){

            if(dynamic_objects.size() < 1){
                RCLCPP_ERROR(get_logger(), "The agent is no where to be seen!");
                return;
            }

            //update the agent's state 
            dynamic_objects.front()->state[0] = msg.x_pos;
            dynamic_objects.front()->state[1] = msg.y_pos;

            Eigen::Quaterniond pose_or;
            pose_or = Eigen::AngleAxisd(msg.heading, V3d::UnitZ());

            dynamic_objects.front()->state[3] = pose_or.w();
            dynamic_objects.front()->state[6] = pose_or.z();
        }

        void set_agent_control_cb(amp_msgs::msg::AgentControl msg){

            //update the agent's control
            current_agent_control[0] = msg.u0;
            current_agent_control[1] = msg.u1;
            current_agent_control[2] = msg.u2;
            current_agent_control[3] = msg.u3;
        }

        //CHATGPT Special
        //write my a cpp function that take in a std::string and determines what the number after the _ is. Handle cases where there is no number or underscore by returning -1
        int getNumberAfterUnderscore(const std::string& s) {
            // Find the underscore
            size_t pos = s.find('_');
            if (pos == std::string::npos || pos + 1 >= s.size()) {
                return -1; // No underscore or nothing after it
            }

            // Extract substring after underscore
            std::string numberPart = s.substr(pos + 1);

            // Validate that it's a valid integer (digits only)
            for (char c : numberPart) {
                if (!std::isdigit(static_cast<unsigned char>(c))) {
                    return -1;
                }
            }

            // Convert to integer
            try {
                return std::stoi(numberPart);
            } catch (...) {
                return -1; // stoi failed (overflow, etc.)
            }
        }


        void publish_tf_pose(V13d state_vector, std::string to_frame_name, std::string base_frame_name = "world"){
            geometry_msgs::msg::TransformStamped t;

            //form header
            t.header.stamp = this->get_clock()->now();
            t.header.frame_id = base_frame_name;
            t.child_frame_id = to_frame_name;

            //input information from the state vector
            t.transform.translation.x = state_vector[0];
            t.transform.translation.y = state_vector[1];
            t.transform.translation.z = state_vector[2];

            t.transform.rotation.w = state_vector[3];
            t.transform.rotation.x = state_vector[4];
            t.transform.rotation.y = state_vector[5];
            t.transform.rotation.z = state_vector[6];

            //send to broadcaster
            tf_broadcaster->sendTransform(t);
        }

        double get_current_time(){
            return this->get_clock()->now().seconds();
        }

        //rclcpp::Publisher<geometry_msgs::msg::pose>::SharedPtr pose_pub;

        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster;
        std::list<DynamicObject*> dynamic_objects;

        rclcpp::Subscription<amp_msgs::msg::LaunchBall>::SharedPtr launch_sub;
        rclcpp::Subscription<amp_msgs::msg::SetPose>::SharedPtr set_pose_sub;
        rclcpp::Subscription<amp_msgs::msg::AgentControl>::SharedPtr agent_control_sub;

        rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr ball_frames_pub;

        rclcpp::TimerBase::SharedPtr tic_timer;

        double previous_tf_update_time = 0;

        V6d ball_damping;
        std::vector<int> empty;
        std::vector<int> lock_z;

        int ball_index = 1;

        V12d current_agent_control;



};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimNode>());
    rclcpp::shutdown();
    return 0;
}