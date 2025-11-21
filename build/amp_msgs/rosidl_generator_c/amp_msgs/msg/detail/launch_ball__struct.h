// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_H_
#define AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LaunchBall in the package amp_msgs.
typedef struct amp_msgs__msg__LaunchBall
{
  float ball_velocity;
  float ball_launch_angle;
  float ball_launch_heading;
} amp_msgs__msg__LaunchBall;

// Struct for a sequence of amp_msgs__msg__LaunchBall.
typedef struct amp_msgs__msg__LaunchBall__Sequence
{
  amp_msgs__msg__LaunchBall * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amp_msgs__msg__LaunchBall__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_H_
