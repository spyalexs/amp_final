// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/launch_ball__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "amp_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "amp_msgs/msg/detail/launch_ball__struct.h"
#include "amp_msgs/msg/detail/launch_ball__functions.h"
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


using _LaunchBall__ros_msg_type = amp_msgs__msg__LaunchBall;

static bool _LaunchBall__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LaunchBall__ros_msg_type * ros_message = static_cast<const _LaunchBall__ros_msg_type *>(untyped_ros_message);
  // Field name: ball_velocity
  {
    cdr << ros_message->ball_velocity;
  }

  // Field name: ball_launch_angle
  {
    cdr << ros_message->ball_launch_angle;
  }

  // Field name: ball_launch_heading
  {
    cdr << ros_message->ball_launch_heading;
  }

  return true;
}

static bool _LaunchBall__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LaunchBall__ros_msg_type * ros_message = static_cast<_LaunchBall__ros_msg_type *>(untyped_ros_message);
  // Field name: ball_velocity
  {
    cdr >> ros_message->ball_velocity;
  }

  // Field name: ball_launch_angle
  {
    cdr >> ros_message->ball_launch_angle;
  }

  // Field name: ball_launch_heading
  {
    cdr >> ros_message->ball_launch_heading;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_amp_msgs
size_t get_serialized_size_amp_msgs__msg__LaunchBall(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaunchBall__ros_msg_type * ros_message = static_cast<const _LaunchBall__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ball_velocity
  {
    size_t item_size = sizeof(ros_message->ball_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ball_launch_angle
  {
    size_t item_size = sizeof(ros_message->ball_launch_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ball_launch_heading
  {
    size_t item_size = sizeof(ros_message->ball_launch_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LaunchBall__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_amp_msgs__msg__LaunchBall(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_amp_msgs
size_t max_serialized_size_amp_msgs__msg__LaunchBall(
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

  // member: ball_velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ball_launch_angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ball_launch_heading
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
    using DataType = amp_msgs__msg__LaunchBall;
    is_plain =
      (
      offsetof(DataType, ball_launch_heading) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LaunchBall__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_amp_msgs__msg__LaunchBall(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LaunchBall = {
  "amp_msgs::msg",
  "LaunchBall",
  _LaunchBall__cdr_serialize,
  _LaunchBall__cdr_deserialize,
  _LaunchBall__get_serialized_size,
  _LaunchBall__max_serialized_size
};

static rosidl_message_type_support_t _LaunchBall__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LaunchBall,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, amp_msgs, msg, LaunchBall)() {
  return &_LaunchBall__type_support;
}

#if defined(__cplusplus)
}
#endif
