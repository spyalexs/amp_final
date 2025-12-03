// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "amp_msgs/msg/detail/ideal_path__rosidl_typesupport_introspection_c.h"
#include "amp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "amp_msgs/msg/detail/ideal_path__functions.h"
#include "amp_msgs/msg/detail/ideal_path__struct.h"


// Include directives for member types
// Member `control_array`
#include "amp_msgs/msg/agent_control.h"
// Member `control_array`
#include "amp_msgs/msg/detail/agent_control__rosidl_typesupport_introspection_c.h"
// Member `duration_array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `start_time`
#include "builtin_interfaces/msg/time.h"
// Member `start_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  amp_msgs__msg__IdealPath__init(message_memory);
}

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_fini_function(void * message_memory)
{
  amp_msgs__msg__IdealPath__fini(message_memory);
}

size_t amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__size_function__IdealPath__control_array(
  const void * untyped_member)
{
  const amp_msgs__msg__AgentControl__Sequence * member =
    (const amp_msgs__msg__AgentControl__Sequence *)(untyped_member);
  return member->size;
}

const void * amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__control_array(
  const void * untyped_member, size_t index)
{
  const amp_msgs__msg__AgentControl__Sequence * member =
    (const amp_msgs__msg__AgentControl__Sequence *)(untyped_member);
  return &member->data[index];
}

void * amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__control_array(
  void * untyped_member, size_t index)
{
  amp_msgs__msg__AgentControl__Sequence * member =
    (amp_msgs__msg__AgentControl__Sequence *)(untyped_member);
  return &member->data[index];
}

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__fetch_function__IdealPath__control_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const amp_msgs__msg__AgentControl * item =
    ((const amp_msgs__msg__AgentControl *)
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__control_array(untyped_member, index));
  amp_msgs__msg__AgentControl * value =
    (amp_msgs__msg__AgentControl *)(untyped_value);
  *value = *item;
}

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__assign_function__IdealPath__control_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  amp_msgs__msg__AgentControl * item =
    ((amp_msgs__msg__AgentControl *)
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__control_array(untyped_member, index));
  const amp_msgs__msg__AgentControl * value =
    (const amp_msgs__msg__AgentControl *)(untyped_value);
  *item = *value;
}

bool amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__resize_function__IdealPath__control_array(
  void * untyped_member, size_t size)
{
  amp_msgs__msg__AgentControl__Sequence * member =
    (amp_msgs__msg__AgentControl__Sequence *)(untyped_member);
  amp_msgs__msg__AgentControl__Sequence__fini(member);
  return amp_msgs__msg__AgentControl__Sequence__init(member, size);
}

size_t amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__size_function__IdealPath__duration_array(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__duration_array(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__duration_array(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__fetch_function__IdealPath__duration_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__duration_array(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__assign_function__IdealPath__duration_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__duration_array(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__resize_function__IdealPath__duration_array(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_member_array[4] = {
  {
    "control_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__IdealPath, control_array),  // bytes offset in struct
    NULL,  // default value
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__size_function__IdealPath__control_array,  // size() function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__control_array,  // get_const(index) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__control_array,  // get(index) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__fetch_function__IdealPath__control_array,  // fetch(index, &value) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__assign_function__IdealPath__control_array,  // assign(index, value) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__resize_function__IdealPath__control_array  // resize(index) function pointer
  },
  {
    "duration_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__IdealPath, duration_array),  // bytes offset in struct
    NULL,  // default value
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__size_function__IdealPath__duration_array,  // size() function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_const_function__IdealPath__duration_array,  // get_const(index) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__get_function__IdealPath__duration_array,  // get(index) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__fetch_function__IdealPath__duration_array,  // fetch(index, &value) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__assign_function__IdealPath__duration_array,  // assign(index, value) function pointer
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__resize_function__IdealPath__duration_array  // resize(index) function pointer
  },
  {
    "run_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__IdealPath, run_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs__msg__IdealPath, start_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_members = {
  "amp_msgs__msg",  // message namespace
  "IdealPath",  // message name
  4,  // number of fields
  sizeof(amp_msgs__msg__IdealPath),
  amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_member_array,  // message members
  amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_init_function,  // function to initialize message memory (memory has to be allocated)
  amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_type_support_handle = {
  0,
  &amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_amp_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, amp_msgs, msg, IdealPath)() {
  amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, amp_msgs, msg, AgentControl)();
  amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_type_support_handle.typesupport_identifier) {
    amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &amp_msgs__msg__IdealPath__rosidl_typesupport_introspection_c__IdealPath_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
