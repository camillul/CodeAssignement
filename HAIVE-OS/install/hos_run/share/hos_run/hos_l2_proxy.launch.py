from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (IncludeLaunchDescription, RegisterEventHandler, TimerAction, ExecuteProcess, LogInfo, DeclareLaunchArgument)
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import (PathJoinSubstitution, FindExecutable, LaunchConfiguration)

from ament_index_python.packages import get_package_share_directory

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
        arguments=['-f', fleet_name, '--local-db'],
        # arguments=['-f', fleet_name],
    )

    layout_path = PathJoinSubstitution([
      FindPackageShare('hos_device_simulation'),
      'layouts/test_layout.json'
    ])
    haive4_sim = Node(
        package='hos_device_simulation',
        executable='simulation_haive4',
        name='simulation_haive4',
        arguments=['-l', layout_path, '--simulate-streams'],
        output='screen',
        emulate_tty=True,
    )

    calibration_path = PathJoinSubstitution([
        FindPackageShare('hos_l2_proxy'),
        'calibrations/calib_data-220713-tip_dispo.json'
    ])

    protocol_path = PathJoinSubstitution([
        FindPackageShare('hos_l2_proxy'),
        'protocols/test_protocol.json'
    #     'protocols/TT_TEST_H4001.json'
    ])
    l2_proxy = Node(
        package='hos_l2_proxy',
        executable='l2_proxy',
        name='l2_proxy',
        arguments=['-f', fleet_name, '-c', calibration_path, '-p', protocol_path, '--ignore-wait'],
        # arguments=['-f', fleet_name, '-c', calibration_path],  # We can publish protocols like this `ros2 topic pub -1 /haive_os/load_protocol std_msgs/String 'data: TT_TEST_H4001.json'`
        output='screen',
        emulate_tty=True,
    )

    launch_desc = [
        DeclareLaunchArgument(
            "log_level",
            default_value=["debug"],
            description="Logging level",
        ),

        rosbridge_server,
        TimerAction(period=2.0, actions=[
            LogInfo(msg=HAIVE_OS),
            device_manager,
        ]),
        TimerAction(period=4.0, actions=[
            LogInfo(msg="System ready!"),
        ]),
        TimerAction(period=5.0, actions=[
            haive4_sim,
        ]),
        TimerAction(period=10.0, actions=[
            l2_proxy,
        ]),
    ]

    # protocol_path_data = f"{get_package_share_directory('hos_l2_proxy')}/protocols/test_protocol.json"
    # for i in range(10):
    #     launch_desc.append(TimerAction(period=10.0 + 60.0 * i, actions=[
    #         ExecuteProcess(
    #             cmd=[[
    #                 'ros2',
    #                 ' topic pub ',
    #                 'haive_os/load_protocol ',
    #                 'std_msgs/String ',
    #                 f'"{{data: {protocol_path_data}}}" '
    #                 '-t 1'
    #             ]],
    #             shell=True
    #         )
    #     ]))

    # return LaunchDescription([
    #     rosbridge_server,
    #     TimerAction(period=2.0, actions=[
    #         LogInfo(msg=haive_os_banner),
    #         device_manager,
    #     ]),
    #     TimerAction(period=4.0, actions=[
    #         LogInfo(msg="System ready!"),
    #     ]),
    #     TimerAction(period=5.0, actions=[
    #         haive4_sim,
    #     ]),
    #     TimerAction(period=7.0, actions=[
    #         l2_proxy,
    #     ]),
    #     TimerAction(period=10.0, actions=[
    #         ExecuteProcess(
    #             cmd=[[
    #                 'ros2',
    #                 ' topic pub ',
    #                 'haive_os/load_protocol ',
    #                 'std_msgs/String ',
    #                 f'"{{data: {protocol_path_data}}}" '
    #                 '-t 1'
    #             ]],
    #             shell=True
    #         )
    #     ]),
    # ])
    return LaunchDescription(launch_desc)
