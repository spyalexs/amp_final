// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/SetPose.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__SET_POSE__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__SET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_SetPose_heading
{
public:
  explicit Init_SetPose_heading(::amp_msgs::msg::SetPose & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::SetPose heading(::amp_msgs::msg::SetPose::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::SetPose msg_;
};

class Init_SetPose_y_pos
{
public:
  explicit Init_SetPose_y_pos(::amp_msgs::msg::SetPose & msg)
  : msg_(msg)
  {}
  Init_SetPose_heading y_pos(::amp_msgs::msg::SetPose::_y_pos_type arg)
  {
    msg_.y_pos = std::move(arg);
    return Init_SetPose_heading(msg_);
  }

private:
  ::amp_msgs::msg::SetPose msg_;
};

class Init_SetPose_x_pos
{
public:
  Init_SetPose_x_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPose_y_pos x_pos(::amp_msgs::msg::SetPose::_x_pos_type arg)
  {
    msg_.x_pos = std::move(arg);
    return Init_SetPose_y_pos(msg_);
  }

private:
  ::amp_msgs::msg::SetPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::SetPose>()
{
  return amp_msgs::msg::builder::Init_SetPose_x_pos();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__SET_POSE__BUILDER_HPP_
