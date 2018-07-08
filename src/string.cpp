#include "Python.h"

#include <iostream>

#include "split.h"
#include "join.h"

static PyObject* py_split(PyObject* self, PyObject *args, PyObject *kwargs) {
    char* s;
    char* sep;
    int maxsplit = -1;

    static char *kwlist[] = {
        "s",
        "sep",
        "maxsplit",
        NULL};

    int success = PyArg_ParseTupleAndKeywords(args,
        kwargs, "s|si", kwlist,
        &s,
        &sep,
        &maxsplit);

    if (!success)
        return Py_None;

    auto tokens = string::split(s, sep, maxsplit);
    PyObject* splits = PyList_New(tokens.size());
    for (int i = 0; i < tokens.size(); i++) {
        PyList_SetItem(splits, i, PyString_FromString(tokens[i].c_str()));
    }
    return Py_BuildValue("O", splits);
}

static PyObject* py_join(PyObject* self, PyObject *args, PyObject *kwargs) {
    PyObject *words;
    char* sep = NULL;

    static char *kwlist[] = {
        "words",
        "sep",
        NULL};

    int success = PyArg_ParseTupleAndKeywords(args,
        kwargs, "Os", kwlist,
        &words,
        &sep);

    if (!success)
        return Py_None;

    std::vector<std::string> tokens;
    for (int i = 0; i < PyList_Size(words); i++) {
        char *token = PyString_AsString(PyList_GetItem(words, i));
        tokens.push_back(std::string(token, token + strlen(token)));
    }
    auto s = string::join(tokens, sep);
    return Py_BuildValue("s", s.c_str());
}

// Mapping between python and c function names.
static PyMethodDef cppstringModule_methods[] = {
    {"split", (PyCFunction) py_split, METH_VARARGS | METH_KEYWORDS},
    {"join", (PyCFunction) py_join, METH_VARARGS | METH_KEYWORDS},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initcppstring(void) {
    PyObject *m;
    m = Py_InitModule("cppstring", cppstringModule_methods);
    if (m == NULL)
        return;
}
