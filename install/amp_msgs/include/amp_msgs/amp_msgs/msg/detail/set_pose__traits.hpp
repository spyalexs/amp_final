// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amp_msgs:msg/SetPose.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__SET_POSE__TRAITS_HPP_
#define AMP_MSGS__MSG__DETAIL__SET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amp_msgs/msg/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace amp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_pos
  {
    out << "x_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pos, out);
    out << ", ";
  }

  // member: y_pos
  {
    out << "y_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pos, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pos, out);
    out << "\n";
  }

  // member: y_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pos, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPose & msg, bool use_flow_style = false)
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
  const amp_msgs::msg::SetPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  amp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amp_msgs::msg::SetPose & msg)
{
  return amp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amp_msgs::msg::SetPose>()
{
  return "amp_msgs::msg::SetPose";
}

template<>
inline const char * name<amp_msgs::msg::SetPose>()
{
  return "amp_msgs/msg/SetPose";
}

template<>
struct has_fixed_size<amp_msgs::msg::SetPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<amp_msgs::msg::SetPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<amp_msgs::msg::SetPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMP_MSGS__MSG__DETAIL__SET_POSE__TRAITS_HPP_
