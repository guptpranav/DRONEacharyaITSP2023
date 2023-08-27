// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_demo_msgs:msg/EncoderVals.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/encoder_vals__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
serial_motor_demo_msgs__msg__EncoderVals__init(serial_motor_demo_msgs__msg__EncoderVals * msg)
{
  if (!msg) {
    return false;
  }
  // mot_1_enc_val
  // mot_2_enc_val
  return true;
}

void
serial_motor_demo_msgs__msg__EncoderVals__fini(serial_motor_demo_msgs__msg__EncoderVals * msg)
{
  if (!msg) {
    return;
  }
  // mot_1_enc_val
  // mot_2_enc_val
}

serial_motor_demo_msgs__msg__EncoderVals *
serial_motor_demo_msgs__msg__EncoderVals__create()
{
  serial_motor_demo_msgs__msg__EncoderVals * msg = (serial_motor_demo_msgs__msg__EncoderVals *)malloc(sizeof(serial_motor_demo_msgs__msg__EncoderVals));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__msg__EncoderVals));
  bool success = serial_motor_demo_msgs__msg__EncoderVals__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__msg__EncoderVals__destroy(serial_motor_demo_msgs__msg__EncoderVals * msg)
{
  if (msg) {
    serial_motor_demo_msgs__msg__EncoderVals__fini(msg);
  }
  free(msg);
}


bool
serial_motor_demo_msgs__msg__EncoderVals__Sequence__init(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  serial_motor_demo_msgs__msg__EncoderVals * data = NULL;
  if (size) {
    data = (serial_motor_demo_msgs__msg__EncoderVals *)calloc(size, sizeof(serial_motor_demo_msgs__msg__EncoderVals));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__msg__EncoderVals__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__msg__EncoderVals__fini(&data[i - 1]);
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
serial_motor_demo_msgs__msg__EncoderVals__Sequence__fini(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      serial_motor_demo_msgs__msg__EncoderVals__fini(&array->data[i]);
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

serial_motor_demo_msgs__msg__EncoderVals__Sequence *
serial_motor_demo_msgs__msg__EncoderVals__Sequence__create(size_t size)
{
  serial_motor_demo_msgs__msg__EncoderVals__Sequence * array = (serial_motor_demo_msgs__msg__EncoderVals__Sequence *)malloc(sizeof(serial_motor_demo_msgs__msg__EncoderVals__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__msg__EncoderVals__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__msg__EncoderVals__Sequence__destroy(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array)
{
  if (array) {
    serial_motor_demo_msgs__msg__EncoderVals__Sequence__fini(array);
  }
  free(array);
}
