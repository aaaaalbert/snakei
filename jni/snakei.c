#include <Python.h>
#include <jni.h>
#include "android/native_activity.h"

#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "PythonExt", __VA_ARGS__))


/*
 * Function to be called from Python
 * Borrowing the JNI stuff from http://stackoverflow.com/questions/25010582/jnienv-for-get-android-id-from-native-code
 * Thanks!
 */
static PyObject* py_myFunction(PyObject* self, PyObject* args)
{
	char *s = "Hello from C!";

	// In theory, this gives us a VM and Env to work with
	ANativeActivity ana;

	JNIEnv* env = ana.env;
	JavaVM* vm = ana.vm;
	void* void_pointer;

	struct JNINativeInterface jnini;

	LOGI("The fun begins!");

	LOGI("jnini version: %i", jnini.GetVersion(env));

	//return Py_BuildValue("i", version);
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



static PyObject* py_f1(PyObject* self, PyObject* args)
{
	char *s = "Hello from C!";

	JNIEnv** env;
	JavaVM* vm;
	void* void_pointer;

	//LOGI("Attaching current thread");
	struct JNIInvokeInterface jniiif;
	/*
	jniiif.AttachCurrentThread(vm, env, void_pointer);

	LOGI("Attached!");
	*/

	// Can we at least make something break by detaching 
	// from a not-attached VM?
	LOGI("Detaching current thread");
	jniiif.DetachCurrentThread(vm);
	LOGI("Done");

	//return Py_BuildValue("i", version);
	return Py_BuildValue("s", s);
}



static PyObject* py_f2(PyObject* self, PyObject* args)
{
	char *s = "Hello from C!";

	JNIEnv* env;
	JavaVM** vm;

	LOGI("Getting JavaVM");
	struct JNINativeInterface jnif;
	jnif.GetJavaVM(env, vm);  // From jni.h
	LOGI("Got JavaVM, getting version");

	int version = (int) jnif.GetVersion(env);
	LOGI("Got version '%i'", version);

	return Py_BuildValue("i", version);
	//return Py_BuildValue("s", s);
}





/*
 * Bind Python function names to our C functions
 */
static PyMethodDef myModule_methods[] = {
	{"myFunction", py_myFunction, METH_VARARGS},
	{"myOtherFunction", py_myOtherFunction, METH_VARARGS},
	{"f1", py_f1, METH_VARARGS},
	{"f2", py_f2, METH_VARARGS},
	{NULL, NULL}
};

/*
 * Python calls this to let us initialize our module
 */
void initsnakei()
{
	LOGI("Initializing snakei 2015-02-12 1823");
	(void) Py_InitModule("snakei", myModule_methods);
	LOGI("Done initializing snakei");
}

