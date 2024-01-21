from setuptools import find_packages
from setuptools import setup

setup(
    name='coordinate_msg',
    version='0.0.0',
    packages=find_packages(
        include=('coordinate_msg', 'coordinate_msg.*')),
)
