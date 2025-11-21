//utilized plenty of info / code from https://docs.ros.org

#include "dynamic_ball.hpp"
#include "dynamic_object.hpp"

#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"


#include <string>

using namespace std::chrono_literals;

#define TF_UPDATE_PERIOD .033 //sec

class SimNode : public rclcpp::Node
{
    public:
        SimNode() : Node("sim_node"){


            // Initialize the transform broadcaster
            tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

            std::vector<int> empty;
            V6d ball_damping;
            ball_damping << 2.0, 2.0, 5.0, 2.0, 2.0, 2.0;
            ball = new DynamicBall(ball_damping, 1, "ball_1", empty);

            dynamic_objects.push_back(ball);

            tic_timer = this->create_wall_timer(1ms, std::bind(&SimNode::tic_cb, this));
        }


    private:

        void tic_cb(){
            //tic all the dynamic objects

            //RCLCPP_INFO(this->get_logger(), ("Current time is: " + std::to_string(get_current_time())).c_str());
            double current_time = get_current_time();

            for(int i = 0; i < dynamic_objects.size(); i++){
                V12d control;
                control.setZero();

                dynamic_objects.at(i)->tic(control, current_time);
            }

            if(previous_tf_update_time + TF_UPDATE_PERIOD < current_time){
                for(int i = 0; i < dynamic_objects.size(); i++){
                    publish_tf_pose(dynamic_objects.at(i)->state, dynamic_objects.at(i)->object_name);
                }

                previous_tf_update_time = current_time;
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
        std::vector<DynamicBall*> dynamic_objects;

        rclcpp::TimerBase::SharedPtr tic_timer;

        double previous_tf_update_time = 0;

        DynamicBall *ball; 

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimNode>());
    rclcpp::shutdown();
    return 0;
}