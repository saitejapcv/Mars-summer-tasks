# Beginner: CLI Tools

- "Workspace" in ROS terms is the location on your system where you are developing with ROS-2. The core ROS 2 workspace is called the underlay. Subsequent local workspaces are called overlays

-This is accomplished by sourcing setup files every time you open a new shell, or by adding the source command to your shell startup script once. Without sourcing the setup files, you won’t be able to access ROS 2 commands, or find or use ROS 2 packages. In other words, you won’t be able to use ROS 2.

## Tasks:

1. Source the setup Files:
- You will need to run this command on every new shell you open to have access to the ROS 2 commands, like so:
`source /opt/ros/humble/setup.bash`

2. Add sourcing to your shell startup script:
- If you don't want to execute step-1 always you open a new shell then you can add the command to your shell startup script:
`echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc`

- If you want to undo this, locate your system’s shell startup script and remove the appended source command.

3. Check Environment Variables:
- Sourcing ROS 2 setup files will set several environment variables necessary for operating ROS 2. If you ever have problems finding or using your ROS 2 packages, make sure that your environment is properly set up using the following command:
`printenv | grep -i ROS`
- Check for the response:
`ROS_VERSION=2
ROS_PYTHON_VERSION=3
ROS_DISTRO=humble`
- If the environment variables are not set correctly, return to the ROS 2 package installation section of the installation guide you followed.

4. The ROS_DOMAIN_ID variable:
- 
