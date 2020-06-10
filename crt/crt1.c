#include <features.h>
#include "libc.h"

#define START "_start"

#include "crt_arch.h"

int main();
weak void _init();
weak void _fini();
_Noreturn int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

void _start(int, char **, char **) __attribute__((stackcall));

void _start(int argc, char **argv, char **envp)
{
        __libc_start_main(main, argc, argv, 0, 0, 0);
}
