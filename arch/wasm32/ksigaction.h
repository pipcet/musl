struct k_sigaction {
	void (*handler)(int);
	unsigned long long flags;
	void (*restorer)(void);
	unsigned mask[2];
};

void __restore_rt();
#define __restore __restore_rt
