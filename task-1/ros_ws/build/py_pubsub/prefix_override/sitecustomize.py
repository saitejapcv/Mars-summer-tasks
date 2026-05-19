import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/saitejapcv/ros/Mars-summer-tasks/task-1/ros_ws/install/py_pubsub'
