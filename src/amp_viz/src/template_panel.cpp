#include "amp_viz/template_panel.hpp"
#include "ui/ui_template_panel.h"

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

    launch_ball_pub = node->create_publisher<amp_msgs::msg::LaunchBall>("/launch_ball", 10);

    //   // Create a String publisher for the output
    //   publisher_ = node->create_publisher<std_msgs::msg::String>("/output", 10);

    //   // Create a String subscription and bind it to the topicCallback inside this class.
    //   subscription_ = node->create_subscription<std_msgs::msg::String>("/input", 10, std::bind(&DemoPanel::topicCallback, this, std::placeholders::_1));

    //link the launch ball button
    QObject::connect(ui->launch_button, &QPushButton::released, this, &TemplatePanel::launchBallCb);
}

rclcpp::Node::SharedPtr TemplatePanel::getRosNode(){
    return node_ptr_->get_raw_node();
}


void TemplatePanel::launchBallCb(){
    amp_msgs::msg::LaunchBall msg;

    msg.ball_velocity = ui->launch_velocity_input->text().toFloat();
    msg.ball_launch_angle = ui->launch_angle_input->text().toFloat();
    msg.ball_launch_heading = ui->launch_heading_input->text().toFloat();

    launch_ball_pub->publish(msg);
}


TemplatePanel::~TemplatePanel() = default;

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(TemplatePanel, rviz_common::Panel)