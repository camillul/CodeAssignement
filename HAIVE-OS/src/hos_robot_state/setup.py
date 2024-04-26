from setuptools import setup


package_name = 'hos_robot_state'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='haive@molcure.io',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'state_manager = hos_robot_state.state_manager:main',
            'test_state_protocol = hos_robot_state.test_state_protocol:main',
            'robot_state_init_client = hos_robot_state.robot_state_init_client:main',
            'robot_state_init_service = hos_robot_state.robot_state_init_service:main',
        ],
    },
)
