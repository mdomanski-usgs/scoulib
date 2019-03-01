#include <Python.h>
#include <hello.h>

static PyObject *ScoulibError;

static PyObject *scoulib_hello(PyObject *self, PyObject *args) {

    const char *h = hello();

    return PyUnicode_FromString(h);
}

static PyMethodDef ScoulibMethods[] = {
    {
        "hello",
        scoulib_hello,
        METH_NOARGS,
        "Say hello.",
    },
    {NULL, NULL, 0, NULL}, // sentinel
};

static PyModuleDef scoulibmodule = {
    PyModuleDef_HEAD_INIT, "scoulib", "Sediment acoustic library", -1,
    ScoulibMethods,
};

PyMODINIT_FUNC PyInit_scoulib() {
    PyObject *module;

    module = PyModule_Create(&scoulibmodule);
    if (module == NULL) {
        return NULL;
    }
    ScoulibError = PyErr_NewException("scoulib.Error", NULL, NULL);
    Py_INCREF(ScoulibError);
    PyModule_AddObject(module, "Error", ScoulibError);
    return module;
}
