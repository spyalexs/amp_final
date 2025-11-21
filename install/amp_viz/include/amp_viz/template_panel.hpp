#pragma once

#include <rclcpp/rclcpp.hpp>

#include <rviz_common/panel.hpp>
#include <rviz_common/ros_integration/ros_node_abstraction_iface.hpp>
#include <rviz_common/display_context.hpp>

#include "ui/ui_template_panel.h"
#include "amp_msgs/msg/launch_ball.hpp"
#include "amp_msgs/msg/set_pose.hpp"


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

      rclcpp::Node::SharedPtr getRosNode();

    private:
        Ui::Template_Panel *ui;


    private Q_SLOTS:
        void launchBallCb();
};