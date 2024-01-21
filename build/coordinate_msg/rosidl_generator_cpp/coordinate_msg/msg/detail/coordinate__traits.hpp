// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef COORDINATE_MSG__MSG__DETAIL__COORDINATE__TRAITS_HPP_
#define COORDINATE_MSG__MSG__DETAIL__COORDINATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "coordinate_msg/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace coordinate_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coordinate & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coordinate & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace coordinate_msg

namespace rosidl_generator_traits
{

[[deprecated("use coordinate_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const coordinate_msg::msg::Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  coordinate_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use coordinate_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const coordinate_msg::msg::Coordinate & msg)
{
  return coordinate_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<coordinate_msg::msg::Coordinate>()
{
  return "coordinate_msg::msg::Coordinate";
}

template<>
inline const char * name<coordinate_msg::msg::Coordinate>()
{
  return "coordinate_msg/msg/Coordinate";
}

template<>
struct has_fixed_size<coordinate_msg::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<coordinate_msg::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<coordinate_msg::msg::Coordinate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COORDINATE_MSG__MSG__DETAIL__COORDINATE__TRAITS_HPP_
