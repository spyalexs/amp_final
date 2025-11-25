// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__TRAITS_HPP_
#define AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amp_msgs/msg/detail/launch_ball__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace amp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaunchBall & msg,
  std::ostream & out)
{
  out << "{";
  // member: ball_velocity
  {
    out << "ball_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_velocity, out);
    out << ", ";
  }

  // member: ball_launch_angle
  {
    out << "ball_launch_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_launch_angle, out);
    out << ", ";
  }

  // member: ball_launch_heading
  {
    out << "ball_launch_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_launch_heading, out);
    out << ", ";
  }

  // member: ball_pos_x
  {
    out << "ball_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_x, out);
    out << ", ";
  }

  // member: ball_pos_y
  {
    out << "ball_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_y, out);
    out << ", ";
  }

  // member: ball_pos_z
  {
    out << "ball_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaunchBall & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ball_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_velocity, out);
    out << "\n";
  }

  // member: ball_launch_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_launch_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_launch_angle, out);
    out << "\n";
  }

  // member: ball_launch_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_launch_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_launch_heading, out);
    out << "\n";
  }

  // member: ball_pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_x, out);
    out << "\n";
  }

  // member: ball_pos_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_y, out);
    out << "\n";
  }

  // member: ball_pos_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_pos_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaunchBall & msg, bool use_flow_style = false)
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
  const amp_msgs::msg::LaunchBall & msg,
  std::ostream & out, size_t indentation = 0)
{
  amp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amp_msgs::msg::LaunchBall & msg)
{
  return amp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amp_msgs::msg::LaunchBall>()
{
  return "amp_msgs::msg::LaunchBall";
}

template<>
inline const char * name<amp_msgs::msg::LaunchBall>()
{
  return "amp_msgs/msg/LaunchBall";
}

template<>
struct has_fixed_size<amp_msgs::msg::LaunchBall>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<amp_msgs::msg::LaunchBall>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<amp_msgs::msg::LaunchBall>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__TRAITS_HPP_
