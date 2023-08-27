function ros2msg = serial_motor_demo_msgs_msg_MotorCommand_1To2_Converter(message,ros2msg)
%serial_motor_demo_msgs_msg_MotorCommand_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.is_pwm = message.IsPwm;
ros2msg.mot_1_req_rad_sec = message.Mot1ReqRadSec;
ros2msg.mot_2_req_rad_sec = message.Mot2ReqRadSec;
end