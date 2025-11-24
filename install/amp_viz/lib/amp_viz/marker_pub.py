#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.duration import Duration

from std_msgs.msg import String
from visualization_msgs.msg import MarkerArray, Marker

from std_msgs.msg import Int32MultiArray

BALL_SCALE  = 0.05
AGENT_SCALE = 0.6

class MarkerPub(Node):

    ball_frames = []
    agent_name = "omni_agent"

    def __init__(self):
        super().__init__('marker_pub')

        self.marker_arrary_pub = self.create_publisher(MarkerArray, "/dynamic_objects", 10)

        self.dynamic_object_timer = self.create_timer(0.03, self.dynamic_object_cb)

        self.create_subscription(Int32MultiArray, "/valid_ball_frames", self.ball_frames_cb, 10)

    def ball_frames_cb(self, msg: Int32MultiArray):
        
        #update the ball frames
        self.ball_frames = []

        for frame in msg.data:
            self.ball_frames.append(f"ball_{frame}")


    def dynamic_object_cb(self):

        frames = self.ball_frames

        marker_msg = MarkerArray()

        for frame in frames:
            msg = Marker()

            msg.header.frame_id = frame
            msg.header.stamp = self.get_clock().now().to_msg()

            msg.type = 2
            msg.action = 0
            msg.pose.position.x = 0.0
            msg.pose.position.y = 0.0
            msg.pose.position.z = 0.0
            msg.pose.orientation.x = 0.0
            msg.pose.orientation.y = 0.0
            msg.pose.orientation.z = 0.0
            msg.pose.orientation.w = 1.0

            msg.scale.x = BALL_SCALE
            msg.scale.y = BALL_SCALE
            msg.scale.z = BALL_SCALE

            msg.color.r = 0.0
            msg.color.g = 1.0
            msg.color.b = 0.0
            msg.color.a = 1.0

            msg.id = int(frame.split("_")[1])

            msg.lifetime = Duration().to_msg()

            marker_msg.markers.append(msg)

        #update the agent
        msg = Marker()

        msg.header.frame_id = self.agent_name
        msg.header.stamp = self.get_clock().now().to_msg()

        msg.type = 1
        msg.action = 0
        msg.pose.position.x = 0.0
        msg.pose.position.y = 0.0
        msg.pose.position.z = AGENT_SCALE / 4
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        msg.pose.orientation.w = 1.0

        msg.scale.x = AGENT_SCALE
        msg.scale.y = AGENT_SCALE
        msg.scale.z = AGENT_SCALE / 2

        msg.color.r = 0.2
        msg.color.g = 0.2
        msg.color.b = 0.4
        msg.color.a = 1.0

        msg.id = 0

        msg.lifetime = Duration().to_msg()

        marker_msg.markers.append(msg)

        self.marker_arrary_pub.publish(marker_msg)


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MarkerPub()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()