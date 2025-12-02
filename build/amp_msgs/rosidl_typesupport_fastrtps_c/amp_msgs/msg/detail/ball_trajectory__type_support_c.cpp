// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/ball_trajectory__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "amp_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "amp_msgs/msg/detail/ball_trajectory__struct.h"
#include "amp_msgs/msg/detail/ball_trajectory__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _BallTrajectory__ros_msg_type = amp_msgs__msg__BallTrajectory;

static bool _BallTrajectory__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BallTrajectory__ros_msg_type * ros_message = static_cast<const _BallTrajectory__ros_msg_type *>(untyped_ros_message);
  // Field name: current_pos_x
  {
    cdr << ros_message->current_pos_x;
  }

  // Field name: current_pos_y
  {
    cdr << ros_message->current_pos_y;
  }

  // Field name: current_pos_z
  {
    cdr << ros_message->current_pos_z;
  }

  // Field name: current_vel_x
  {
    cdr << ros_message->current_vel_x;
  }

  // Field name: current_vel_y
  {
    cdr << ros_message->current_vel_y;
  }

  // Field name: current_vel_z
  {
    cdr << ros_message->current_vel_z;
  }

  // Field name: current_damping_x
  {
    cdr << ros_message->current_damping_x;
  }

  // Field name: current_damping_y
  {
    cdr << ros_message->current_damping_y;
  }

  // Field name: current_damping_z
  {
    cdr << ros_message->current_damping_z;
  }

  // Field name: current_mass
  {
    cdr << ros_message->current_mass;
  }

  // Field name: landing_height
  {
    cdr << ros_message->landing_height;
  }

  return true;
}

static bool _BallTrajectory__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BallTrajectory__ros_msg_type * ros_message = static_cast<_BallTrajectory__ros_msg_type *>(untyped_ros_message);
  // Field name: current_pos_x
  {
    cdr >> ros_message->current_pos_x;
  }

  // Field name: current_pos_y
  {
    cdr >> ros_message->current_pos_y;
  }

  // Field name: current_pos_z
  {
    cdr >> ros_message->current_pos_z;
  }

  // Field name: current_vel_x
  {
    cdr >> ros_message->current_vel_x;
  }

  // Field name: current_vel_y
  {
    cdr >> ros_message->current_vel_y;
  }

  // Field name: current_vel_z
  {
    cdr >> ros_message->current_vel_z;
  }

  // Field name: current_damping_x
  {
    cdr >> ros_message->current_damping_x;
  }

  // Field name: current_damping_y
  {
    cdr >> ros_message->current_damping_y;
  }

  // Field name: current_damping_z
  {
    cdr >> ros_message->current_damping_z;
  }

  // Field name: current_mass
  {
    cdr >> ros_message->current_mass;
  }

  // Field name: landing_height
  {
    cdr >> ros_message->landing_height;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_amp_msgs
size_t get_serialized_size_amp_msgs__msg__BallTrajectory(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BallTrajectory__ros_msg_type * ros_message = static_cast<const _BallTrajectory__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name current_pos_x
  {
    size_t item_size = sizeof(ros_message->current_pos_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_pos_y
  {
    size_t item_size = sizeof(ros_message->current_pos_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_pos_z
  {
    size_t item_size = sizeof(ros_message->current_pos_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_vel_x
  {
    size_t item_size = sizeof(ros_message->current_vel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_vel_y
  {
    size_t item_size = sizeof(ros_message->current_vel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_vel_z
  {
    size_t item_size = sizeof(ros_message->current_vel_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_damping_x
  {
    size_t item_size = sizeof(ros_message->current_damping_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_damping_y
  {
    size_t item_size = sizeof(ros_message->current_damping_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_damping_z
  {
    size_t item_size = sizeof(ros_message->current_damping_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_mass
  {
    size_t item_size = sizeof(ros_message->current_mass);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name landing_height
  {
    size_t item_size = sizeof(ros_message->landing_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BallTrajectory__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_amp_msgs__msg__BallTrajectory(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_amp_msgs
size_t max_serialized_size_amp_msgs__msg__BallTrajectory(
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

  // member: current_pos_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_pos_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_pos_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_vel_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_vel_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_vel_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_damping_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_damping_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_damping_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_mass
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: landing_height
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
    using DataType = amp_msgs__msg__BallTrajectory;
    is_plain =
      (
      offsetof(DataType, landing_height) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BallTrajectory__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_amp_msgs__msg__BallTrajectory(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BallTrajectory = {
  "amp_msgs::msg",
  "BallTrajectory",
  _BallTrajectory__cdr_serialize,
  _BallTrajectory__cdr_deserialize,
  _BallTrajectory__get_serialized_size,
  _BallTrajectory__max_serialized_size
};

static rosidl_message_type_support_t _BallTrajectory__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BallTrajectory,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, amp_msgs, msg, BallTrajectory)() {
  return &_BallTrajectory__type_support;
}

#if defined(__cplusplus)
}
#endif
