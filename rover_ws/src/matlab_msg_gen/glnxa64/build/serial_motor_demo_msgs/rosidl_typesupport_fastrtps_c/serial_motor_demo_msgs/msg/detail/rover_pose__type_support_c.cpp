// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from serial_motor_demo_msgs:msg/RoverPose.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/rover_pose__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "serial_motor_demo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "serial_motor_demo_msgs/msg/detail/rover_pose__struct.h"
#include "serial_motor_demo_msgs/msg/detail/rover_pose__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RoverPose__ros_msg_type = serial_motor_demo_msgs__msg__RoverPose;

static bool _RoverPose__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RoverPose__ros_msg_type * ros_message = static_cast<const _RoverPose__ros_msg_type *>(untyped_ros_message);
  // Field name: rover_x
  {
    cdr << ros_message->rover_x;
  }

  // Field name: rover_y
  {
    cdr << ros_message->rover_y;
  }

  return true;
}

static bool _RoverPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RoverPose__ros_msg_type * ros_message = static_cast<_RoverPose__ros_msg_type *>(untyped_ros_message);
  // Field name: rover_x
  {
    cdr >> ros_message->rover_x;
  }

  // Field name: rover_y
  {
    cdr >> ros_message->rover_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_serial_motor_demo_msgs
size_t get_serialized_size_serial_motor_demo_msgs__msg__RoverPose(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RoverPose__ros_msg_type * ros_message = static_cast<const _RoverPose__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name rover_x
  {
    size_t item_size = sizeof(ros_message->rover_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rover_y
  {
    size_t item_size = sizeof(ros_message->rover_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RoverPose__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_serial_motor_demo_msgs__msg__RoverPose(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_serial_motor_demo_msgs
size_t max_serialized_size_serial_motor_demo_msgs__msg__RoverPose(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: rover_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rover_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RoverPose__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_serial_motor_demo_msgs__msg__RoverPose(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RoverPose = {
  "serial_motor_demo_msgs::msg",
  "RoverPose",
  _RoverPose__cdr_serialize,
  _RoverPose__cdr_deserialize,
  _RoverPose__get_serialized_size,
  _RoverPose__max_serialized_size
};

static rosidl_message_type_support_t _RoverPose__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RoverPose,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, serial_motor_demo_msgs, msg, RoverPose)() {
  return &_RoverPose__type_support;
}

#if defined(__cplusplus)
}
#endif
