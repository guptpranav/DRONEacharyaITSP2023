function ros2msg = serial_motor_demo_msgs_msg_MotorVels_1To2_Converter(message,ros2msg)
%serial_motor_demo_msgs_msg_MotorVels_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.mot_1_rad_sec = message.Mot1RadSec;
ros2msg.mot_2_rad_sec = message.Mot2RadSec;
end