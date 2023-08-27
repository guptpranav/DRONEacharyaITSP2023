// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from serial_motor_demo_msgs:msg/EncoderVals.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ENCODER_VALS__FUNCTIONS_H_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ENCODER_VALS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "serial_motor_demo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "serial_motor_demo_msgs/msg/detail/encoder_vals__struct.h"

/// Initialize msg/EncoderVals message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * serial_motor_demo_msgs__msg__EncoderVals
 * )) before or use
 * serial_motor_demo_msgs__msg__EncoderVals__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
bool
serial_motor_demo_msgs__msg__EncoderVals__init(serial_motor_demo_msgs__msg__EncoderVals * msg);

/// Finalize msg/EncoderVals message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
void
serial_motor_demo_msgs__msg__EncoderVals__fini(serial_motor_demo_msgs__msg__EncoderVals * msg);

/// Create msg/EncoderVals message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * serial_motor_demo_msgs__msg__EncoderVals__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
serial_motor_demo_msgs__msg__EncoderVals *
serial_motor_demo_msgs__msg__EncoderVals__create();

/// Destroy msg/EncoderVals message.
/**
 * It calls
 * serial_motor_demo_msgs__msg__EncoderVals__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
void
serial_motor_demo_msgs__msg__EncoderVals__destroy(serial_motor_demo_msgs__msg__EncoderVals * msg);


/// Initialize array of msg/EncoderVals messages.
/**
 * It allocates the memory for the number of elements and calls
 * serial_motor_demo_msgs__msg__EncoderVals__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
bool
serial_motor_demo_msgs__msg__EncoderVals__Sequence__init(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array, size_t size);

/// Finalize array of msg/EncoderVals messages.
/**
 * It calls
 * serial_motor_demo_msgs__msg__EncoderVals__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
void
serial_motor_demo_msgs__msg__EncoderVals__Sequence__fini(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array);

/// Create array of msg/EncoderVals messages.
/**
 * It allocates the memory for the array and calls
 * serial_motor_demo_msgs__msg__EncoderVals__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
serial_motor_demo_msgs__msg__EncoderVals__Sequence *
serial_motor_demo_msgs__msg__EncoderVals__Sequence__create(size_t size);

/// Destroy array of msg/EncoderVals messages.
/**
 * It calls
 * serial_motor_demo_msgs__msg__EncoderVals__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_serial_motor_demo_msgs
void
serial_motor_demo_msgs__msg__EncoderVals__Sequence__destroy(serial_motor_demo_msgs__msg__EncoderVals__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ENCODER_VALS__FUNCTIONS_H_
