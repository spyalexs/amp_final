#include "amp_agents/agent_backend.hpp"

AgentBackend::AgentBackend() : Node("sim_node"), agent_tree(agent, &env){

    //create tf listener
    tf_buffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);

    //init pubs
    control_pub = create_publisher<amp_msgs::msg::AgentControl>("/agent_control", 10);
    agent_status_pub = create_publisher<std_msgs::msg::Int16>("/agent_status", 10);
    path_pub = create_publisher<amp_msgs::msg::IdealPath>("/agent_path", 10);

    //init subs
    valid_balls_sub = create_subscription<std_msgs::msg::Int32MultiArray>("/valid_ball_frames", 10, std::bind(&AgentBackend::valid_ball_frames_cb, this, std::placeholders::_1));

    // TargetInformation target = determine_ball_landing_location(V3d(0,0,2), V3d(1,1,0), V3d(1,1,1), 1, 0);
    // RCLCPP_INFO(get_logger(), "The ball will land in %f seconds, at (%f, %f, %f)", target.time, target.location(0), target.location(1), target.location(2));
}


void AgentBackend::valid_ball_frames_cb(std_msgs::msg::Int32MultiArray msg){
    valid_ball_frames = msg.data;
}


void AgentBackend::publish_control(std::vector<double> control){
    amp_msgs::msg::AgentControl msg;
    
    //handle for omni agent
    if(control.size() == 4){
        msg.u0 = control.at(0);
        msg.u1 = control.at(1);
        msg.u2 = control.at(2);
        msg.u3 = control.at(3);

        control_pub->publish(msg);

        return;
    }

    //handle for differential drive agent
    if(control.size() == 2){
        msg.u0 = control.at(0);
        msg.u1 = control.at(1);

        control_pub->publish(msg);

        return;
    }

    RCLCPP_WARN(get_logger(), "Invalid control size sent - not publishing!");

}

geometry_msgs::msg::TransformStamped AgentBackend::getAgentTransform(){
    return getTransform("world", AGENT_NAME);
}

geometry_msgs::msg::TransformStamped AgentBackend::getBallTransform(int ball_index=-1){
    //by default get the latest ball
    if(ball_index == -1){

        if(valid_ball_frames.size() > 0){
            ball_index = valid_ball_frames.back();
        }else{
            RCLCPP_WARN(get_logger(), "Cannot get the latest ball transform as the frame does not exist!");

            geometry_msgs::msg::TransformStamped invalid_msg;
            invalid_msg.header.frame_id = INVALID_TF_HEADER;

            return  invalid_msg;
        }
    } else {

        bool ball_index_valid = false;
        for(int i = 0; i < valid_ball_frames.size(); i++){

            if(valid_ball_frames.at(i) == ball_index){

                ball_index_valid = true;

                break;
            }
        }

        if(!ball_index_valid){
            RCLCPP_WARN(get_logger(), "Cannot the specified ball transform as the frame does not exist!");

            geometry_msgs::msg::TransformStamped invalid_msg;
            invalid_msg.header.frame_id = INVALID_TF_HEADER;

            return  invalid_msg;
        }
    }

    std::string ball_frame_name = "ball_" + std::to_string(ball_index);

    return getTransform("world", ball_frame_name);
}

geometry_msgs::msg::TransformStamped AgentBackend::getTransform(std::string to_frame, std::string from_frame){
    try{
        return tf_buffer->lookupTransform(to_frame, from_frame, tf2::TimePointZero);
    } catch (const tf2::TransformException & ex){
        RCLCPP_WARN(get_logger(), "Could not transform %s to %s: %s", to_frame, from_frame, ex.what());
    }

    geometry_msgs::msg::TransformStamped invalid_msg;
    invalid_msg.header.frame_id = INVALID_TF_HEADER;

    return invalid_msg;
}

TargetInformation AgentBackend::determine_ball_landing_location(V3d current_position, V3d current_velocities, V3d current_damping, double mass, double landing_hieght){
    //determine where the ball will land based on its properties and characteristics

    //adjjust for mass
    current_damping = current_damping / mass;

    //calculate the time it will take to complete the fall -- turns out this isn't simple...
    double t = solve_time(mass, current_damping(2), current_velocities(2), current_position(2), landing_hieght);

    //calculate the displacement in the other axis
    // 0 = b(dx) + m(ddx) -> laplace -> bXs + mXss - v0 = 0
    //v0 / (bs+mss) = X -> a/(b+s) + c/s = X
    //c = v0/b, a = -c

    double x_final = current_position(0) + current_velocities(0) / current_damping(0) - (current_velocities(0) / current_damping(0)) * exp(-current_damping(0) * t);
    double y_final = current_position(1) + current_velocities(1) / current_damping(1) - (current_velocities(1) / current_damping(1)) * exp(-current_damping(1) * t);

    return TargetInformation(V3d(x_final, y_final, landing_hieght), t);
}

//This is a chatgpt special
double AgentBackend::solve_time(double m, double b, double v0, double x0, double L, double g)
{
    // Define intermediate terms
    const double C = L - x0;
    const double A = v0 + g / b;

    // Argument for Lambert W
    double arg = (-(b * v0 + g) / g) *
                 std::exp((b * b * C - b * m * v0 - g * m) / (g * m));

    // Compute Lambert W principal branch
    double W = boost::math::lambert_w0(arg);

    // Full closed-form solution
    double t = (-b * b * C + b * m * v0 + g * m * W + g * m) / (b * g);

    return t;
}

void AgentBackend::update_agent_status(int status){
    std_msgs::msg::Int16 msg;
    msg.data = status;
    agent_status_pub->publish(msg);

    //update the agent status member
    agent_status = status;
}

int AgentBackend::get_agent_status(){
    
    return agent_status;
}

void AgentBackend::generate_tree(double propagation_time){
    RCLCPP_WARN(get_logger(), "This shouldn't be called...");
}

double AgentBackend::get_time_as_double(){
    //RCLCPP_INFO(get_logger(), "Current time is %f",get_clock()->now().seconds() );

    return get_clock()->now().seconds();
}

//HELP from gemni here
builtin_interfaces::msg::Time AgentBackend::create_ros2_time_from_double(double total_seconds){
    builtin_interfaces::msg::Time ros_time;
    double integer_part;
    double fractional_part = std::modf(total_seconds, &integer_part);

    ros_time.sec = static_cast<int32_t>(integer_part);
    ros_time.nanosec = static_cast<uint32_t>(fractional_part * 1e9);

    return ros_time;
}


