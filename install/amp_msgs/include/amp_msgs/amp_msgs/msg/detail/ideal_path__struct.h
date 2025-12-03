// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_H_
#define AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'control_array'
#include "amp_msgs/msg/detail/agent_control__struct.h"
// Member 'duration_array'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'start_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/IdealPath in the package amp_msgs.
typedef struct amp_msgs__msg__IdealPath
{
  amp_msgs__msg__AgentControl__Sequence control_array;
  rosidl_runtime_c__float__Sequence duration_array;
  float run_time;
  builtin_interfaces__msg__Time start_time;
} amp_msgs__msg__IdealPath;

// Struct for a sequence of amp_msgs__msg__IdealPath.
typedef struct amp_msgs__msg__IdealPath__Sequence
{
  amp_msgs__msg__IdealPath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amp_msgs__msg__IdealPath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_H_
