/*
 * Reference to
 * https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio
 */

#include <Python.h>
#include <cmath>


const double e = 2.7182818284590452353602874713527;


double sinh_impl(double x) {
    return (1 - pow(e, (-2 * x))) / (2 * pow(e, -x));
}


double cosh_impl(double x) {
    return (1 + pow(e, (-2 * x))) / (2 * pow(e, -x));
}


/*
Old pure C++ implementation
double tanh_impl(double x) {
    return sinh_impl(x) / cosh_impl(x);
}
*/
// Updated implementation
static PyObject* tanh_impl(PyObject* self, PyObject* args) {
	double x;
	if(!PyArg_ParseTuple(args, "d", &x)) {
		return NULL;
	}
	double tanh_x = sinh_impl(x) / cosh_impl(x);
	return PyFloat_FromDouble(tanh_x);
}


static PyObject* version(PyObject* self) {
	return Py_BuildValue("s", "version 1.0");
}


/*
 * Add a structure that defines how tanh_impl function is presented to Python
 */
static PyMethodDef superfastcode_methods[] = {
	// arg1: first property is the name exposed to python fast_tanh
	// arg2: C++ function name that contains the implementation.
	{"fast_tanh", (PyCFunction) tanh_impl, METH_VARARGS, "calculates tanh"},
	{"__version__", (PyCFunction) version, METH_NOARGS, "return the version"},

	// Terminate the array with object containing nulls
	{NULL, NULL, 0, NULL}
};


/*
 * Add a structure that defines the module we want to refer in the Python code
 */
static struct PyModuleDef superfastcode_module = {
	PyModuleDef_HEAD_INIT,
	"module",						// module name to use with python import statement
	"Provides some functions, but faster", 	// module description
	0,
	superfastcode_methods					// Structure that defines the methods of the module
};


/*
 * Add a method that Python calls when it loads the module
 * This must be named PyInit_<module-name>. Where <module-name> matches 
 * the C++ project's General > Target Name property
 */
PyMODINIT_FUNC PyInit_module(void) {
	return PyModule_Create(&superfastcode_module);
}