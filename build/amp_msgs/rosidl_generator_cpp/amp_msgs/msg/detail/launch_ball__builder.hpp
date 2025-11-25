// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/launch_ball__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_LaunchBall_ball_pos_z
{
public:
  explicit Init_LaunchBall_ball_pos_z(::amp_msgs::msg::LaunchBall & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::LaunchBall ball_pos_z(::amp_msgs::msg::LaunchBall::_ball_pos_z_type arg)
  {
    msg_.ball_pos_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

class Init_LaunchBall_ball_pos_y
{
public:
  explicit Init_LaunchBall_ball_pos_y(::amp_msgs::msg::LaunchBall & msg)
  : msg_(msg)
  {}
  Init_LaunchBall_ball_pos_z ball_pos_y(::amp_msgs::msg::LaunchBall::_ball_pos_y_type arg)
  {
    msg_.ball_pos_y = std::move(arg);
    return Init_LaunchBall_ball_pos_z(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

class Init_LaunchBall_ball_pos_x
{
public:
  explicit Init_LaunchBall_ball_pos_x(::amp_msgs::msg::LaunchBall & msg)
  : msg_(msg)
  {}
  Init_LaunchBall_ball_pos_y ball_pos_x(::amp_msgs::msg::LaunchBall::_ball_pos_x_type arg)
  {
    msg_.ball_pos_x = std::move(arg);
    return Init_LaunchBall_ball_pos_y(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

class Init_LaunchBall_ball_launch_heading
{
public:
  explicit Init_LaunchBall_ball_launch_heading(::amp_msgs::msg::LaunchBall & msg)
  : msg_(msg)
  {}
  Init_LaunchBall_ball_pos_x ball_launch_heading(::amp_msgs::msg::LaunchBall::_ball_launch_heading_type arg)
  {
    msg_.ball_launch_heading = std::move(arg);
    return Init_LaunchBall_ball_pos_x(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

class Init_LaunchBall_ball_launch_angle
{
public:
  explicit Init_LaunchBall_ball_launch_angle(::amp_msgs::msg::LaunchBall & msg)
  : msg_(msg)
  {}
  Init_LaunchBall_ball_launch_heading ball_launch_angle(::amp_msgs::msg::LaunchBall::_ball_launch_angle_type arg)
  {
    msg_.ball_launch_angle = std::move(arg);
    return Init_LaunchBall_ball_launch_heading(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

class Init_LaunchBall_ball_velocity
{
public:
  Init_LaunchBall_ball_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaunchBall_ball_launch_angle ball_velocity(::amp_msgs::msg::LaunchBall::_ball_velocity_type arg)
  {
    msg_.ball_velocity = std::move(arg);
    return Init_LaunchBall_ball_launch_angle(msg_);
  }

private:
  ::amp_msgs::msg::LaunchBall msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::LaunchBall>()
{
  return amp_msgs::msg::builder::Init_LaunchBall_ball_velocity();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__BUILDER_HPP_
