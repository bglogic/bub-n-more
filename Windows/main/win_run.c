#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Python.h"

extern int Py_Main(int, char **);

int WINAPI WinMain(
    HINSTANCE hInstance,      /* handle to current instance */
    HINSTANCE hPrevInstance,  /* handle to previous instance */
    LPSTR lpCmdLine,          /* pointer to command line */
    int nCmdShow              /* show state of window */
)
{
	int argc = __argc;
	char** argv = __argv;
	char* my_argv[2];
	if (argc <= 1) {
		my_argv[0] = argv[0];
		my_argv[1] = "BubBob.py";
		argc = 2;
		argv = my_argv;
	}
	return Py_Main(argc, argv);
}
