// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__IDEAL_PATH__TRAITS_HPP_
#define AMP_MSGS__MSG__DETAIL__IDEAL_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amp_msgs/msg/detail/ideal_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'control_array'
#include "amp_msgs/msg/detail/agent_control__traits.hpp"
// Member 'start_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace amp_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IdealPath & msg,
  std::ostream & out)
{
  out << "{";
  // member: control_array
  {
    if (msg.control_array.size() == 0) {
      out << "control_array: []";
    } else {
      out << "control_array: [";
      size_t pending_items = msg.control_array.size();
      for (auto item : msg.control_array) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: duration_array
  {
    if (msg.duration_array.size() == 0) {
      out << "duration_array: []";
    } else {
      out << "duration_array: [";
      size_t pending_items = msg.duration_array.size();
      for (auto item : msg.duration_array) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: run_time
  {
    out << "run_time: ";
    rosidl_generator_traits::value_to_yaml(msg.run_time, out);
    out << ", ";
  }

  // member: start_time
  {
    out << "start_time: ";
    to_flow_style_yaml(msg.start_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IdealPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: control_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.control_array.size() == 0) {
      out << "control_array: []\n";
    } else {
      out << "control_array:\n";
      for (auto item : msg.control_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: duration_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.duration_array.size() == 0) {
      out << "duration_array: []\n";
    } else {
      out << "duration_array:\n";
      for (auto item : msg.duration_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: run_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "run_time: ";
    rosidl_generator_traits::value_to_yaml(msg.run_time, out);
    out << "\n";
  }

  // member: start_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_time:\n";
    to_block_style_yaml(msg.start_time, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IdealPath & msg, bool use_flow_style = false)
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
  const amp_msgs::msg::IdealPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  amp_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amp_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amp_msgs::msg::IdealPath & msg)
{
  return amp_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amp_msgs::msg::IdealPath>()
{
  return "amp_msgs::msg::IdealPath";
}

template<>
inline const char * name<amp_msgs::msg::IdealPath>()
{
  return "amp_msgs/msg/IdealPath";
}

template<>
struct has_fixed_size<amp_msgs::msg::IdealPath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<amp_msgs::msg::IdealPath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<amp_msgs::msg::IdealPath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMP_MSGS__MSG__DETAIL__IDEAL_PATH__TRAITS_HPP_
