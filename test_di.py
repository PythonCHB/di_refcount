#!/usr/bin/vn python

"""
some really simple test code

mostly to assure you that it compiled
"""

from di import di, ref_by_id


def test_di_1():

    obj = {'a': 'b', 1: 2}
    obj_id = id(obj)
    assert di(obj_id) == obj


def test_ref_by_id_1():
    obj = ['a', 'list', 'of', 'stuff']
    obj_id = id(obj)
    assert ref_by_id(obj_id) == 1


def test_ref_by_id_2():
    """ does a few more counts """
    obj = ['a', 'list', 'of', 'stuff']
    obj_id = id(obj)

    assert ref_by_id(obj_id) == 1

    a = b = c = obj
    assert ref_by_id(obj_id) == 4

    del obj
    assert ref_by_id(obj_id) == 3

    del b,c
    assert ref_by_id(obj_id) == 1

    del a
    assert ref_by_id(obj_id) == 0 # note: dangerous!
    ## if that memory location gets re-used, this will break!
    ## and could segfault hard.
