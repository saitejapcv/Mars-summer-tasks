from setuptools import find_packages, setup

package_name = 'turtle_patrol'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='user',
    maintainer_email='user@todo.todo',
    description='Circular Patrol with Custom Actions',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # Register our two nodes as executable commands
            'circle_patrol_server = turtle_patrol.circle_patrol_server:main',
            'circle_patrol_client = turtle_patrol.circle_patrol_client:main',
        ],
    },
)
