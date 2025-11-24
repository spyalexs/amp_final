#include "amp_viz/template_panel.hpp"
#include "ui/ui_template_panel.h"

using namespace std::chrono_literals;

TemplatePanel::TemplatePanel(QWidget* parent) : Panel(parent), ui(new Ui::Template_Panel){
    
    ui->setupUi(this);

}

void TemplatePanel::onInitialize()
{

    //   // Access the abstract ROS Node and
    //   // in the process lock it for exclusive use until the method is done.
    node_ptr_ = getDisplayContext()->getRosNodeAbstraction().lock();

    //   // Get a pointer to the familiar rclcpp::Node for making subscriptions/publishers
    //   // (as per normal rclcpp code)
    rclcpp::Node::SharedPtr node = getRosNode();

    //create pubs
    launch_ball_pub = node->create_publisher<amp_msgs::msg::LaunchBall>("/launch_ball", 10);
    set_position_pub = node->create_publisher<amp_msgs::msg::SetPose>("/set_agent_pose", 10);

    //create tf listener
    tf_buffer = std::make_unique<tf2_ros::Buffer>(node->get_clock());
    tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);

    //create cb timer to update the agent pose
    pose_update_timer = node->create_wall_timer(0.03s, std::bind(&TemplatePanel::update_pose_display, this));

    //link the launch ball button
    QObject::connect(ui->launch_button, &QPushButton::released, this, &TemplatePanel::launchBallCb);
    QObject::connect(ui->set_position_button, &QPushButton::released, this, &TemplatePanel::setPositionCb);
}

rclcpp::Node::SharedPtr TemplatePanel::getRosNode(){
    return node_ptr_->get_raw_node();
}


void TemplatePanel::update_pose_display(){
    //get the current pose of the agent from tf
    try {
        geometry_msgs::msg::TransformStamped t = tf_buffer->lookupTransform(WORLD_FRAME_NAME, AGENT_NAME, tf2::TimePointZero);

        //write the pose onto the panel
        ui->read_x_pos->setText(QString::number(t.transform.translation.x));
        ui->read_y_pos->setText(QString::number(t.transform.translation.y));
        ui->read_heading->setText(QString::number(atan2(
            2 * (t.transform.rotation.w * t.transform.rotation.z - t.transform.rotation.x * t.transform.rotation.y),
            1 - 2 * (t.transform.rotation.y * t.transform.rotation.y + t.transform.rotation.z * t.transform.rotation.z)) * 
            180 / M_PI));
        
    } catch (const tf2::TransformException & ex) {
        RCLCPP_WARN(getRosNode()->get_logger(), "Could not transform %s to %s: %s", WORLD_FRAME_NAME, AGENT_NAME, ex.what());
        return;
    }


}

void TemplatePanel::launchBallCb(){
    amp_msgs::msg::LaunchBall msg;

    msg.ball_velocity = ui->launch_velocity_input->text().toFloat();
    msg.ball_launch_angle = ui->launch_angle_input->text().toFloat();
    msg.ball_launch_heading = ui->launch_heading_input->text().toFloat();

    launch_ball_pub->publish(msg);
}

void TemplatePanel::setPositionCb(){
    amp_msgs::msg::SetPose msg;

    //convert from degrees
    msg.heading= ui->set_heading->text().toFloat() / 180 * M_PI;
    msg.x_pos = ui->set_x_pos->text().toFloat();
    msg.y_pos = ui->set_y_pos->text().toFloat();

    set_position_pub->publish(msg);
}



TemplatePanel::~TemplatePanel() = default;

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(TemplatePanel, rviz_common::Panel)