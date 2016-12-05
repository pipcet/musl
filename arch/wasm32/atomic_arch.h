#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
        int ret = *p;
        if (*p == t)
                *p = s;

        return ret;
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
        *p &= v;
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
        *p |= v;
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
        *p &= v;
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
        *p |= v;
}

#define a_inc a_inc
static inline void a_inc(volatile int *p)
{
        *p++;
}

#define a_dec a_dec
static inline void a_dec(volatile int *p)
{
        *p--;
}

#define a_store a_store
static inline void a_store(volatile int *p, int x)
{
        *p = x;
}

#define a_barrier a_barrier
static inline void a_barrier()
{
	__asm__ __volatile__( "" : : : "memory" );
}

#define a_spin a_spin
static inline void a_spin()
{
}

#define a_crash a_crash
static inline void a_crash()
{
        for(;;);
}
