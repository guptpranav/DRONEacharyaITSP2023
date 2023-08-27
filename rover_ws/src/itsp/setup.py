from setuptools import find_packages, setup

package_name = 'itsp'

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
    maintainer='humble',
    maintainer_email='pranavgupta53535@gmail.com',
    description='ITSP',
    license='GPLv3',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'rpmsubdemo = itsp.rpmsubtest:main',
            'roverpose  = itsp.roverposepub:main',
        ],
    },
)
