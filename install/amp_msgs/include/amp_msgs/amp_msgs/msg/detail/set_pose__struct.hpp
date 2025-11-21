// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/SetPose.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__SetPose __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__SetPose __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetPose_
{
  using Type = SetPose_<ContainerAllocator>;

  explicit SetPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0f;
      this->y_pos = 0.0f;
      this->heading = 0.0f;
    }
  }

  explicit SetPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0f;
      this->y_pos = 0.0f;
      this->heading = 0.0f;
    }
  }

  // field types and members
  using _x_pos_type =
    float;
  _x_pos_type x_pos;
  using _y_pos_type =
    float;
  _y_pos_type y_pos;
  using _heading_type =
    float;
  _heading_type heading;

  // setters for named parameter idiom
  Type & set__x_pos(
    const float & _arg)
  {
    this->x_pos = _arg;
    return *this;
  }
  Type & set__y_pos(
    const float & _arg)
  {
    this->y_pos = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::SetPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::SetPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::SetPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::SetPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::SetPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::SetPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::SetPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::SetPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::SetPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::SetPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__SetPose
    std::shared_ptr<amp_msgs::msg::SetPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__SetPose
    std::shared_ptr<amp_msgs::msg::SetPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPose_ & other) const
  {
    if (this->x_pos != other.x_pos) {
      return false;
    }
    if (this->y_pos != other.y_pos) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPose_

// alias to use template instance with default allocator
using SetPose =
  amp_msgs::msg::SetPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__SET_POSE__STRUCT_HPP_
