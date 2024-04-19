// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef COORDINATE_MSG__MSG__DETAIL__COORDINATE__BUILDER_HPP_
#define COORDINATE_MSG__MSG__DETAIL__COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "coordinate_msg/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace coordinate_msg
{

namespace msg
{

namespace builder
{

class Init_Coordinate_z
{
public:
  explicit Init_Coordinate_z(::coordinate_msg::msg::Coordinate & msg)
  : msg_(msg)
  {}
  ::coordinate_msg::msg::Coordinate z(::coordinate_msg::msg::Coordinate::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::coordinate_msg::msg::Coordinate msg_;
};

class Init_Coordinate_y
{
public:
  explicit Init_Coordinate_y(::coordinate_msg::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_z y(::coordinate_msg::msg::Coordinate::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Coordinate_z(msg_);
  }

private:
  ::coordinate_msg::msg::Coordinate msg_;
};

class Init_Coordinate_x
{
public:
  explicit Init_Coordinate_x(::coordinate_msg::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_y x(::coordinate_msg::msg::Coordinate::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coordinate_y(msg_);
  }

private:
  ::coordinate_msg::msg::Coordinate msg_;
};

class Init_Coordinate_num
{
public:
  Init_Coordinate_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_x num(::coordinate_msg::msg::Coordinate::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_Coordinate_x(msg_);
  }

private:
  ::coordinate_msg::msg::Coordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::coordinate_msg::msg::Coordinate>()
{
  return coordinate_msg::msg::builder::Init_Coordinate_num();
}

}  // namespace coordinate_msg

#endif  // COORDINATE_MSG__MSG__DETAIL__COORDINATE__BUILDER_HPP_
