#pragma once

#include <rclcpp/rclcpp.hpp>

#include <rviz_common/panel.hpp>
#include <rviz_common/ros_integration/ros_node_abstraction_iface.hpp>
#include <rviz_common/display_context.hpp>

#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2/exceptions.h"

#include "ui/ui_template_panel.h"
#include "amp_msgs/msg/launch_ball.hpp"
#include "amp_msgs/msg/set_pose.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"

#define AGENT_NAME "omni_agent"
#define WORLD_FRAME_NAME "world"

class TemplatePanel : public rviz_common::Panel{
    Q_OBJECT
    public:
        explicit TemplatePanel(QWidget * parent = 0);
        ~TemplatePanel() override;

        void onInitialize() override;

        QWidget* parent_widget;

    protected:
      std::shared_ptr<rviz_common::ros_integration::RosNodeAbstractionIface> node_ptr_;

      rclcpp::Publisher<amp_msgs::msg::LaunchBall>::SharedPtr launch_ball_pub;
      rclcpp::Publisher<amp_msgs::msg::SetPose>::SharedPtr set_position_pub;

      rclcpp::Node::SharedPtr getRosNode();

    private:
        Ui::Template_Panel *ui;

        std::shared_ptr<tf2_ros::TransformListener> tf_listener{nullptr};
        std::unique_ptr<tf2_ros::Buffer> tf_buffer;

        rclcpp::TimerBase::SharedPtr pose_update_timer{nullptr};

        void update_pose_display();

    private Q_SLOTS:
        void launchBallCb();
        void setPositionCb();

};