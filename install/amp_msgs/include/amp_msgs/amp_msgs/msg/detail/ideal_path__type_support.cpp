// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "amp_msgs/msg/detail/ideal_path__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace amp_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IdealPath_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) amp_msgs::msg::IdealPath(_init);
}

void IdealPath_fini_function(void * message_memory)
{
  auto typed_message = static_cast<amp_msgs::msg::IdealPath *>(message_memory);
  typed_message->~IdealPath();
}

size_t size_function__IdealPath__control_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<amp_msgs::msg::AgentControl> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IdealPath__control_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<amp_msgs::msg::AgentControl> *>(untyped_member);
  return &member[index];
}

void * get_function__IdealPath__control_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<amp_msgs::msg::AgentControl> *>(untyped_member);
  return &member[index];
}

void fetch_function__IdealPath__control_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const amp_msgs::msg::AgentControl *>(
    get_const_function__IdealPath__control_array(untyped_member, index));
  auto & value = *reinterpret_cast<amp_msgs::msg::AgentControl *>(untyped_value);
  value = item;
}

void assign_function__IdealPath__control_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<amp_msgs::msg::AgentControl *>(
    get_function__IdealPath__control_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const amp_msgs::msg::AgentControl *>(untyped_value);
  item = value;
}

void resize_function__IdealPath__control_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<amp_msgs::msg::AgentControl> *>(untyped_member);
  member->resize(size);
}

size_t size_function__IdealPath__duration_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IdealPath__duration_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__IdealPath__duration_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__IdealPath__duration_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__IdealPath__duration_array(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__IdealPath__duration_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__IdealPath__duration_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__IdealPath__duration_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IdealPath_message_member_array[4] = {
  {
    "control_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<amp_msgs::msg::AgentControl>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs::msg::IdealPath, control_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__IdealPath__control_array,  // size() function pointer
    get_const_function__IdealPath__control_array,  // get_const(index) function pointer
    get_function__IdealPath__control_array,  // get(index) function pointer
    fetch_function__IdealPath__control_array,  // fetch(index, &value) function pointer
    assign_function__IdealPath__control_array,  // assign(index, value) function pointer
    resize_function__IdealPath__control_array  // resize(index) function pointer
  },
  {
    "duration_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs::msg::IdealPath, duration_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__IdealPath__duration_array,  // size() function pointer
    get_const_function__IdealPath__duration_array,  // get_const(index) function pointer
    get_function__IdealPath__duration_array,  // get(index) function pointer
    fetch_function__IdealPath__duration_array,  // fetch(index, &value) function pointer
    assign_function__IdealPath__duration_array,  // assign(index, value) function pointer
    resize_function__IdealPath__duration_array  // resize(index) function pointer
  },
  {
    "run_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs::msg::IdealPath, run_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "start_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amp_msgs::msg::IdealPath, start_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IdealPath_message_members = {
  "amp_msgs::msg",  // message namespace
  "IdealPath",  // message name
  4,  // number of fields
  sizeof(amp_msgs::msg::IdealPath),
  IdealPath_message_member_array,  // message members
  IdealPath_init_function,  // function to initialize message memory (memory has to be allocated)
  IdealPath_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IdealPath_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IdealPath_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace amp_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<amp_msgs::msg::IdealPath>()
{
  return &::amp_msgs::msg::rosidl_typesupport_introspection_cpp::IdealPath_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, amp_msgs, msg, IdealPath)() {
  return &::amp_msgs::msg::rosidl_typesupport_introspection_cpp::IdealPath_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
