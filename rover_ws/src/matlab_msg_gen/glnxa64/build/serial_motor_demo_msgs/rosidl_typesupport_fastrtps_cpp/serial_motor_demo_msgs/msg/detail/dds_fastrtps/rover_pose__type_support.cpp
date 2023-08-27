// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from serial_motor_demo_msgs:msg/RoverPose.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/rover_pose__rosidl_typesupport_fastrtps_cpp.hpp"
#include "serial_motor_demo_msgs/msg/detail/rover_pose__struct.hpp"

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

namespace serial_motor_demo_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_serial_motor_demo_msgs
cdr_serialize(
  const serial_motor_demo_msgs::msg::RoverPose & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: rover_x
  cdr << ros_message.rover_x;
  // Member: rover_y
  cdr << ros_message.rover_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_serial_motor_demo_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  serial_motor_demo_msgs::msg::RoverPose & ros_message)
{
  // Member: rover_x
  cdr >> ros_message.rover_x;

  // Member: rover_y
  cdr >> ros_message.rover_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_serial_motor_demo_msgs
get_serialized_size(
  const serial_motor_demo_msgs::msg::RoverPose & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: rover_x
  {
    size_t item_size = sizeof(ros_message.rover_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rover_y
  {
    size_t item_size = sizeof(ros_message.rover_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_serial_motor_demo_msgs
max_serialized_size_RoverPose(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: rover_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rover_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RoverPose__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const serial_motor_demo_msgs::msg::RoverPose *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RoverPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<serial_motor_demo_msgs::msg::RoverPose *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RoverPose__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const serial_motor_demo_msgs::msg::RoverPose *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RoverPose__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RoverPose(full_bounded, 0);
}

static message_type_support_callbacks_t _RoverPose__callbacks = {
  "serial_motor_demo_msgs::msg",
  "RoverPose",
  _RoverPose__cdr_serialize,
  _RoverPose__cdr_deserialize,
  _RoverPose__get_serialized_size,
  _RoverPose__max_serialized_size
};

static rosidl_message_type_support_t _RoverPose__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RoverPose__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace serial_motor_demo_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_serial_motor_demo_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<serial_motor_demo_msgs::msg::RoverPose>()
{
  return &serial_motor_demo_msgs::msg::typesupport_fastrtps_cpp::_RoverPose__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, serial_motor_demo_msgs, msg, RoverPose)() {
  return &serial_motor_demo_msgs::msg::typesupport_fastrtps_cpp::_RoverPose__handle;
}

#ifdef __cplusplus
}
#endif
