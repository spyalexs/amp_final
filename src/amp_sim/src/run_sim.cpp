//utilized plenty of info / code from https://docs.ros.org

#include <Eigen/Dense>

#include "dynamic_ball.hpp"
#include "dynamic_object.hpp"

#include <rclcpp/rclcpp.hpp>
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"

#include "amp_msgs/msg/launch_ball.hpp"
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

            //initialize the ball damping
            ball_damping << 2.0, 2.0, 5.0, 2.0, 2.0, 2.0;

            dynamic_objects.push_back(new DynamicBall(ball_damping, 1, "ball_1", empty));

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
                control.setZero();

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

            if(previous_tf_update_time + TF_UPDATE_PERIOD < current_time){
                for(auto it = dynamic_objects.begin(); it != dynamic_objects.end(); ++it){
                    publish_tf_pose((**it).state, (**it).object_name);
                }

                previous_tf_update_time = current_time;
            }


        }

        void launch_ball_cb(amp_msgs::msg::LaunchBall msg){

            //calculate the launch velocity
            V3d launch_vector(msg.ball_velocity, 0.0, 0.0);
            launch_vector = 
                Eigen::AngleAxisd(msg.ball_launch_heading, V3d::UnitZ()) * 
                Eigen::AngleAxisd(msg.ball_launch_angle, V3d::UnitY()) * 
                launch_vector;


            dynamic_objects.push_back(new DynamicBall(ball_damping, 1, "ball_2", empty));
            dynamic_objects.back()->state[7] = launch_vector(0);
            dynamic_objects.back()->state[8] = launch_vector(1);
            dynamic_objects.back()->state[9] = launch_vector(2);

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

        rclcpp::TimerBase::SharedPtr tic_timer;

        double previous_tf_update_time = 0;

        V6d ball_damping;
        std::vector<int> empty;


};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimNode>());
    rclcpp::shutdown();
    return 0;
}