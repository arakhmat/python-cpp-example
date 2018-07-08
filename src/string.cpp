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
    PyObject* ret_obj = PyList_New(tokens.size());
    for (int i = 0; i < tokens.size(); i++) {
        const char *token = tokens[i].c_str();
        PyObject* token_obj;
#if PY_MAJOR_VERSION >= 3
        token_obj = PyUnicode_FromString(token);
#else
        token_obj = PyString_FromString(token);
#endif
        PyList_SetItem(ret_obj, i, token_obj);
    }
    return Py_BuildValue("O", ret_obj);
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
        auto item = PyList_GetItem(words, i);
        char *token;
#if PY_MAJOR_VERSION >= 3
        token = (char*) PyUnicode_DATA(item);
#else
        token = PyString_AsString(item);
#endif
        tokens.push_back(std::string(token, token + strlen(token)));
    }
    auto s = string::join(tokens, sep);
    return Py_BuildValue("s", s.c_str());
}

// Mapping between python and c function names.
static PyMethodDef cppstring_module_methods[] = {
    {"split", (PyCFunction) py_split, METH_VARARGS | METH_KEYWORDS},
    {"join", (PyCFunction) py_join, METH_VARARGS | METH_KEYWORDS},
    {NULL, NULL, 0, NULL}
};
/* Module entry point Python 3 */

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef cppstring = {
    PyModuleDef_HEAD_INIT,
    "cppstring",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    cppstring_module_methods
};

PyMODINIT_FUNC PyInit_cppstring(void)
{
    return PyModule_Create(&cppstring);
}
#else
PyMODINIT_FUNC initcppstring(void) {
    Py_InitModule("cppstring", cppstring_module_methods);
}
#endif

