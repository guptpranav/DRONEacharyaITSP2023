function ros1msg = serial_motor_demo_msgs_msg_MotorVels_2To1_Converter(message,ros1msg)
%serial_motor_demo_msgs_msg_MotorVels_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Mot1RadSec = message.mot_1_rad_sec;
ros1msg.Mot2RadSec = message.mot_2_rad_sec;
end