// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from amp_msgs:msg/IdealPath.idl
// generated code does not contain a copyright notice
#include "amp_msgs/msg/detail/ideal_path__rosidl_typesupport_fastrtps_cpp.hpp"
#include "amp_msgs/msg/detail/ideal_path__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace amp_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const amp_msgs::msg::AgentControl &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  amp_msgs::msg::AgentControl &);
size_t get_serialized_size(
  const amp_msgs::msg::AgentControl &,
  size_t current_alignment);
size_t
max_serialized_size_AgentControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace amp_msgs


namespace amp_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
cdr_serialize(
  const amp_msgs::msg::IdealPath & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: control_array
  {
    size_t size = ros_message.control_array.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      amp_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.control_array[i],
        cdr);
    }
  }
  // Member: duration_array
  {
    cdr << ros_message.duration_array;
  }
  // Member: run_time
  cdr << ros_message.run_time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  amp_msgs::msg::IdealPath & ros_message)
{
  // Member: control_array
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.control_array.resize(size);
    for (size_t i = 0; i < size; i++) {
      amp_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.control_array[i]);
    }
  }

  // Member: duration_array
  {
    cdr >> ros_message.duration_array;
  }

  // Member: run_time
  cdr >> ros_message.run_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
get_serialized_size(
  const amp_msgs::msg::IdealPath & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: control_array
  {
    size_t array_size = ros_message.control_array.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        amp_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.control_array[index], current_alignment);
    }
  }
  // Member: duration_array
  {
    size_t array_size = ros_message.duration_array.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.duration_array[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: run_time
  {
    size_t item_size = sizeof(ros_message.run_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_amp_msgs
max_serialized_size_IdealPath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: control_array
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        amp_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_AgentControl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: duration_array
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: run_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = amp_msgs::msg::IdealPath;
    is_plain =
      (
      offsetof(DataType, run_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _IdealPath__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const amp_msgs::msg::IdealPath *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IdealPath__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<amp_msgs::msg::IdealPath *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IdealPath__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const amp_msgs::msg::IdealPath *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IdealPath__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_IdealPath(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _IdealPath__callbacks = {
  "amp_msgs::msg",
  "IdealPath",
  _IdealPath__cdr_serialize,
  _IdealPath__cdr_deserialize,
  _IdealPath__get_serialized_size,
  _IdealPath__max_serialized_size
};

static rosidl_message_type_support_t _IdealPath__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IdealPath__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace amp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_amp_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<amp_msgs::msg::IdealPath>()
{
  return &amp_msgs::msg::typesupport_fastrtps_cpp::_IdealPath__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, amp_msgs, msg, IdealPath)() {
  return &amp_msgs::msg::typesupport_fastrtps_cpp::_IdealPath__handle;
}

#ifdef __cplusplus
}
#endif
