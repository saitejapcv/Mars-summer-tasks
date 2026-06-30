from setuptools import find_packages, setup
import os   
from glob import glob

package_name = 'my_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'urdf'),
         glob('urdf/*.urdf') + glob('urdf/*.xacro')),
        (os.path.join('share', package_name, 'launch'),
         glob('launch/*.py')),
        (os.path.join('share', package_name, 'worlds'),
         glob('worlds/*.sdf')),
        (os.path.join('share', package_name, 'config'),
         glob('config/*.rviz') + glob('config/*.yaml')),
        (os.path.join('share', package_name, 'aruco_markers', 'aruco_marker_images'),
         glob('aruco_markers/aruco_marker_images/*.png')),
        (os.path.join('share', package_name, 'worlds', 'assets'),
         glob('worlds/assets/*.obj') + glob('worlds/assets/*.mtl')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='charan',
    maintainer_email='charandeviswamy@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
        ],
    },
)
