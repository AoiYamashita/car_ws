// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from coordinate_msg:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_HPP_
#define COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__coordinate_msg__msg__Coordinate __attribute__((deprecated))
#else
# define DEPRECATED__coordinate_msg__msg__Coordinate __declspec(deprecated)
#endif

namespace coordinate_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coordinate_
{
  using Type = Coordinate_<ContainerAllocator>;

  explicit Coordinate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
    }
  }

  explicit Coordinate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
    }
  }

  // field types and members
  using _num_type =
    int8_t;
  _num_type num;
  using _x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _x_type x;
  using _y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _y_type y;
  using _z_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _z_type z;

  // setters for named parameter idiom
  Type & set__num(
    const int8_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    coordinate_msg::msg::Coordinate_<ContainerAllocator> *;
  using ConstRawPtr =
    const coordinate_msg::msg::Coordinate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      coordinate_msg::msg::Coordinate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      coordinate_msg::msg::Coordinate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__coordinate_msg__msg__Coordinate
    std::shared_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__coordinate_msg__msg__Coordinate
    std::shared_ptr<coordinate_msg::msg::Coordinate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinate_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinate_

// alias to use template instance with default allocator
using Coordinate =
  coordinate_msg::msg::Coordinate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace coordinate_msg

#endif  // COORDINATE_MSG__MSG__DETAIL__COORDINATE__STRUCT_HPP_
