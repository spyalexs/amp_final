// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amp_msgs:msg/AgentControl.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__TRAITS_HPP_
#define AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amp_msgs/msg/detail/agent_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace amp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgentControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: u0
  {
    out << "u0: ";
    rosidl_generator_traits::value_to_yaml(msg.u0, out);
    out << ", ";
  }

  // member: u1
  {
    out << "u1: ";
    rosidl_generator_traits::value_to_yaml(msg.u1, out);
    out << ", ";
  }

  // member: u2
  {
    out << "u2: ";
    rosidl_generator_traits::value_to_yaml(msg.u2, out);
    out << ", ";
  }

  // member: u3
  {
    out << "u3: ";
    rosidl_generator_traits::value_to_yaml(msg.u3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgentControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: u0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u0: ";
    rosidl_generator_traits::value_to_yaml(msg.u0, out);
    out << "\n";
  }

  // member: u1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u1: ";
    rosidl_generator_traits::value_to_yaml(msg.u1, out);
    out << "\n";
  }

  // member: u2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u2: ";
    rosidl_generator_traits::value_to_yaml(msg.u2, out);
    out << "\n";
  }

  // member: u3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u3: ";
    rosidl_generator_traits::value_to_yaml(msg.u3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgentControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace amp_msgs

namespace rosidl_generator_traits
{

[[deprecated("use amp_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const amp_msgs::msg::AgentControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  amp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amp_msgs::msg::AgentControl & msg)
{
  return amp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amp_msgs::msg::AgentControl>()
{
  return "amp_msgs::msg::AgentControl";
}

template<>
inline const char * name<amp_msgs::msg::AgentControl>()
{
  return "amp_msgs/msg/AgentControl";
}

template<>
struct has_fixed_size<amp_msgs::msg::AgentControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<amp_msgs::msg::AgentControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<amp_msgs::msg::AgentControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__TRAITS_HPP_
