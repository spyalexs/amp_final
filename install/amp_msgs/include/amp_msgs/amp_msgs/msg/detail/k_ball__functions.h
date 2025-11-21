// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from amp_msgs:msg/KBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__K_BALL__FUNCTIONS_H_
#define AMP_MSGS__MSG__DETAIL__K_BALL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "amp_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "amp_msgs/msg/detail/k_ball__struct.h"

/// Initialize msg/KBall message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * amp_msgs__msg__KBall
 * )) before or use
 * amp_msgs__msg__KBall__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__init(amp_msgs__msg__KBall * msg);

/// Finalize msg/KBall message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
void
amp_msgs__msg__KBall__fini(amp_msgs__msg__KBall * msg);

/// Create msg/KBall message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * amp_msgs__msg__KBall__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
amp_msgs__msg__KBall *
amp_msgs__msg__KBall__create();

/// Destroy msg/KBall message.
/**
 * It calls
 * amp_msgs__msg__KBall__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
void
amp_msgs__msg__KBall__destroy(amp_msgs__msg__KBall * msg);

/// Check for msg/KBall message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__are_equal(const amp_msgs__msg__KBall * lhs, const amp_msgs__msg__KBall * rhs);

/// Copy a msg/KBall message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__copy(
  const amp_msgs__msg__KBall * input,
  amp_msgs__msg__KBall * output);

/// Initialize array of msg/KBall messages.
/**
 * It allocates the memory for the number of elements and calls
 * amp_msgs__msg__KBall__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__Sequence__init(amp_msgs__msg__KBall__Sequence * array, size_t size);

/// Finalize array of msg/KBall messages.
/**
 * It calls
 * amp_msgs__msg__KBall__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
void
amp_msgs__msg__KBall__Sequence__fini(amp_msgs__msg__KBall__Sequence * array);

/// Create array of msg/KBall messages.
/**
 * It allocates the memory for the array and calls
 * amp_msgs__msg__KBall__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
amp_msgs__msg__KBall__Sequence *
amp_msgs__msg__KBall__Sequence__create(size_t size);

/// Destroy array of msg/KBall messages.
/**
 * It calls
 * amp_msgs__msg__KBall__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
void
amp_msgs__msg__KBall__Sequence__destroy(amp_msgs__msg__KBall__Sequence * array);

/// Check for msg/KBall message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__Sequence__are_equal(const amp_msgs__msg__KBall__Sequence * lhs, const amp_msgs__msg__KBall__Sequence * rhs);

/// Copy an array of msg/KBall messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_amp_msgs
bool
amp_msgs__msg__KBall__Sequence__copy(
  const amp_msgs__msg__KBall__Sequence * input,
  amp_msgs__msg__KBall__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AMP_MSGS__MSG__DETAIL__K_BALL__FUNCTIONS_H_
