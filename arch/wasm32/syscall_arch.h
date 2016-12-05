#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

extern long long __wasm_syscall(long long n, ...) __attribute__((stackcall));

static __inline long long __syscall0(long long n)
{
        return __wasm_syscall(n);
}

static __inline long long __syscall1(long long n, long long a1)
{
        return __wasm_syscall(n, a1);
}

static __inline long long __syscall2(long long n, long long a1, long long a2)
{
        return __wasm_syscall(n, a1, a2);
}

static __inline long long __syscall3(long long n, long long a1, long long a2, long long a3)
{
        return __wasm_syscall(n, a1, a2, a3);
}

static __inline long long __syscall4(long long n, long long a1, long long a2, long long a3, long long a4)
{
        return __wasm_syscall(n, a1, a2, a3, a4);
}

static __inline long long __syscall5(long long n, long long a1, long long a2, long long a3, long long a4, long long a5)
{
        return __wasm_syscall(n, a1, a2, a3, a4, a5);
}

static __inline long long __syscall6(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6)
{
        return __wasm_syscall(n, a1, a2, a3, a4, a5, a6);
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"
