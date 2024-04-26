from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (IncludeLaunchDescription, TimerAction, LogInfo)
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from hos_run.hos_banner import HAIVE_OS


def generate_launch_description():
    rosbridge_server = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('rosbridge_server'),
                'launch/rosbridge_websocket_launch.xml'
            ])
        ),
        launch_arguments={
            'port': '9091',
        }.items()
    )

    fleet_name = "shinkawasaki"
    device_manager = Node(
        package='hos_device_layer',
        executable='device_manager',
        name='device_manager',
        output='screen',
        emulate_tty=True,
        arguments=['-f', fleet_name],
    )

    layout_path = PathJoinSubstitution([
      FindPackageShare('hos_device_simulation'),
      'layouts/test_layout.json'
    ])
    haive4_sim = Node(
        package='hos_device_simulation',
        executable='simulation_haive4',
        name='simulation_haive4',
        arguments=['-l', layout_path],
        output='screen',
        emulate_tty=True,
    )

    my_node = Node(
        package='hos_behavior_layer',
        executable='my_node',
        name='my_node',
        output='screen',
        emulate_tty=True,
    )

    return LaunchDescription([
        rosbridge_server,
        TimerAction(period=2.0, actions=[
            LogInfo(msg=HAIVE_OS),
            device_manager,
        ]),
        TimerAction(period=10.0, actions=[
            haive4_sim,
            my_node,
            LogInfo(msg="System ready!"),
        ]),
    ])
