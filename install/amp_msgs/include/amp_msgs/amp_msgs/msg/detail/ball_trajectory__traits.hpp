// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__TRAITS_HPP_
#define AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amp_msgs/msg/detail/ball_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace amp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BallTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_pos_x
  {
    out << "current_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_x, out);
    out << ", ";
  }

  // member: current_pos_y
  {
    out << "current_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_y, out);
    out << ", ";
  }

  // member: current_pos_z
  {
    out << "current_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_z, out);
    out << ", ";
  }

  // member: current_vel_x
  {
    out << "current_vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_x, out);
    out << ", ";
  }

  // member: current_vel_y
  {
    out << "current_vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_y, out);
    out << ", ";
  }

  // member: current_vel_z
  {
    out << "current_vel_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_z, out);
    out << ", ";
  }

  // member: current_damping_x
  {
    out << "current_damping_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_x, out);
    out << ", ";
  }

  // member: current_damping_y
  {
    out << "current_damping_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_y, out);
    out << ", ";
  }

  // member: current_damping_z
  {
    out << "current_damping_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_z, out);
    out << ", ";
  }

  // member: current_mass
  {
    out << "current_mass: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mass, out);
    out << ", ";
  }

  // member: landing_height
  {
    out << "landing_height: ";
    rosidl_generator_traits::value_to_yaml(msg.landing_height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BallTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_x, out);
    out << "\n";
  }

  // member: current_pos_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pos_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_y, out);
    out << "\n";
  }

  // member: current_pos_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_pos_z, out);
    out << "\n";
  }

  // member: current_vel_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_x, out);
    out << "\n";
  }

  // member: current_vel_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_y, out);
    out << "\n";
  }

  // member: current_vel_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_vel_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_vel_z, out);
    out << "\n";
  }

  // member: current_damping_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_damping_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_x, out);
    out << "\n";
  }

  // member: current_damping_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_damping_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_y, out);
    out << "\n";
  }

  // member: current_damping_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_damping_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_damping_z, out);
    out << "\n";
  }

  // member: current_mass
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_mass: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mass, out);
    out << "\n";
  }

  // member: landing_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "landing_height: ";
    rosidl_generator_traits::value_to_yaml(msg.landing_height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BallTrajectory & msg, bool use_flow_style = false)
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
  const amp_msgs::msg::BallTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  amp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amp_msgs::msg::BallTrajectory & msg)
{
  return amp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amp_msgs::msg::BallTrajectory>()
{
  return "amp_msgs::msg::BallTrajectory";
}

template<>
inline const char * name<amp_msgs::msg::BallTrajectory>()
{
  return "amp_msgs/msg/BallTrajectory";
}

template<>
struct has_fixed_size<amp_msgs::msg::BallTrajectory>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<amp_msgs::msg::BallTrajectory>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<amp_msgs::msg::BallTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__TRAITS_HPP_
