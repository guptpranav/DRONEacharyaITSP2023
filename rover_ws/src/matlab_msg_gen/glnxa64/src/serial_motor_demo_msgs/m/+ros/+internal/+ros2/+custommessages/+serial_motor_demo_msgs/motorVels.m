function [data, info] = motorVels
%MotorVels gives an empty data for serial_motor_demo_msgs/MotorVels
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'serial_motor_demo_msgs/MotorVels';
[data.mot_1_rad_sec, info.mot_1_rad_sec] = ros.internal.ros2.messages.ros2.default_type('single',1,0);
[data.mot_2_rad_sec, info.mot_2_rad_sec] = ros.internal.ros2.messages.ros2.default_type('single',1,0);
info.MessageType = 'serial_motor_demo_msgs/MotorVels';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'mot_1_rad_sec';
info.MatPath{2} = 'mot_2_rad_sec';
