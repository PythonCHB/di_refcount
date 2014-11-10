from distutils.core import setup
from distutils.extension import Extension
setup(
    name = 'di',
    version = '0.1',
    description = 'Turn an id() back into a Python object reference.',
    long_description = 'Turn an id() back into a Python object reference.  Kind of like running with scissors.',
    maintainer = 'Bill Bumgarner',
    maintainer_email = 'bbum@mac.com',
    license = 'MIT',
    ext_modules=[
        Extension(
            'di',
            ['di.c'],
        ),
    ],
)

