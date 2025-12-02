// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__BallTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__BallTrajectory __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BallTrajectory_
{
  using Type = BallTrajectory_<ContainerAllocator>;

  explicit BallTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_pos_x = 0.0f;
      this->current_pos_y = 0.0f;
      this->current_pos_z = 0.0f;
      this->current_vel_x = 0.0f;
      this->current_vel_y = 0.0f;
      this->current_vel_z = 0.0f;
      this->current_damping_x = 0.0f;
      this->current_damping_y = 0.0f;
      this->current_damping_z = 0.0f;
      this->current_mass = 0.0f;
      this->landing_height = 0.0f;
    }
  }

  explicit BallTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_pos_x = 0.0f;
      this->current_pos_y = 0.0f;
      this->current_pos_z = 0.0f;
      this->current_vel_x = 0.0f;
      this->current_vel_y = 0.0f;
      this->current_vel_z = 0.0f;
      this->current_damping_x = 0.0f;
      this->current_damping_y = 0.0f;
      this->current_damping_z = 0.0f;
      this->current_mass = 0.0f;
      this->landing_height = 0.0f;
    }
  }

  // field types and members
  using _current_pos_x_type =
    float;
  _current_pos_x_type current_pos_x;
  using _current_pos_y_type =
    float;
  _current_pos_y_type current_pos_y;
  using _current_pos_z_type =
    float;
  _current_pos_z_type current_pos_z;
  using _current_vel_x_type =
    float;
  _current_vel_x_type current_vel_x;
  using _current_vel_y_type =
    float;
  _current_vel_y_type current_vel_y;
  using _current_vel_z_type =
    float;
  _current_vel_z_type current_vel_z;
  using _current_damping_x_type =
    float;
  _current_damping_x_type current_damping_x;
  using _current_damping_y_type =
    float;
  _current_damping_y_type current_damping_y;
  using _current_damping_z_type =
    float;
  _current_damping_z_type current_damping_z;
  using _current_mass_type =
    float;
  _current_mass_type current_mass;
  using _landing_height_type =
    float;
  _landing_height_type landing_height;

  // setters for named parameter idiom
  Type & set__current_pos_x(
    const float & _arg)
  {
    this->current_pos_x = _arg;
    return *this;
  }
  Type & set__current_pos_y(
    const float & _arg)
  {
    this->current_pos_y = _arg;
    return *this;
  }
  Type & set__current_pos_z(
    const float & _arg)
  {
    this->current_pos_z = _arg;
    return *this;
  }
  Type & set__current_vel_x(
    const float & _arg)
  {
    this->current_vel_x = _arg;
    return *this;
  }
  Type & set__current_vel_y(
    const float & _arg)
  {
    this->current_vel_y = _arg;
    return *this;
  }
  Type & set__current_vel_z(
    const float & _arg)
  {
    this->current_vel_z = _arg;
    return *this;
  }
  Type & set__current_damping_x(
    const float & _arg)
  {
    this->current_damping_x = _arg;
    return *this;
  }
  Type & set__current_damping_y(
    const float & _arg)
  {
    this->current_damping_y = _arg;
    return *this;
  }
  Type & set__current_damping_z(
    const float & _arg)
  {
    this->current_damping_z = _arg;
    return *this;
  }
  Type & set__current_mass(
    const float & _arg)
  {
    this->current_mass = _arg;
    return *this;
  }
  Type & set__landing_height(
    const float & _arg)
  {
    this->landing_height = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::BallTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::BallTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::BallTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::BallTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__BallTrajectory
    std::shared_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__BallTrajectory
    std::shared_ptr<amp_msgs::msg::BallTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BallTrajectory_ & other) const
  {
    if (this->current_pos_x != other.current_pos_x) {
      return false;
    }
    if (this->current_pos_y != other.current_pos_y) {
      return false;
    }
    if (this->current_pos_z != other.current_pos_z) {
      return false;
    }
    if (this->current_vel_x != other.current_vel_x) {
      return false;
    }
    if (this->current_vel_y != other.current_vel_y) {
      return false;
    }
    if (this->current_vel_z != other.current_vel_z) {
      return false;
    }
    if (this->current_damping_x != other.current_damping_x) {
      return false;
    }
    if (this->current_damping_y != other.current_damping_y) {
      return false;
    }
    if (this->current_damping_z != other.current_damping_z) {
      return false;
    }
    if (this->current_mass != other.current_mass) {
      return false;
    }
    if (this->landing_height != other.landing_height) {
      return false;
    }
    return true;
  }
  bool operator!=(const BallTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BallTrajectory_

// alias to use template instance with default allocator
using BallTrajectory =
  amp_msgs::msg::BallTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__STRUCT_HPP_
