// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/AgentControl.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/agent_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_AgentControl_u3
{
public:
  explicit Init_AgentControl_u3(::amp_msgs::msg::AgentControl & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::AgentControl u3(::amp_msgs::msg::AgentControl::_u3_type arg)
  {
    msg_.u3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::AgentControl msg_;
};

class Init_AgentControl_u2
{
public:
  explicit Init_AgentControl_u2(::amp_msgs::msg::AgentControl & msg)
  : msg_(msg)
  {}
  Init_AgentControl_u3 u2(::amp_msgs::msg::AgentControl::_u2_type arg)
  {
    msg_.u2 = std::move(arg);
    return Init_AgentControl_u3(msg_);
  }

private:
  ::amp_msgs::msg::AgentControl msg_;
};

class Init_AgentControl_u1
{
public:
  explicit Init_AgentControl_u1(::amp_msgs::msg::AgentControl & msg)
  : msg_(msg)
  {}
  Init_AgentControl_u2 u1(::amp_msgs::msg::AgentControl::_u1_type arg)
  {
    msg_.u1 = std::move(arg);
    return Init_AgentControl_u2(msg_);
  }

private:
  ::amp_msgs::msg::AgentControl msg_;
};

class Init_AgentControl_u0
{
public:
  Init_AgentControl_u0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgentControl_u1 u0(::amp_msgs::msg::AgentControl::_u0_type arg)
  {
    msg_.u0 = std::move(arg);
    return Init_AgentControl_u1(msg_);
  }

private:
  ::amp_msgs::msg::AgentControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::AgentControl>()
{
  return amp_msgs::msg::builder::Init_AgentControl_u0();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__BUILDER_HPP_
