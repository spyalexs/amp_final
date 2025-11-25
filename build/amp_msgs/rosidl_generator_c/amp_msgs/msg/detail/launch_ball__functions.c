// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/launch_ball__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
amp_msgs__msg__LaunchBall__init(amp_msgs__msg__LaunchBall * msg)
{
  if (!msg) {
    return false;
  }
  // ball_velocity
  // ball_launch_angle
  // ball_launch_heading
  // ball_pos_x
  // ball_pos_y
  // ball_pos_z
  return true;
}

void
amp_msgs__msg__LaunchBall__fini(amp_msgs__msg__LaunchBall * msg)
{
  if (!msg) {
    return;
  }
  // ball_velocity
  // ball_launch_angle
  // ball_launch_heading
  // ball_pos_x
  // ball_pos_y
  // ball_pos_z
}

bool
amp_msgs__msg__LaunchBall__are_equal(const amp_msgs__msg__LaunchBall * lhs, const amp_msgs__msg__LaunchBall * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ball_velocity
  if (lhs->ball_velocity != rhs->ball_velocity) {
    return false;
  }
  // ball_launch_angle
  if (lhs->ball_launch_angle != rhs->ball_launch_angle) {
    return false;
  }
  // ball_launch_heading
  if (lhs->ball_launch_heading != rhs->ball_launch_heading) {
    return false;
  }
  // ball_pos_x
  if (lhs->ball_pos_x != rhs->ball_pos_x) {
    return false;
  }
  // ball_pos_y
  if (lhs->ball_pos_y != rhs->ball_pos_y) {
    return false;
  }
  // ball_pos_z
  if (lhs->ball_pos_z != rhs->ball_pos_z) {
    return false;
  }
  return true;
}

bool
amp_msgs__msg__LaunchBall__copy(
  const amp_msgs__msg__LaunchBall * input,
  amp_msgs__msg__LaunchBall * output)
{
  if (!input || !output) {
    return false;
  }
  // ball_velocity
  output->ball_velocity = input->ball_velocity;
  // ball_launch_angle
  output->ball_launch_angle = input->ball_launch_angle;
  // ball_launch_heading
  output->ball_launch_heading = input->ball_launch_heading;
  // ball_pos_x
  output->ball_pos_x = input->ball_pos_x;
  // ball_pos_y
  output->ball_pos_y = input->ball_pos_y;
  // ball_pos_z
  output->ball_pos_z = input->ball_pos_z;
  return true;
}

amp_msgs__msg__LaunchBall *
amp_msgs__msg__LaunchBall__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__LaunchBall * msg = (amp_msgs__msg__LaunchBall *)allocator.allocate(sizeof(amp_msgs__msg__LaunchBall), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(amp_msgs__msg__LaunchBall));
  bool success = amp_msgs__msg__LaunchBall__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
amp_msgs__msg__LaunchBall__destroy(amp_msgs__msg__LaunchBall * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    amp_msgs__msg__LaunchBall__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
amp_msgs__msg__LaunchBall__Sequence__init(amp_msgs__msg__LaunchBall__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__LaunchBall * data = NULL;

  if (size) {
    data = (amp_msgs__msg__LaunchBall *)allocator.zero_allocate(size, sizeof(amp_msgs__msg__LaunchBall), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = amp_msgs__msg__LaunchBall__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        amp_msgs__msg__LaunchBall__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
amp_msgs__msg__LaunchBall__Sequence__fini(amp_msgs__msg__LaunchBall__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      amp_msgs__msg__LaunchBall__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

amp_msgs__msg__LaunchBall__Sequence *
amp_msgs__msg__LaunchBall__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__LaunchBall__Sequence * array = (amp_msgs__msg__LaunchBall__Sequence *)allocator.allocate(sizeof(amp_msgs__msg__LaunchBall__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = amp_msgs__msg__LaunchBall__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
amp_msgs__msg__LaunchBall__Sequence__destroy(amp_msgs__msg__LaunchBall__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    amp_msgs__msg__LaunchBall__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
amp_msgs__msg__LaunchBall__Sequence__are_equal(const amp_msgs__msg__LaunchBall__Sequence * lhs, const amp_msgs__msg__LaunchBall__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!amp_msgs__msg__LaunchBall__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
amp_msgs__msg__LaunchBall__Sequence__copy(
  const amp_msgs__msg__LaunchBall__Sequence * input,
  amp_msgs__msg__LaunchBall__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(amp_msgs__msg__LaunchBall);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    amp_msgs__msg__LaunchBall * data =
      (amp_msgs__msg__LaunchBall *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!amp_msgs__msg__LaunchBall__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          amp_msgs__msg__LaunchBall__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!amp_msgs__msg__LaunchBall__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
