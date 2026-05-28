import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/charan/Mars-summer-tasks/task-2/ros_ws/install/turtle_patrol'
