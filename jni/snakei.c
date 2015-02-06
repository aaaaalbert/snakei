/* 
 * This time, try to access a Java method from C.
 */

#include <Python.h>
#include <jni.h>
#include <android_native_app_glue.h>

/*
 * Function to be called from Python
 * Borrowing the JNI stuff from http://stackoverflow.com/questions/25010582/jnienv-for-get-android-id-from-native-code
 * Thanks!
 */
static PyObject* py_myFunction(PyObject* self, PyObject* args)
{
	struct android_app* state;
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


void android_main(struct android_app* state)
{
	JNIEnv *env = state->activity->env;
	JavaVM *vm = state->activity->vm;
	(*vm)->AttachCurrentThread(vm, &env, NULL);

	/* TODO Interesting code should go here! */

	(*vm)->DetachCurrentThread(vm);
}
