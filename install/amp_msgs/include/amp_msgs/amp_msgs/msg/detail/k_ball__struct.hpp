// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/KBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__K_BALL__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__K_BALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__KBall __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__KBall __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KBall_
{
  using Type = KBall_<ContainerAllocator>;

  explicit KBall_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_velocity = 0.0f;
      this->ball_launch_angle = 0.0f;
      this->ball_launch_heading = 0.0f;
    }
  }

  explicit KBall_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_velocity = 0.0f;
      this->ball_launch_angle = 0.0f;
      this->ball_launch_heading = 0.0f;
    }
  }

  // field types and members
  using _ball_velocity_type =
    float;
  _ball_velocity_type ball_velocity;
  using _ball_launch_angle_type =
    float;
  _ball_launch_angle_type ball_launch_angle;
  using _ball_launch_heading_type =
    float;
  _ball_launch_heading_type ball_launch_heading;

  // setters for named parameter idiom
  Type & set__ball_velocity(
    const float & _arg)
  {
    this->ball_velocity = _arg;
    return *this;
  }
  Type & set__ball_launch_angle(
    const float & _arg)
  {
    this->ball_launch_angle = _arg;
    return *this;
  }
  Type & set__ball_launch_heading(
    const float & _arg)
  {
    this->ball_launch_heading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::KBall_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::KBall_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::KBall_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::KBall_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::KBall_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::KBall_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::KBall_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::KBall_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::KBall_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::KBall_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__KBall
    std::shared_ptr<amp_msgs::msg::KBall_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__KBall
    std::shared_ptr<amp_msgs::msg::KBall_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KBall_ & other) const
  {
    if (this->ball_velocity != other.ball_velocity) {
      return false;
    }
    if (this->ball_launch_angle != other.ball_launch_angle) {
      return false;
    }
    if (this->ball_launch_heading != other.ball_launch_heading) {
      return false;
    }
    return true;
  }
  bool operator!=(const KBall_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KBall_

// alias to use template instance with default allocator
using KBall =
  amp_msgs::msg::KBall_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__K_BALL__STRUCT_HPP_
