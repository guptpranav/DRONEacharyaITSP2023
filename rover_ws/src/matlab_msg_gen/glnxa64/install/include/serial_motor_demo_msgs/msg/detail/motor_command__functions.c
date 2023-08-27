// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_demo_msgs:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/motor_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
serial_motor_demo_msgs__msg__MotorCommand__init(serial_motor_demo_msgs__msg__MotorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // is_pwm
  // mot_1_req_rad_sec
  // mot_2_req_rad_sec
  return true;
}

void
serial_motor_demo_msgs__msg__MotorCommand__fini(serial_motor_demo_msgs__msg__MotorCommand * msg)
{
  if (!msg) {
    return;
  }
  // is_pwm
  // mot_1_req_rad_sec
  // mot_2_req_rad_sec
}

serial_motor_demo_msgs__msg__MotorCommand *
serial_motor_demo_msgs__msg__MotorCommand__create()
{
  serial_motor_demo_msgs__msg__MotorCommand * msg = (serial_motor_demo_msgs__msg__MotorCommand *)malloc(sizeof(serial_motor_demo_msgs__msg__MotorCommand));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__msg__MotorCommand));
  bool success = serial_motor_demo_msgs__msg__MotorCommand__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__msg__MotorCommand__destroy(serial_motor_demo_msgs__msg__MotorCommand * msg)
{
  if (msg) {
    serial_motor_demo_msgs__msg__MotorCommand__fini(msg);
  }
  free(msg);
}


bool
serial_motor_demo_msgs__msg__MotorCommand__Sequence__init(serial_motor_demo_msgs__msg__MotorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  serial_motor_demo_msgs__msg__MotorCommand * data = NULL;
  if (size) {
    data = (serial_motor_demo_msgs__msg__MotorCommand *)calloc(size, sizeof(serial_motor_demo_msgs__msg__MotorCommand));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__msg__MotorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__msg__MotorCommand__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
serial_motor_demo_msgs__msg__MotorCommand__Sequence__fini(serial_motor_demo_msgs__msg__MotorCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      serial_motor_demo_msgs__msg__MotorCommand__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

serial_motor_demo_msgs__msg__MotorCommand__Sequence *
serial_motor_demo_msgs__msg__MotorCommand__Sequence__create(size_t size)
{
  serial_motor_demo_msgs__msg__MotorCommand__Sequence * array = (serial_motor_demo_msgs__msg__MotorCommand__Sequence *)malloc(sizeof(serial_motor_demo_msgs__msg__MotorCommand__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__msg__MotorCommand__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__msg__MotorCommand__Sequence__destroy(serial_motor_demo_msgs__msg__MotorCommand__Sequence * array)
{
  if (array) {
    serial_motor_demo_msgs__msg__MotorCommand__Sequence__fini(array);
  }
  free(array);
}
