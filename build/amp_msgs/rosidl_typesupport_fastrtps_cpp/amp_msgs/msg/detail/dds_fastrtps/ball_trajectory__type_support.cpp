// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/ball_trajectory__rosidl_typesupport_fastrtps_cpp.hpp"
#include "amp_msgs/msg/detail/ball_trajectory__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace amp_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
cdr_serialize(
  const amp_msgs::msg::BallTrajectory & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: current_pos_x
  cdr << ros_message.current_pos_x;
  // Member: current_pos_y
  cdr << ros_message.current_pos_y;
  // Member: current_pos_z
  cdr << ros_message.current_pos_z;
  // Member: current_vel_x
  cdr << ros_message.current_vel_x;
  // Member: current_vel_y
  cdr << ros_message.current_vel_y;
  // Member: current_vel_z
  cdr << ros_message.current_vel_z;
  // Member: current_damping_x
  cdr << ros_message.current_damping_x;
  // Member: current_damping_y
  cdr << ros_message.current_damping_y;
  // Member: current_damping_z
  cdr << ros_message.current_damping_z;
  // Member: current_mass
  cdr << ros_message.current_mass;
  // Member: landing_height
  cdr << ros_message.landing_height;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  amp_msgs::msg::BallTrajectory & ros_message)
{
  // Member: current_pos_x
  cdr >> ros_message.current_pos_x;

  // Member: current_pos_y
  cdr >> ros_message.current_pos_y;

  // Member: current_pos_z
  cdr >> ros_message.current_pos_z;

  // Member: current_vel_x
  cdr >> ros_message.current_vel_x;

  // Member: current_vel_y
  cdr >> ros_message.current_vel_y;

  // Member: current_vel_z
  cdr >> ros_message.current_vel_z;

  // Member: current_damping_x
  cdr >> ros_message.current_damping_x;

  // Member: current_damping_y
  cdr >> ros_message.current_damping_y;

  // Member: current_damping_z
  cdr >> ros_message.current_damping_z;

  // Member: current_mass
  cdr >> ros_message.current_mass;

  // Member: landing_height
  cdr >> ros_message.landing_height;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
get_serialized_size(
  const amp_msgs::msg::BallTrajectory & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: current_pos_x
  {
    size_t item_size = sizeof(ros_message.current_pos_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_pos_y
  {
    size_t item_size = sizeof(ros_message.current_pos_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_pos_z
  {
    size_t item_size = sizeof(ros_message.current_pos_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_vel_x
  {
    size_t item_size = sizeof(ros_message.current_vel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_vel_y
  {
    size_t item_size = sizeof(ros_message.current_vel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_vel_z
  {
    size_t item_size = sizeof(ros_message.current_vel_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_damping_x
  {
    size_t item_size = sizeof(ros_message.current_damping_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_damping_y
  {
    size_t item_size = sizeof(ros_message.current_damping_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_damping_z
  {
    size_t item_size = sizeof(ros_message.current_damping_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_mass
  {
    size_t item_size = sizeof(ros_message.current_mass);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: landing_height
  {
    size_t item_size = sizeof(ros_message.landing_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
max_serialized_size_BallTrajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: current_pos_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_pos_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_pos_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_vel_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_vel_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_vel_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_damping_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_damping_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_damping_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_mass
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: landing_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = amp_msgs::msg::BallTrajectory;
    is_plain =
      (
      offsetof(DataType, landing_height) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BallTrajectory__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const amp_msgs::msg::BallTrajectory *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BallTrajectory__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<amp_msgs::msg::BallTrajectory *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BallTrajectory__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const amp_msgs::msg::BallTrajectory *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BallTrajectory__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BallTrajectory(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BallTrajectory__callbacks = {
  "amp_msgs::msg",
  "BallTrajectory",
  _BallTrajectory__cdr_serialize,
  _BallTrajectory__cdr_deserialize,
  _BallTrajectory__get_serialized_size,
  _BallTrajectory__max_serialized_size
};

static rosidl_message_type_support_t _BallTrajectory__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BallTrajectory__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace amp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_amp_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<amp_msgs::msg::BallTrajectory>()
{
  return &amp_msgs::msg::typesupport_fastrtps_cpp::_BallTrajectory__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, amp_msgs, msg, BallTrajectory)() {
  return &amp_msgs::msg::typesupport_fastrtps_cpp::_BallTrajectory__handle;
}

#ifdef __cplusplus
}
#endif
