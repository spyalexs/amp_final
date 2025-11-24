from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        #launch the marker publisher
        Node(
            package='amp_viz',
            namespace='amp',
            executable='marker_pub.py',
            name='amp_viz'
        ),

        #launch rviz
        Node(
            package='rviz2',
            namespace='amp',
            executable='rviz2',
            name='rviz'
        ),
    ])