HAIVE OS is the software platform responsible for connecting and orchestrating the devices and services of the HAIVE robotics platform. For a detailed introduction of the system, you can visit the [HAIVE OS docs](https://molcure.github.io/HAIVE-OS_Pages/#/).

## Getting Started

Clone the repository on an Ubuntu 22.04 system:

Make sure you have `rosdep` installed:
```shell
sudo apt install python3-rosdep2
rosdep update
```

Install dependencies:
```shell
cd HAIVE-OS/
rosdep install --from-paths src -y --ignore-src
```

Build and run:
```shell
colcon build
. install/setup.bash
ros2 launch hos_run hos_run.launch.py
```
