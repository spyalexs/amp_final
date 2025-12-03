// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__IDEAL_PATH__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__IDEAL_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/ideal_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_IdealPath_start_time
{
public:
  explicit Init_IdealPath_start_time(::amp_msgs::msg::IdealPath & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::IdealPath start_time(::amp_msgs::msg::IdealPath::_start_time_type arg)
  {
    msg_.start_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::IdealPath msg_;
};

class Init_IdealPath_run_time
{
public:
  explicit Init_IdealPath_run_time(::amp_msgs::msg::IdealPath & msg)
  : msg_(msg)
  {}
  Init_IdealPath_start_time run_time(::amp_msgs::msg::IdealPath::_run_time_type arg)
  {
    msg_.run_time = std::move(arg);
    return Init_IdealPath_start_time(msg_);
  }

private:
  ::amp_msgs::msg::IdealPath msg_;
};

class Init_IdealPath_duration_array
{
public:
  explicit Init_IdealPath_duration_array(::amp_msgs::msg::IdealPath & msg)
  : msg_(msg)
  {}
  Init_IdealPath_run_time duration_array(::amp_msgs::msg::IdealPath::_duration_array_type arg)
  {
    msg_.duration_array = std::move(arg);
    return Init_IdealPath_run_time(msg_);
  }

private:
  ::amp_msgs::msg::IdealPath msg_;
};

class Init_IdealPath_control_array
{
public:
  Init_IdealPath_control_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IdealPath_duration_array control_array(::amp_msgs::msg::IdealPath::_control_array_type arg)
  {
    msg_.control_array = std::move(arg);
    return Init_IdealPath_duration_array(msg_);
  }

private:
  ::amp_msgs::msg::IdealPath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::IdealPath>()
{
  return amp_msgs::msg::builder::Init_IdealPath_control_array();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__IDEAL_PATH__BUILDER_HPP_
