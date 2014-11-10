Copyright 2007 Bill Bumgarner All Rights Reserved.

Copyright 2014 Christopher Barker All Rights Reserved.

MIT License -- Free as in "free".

This is a verison of Bill Bumgarner's "di" module.

http://www.friday.com/bbum/2007/08/24/python-di/
http://svn.red-bean.com/bbum/trunk/hacques/di/

Summary
--------

This is the di module as is, with the addition of another function::

  ref_by_id()

``di(i)`` returns an object given its id ( as returned by ``id(obj)`` ).

``ref_by_id(i)`` returns the reference count of the the object by its id.

This is useful for debugging memory leaks, reference counting errors, etc.
For instance, if you have a circular reference, objects can never have
their reference count reduced to zero, and thsu will never be deleted.
But all references to them maybe have been, so there is no way to get
their reference count info in the usual way.

Note that both of these functions are very dangerous -- if you pass in
an invalid id, you can (will!) get a segmentation fault and a hard crash.


Usage
------

::

    >>> obj = {'a' : 'b', 1 : 2}
    >>> from di import di, ref_by_id
    >>> id(obj)
    681856
    >>> di(681856)
    {'a': 'b', 1: 2}

    >>> obj = ['a', 'list', 'of', 'stuff']
    >>> obj_id = id(obj)
    >>> ref_by_id(obj_id)
    1
    >>> a = b = c = obj
    >>> ref_by_id(obj_id)
    4
    >>> del obj
    >>> ref_by_id(obj_id)
    3
    >>> del b,c
    >>> ref_by_id(obj_id)
    1
    >>> del a
    >>> ref_by_id(obj_id)
    0


Don't use this in production code.  That would be stupid.
This is, however, very useful for debugging purposes.

Building
---------

The usual setup.py dance::

  python setup.py build_ext --inplace

will build it in place.

To install::

  python setup.py install

Or in develop mode:

    python setup.py develop

