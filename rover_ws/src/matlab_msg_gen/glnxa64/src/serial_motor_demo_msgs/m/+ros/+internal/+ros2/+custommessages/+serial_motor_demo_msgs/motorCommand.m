function [data, info] = motorCommand
%MotorCommand gives an empty data for serial_motor_demo_msgs/MotorCommand
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'serial_motor_demo_msgs/MotorCommand';
[data.is_pwm, info.is_pwm] = ros.internal.ros2.messages.ros2.default_type('logical',1,0);
[data.mot_1_req_rad_sec, info.mot_1_req_rad_sec] = ros.internal.ros2.messages.ros2.default_type('single',1,0);
[data.mot_2_req_rad_sec, info.mot_2_req_rad_sec] = ros.internal.ros2.messages.ros2.default_type('single',1,0);
info.MessageType = 'serial_motor_demo_msgs/MotorCommand';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,3);
info.MatPath{1} = 'is_pwm';
info.MatPath{2} = 'mot_1_req_rad_sec';
info.MatPath{3} = 'mot_2_req_rad_sec';
