// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from amp_msgs:msg/SetPose.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/set_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
amp_msgs__msg__SetPose__init(amp_msgs__msg__SetPose * msg)
{
  if (!msg) {
    return false;
  }
  // x_pos
  // y_pos
  // heading
  return true;
}

void
amp_msgs__msg__SetPose__fini(amp_msgs__msg__SetPose * msg)
{
  if (!msg) {
    return;
  }
  // x_pos
  // y_pos
  // heading
}

bool
amp_msgs__msg__SetPose__are_equal(const amp_msgs__msg__SetPose * lhs, const amp_msgs__msg__SetPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_pos
  if (lhs->x_pos != rhs->x_pos) {
    return false;
  }
  // y_pos
  if (lhs->y_pos != rhs->y_pos) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  return true;
}

bool
amp_msgs__msg__SetPose__copy(
  const amp_msgs__msg__SetPose * input,
  amp_msgs__msg__SetPose * output)
{
  if (!input || !output) {
    return false;
  }
  // x_pos
  output->x_pos = input->x_pos;
  // y_pos
  output->y_pos = input->y_pos;
  // heading
  output->heading = input->heading;
  return true;
}

amp_msgs__msg__SetPose *
amp_msgs__msg__SetPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__SetPose * msg = (amp_msgs__msg__SetPose *)allocator.allocate(sizeof(amp_msgs__msg__SetPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(amp_msgs__msg__SetPose));
  bool success = amp_msgs__msg__SetPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
amp_msgs__msg__SetPose__destroy(amp_msgs__msg__SetPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    amp_msgs__msg__SetPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
amp_msgs__msg__SetPose__Sequence__init(amp_msgs__msg__SetPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__SetPose * data = NULL;

  if (size) {
    data = (amp_msgs__msg__SetPose *)allocator.zero_allocate(size, sizeof(amp_msgs__msg__SetPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = amp_msgs__msg__SetPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        amp_msgs__msg__SetPose__fini(&data[i - 1]);
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
amp_msgs__msg__SetPose__Sequence__fini(amp_msgs__msg__SetPose__Sequence * array)
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
      amp_msgs__msg__SetPose__fini(&array->data[i]);
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

amp_msgs__msg__SetPose__Sequence *
amp_msgs__msg__SetPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__SetPose__Sequence * array = (amp_msgs__msg__SetPose__Sequence *)allocator.allocate(sizeof(amp_msgs__msg__SetPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = amp_msgs__msg__SetPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
amp_msgs__msg__SetPose__Sequence__destroy(amp_msgs__msg__SetPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    amp_msgs__msg__SetPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
amp_msgs__msg__SetPose__Sequence__are_equal(const amp_msgs__msg__SetPose__Sequence * lhs, const amp_msgs__msg__SetPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!amp_msgs__msg__SetPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
amp_msgs__msg__SetPose__Sequence__copy(
  const amp_msgs__msg__SetPose__Sequence * input,
  amp_msgs__msg__SetPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(amp_msgs__msg__SetPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    amp_msgs__msg__SetPose * data =
      (amp_msgs__msg__SetPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!amp_msgs__msg__SetPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          amp_msgs__msg__SetPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!amp_msgs__msg__SetPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
