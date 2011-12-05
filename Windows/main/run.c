#include <Windows.h>

/*extern int Py_Main(int argc, char **argv);*/

typedef int (*py_main) (int, char**);

static char* libnames[] = {
        "Python27.dll",
        "Python26.dll",
        "Python25.dll",
        "Python24.dll",
	"Python23.dll",
	"Python22.dll",
	(char*) 0 };

py_main get_py_main(void)
{
	char** p;
	for (p=libnames; *p; p++) {
		HINSTANCE lib = LoadLibrary(*p);
		if (lib) {
			FARPROC f = GetProcAddress(lib, "Py_Main");
			if (f)
				return (py_main) f;
			FreeLibrary(lib);
		}
	}
	MessageBox((HWND)0, "Cannot locate the Python DLL (Python2?.dll).",
		(char*)0, MB_ICONERROR);
	exit(1);
}

int main (int argc, char **argv)
{
	char* my_argv[2];
	if (argc <= 1) {
		my_argv[0] = argv[0];
		my_argv[1] = "BubBob.py";
		argc = 2;
		argv = my_argv;
	}
	return get_py_main()(argc, argv);
}
