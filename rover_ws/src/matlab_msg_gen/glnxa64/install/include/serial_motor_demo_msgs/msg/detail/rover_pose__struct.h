// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_demo_msgs:msg/RoverPose.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_H_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RoverPose in the package serial_motor_demo_msgs.
typedef struct serial_motor_demo_msgs__msg__RoverPose
{
  double rover_x;
  double rover_y;
} serial_motor_demo_msgs__msg__RoverPose;

// Struct for a sequence of serial_motor_demo_msgs__msg__RoverPose.
typedef struct serial_motor_demo_msgs__msg__RoverPose__Sequence
{
  serial_motor_demo_msgs__msg__RoverPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_demo_msgs__msg__RoverPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__STRUCT_H_
