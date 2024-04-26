#HAIVE-OS (Snapshot)

HAIVE-OS was the ROS architecture design to handle all the robot's state space representation, connection, communication. Here we have only a snapshot of it, architecture that I mainly designed and developped with Johannes (former collegue).
You can also acces the Documentation here, explaining the main packages of the HAIVE-OS
[HAIVE-OS Documentation](https://molcure.github.io/HAIVE-OS_Pages/#/)

## Installation 

Follow these step to install a docker image for ros2 since HAIVE-OS was running on ros2 humble.
https://docs.ros.org/en/humble/How-To-Guides/Run-2-nodes-in-single-or-separate-docker-containers.html

Once you're running the container inside the contaienr run those command :

```shell
apt-get update
```

```shell
apt-get install python3-pip
```

```shell
apt-get pip install requests
```

```shell
ros2 launch hos_run hos_run.launch.py device_db:=--local-db
```