from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (IncludeLaunchDescription, TimerAction, ExecuteProcess, LogInfo, DeclareLaunchArgument)
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import (PathJoinSubstitution, LaunchConfiguration)

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

    # logger = LaunchConfiguration("log_level")

    fleet_name = "shinkawasaki"
    device_manager = Node(
        package='hos_device_layer',
        executable='device_manager',
        name='device_manager',
        output='screen',
        emulate_tty=True,
        arguments=['-f', fleet_name],
        # arguments=['--ros-args', '--log-level', logger]
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

    calibration_path = PathJoinSubstitution([
      FindPackageShare('hos_l2_proxy'),
      'calibrations/calib_data-220713-tip_dispo.json'
    ])
    protocol_path = PathJoinSubstitution([
      FindPackageShare('hos_l2_proxy'),
      'protocols/test_protocol.json'
    #   'protocols/TT_TEST_H4001.json'
    ])
    l2_proxy = Node(
        package='hos_l2_proxy',
        executable='l2_proxy',
        name='l2_proxy',
        # arguments=['-f', fleet_name, '--ros-args', '--log-level', logger],
        arguments=['-f', fleet_name, '-c', calibration_path, '-p', protocol_path],
        # arguments=['-f', fleet_name, '-c', calibration_path],  # We can publish protocols like this `ros2 topic pub -1 /haive_os/load_protocol std_msgs/String 'data: /home/ubuntu/TT_TEST_H4001.json'`
        output='screen',
        emulate_tty=True,
    )

    robot_state = Node(
        package='hos_robot_state',
        executable='robot_state_node',
        name='robot_state_node',
        output='screen',
        emulate_tty=True,
    )


    # args_cmd_slot_power = "[{'name': 'slot', 'type': 'uint8', 'data': '1'}, {'name': 'is_on', 'type': 'bool', 'data': 'True'}]"
    return LaunchDescription([
        # DeclareLaunchArgument(
        #     "log_level",
        #     default_value=["debug"],
        #     description="Logging level",
        # ),

        rosbridge_server,
        TimerAction(period=2.0, actions=[
            LogInfo(msg=HAIVE_OS),
            device_manager,
            LogInfo(msg="System ready!"),
        ]),
        # TimerAction(period=10.0, actions=[
        #     robot_state,
        # ]),
        TimerAction(period=14.0, actions=[
            haive4_sim,
        ]),
        #  TimerAction(period=18.0, actions=[
        #     l2_proxy,
        # ]),   

        # TimerAction(period=5.0, actions=[
        #     ExecuteProcess(
        #         cmd=[[
        #             'ros2',
        #             ' service call ',
        #             'haive_os/device/api_call ',
        #             'hos_interfaces/srv/DeviceAPICall ',
        #             f'"{{task_id: 0, device_uid: 0, function_name: cmd_led_all_off, num_args: 0, args: []}}"',
        #         ]],
        #         shell=True
        #     )
        # ]),
        # TimerAction(period=15.0, actions=[
        #     ExecuteProcess(
        #         cmd=[[
        #             'ros2',
        #             ' service call ',
        #             'haive_os/device/api_call ',
        #             'hos_interfaces/srv/DeviceAPICall ',
        #             f'"{{task_id: 0, device_uid: 0, function_name: cmd_slot_power, num_args: 2, args: {args_cmd_slot_power}}}"',
        #         ]],
        #         shell=True
        #     )
        # ]),
    ])
