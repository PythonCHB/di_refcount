from setuptools import setup
from distutils.extension import Extension

setup(
    name='di',
    version='0.1',
    description='Turn an id() back into a Python object reference, and get a refcount from an id',
    long_description='Turn an id() back into a Python object reference. It will also return the reference count of an object from its id.  Kind of like running with scissors.',
    maintainer='Chris Barker',
    maintainer_email='PythonCHB@gmail.com',
    license='MIT',
    ext_modules=[
        Extension(
            'di',
            ['di.c'],
        ),
    ],
)

