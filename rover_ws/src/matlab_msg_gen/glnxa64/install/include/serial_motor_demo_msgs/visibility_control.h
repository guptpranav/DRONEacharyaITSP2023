#ifndef SERIAL_MOTOR_DEMO_MSGS__VISIBILITY_CONTROL_H_
#define SERIAL_MOTOR_DEMO_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SERIAL_MOTOR_DEMO_MSGS_EXPORT __attribute__ ((dllexport))
    #define SERIAL_MOTOR_DEMO_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define SERIAL_MOTOR_DEMO_MSGS_EXPORT __declspec(dllexport)
    #define SERIAL_MOTOR_DEMO_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef SERIAL_MOTOR_DEMO_MSGS_BUILDING_LIBRARY
    #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC SERIAL_MOTOR_DEMO_MSGS_EXPORT
  #else
    #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC SERIAL_MOTOR_DEMO_MSGS_IMPORT
  #endif
  #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC_TYPE SERIAL_MOTOR_DEMO_MSGS_PUBLIC
  #define SERIAL_MOTOR_DEMO_MSGS_LOCAL
#else
  #define SERIAL_MOTOR_DEMO_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define SERIAL_MOTOR_DEMO_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define SERIAL_MOTOR_DEMO_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC
    #define SERIAL_MOTOR_DEMO_MSGS_LOCAL
  #endif
  #define SERIAL_MOTOR_DEMO_MSGS_PUBLIC_TYPE
#endif
#endif  // SERIAL_MOTOR_DEMO_MSGS__VISIBILITY_CONTROL_H_
// Generated 11-Aug-2023 19:37:06
 