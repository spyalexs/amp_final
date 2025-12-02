// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_H_
#define AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BallTrajectory in the package amp_msgs.
typedef struct amp_msgs__msg__BallTrajectory
{
  float current_pos_x;
  float current_pos_y;
  float current_pos_z;
  float current_vel_x;
  float current_vel_y;
  float current_vel_z;
  float current_damping_x;
  float current_damping_y;
  float current_damping_z;
  float current_mass;
  float landing_height;
} amp_msgs__msg__BallTrajectory;

// Struct for a sequence of amp_msgs__msg__BallTrajectory.
typedef struct amp_msgs__msg__BallTrajectory__Sequence
{
  amp_msgs__msg__BallTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amp_msgs__msg__BallTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_H_
