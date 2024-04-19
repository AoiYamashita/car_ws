// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice
#include "coordinate_msg/msg/detail/coordinate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
coordinate_msg__msg__Coordinate__init(coordinate_msg__msg__Coordinate * msg)
{
  if (!msg) {
    return false;
  }
  // num
  // x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->x, 0)) {
    coordinate_msg__msg__Coordinate__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->y, 0)) {
    coordinate_msg__msg__Coordinate__fini(msg);
    return false;
  }
  // z
  if (!rosidl_runtime_c__float__Sequence__init(&msg->z, 0)) {
    coordinate_msg__msg__Coordinate__fini(msg);
    return false;
  }
  return true;
}

void
coordinate_msg__msg__Coordinate__fini(coordinate_msg__msg__Coordinate * msg)
{
  if (!msg) {
    return;
  }
  // num
  // x
  rosidl_runtime_c__float__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__float__Sequence__fini(&msg->y);
  // z
  rosidl_runtime_c__float__Sequence__fini(&msg->z);
}

bool
coordinate_msg__msg__Coordinate__are_equal(const coordinate_msg__msg__Coordinate * lhs, const coordinate_msg__msg__Coordinate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num
  if (lhs->num != rhs->num) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  return true;
}

bool
coordinate_msg__msg__Coordinate__copy(
  const coordinate_msg__msg__Coordinate * input,
  coordinate_msg__msg__Coordinate * output)
{
  if (!input || !output) {
    return false;
  }
  // num
  output->num = input->num;
  // x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  return true;
}

coordinate_msg__msg__Coordinate *
coordinate_msg__msg__Coordinate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  coordinate_msg__msg__Coordinate * msg = (coordinate_msg__msg__Coordinate *)allocator.allocate(sizeof(coordinate_msg__msg__Coordinate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(coordinate_msg__msg__Coordinate));
  bool success = coordinate_msg__msg__Coordinate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
coordinate_msg__msg__Coordinate__destroy(coordinate_msg__msg__Coordinate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    coordinate_msg__msg__Coordinate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
coordinate_msg__msg__Coordinate__Sequence__init(coordinate_msg__msg__Coordinate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  coordinate_msg__msg__Coordinate * data = NULL;

  if (size) {
    data = (coordinate_msg__msg__Coordinate *)allocator.zero_allocate(size, sizeof(coordinate_msg__msg__Coordinate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = coordinate_msg__msg__Coordinate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        coordinate_msg__msg__Coordinate__fini(&data[i - 1]);
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
coordinate_msg__msg__Coordinate__Sequence__fini(coordinate_msg__msg__Coordinate__Sequence * array)
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
      coordinate_msg__msg__Coordinate__fini(&array->data[i]);
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

coordinate_msg__msg__Coordinate__Sequence *
coordinate_msg__msg__Coordinate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  coordinate_msg__msg__Coordinate__Sequence * array = (coordinate_msg__msg__Coordinate__Sequence *)allocator.allocate(sizeof(coordinate_msg__msg__Coordinate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = coordinate_msg__msg__Coordinate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
coordinate_msg__msg__Coordinate__Sequence__destroy(coordinate_msg__msg__Coordinate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    coordinate_msg__msg__Coordinate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
coordinate_msg__msg__Coordinate__Sequence__are_equal(const coordinate_msg__msg__Coordinate__Sequence * lhs, const coordinate_msg__msg__Coordinate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!coordinate_msg__msg__Coordinate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
coordinate_msg__msg__Coordinate__Sequence__copy(
  const coordinate_msg__msg__Coordinate__Sequence * input,
  coordinate_msg__msg__Coordinate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(coordinate_msg__msg__Coordinate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    coordinate_msg__msg__Coordinate * data =
      (coordinate_msg__msg__Coordinate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!coordinate_msg__msg__Coordinate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          coordinate_msg__msg__Coordinate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!coordinate_msg__msg__Coordinate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
