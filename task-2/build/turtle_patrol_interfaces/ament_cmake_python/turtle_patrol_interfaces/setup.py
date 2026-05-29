from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_patrol_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('turtle_patrol_interfaces', 'turtle_patrol_interfaces.*')),
)
