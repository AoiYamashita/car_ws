// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_H_
#define COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Coordinate in the package coordinate_msg.
typedef struct coordinate_msg__msg__Coordinate
{
  int8_t num;
  rosidl_runtime_c__float__Sequence x;
  rosidl_runtime_c__float__Sequence y;
  rosidl_runtime_c__float__Sequence z;
} coordinate_msg__msg__Coordinate;

// Struct for a sequence of coordinate_msg__msg__Coordinate.
typedef struct coordinate_msg__msg__Coordinate__Sequence
{
  coordinate_msg__msg__Coordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} coordinate_msg__msg__Coordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_H_
