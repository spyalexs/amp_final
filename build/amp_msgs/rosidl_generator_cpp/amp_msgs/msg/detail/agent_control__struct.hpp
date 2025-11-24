// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/AgentControl.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__AgentControl __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__AgentControl __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgentControl_
{
  using Type = AgentControl_<ContainerAllocator>;

  explicit AgentControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u0 = 0.0f;
      this->u1 = 0.0f;
      this->u2 = 0.0f;
      this->u3 = 0.0f;
    }
  }

  explicit AgentControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u0 = 0.0f;
      this->u1 = 0.0f;
      this->u2 = 0.0f;
      this->u3 = 0.0f;
    }
  }

  // field types and members
  using _u0_type =
    float;
  _u0_type u0;
  using _u1_type =
    float;
  _u1_type u1;
  using _u2_type =
    float;
  _u2_type u2;
  using _u3_type =
    float;
  _u3_type u3;

  // setters for named parameter idiom
  Type & set__u0(
    const float & _arg)
  {
    this->u0 = _arg;
    return *this;
  }
  Type & set__u1(
    const float & _arg)
  {
    this->u1 = _arg;
    return *this;
  }
  Type & set__u2(
    const float & _arg)
  {
    this->u2 = _arg;
    return *this;
  }
  Type & set__u3(
    const float & _arg)
  {
    this->u3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::AgentControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::AgentControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::AgentControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::AgentControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__AgentControl
    std::shared_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__AgentControl
    std::shared_ptr<amp_msgs::msg::AgentControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgentControl_ & other) const
  {
    if (this->u0 != other.u0) {
      return false;
    }
    if (this->u1 != other.u1) {
      return false;
    }
    if (this->u2 != other.u2) {
      return false;
    }
    if (this->u3 != other.u3) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgentControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgentControl_

// alias to use template instance with default allocator
using AgentControl =
  amp_msgs::msg::AgentControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__AGENT_CONTROL__STRUCT_HPP_
