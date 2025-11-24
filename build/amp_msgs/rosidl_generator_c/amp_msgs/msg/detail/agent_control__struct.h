// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amp_msgs:msg/AgentControl.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_H_
#define AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AgentControl in the package amp_msgs.
typedef struct amp_msgs__msg__AgentControl
{
  float u0;
  float u1;
  float u2;
  float u3;
} amp_msgs__msg__AgentControl;

// Struct for a sequence of amp_msgs__msg__AgentControl.
typedef struct amp_msgs__msg__AgentControl__Sequence
{
  amp_msgs__msg__AgentControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amp_msgs__msg__AgentControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_H_
