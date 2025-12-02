// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/ball_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
amp_msgs__msg__BallTrajectory__init(amp_msgs__msg__BallTrajectory * msg)
{
  if (!msg) {
    return false;
  }
  // current_pos_x
  // current_pos_y
  // current_pos_z
  // current_vel_x
  // current_vel_y
  // current_vel_z
  // current_damping_x
  // current_damping_y
  // current_damping_z
  // current_mass
  // landing_height
  return true;
}

void
amp_msgs__msg__BallTrajectory__fini(amp_msgs__msg__BallTrajectory * msg)
{
  if (!msg) {
    return;
  }
  // current_pos_x
  // current_pos_y
  // current_pos_z
  // current_vel_x
  // current_vel_y
  // current_vel_z
  // current_damping_x
  // current_damping_y
  // current_damping_z
  // current_mass
  // landing_height
}

bool
amp_msgs__msg__BallTrajectory__are_equal(const amp_msgs__msg__BallTrajectory * lhs, const amp_msgs__msg__BallTrajectory * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_pos_x
  if (lhs->current_pos_x != rhs->current_pos_x) {
    return false;
  }
  // current_pos_y
  if (lhs->current_pos_y != rhs->current_pos_y) {
    return false;
  }
  // current_pos_z
  if (lhs->current_pos_z != rhs->current_pos_z) {
    return false;
  }
  // current_vel_x
  if (lhs->current_vel_x != rhs->current_vel_x) {
    return false;
  }
  // current_vel_y
  if (lhs->current_vel_y != rhs->current_vel_y) {
    return false;
  }
  // current_vel_z
  if (lhs->current_vel_z != rhs->current_vel_z) {
    return false;
  }
  // current_damping_x
  if (lhs->current_damping_x != rhs->current_damping_x) {
    return false;
  }
  // current_damping_y
  if (lhs->current_damping_y != rhs->current_damping_y) {
    return false;
  }
  // current_damping_z
  if (lhs->current_damping_z != rhs->current_damping_z) {
    return false;
  }
  // current_mass
  if (lhs->current_mass != rhs->current_mass) {
    return false;
  }
  // landing_height
  if (lhs->landing_height != rhs->landing_height) {
    return false;
  }
  return true;
}

bool
amp_msgs__msg__BallTrajectory__copy(
  const amp_msgs__msg__BallTrajectory * input,
  amp_msgs__msg__BallTrajectory * output)
{
  if (!input || !output) {
    return false;
  }
  // current_pos_x
  output->current_pos_x = input->current_pos_x;
  // current_pos_y
  output->current_pos_y = input->current_pos_y;
  // current_pos_z
  output->current_pos_z = input->current_pos_z;
  // current_vel_x
  output->current_vel_x = input->current_vel_x;
  // current_vel_y
  output->current_vel_y = input->current_vel_y;
  // current_vel_z
  output->current_vel_z = input->current_vel_z;
  // current_damping_x
  output->current_damping_x = input->current_damping_x;
  // current_damping_y
  output->current_damping_y = input->current_damping_y;
  // current_damping_z
  output->current_damping_z = input->current_damping_z;
  // current_mass
  output->current_mass = input->current_mass;
  // landing_height
  output->landing_height = input->landing_height;
  return true;
}

amp_msgs__msg__BallTrajectory *
amp_msgs__msg__BallTrajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__BallTrajectory * msg = (amp_msgs__msg__BallTrajectory *)allocator.allocate(sizeof(amp_msgs__msg__BallTrajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(amp_msgs__msg__BallTrajectory));
  bool success = amp_msgs__msg__BallTrajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
amp_msgs__msg__BallTrajectory__destroy(amp_msgs__msg__BallTrajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    amp_msgs__msg__BallTrajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
amp_msgs__msg__BallTrajectory__Sequence__init(amp_msgs__msg__BallTrajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__BallTrajectory * data = NULL;

  if (size) {
    data = (amp_msgs__msg__BallTrajectory *)allocator.zero_allocate(size, sizeof(amp_msgs__msg__BallTrajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = amp_msgs__msg__BallTrajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        amp_msgs__msg__BallTrajectory__fini(&data[i - 1]);
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
amp_msgs__msg__BallTrajectory__Sequence__fini(amp_msgs__msg__BallTrajectory__Sequence * array)
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
      amp_msgs__msg__BallTrajectory__fini(&array->data[i]);
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

amp_msgs__msg__BallTrajectory__Sequence *
amp_msgs__msg__BallTrajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__BallTrajectory__Sequence * array = (amp_msgs__msg__BallTrajectory__Sequence *)allocator.allocate(sizeof(amp_msgs__msg__BallTrajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = amp_msgs__msg__BallTrajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
amp_msgs__msg__BallTrajectory__Sequence__destroy(amp_msgs__msg__BallTrajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    amp_msgs__msg__BallTrajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
amp_msgs__msg__BallTrajectory__Sequence__are_equal(const amp_msgs__msg__BallTrajectory__Sequence * lhs, const amp_msgs__msg__BallTrajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!amp_msgs__msg__BallTrajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
amp_msgs__msg__BallTrajectory__Sequence__copy(
  const amp_msgs__msg__BallTrajectory__Sequence * input,
  amp_msgs__msg__BallTrajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(amp_msgs__msg__BallTrajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    amp_msgs__msg__BallTrajectory * data =
      (amp_msgs__msg__BallTrajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!amp_msgs__msg__BallTrajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          amp_msgs__msg__BallTrajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!amp_msgs__msg__BallTrajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
