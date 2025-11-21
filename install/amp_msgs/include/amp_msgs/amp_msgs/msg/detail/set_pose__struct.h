// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amp_msgs:msg/SetPose.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_H_
#define AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SetPose in the package amp_msgs.
typedef struct amp_msgs__msg__SetPose
{
  float x_pos;
  float y_pos;
  float heading;
} amp_msgs__msg__SetPose;

// Struct for a sequence of amp_msgs__msg__SetPose.
typedef struct amp_msgs__msg__SetPose__Sequence
{
  amp_msgs__msg__SetPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amp_msgs__msg__SetPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_H_
