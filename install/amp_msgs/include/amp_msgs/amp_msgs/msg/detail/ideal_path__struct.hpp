// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_HPP_
#define AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'control_array'
#include "amp_msgs/msg/detail/agent_control__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__amp_msgs__msg__IdealPath __attribute__((deprecated))
#else
# define DEPRECATED__amp_msgs__msg__IdealPath __declspec(deprecated)
#endif

namespace amp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IdealPath_
{
  using Type = IdealPath_<ContainerAllocator>;

  explicit IdealPath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->run_time = 0.0f;
    }
  }

  explicit IdealPath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->run_time = 0.0f;
    }
  }

  // field types and members
  using _control_array_type =
    std::vector<amp_msgs::msg::AgentControl_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<amp_msgs::msg::AgentControl_<ContainerAllocator>>>;
  _control_array_type control_array;
  using _duration_array_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _duration_array_type duration_array;
  using _run_time_type =
    float;
  _run_time_type run_time;

  // setters for named parameter idiom
  Type & set__control_array(
    const std::vector<amp_msgs::msg::AgentControl_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<amp_msgs::msg::AgentControl_<ContainerAllocator>>> & _arg)
  {
    this->control_array = _arg;
    return *this;
  }
  Type & set__duration_array(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->duration_array = _arg;
    return *this;
  }
  Type & set__run_time(
    const float & _arg)
  {
    this->run_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    amp_msgs::msg::IdealPath_<ContainerAllocator> *;
  using ConstRawPtr =
    const amp_msgs::msg::IdealPath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::IdealPath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amp_msgs::msg::IdealPath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amp_msgs__msg__IdealPath
    std::shared_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amp_msgs__msg__IdealPath
    std::shared_ptr<amp_msgs::msg::IdealPath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IdealPath_ & other) const
  {
    if (this->control_array != other.control_array) {
      return false;
    }
    if (this->duration_array != other.duration_array) {
      return false;
    }
    if (this->run_time != other.run_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const IdealPath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IdealPath_

// alias to use template instance with default allocator
using IdealPath =
  amp_msgs::msg::IdealPath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__IDEAL_PATH__STRUCT_HPP_
