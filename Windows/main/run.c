#include <Python.h>

extern int Py_Main(int argc, char **argv);

int main (int argc, char **argv)
{
	char* my_argv[2];
	if (argc <= 1) {
		my_argv[0] = argv[0];
		my_argv[1] = "BubBob.py";
		argc = 2;
		argv = my_argv;
	}
	return Py_Main(argc, argv);
}
