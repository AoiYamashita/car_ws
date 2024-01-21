// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "coordinate_msg/msg/detail/coordinate__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace coordinate_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Coordinate_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) coordinate_msg::msg::Coordinate(_init);
}

void Coordinate_fini_function(void * message_memory)
{
  auto typed_message = static_cast<coordinate_msg::msg::Coordinate *>(message_memory);
  typed_message->~Coordinate();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Coordinate_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg::msg::Coordinate, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg::msg::Coordinate, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "r",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(coordinate_msg::msg::Coordinate, r),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Coordinate_message_members = {
  "coordinate_msg::msg",  // message namespace
  "Coordinate",  // message name
  3,  // number of fields
  sizeof(coordinate_msg::msg::Coordinate),
  Coordinate_message_member_array,  // message members
  Coordinate_init_function,  // function to initialize message memory (memory has to be allocated)
  Coordinate_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Coordinate_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Coordinate_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace coordinate_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<coordinate_msg::msg::Coordinate>()
{
  return &::coordinate_msg::msg::rosidl_typesupport_introspection_cpp::Coordinate_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, coordinate_msg, msg, Coordinate)() {
  return &::coordinate_msg::msg::rosidl_typesupport_introspection_cpp::Coordinate_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
