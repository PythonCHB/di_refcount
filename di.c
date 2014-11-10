#include <Python/Python.h>

PyDoc_STRVAR(di_di_doc,
             "Given the result of id(), returns a Python object reference.");

static PyObject *
di_di(PyObject *self, PyObject *args)
{
    PyObject *obj;
    if (!PyArg_ParseTuple(args, "l:di", &obj))
        return  NULL;

    Py_INCREF(obj);
    return obj;
}

PyDoc_STRVAR(di_ref_by_id_doc,
             "returns the refcount of the python object with the given id.");

static PyObject *
di_ref_by_id(PyObject *self, PyObject *args)
{
    PyObject *obj;
    PyObject *refcount;

    if (!PyArg_ParseTuple(args, "l:di", &obj))
        return  NULL;

    refcount = PyInt_FromLong(Py_REFCNT(obj));

    // Py_INCREF(refcount); /* Is this required? */
    //                      /* doesn't matter much -- small ints are interned anyway*/
    return refcount;
}


static PyMethodDef di_methods[] = {
	{"di", di_di, METH_VARARGS, di_di_doc},
    {"ref_by_id", di_ref_by_id, METH_VARARGS, di_ref_by_id_doc},
    {NULL, NULL}
};

PyDoc_STRVAR(di_doc, "Convert id() back to an object.");

PyMODINIT_FUNC
initdi(void)
{
	PyObject *m;

	m = Py_InitModule3("di", di_methods, di_doc);
	if (m == NULL) return;
}

/*

The MIT License

Copyright (c) 2007 Bill Bumgarner <bbum@mac.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/