import rclpy
from rclpy.node import Node

from serial_motor_demo_msgs.msg import MotorCommand


class RPMsub(Node):

    def __init__(self):
        super().__init__('rpm_sub')
        self.subscription = self.create_subscription(
            MotorCommand,
            'motor_command',
            self.listener_callback,
            10)
        self.subscription

    def listener_callback(self, msg):
        self.get_logger().info('RPM1 = {RPM1:.3f} and RPM2 = {RPM2:.3f}'.format(RPM1=msg.mot_1_req_rad_sec, RPM2=msg.mot_2_req_rad_sec))


def main(args=None):
    rclpy.init(args=args)

    rpmsub = RPMsub()

    rclpy.spin(rpmsub)

    rpmsub.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()