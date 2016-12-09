static inline struct pthread *__pthread_self()
{
        static struct pthread self;
	return &self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]
