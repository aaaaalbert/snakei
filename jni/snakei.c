/* 
 * To start off, let's try the example given in 
 * http://csl.name/C-functions-from-Python/
 * Let's see if this builds at all.
 */

#include <Python.h>

/*
 * Function to be called from Python
 */
static PyObject* py_myFunction(PyObject* self, PyObject* args)
{
	char *s = "Hello from C!";
	return Py_BuildValue("s", s);
}

/*
 * Another function to be called from Python
 */
static PyObject* py_myOtherFunction(PyObject* self, PyObject* args)
{
	double x, y;
	PyArg_ParseTuple(args, "dd", &x, &y);
	return Py_BuildValue("d", x*y);
}

/*
 * Bind Python function names to our C functions
 */
static PyMethodDef myModule_methods[] = {
	{"myFunction", py_myFunction, METH_VARARGS},
	{"myOtherFunction", py_myOtherFunction, METH_VARARGS},
	{NULL, NULL}
};

/*
 * Python calls this to let us initialize our module
 */
void initsnakei()
{
	(void) Py_InitModule("snakei", myModule_methods);
}
