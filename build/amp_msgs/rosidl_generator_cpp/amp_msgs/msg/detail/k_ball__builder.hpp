// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/KBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__K_BALL__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__K_BALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/k_ball__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_KBall_ball_launch_heading
{
public:
  explicit Init_KBall_ball_launch_heading(::amp_msgs::msg::KBall & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::KBall ball_launch_heading(::amp_msgs::msg::KBall::_ball_launch_heading_type arg)
  {
    msg_.ball_launch_heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::KBall msg_;
};

class Init_KBall_ball_launch_angle
{
public:
  explicit Init_KBall_ball_launch_angle(::amp_msgs::msg::KBall & msg)
  : msg_(msg)
  {}
  Init_KBall_ball_launch_heading ball_launch_angle(::amp_msgs::msg::KBall::_ball_launch_angle_type arg)
  {
    msg_.ball_launch_angle = std::move(arg);
    return Init_KBall_ball_launch_heading(msg_);
  }

private:
  ::amp_msgs::msg::KBall msg_;
};

class Init_KBall_ball_velocity
{
public:
  Init_KBall_ball_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KBall_ball_launch_angle ball_velocity(::amp_msgs::msg::KBall::_ball_velocity_type arg)
  {
    msg_.ball_velocity = std::move(arg);
    return Init_KBall_ball_launch_angle(msg_);
  }

private:
  ::amp_msgs::msg::KBall msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::KBall>()
{
  return amp_msgs::msg::builder::Init_KBall_ball_velocity();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__K_BALL__BUILDER_HPP_
