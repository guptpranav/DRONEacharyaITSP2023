function [data, info] = roverPose
%RoverPose gives an empty data for serial_motor_demo_msgs/RoverPose
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'serial_motor_demo_msgs/RoverPose';
[data.rover_x, info.rover_x] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
[data.rover_y, info.rover_y] = ros.internal.ros2.messages.ros2.default_type('double',1,0);
info.MessageType = 'serial_motor_demo_msgs/RoverPose';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'rover_x';
info.MatPath{2} = 'rover_y';
