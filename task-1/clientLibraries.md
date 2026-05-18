# Client Libraries

## Colcon

- colcon is an iteration on the ROS build tools catkin_make, catkin_make_isolated, catkin_tools and ament_tools. It is used to build workspace.

### Installing colcon:

`sudo apt install python3-colcon-common-extensions`

### Basics:

- ROS workspace is a directory with a particular structure. Commonly there is a src subdirectory. Inside that subdirectory is where the source code of ROS packages will be located. 
- By default when we are building workspace with colcon it will create build, install, log sub directories.
1. The build directory will be where intermediate files are stored.
2. The install directory is where each package will be installed to.
3. The log directory contains various logging information about each colcon invocation.

### Creating Workspace

- Create a directory with a empty sub directory(src).
- Go to src directory and add some sources like cloning a git repository in it.

### Source the underlay

- It is important that we have sourced the environment for an existing ROS 2 installation that will provide our workspace with the necessary build dependencies for the packages. We call this environment an underlay. 
- Our workspace created right now will be an overlay on top of existing ROS 2 installation which is an underlay. In general, it is recommended to use an overlay when you plan to iterate on a small number of packages, rather than putting all of your packages into the same workspace.

### Building workspace

- In the root of the workspace, run `colcon build`.
- `--symlink-install` is used so you don't have to rebuild your workspace every time you change a non-compiled file (like a Python script, a launch file, or a configuration file).
- Running `colcon build` can sometime crash or make you system slow if your CPU-, RAM- and I/O-limited. So add `--executor sequential` so that packages will be build one by one instead of parallelism. 
- After the build is finished, we should see the build, install, and log directories.
- This will take some time to complete. If you didn't use `--symlink-install` and if system stuck then use Ctrl-c to end the process and then try using `--symlink-install`.

### Run Tests

- To run tests for the packages we just built, run the following:

`colcon test`

### Source the environment

- When colcon has completed building successfully, the output will be in the install directory. Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths.
- colcon will have generated bash/bat files in the install directory to help set up the environment. These files will add all of the required elements to your path and library paths as well as provide any bash or shell commands exported by packages.

command to source the environment: `source install/setup.bash`.

- Now you can run the packages using `ros2 run <package-name>`.

## Creating Workspace

- A workspace is a directory containing ROS 2 packages. Before using ROS 2, it’s necessary to source your ROS 2 installation workspace in the terminal you plan to work in. This makes ROS 2’s packages available for you to use in that terminal.

#### Overlay:
- It is a secondary workspace where you can add new packages without interfering with the existing ROS 2 workspace that you’re extending, or “underlay”.
- Your underlay must contain the dependencies of all the packages in your overlay.
- Packages in your overlay will override packages in the underlay.
- It’s also possible to have several layers of underlays and overlays, with each successive overlay using the packages of its parent underlays.

- Remember to source ROS 2 environment before starting.

### Create a new directory:

- Create a new directory with src as a empty sub directory. This is where you will create packages.
- Go to src directory and add some sources like cloning a git repository in it.

### Resolve dependencies:

- Before building the workspace, you need to resolve the package dependencies. You may have all the dependencies already, but best practice is to check for dependencies every time you clone.
- From the root of your workspace (ros2_ws), run the following command:

`rosdep install -i --from-path src --rosdistro humble -y`

If you already have all your dependencies, the console will return:

`#All required rosdeps installed successfully`d
f
### Build The workspace with Colcon

- As instructed in the Colcon section build workspace with colcon.
- You will see new directories: install, build, log which indicate success.

### Source the overlay

- Before sourcing the overlay, it is very important that you open a new terminal, separate from the one where you built the workspace. Sourcing an overlay in the same terminal where you built, or likewise building where an overlay is sourced, may create complex issues.

In the new terminal, source your main ROS 2 environment as the “underlay”, so you can build the overlay “on top of” it:

`source /opt/ros/humble/setup.bash`

Go into the root of your workspace and source your overlay:

`source install/local_setup.bash`

- Now you can run the packages from the overlay.

### Modify the Overlay

- You can modify and rebuild packages in the overlay separately from the underlay.
- The overlay takes precedence over the underlay.

1. Change the code of your package and save the file. 
2. Return to the first terminal where you ran colcon build earlier and run it again.
3. Return to the second terminal (where the overlay is sourced) and run the package again.
4. Even though your main ROS 2 environment was sourced in this terminal earlier, the overlay of your ros2_ws environment takes precedence over the contents of the underlay.
5. To see that your underlay is still intact, open a brand new terminal and source only your ROS 2 installation. Run the package.
6. You can see that modifications in the overlay did not actually affect anything in the underlay.

## Creating a Package

- A package is an organizational unit for your ROS 2 code. If you want to be able to install your code or share it with others, then you’ll need it organized in a package. With packages, you can release your ROS 2 work and allow others to build and use it easily.
- Package creation in ROS 2 uses ament as its build system and colcon as its build tool.
- You can create a package using either CMake or Python, which are officially supported, though other build types do exist.

### Using CMake.

- The simplest possible package may have a file structure that looks like:
`my_package/
     CMakeLists.txt
     include/my_package/
     package.xml
     src/
`
