function ros1msg = serial_motor_demo_msgs_msg_MotorCommand_2To1_Converter(message,ros1msg)
%serial_motor_demo_msgs_msg_MotorCommand_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.IsPwm = message.is_pwm;
ros1msg.Mot1ReqRadSec = message.mot_1_req_rad_sec;
ros1msg.Mot2ReqRadSec = message.mot_2_req_rad_sec;
end