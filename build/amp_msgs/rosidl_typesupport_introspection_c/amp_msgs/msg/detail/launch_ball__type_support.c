// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "amp_msgs/msg/detail/launch_ball__rosidl_typesupport_introspection_c.h"
#include "amp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "amp_msgs/msg/detail/launch_ball__functions.h"
#include "amp_msgs/msg/detail/launch_ball__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  amp_msgs__msg__LaunchBall__init(message_memory);
}

void amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_fini_function(void * message_memory)
{
  amp_msgs__msg__LaunchBall__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_member_array[3] = {
  {
    "ball_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__LaunchBall, ball_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ball_launch_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__LaunchBall, ball_launch_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ball_launch_heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__LaunchBall, ball_launch_heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_members = {
  "amp_msgs__msg",  // message namespace
  "LaunchBall",  // message name
  3,  // number of fields
  sizeof(amp_msgs__msg__LaunchBall),
  amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_member_array,  // message members
  amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_init_function,  // function to initialize message memory (memory has to be allocated)
  amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_type_support_handle = {
  0,
  &amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_amp_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, amp_msgs, msg, LaunchBall)() {
  if (!amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_type_support_handle.typesupport_identifier) {
    amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &amp_msgs__msg__LaunchBall__rosidl_typesupport_introspection_c__LaunchBall_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
