from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (IncludeLaunchDescription, TimerAction, LogInfo, DeclareLaunchArgument)
from launch.conditions import IfCondition
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import (LaunchConfiguration, PathJoinSubstitution, PythonExpression)

from hos_run.hos_banner import HAIVE_OS


def generate_launch_description():
    wait_for_rosbridge_server_s = LaunchConfiguration('wait_rosbridge_s')
    wait_for_device_layer_s = LaunchConfiguration('wait_for_device_layer_s')
    wait_for_state_layer_s = LaunchConfiguration('wait_for_state_layer_s')
    log_level = LaunchConfiguration('log_level')
    device_manager_fleet = LaunchConfiguration('fleetname')
    device_manager_local_db = LaunchConfiguration('device_db')
    
    # Delay times for launching nodes in order
    wait_for_rosbridge_server_s_arg = DeclareLaunchArgument(
        'wait_rosbridge_s',
        default_value=['16.0'],
        description="Time to wait for rosbridge server node to start.",
    )
    wait_for_device_layer_s_arg = DeclareLaunchArgument(
        'wait_for_device_layer_s',
        default_value=['1.0'],
        description="Time to wait for device manager node to start.",
    )

    wait_for_state_layer_s_arg = DeclareLaunchArgument(
        'wait_for_state_layer_s',
        default_value=['16.0'],
        description="Time to wait for device manager node to start.",
    )
    # Node arguments
    log_level_arg = DeclareLaunchArgument(
        'log_level',
        default_value=['debug'],
        description="Logging level",
    )
    device_manager_fleet_arg = DeclareLaunchArgument(
        'fleetname',
        default_value=['shinkawasaki'],
        description="Identifies the data to be loaded for a specfic fleet.",
    )
    local_device_db_arg = DeclareLaunchArgument(
        'device_db',
        default_value=['--no-local-db'],
        choices=['--local-db', '--no-local-db'],
        description="Flag to use local copy of db data. (Increases bootup time)",
    )

    # start_rosbridge_server = TimerAction(period=wait_for_rosbridge_server_s, actions=[IncludeLaunchDescription(
    #     AnyLaunchDescriptionSource(
    #         PathJoinSubstitution([
    #             FindPackageShare('rosbridge_server'),
    #             'launch/rosbridge_websocket_launch.xml'
    #         ])
    #     ),
    #     launch_arguments={
    #         'port': '9091',
    #     }.items()
    # )
    # ])

    show_banner = TimerAction(period=wait_for_rosbridge_server_s, actions=[LogInfo(msg=HAIVE_OS)])

    start_device_manager = TimerAction(period=wait_for_device_layer_s, actions=[
        Node(
            package='hos_device_layer',
            executable='device_manager',
            name='device_manager',
            output='screen',
            emulate_tty=True,
            arguments=['-f', device_manager_fleet, device_manager_local_db]
        )
    ])

    show_banner = TimerAction(period=wait_for_device_layer_s, actions=[LogInfo(msg=HAIVE_OS)])

    start_state_manager = TimerAction(period=wait_for_device_layer_s, actions=[
        Node(
            package='hos_robot_state',
            executable='state_manager',
            name='state_manager',
            output='screen',
            emulate_tty=True,
            arguments=['-f', device_manager_fleet, device_manager_local_db]
        )
    ])

    start_robot_state_init = TimerAction(period=wait_for_state_layer_s, actions=[
        Node(
            package='hos_robot_state',
            executable='robot_state_init_service',
            name='robot_state_init_service',
            output='screen',
            emulate_tty=True,
            arguments=['-f', device_manager_fleet, device_manager_local_db]
        )
    ])


    ld = LaunchDescription()

    # Declare launch options
    ld.add_action(wait_for_rosbridge_server_s_arg)
    ld.add_action(wait_for_device_layer_s_arg)
    ld.add_action(wait_for_state_layer_s_arg)
    ld.add_action(log_level_arg)
    ld.add_action(device_manager_fleet_arg)
    ld.add_action(local_device_db_arg)

    # Add actions to launch nodes
    # ld.add_action(start_rosbridge_server)
    ld.add_action(show_banner)
    ld.add_action(start_device_manager)
    ld.add_action(start_state_manager)
    ld.add_action(start_robot_state_init)

    return ld
