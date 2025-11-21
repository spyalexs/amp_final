from setuptools import find_packages
from setuptools import setup

setup(
    name='amp_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('amp_msgs', 'amp_msgs.*')),
)
