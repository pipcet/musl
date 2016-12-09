#define asm __asm__

asm(".include \"wasm32-import-macros.s\"");

#ifdef __PIC__
asm(".import3_pic thinthin,syscall,__thinthin_syscall");
#else
asm(".import3 thinthin,syscall,__thinthin_syscall");
#endif

extern long __thinthin_syscall(long n, ...) __attribute__((stackcall));

long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) __attribute__((stackcall));


long long __wasm_syscall(long long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6) {
  return __thinthin_syscall(n, a1, a2, a3, a4, a5, a6);
}

asm(".globl $syscall\n"
    "\tcreatesig FiiiiiiiE\n"
    "\t.pushsection .wasm.chars.import\n"
    "\t.byte 0x00\n"
    "\t.popsection\n"
    "\t.pushsection .wasm.payload.import\n"
    "\tlstring \"sys\"\n"
    "\tlstring \"call\"\n"
    "\t.byte 0x00\n"
    "\trleb128 __sigchar_FiiiiiiiE\n"
    "\t.popsection\n"
    "\t.pushsection .wasm.chars.function_index.a,\"\"\n"
    "$syscall:\n"
    "\t.byte 0xff\n"
    "\t.popsection\n"
    "\t.pushsection .wasm.chars.name.a\n"
    "\t.byte 0x00\n"
    "\t.popsection\n"
    "\t.pushsection .wasm.payload.name.a\n"
    "\tlstring $syscall\n"
    "\t.byte 0\n"
    "\t.popsection\n");
