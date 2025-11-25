// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/LaunchBall.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__LaunchBall __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__LaunchBall __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LaunchBall_
{
  using Type = LaunchBall_<ContainerAllocator>;

  explicit LaunchBall_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_velocity = 0.0f;
      this->ball_launch_angle = 0.0f;
      this->ball_launch_heading = 0.0f;
      this->ball_pos_x = 0.0f;
      this->ball_pos_y = 0.0f;
      this->ball_pos_z = 0.0f;
    }
  }

  explicit LaunchBall_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_velocity = 0.0f;
      this->ball_launch_angle = 0.0f;
      this->ball_launch_heading = 0.0f;
      this->ball_pos_x = 0.0f;
      this->ball_pos_y = 0.0f;
      this->ball_pos_z = 0.0f;
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
  using _ball_pos_x_type =
    float;
  _ball_pos_x_type ball_pos_x;
  using _ball_pos_y_type =
    float;
  _ball_pos_y_type ball_pos_y;
  using _ball_pos_z_type =
    float;
  _ball_pos_z_type ball_pos_z;

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
  Type & set__ball_pos_x(
    const float & _arg)
  {
    this->ball_pos_x = _arg;
    return *this;
  }
  Type & set__ball_pos_y(
    const float & _arg)
  {
    this->ball_pos_y = _arg;
    return *this;
  }
  Type & set__ball_pos_z(
    const float & _arg)
  {
    this->ball_pos_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::LaunchBall_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::LaunchBall_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::LaunchBall_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::LaunchBall_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__LaunchBall
    std::shared_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__LaunchBall
    std::shared_ptr<amp_msgs::msg::LaunchBall_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaunchBall_ & other) const
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
    if (this->ball_pos_x != other.ball_pos_x) {
      return false;
    }
    if (this->ball_pos_y != other.ball_pos_y) {
      return false;
    }
    if (this->ball_pos_z != other.ball_pos_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaunchBall_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaunchBall_

// alias to use template instance with default allocator
using LaunchBall =
  amp_msgs::msg::LaunchBall_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__LAUNCH_BALL__STRUCT_HPP_
