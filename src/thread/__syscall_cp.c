#include "pthread_impl.h"
#include "syscall.h"

__attribute__((__visibility__("hidden")))
long __syscall_cp_c();

static long sccp(syscall_arg_t nr,
                 syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
                 syscall_arg_t x, syscall_arg_t y, syscall_arg_t z)
{
	return (__syscall6)(nr, u, v, w, x, y, z);
}

weak_alias(sccp, __syscall_cp_c);

long (__syscall_cp)(syscall_arg_t nr,
                    syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
                    syscall_arg_t x, syscall_arg_t y, syscall_arg_t z)
{
	return sccp(nr, u, v, w, x, y, z);
}
