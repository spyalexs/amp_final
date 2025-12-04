#!/usr/bin/env python3

from os.path import join
import copy
from math import floor

import rclpy
import tf2_ros
from rclpy.node import Node
from rclpy.duration import Duration

from visualization_msgs.msg import MarkerArray, Marker
from std_msgs.msg import Int32MultiArray
from geometry_msgs.msg import TransformStamped
from builtin_interfaces.msg import Time

from ament_index_python import get_package_share_directory 


BALL_SCALE  = 0.1
CANNON_SCALE  = 0.02
AGENT_SCALE = 0.6
CANNON_FRAME_NAME = "cannon_barrel"

class MarkerPub(Node):

    ball_frames = []
    agent_name = "omni_agent"

    def __init__(self):
        super().__init__('marker_pub')

        self.marker_arrary_pub = self.create_publisher(MarkerArray, "/dynamic_objects", 10)
        self.cannon_barrel_pub = self.create_publisher(Marker, "/cannon_barrel", 10)
        self.obstalce_pub = self.create_publisher(MarkerArray, "/obstalces", 10)

        self.dynamic_object_timer = self.create_timer(0.1, self.dynamic_object_cb)
        self.cannon_barrel_timer = self.create_timer(0.1, self.cannon_barrel_cb)
        self.obstacle_timer = self.create_timer(2.0, self.obstalces_cb)

        self.create_subscription(Int32MultiArray, "/valid_ball_frames", self.ball_frames_cb, 10)

        self.cannon_barrel_mesh_path =  "file://" + join(get_package_share_directory("amp_viz"), "meshes/cannon_barrel/mesh.dae")

        #statically broadcast obstalce frames
        self.tf_static_broadcasters = []

        #broadcast the two obstalces
        self.publish_obstalce_frame("obs_1", [2.4, 0.0, 0.0])
        self.publish_obstalce_frame("obs_2", [-0.1, 2.3, 0.0])

    #little help from gemni here
    def publish_obstalce_frame(self, obstacle_frame_name, pos, base_frame = "world"):
        self.tf_static_broadcasters.append(tf2_ros.StaticTransformBroadcaster(self))

        # Create a TransformStamped message
        static_transform_stamped = TransformStamped()
        static_transform_stamped.header.stamp = self.get_clock().now().to_msg()
        static_transform_stamped.header.frame_id = base_frame  # Parent frame
        static_transform_stamped.child_frame_id = obstacle_frame_name  # Child frame

        # Set the translation (x, y, z)
        static_transform_stamped.transform.translation.x = pos[0]
        static_transform_stamped.transform.translation.y = pos[1]
        static_transform_stamped.transform.translation.z = pos[2]

        # Set the rotation (quaternion: x, y, z, w) - here, identity quaternion (no rotation)
        static_transform_stamped.transform.rotation.x = 0.0
        static_transform_stamped.transform.rotation.y = 0.0
        static_transform_stamped.transform.rotation.z = 0.0
        static_transform_stamped.transform.rotation.w = 1.0

        # Publish the static transform
        self.tf_static_broadcasters[-1].sendTransform(static_transform_stamped)


    def obstalces_cb(self):

        #obstalce markers
        marker_msg = MarkerArray()

        #obstalce 1
        msg = Marker()

        msg.header.frame_id = "obs_1"
        msg.header.stamp = self.get_marker_pub_time()

        msg.type = 1
        msg.action = 0
        msg.pose.position.x = 0.0
        msg.pose.position.y = 0.0
        msg.pose.position.z = 0.55
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        msg.pose.orientation.w = 1.0

        msg.scale.x = 0.6
        msg.scale.y = 0.6
        msg.scale.z = 1.1

        msg.color.r = 0.8
        msg.color.g = 0.0
        msg.color.b = 0.0
        msg.color.a = 1.0

        msg.id = 10

        msg.lifetime = Duration().to_msg()

        marker_msg.markers.append(copy.deepcopy(msg))

        #obstalce 2
        msg.header.frame_id = "obs_2"
        msg.header.stamp = self.get_marker_pub_time()

        msg.type = 1
        msg.action = 0
        msg.pose.position.x = 0.0
        msg.pose.position.y = 0.0
        msg.pose.position.z = 0.55
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        msg.pose.orientation.w = 1.0

        msg.scale.x = 1.6
        msg.scale.y = 1.6
        msg.scale.z = 1.1

        msg.color.r = 0.8
        msg.color.g = 0.0
        msg.color.b = 0.0
        msg.color.a = 1.0

        msg.id = 11

        msg.lifetime = Duration().to_msg()

        marker_msg.markers.append(copy.deepcopy(msg))

        #publish obstalces
        self.obstalce_pub.publish(marker_msg)

    def ball_frames_cb(self, msg: Int32MultiArray):
        
        #update the ball frames
        self.ball_frames = []

        for frame in msg.data:
            self.ball_frames.append(f"ball_{frame}")


    def cannon_barrel_cb(self):

        # update the marker for the cannon barrel
        msg = Marker()

        msg.header.frame_id = CANNON_FRAME_NAME
        msg.header.stamp = self.get_marker_pub_time()

        msg.type = 10
        msg.action = 0
        msg.pose.position.x = 0.0
        msg.pose.position.y = 0.0
        msg.pose.position.z = 0.0
        msg.pose.orientation.x = -0.0
        msg.pose.orientation.y = 0.7071
        msg.pose.orientation.z = 0.7071
        msg.pose.orientation.w = 0.0

        msg.scale.x = CANNON_SCALE
        msg.scale.y = CANNON_SCALE
        msg.scale.z = CANNON_SCALE

        msg.color.r = 0.3
        msg.color.g = 0.3
        msg.color.b = 0.3
        msg.color.a = 1.0

        msg.mesh_resource = self.cannon_barrel_mesh_path

        msg.id = 6

        msg.lifetime = Duration().to_msg()

        self.cannon_barrel_pub.publish(msg)

    def dynamic_object_cb(self):

        frames = self.ball_frames

        marker_msg = MarkerArray()

        for frame in frames:
            msg = Marker()

            msg.header.frame_id = frame
            msg.header.stamp = self.get_marker_pub_time()

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
        msg.header.stamp = self.get_marker_pub_time()

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

    def get_marker_pub_time(self):

        #not a clean way of preventing future extrapolation but a time effective one
        time_tuple = self.get_clock().now().seconds_nanoseconds()
        time_double = time_tuple[0] + time_tuple[1] * 1e-9
        time_double = time_double - 0.1

        time_msg = Time()
        time_msg.sec = floor(time_double)
        time_msg.nanosec = int((time_double - floor(time_double)) * 1e9)

        return time_msg
        
        


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