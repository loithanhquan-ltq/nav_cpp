# nav_cpp

**nav_cpp** is a ROS1 C++ package demonstrating basic navigation for robots. It includes nodes for movement control, goal navigation, and simple path planning using C++.

---

## Features
- C++ navigation nodes for sending goal commands.  
- Basic path planning from current position to a target.  
- Publishers and subscribers for navigation-related topics such as position, velocity, and movement commands.  
- Can be integrated with `move_base` or other ROS planners.

---

## Requirements
- ROS1 (e.g., Noetic / Melodic)  
- ROS packages: `geometry_msgs`, `nav_msgs`, `tf`  
- C++11 or later

---

## Installation
1. Clone the repository into your catkin workspace:  
```bash
cd ~/catkin_ws/src
git clone https://github.com/loithanhquan-ltq/nav_cpp.git

2. Build the workspace:

cd ~/catkin_ws
catkin_make
source devel/setup.bash

---

## Usage

rosrun nav_cpp navigator_node

