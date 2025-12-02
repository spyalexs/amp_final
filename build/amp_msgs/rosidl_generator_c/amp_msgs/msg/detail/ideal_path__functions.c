// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/ideal_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `control_array`
#include "amp_msgs/msg/detail/agent_control__functions.h"
// Member `duration_array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
amp_msgs__msg__IdealPath__init(amp_msgs__msg__IdealPath * msg)
{
  if (!msg) {
    return false;
  }
  // control_array
  if (!amp_msgs__msg__AgentControl__Sequence__init(&msg->control_array, 0)) {
    amp_msgs__msg__IdealPath__fini(msg);
    return false;
  }
  // duration_array
  if (!rosidl_runtime_c__float__Sequence__init(&msg->duration_array, 0)) {
    amp_msgs__msg__IdealPath__fini(msg);
    return false;
  }
  // run_time
  return true;
}

void
amp_msgs__msg__IdealPath__fini(amp_msgs__msg__IdealPath * msg)
{
  if (!msg) {
    return;
  }
  // control_array
  amp_msgs__msg__AgentControl__Sequence__fini(&msg->control_array);
  // duration_array
  rosidl_runtime_c__float__Sequence__fini(&msg->duration_array);
  // run_time
}

bool
amp_msgs__msg__IdealPath__are_equal(const amp_msgs__msg__IdealPath * lhs, const amp_msgs__msg__IdealPath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // control_array
  if (!amp_msgs__msg__AgentControl__Sequence__are_equal(
      &(lhs->control_array), &(rhs->control_array)))
  {
    return false;
  }
  // duration_array
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->duration_array), &(rhs->duration_array)))
  {
    return false;
  }
  // run_time
  if (lhs->run_time != rhs->run_time) {
    return false;
  }
  return true;
}

bool
amp_msgs__msg__IdealPath__copy(
  const amp_msgs__msg__IdealPath * input,
  amp_msgs__msg__IdealPath * output)
{
  if (!input || !output) {
    return false;
  }
  // control_array
  if (!amp_msgs__msg__AgentControl__Sequence__copy(
      &(input->control_array), &(output->control_array)))
  {
    return false;
  }
  // duration_array
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->duration_array), &(output->duration_array)))
  {
    return false;
  }
  // run_time
  output->run_time = input->run_time;
  return true;
}

amp_msgs__msg__IdealPath *
amp_msgs__msg__IdealPath__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__IdealPath * msg = (amp_msgs__msg__IdealPath *)allocator.allocate(sizeof(amp_msgs__msg__IdealPath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(amp_msgs__msg__IdealPath));
  bool success = amp_msgs__msg__IdealPath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
amp_msgs__msg__IdealPath__destroy(amp_msgs__msg__IdealPath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    amp_msgs__msg__IdealPath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
amp_msgs__msg__IdealPath__Sequence__init(amp_msgs__msg__IdealPath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__IdealPath * data = NULL;

  if (size) {
    data = (amp_msgs__msg__IdealPath *)allocator.zero_allocate(size, sizeof(amp_msgs__msg__IdealPath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = amp_msgs__msg__IdealPath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        amp_msgs__msg__IdealPath__fini(&data[i - 1]);
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
amp_msgs__msg__IdealPath__Sequence__fini(amp_msgs__msg__IdealPath__Sequence * array)
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
      amp_msgs__msg__IdealPath__fini(&array->data[i]);
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

amp_msgs__msg__IdealPath__Sequence *
amp_msgs__msg__IdealPath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amp_msgs__msg__IdealPath__Sequence * array = (amp_msgs__msg__IdealPath__Sequence *)allocator.allocate(sizeof(amp_msgs__msg__IdealPath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = amp_msgs__msg__IdealPath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
amp_msgs__msg__IdealPath__Sequence__destroy(amp_msgs__msg__IdealPath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    amp_msgs__msg__IdealPath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
amp_msgs__msg__IdealPath__Sequence__are_equal(const amp_msgs__msg__IdealPath__Sequence * lhs, const amp_msgs__msg__IdealPath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!amp_msgs__msg__IdealPath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
amp_msgs__msg__IdealPath__Sequence__copy(
  const amp_msgs__msg__IdealPath__Sequence * input,
  amp_msgs__msg__IdealPath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(amp_msgs__msg__IdealPath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    amp_msgs__msg__IdealPath * data =
      (amp_msgs__msg__IdealPath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!amp_msgs__msg__IdealPath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          amp_msgs__msg__IdealPath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!amp_msgs__msg__IdealPath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
