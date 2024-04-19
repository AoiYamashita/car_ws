// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "coordinate_msg/msg/detail/coordinate__rosidl_typesupport_introspection_c.h"
#include "coordinate_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "coordinate_msg/msg/detail/coordinate__functions.h"
#include "coordinate_msg/msg/detail/coordinate__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  coordinate_msg__msg__Coordinate__init(message_memory);
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_fini_function(void * message_memory)
{
  coordinate_msg__msg__Coordinate__fini(message_memory);
}

size_t coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__z(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__z(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__z(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_member_array[4] = {
  {
    "num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg__msg__Coordinate, num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg__msg__Coordinate, x),  // bytes offset in struct
    NULL,  // default value
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__x,  // size() function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__x,  // get_const(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__x,  // get(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__x,  // fetch(index, &value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__x,  // assign(index, value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg__msg__Coordinate, y),  // bytes offset in struct
    NULL,  // default value
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__y,  // size() function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__y,  // get_const(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__y,  // get(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__y,  // fetch(index, &value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__y,  // assign(index, value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__y  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg__msg__Coordinate, z),  // bytes offset in struct
    NULL,  // default value
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__size_function__Coordinate__z,  // size() function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_const_function__Coordinate__z,  // get_const(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__get_function__Coordinate__z,  // get(index) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__fetch_function__Coordinate__z,  // fetch(index, &value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__assign_function__Coordinate__z,  // assign(index, value) function pointer
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__resize_function__Coordinate__z  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_members = {
  "coordinate_msg__msg",  // message namespace
  "Coordinate",  // message name
  4,  // number of fields
  sizeof(coordinate_msg__msg__Coordinate),
  coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_member_array,  // message members
  coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_init_function,  // function to initialize message memory (memory has to be allocated)
  coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_type_support_handle = {
  0,
  &coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_coordinate_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, coordinate_msg, msg, Coordinate)() {
  if (!coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_type_support_handle.typesupport_identifier) {
    coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &coordinate_msg__msg__Coordinate__rosidl_typesupport_introspection_c__Coordinate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
