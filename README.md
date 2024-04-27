# HAIVE-OS (Snapshot)

HAIVE-OS was the ROS architecture design to handle all the robot's state space representation, connection, communication. Here we have only a snapshot of it, architecture that I mainly designed and developped with Johannes (former collegue).
You can also acces the Documentation here, explaining the main packages of the HAIVE-OS
[HAIVE-OS Documentation](https://molcure.github.io/HAIVE-OS_Pages/#/)

## Installation 

Follow these step to install a docker image for ros2 since HAIVE-OS was running on ros2 humble.
https://docs.ros.org/en/humble/How-To-Guides/Run-2-nodes-in-single-or-separate-docker-containers.html

Once you're running the container, run those command :

First in your computer shell :
```shell
docker cp CodeAssignement <your_container_id>:boot/
```

Then in docker container shell :
```shell
cd boot/CodeAssignement/HAIVE-OS
apt-get update
apt-get install python3-pip
pip install requests
colcon build

```
## Run
Here the steps to run the code

```shell
. install/setup.bash
ros2 launch hos_run hos_run.launch.py device_db:=--local-db
```

This should run the ROS2 environnement and the HAIVE-OS feel free to check the envrionnement with rqt or any tool, Please contact camille.ulrb@gmail.com for any futher information.

You can also run the test from the hos_robot_state package 

```shell
pytest -s src/hos_robot_state/test/test_haive_state.py
```
