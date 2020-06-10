#define asm __asm__

typedef struct __jmp_buf_internal_tag
  {
    void * __pc0;
    void * __rpc;
    void * __fp;
    void * __sp;
    unsigned __mask_was_saved;
  } __jmp_buf[1];

int
__sigjmp_save(__jmp_buf env, int savemask)
{
  env[0].__mask_was_saved = savemask;

  return 0;
}

int setjmp(void *env)
{
  asm volatile(".flush");

  void *x;

  asm volatile("%S0\n\t"
               "local.get $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "%R0\n\t"
               : "=r" (x));


  x = (void *)*(void **)x;
  x = (void *)*(void **)x;

  asm volatile(
               //"local.get $sp1\n\t"
               //"i32.const -16\n\t"
               //"i32.add\n\t"
               //"i32.load a=2 0\n\t"
               //"i32.load a=2 0\n\t"
               //"i32.load a=2 8\n\t"
               //"local.get $rpc\n\t"
               //"i32.store a=2 0\n\t"

               "%1\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 8\n\t"
               "i32.store a=2 0\n\t"

               "%1\n\t"
               "local.get $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 16\n\t"
               "i32.store a=2 4\n\t"

               "%1\n\t"
               "local.get $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.store a=2 8\n\t"

               "%1\n\t"
               "local.get $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.store a=2 12\n\t"

               "i32.const 0\n\t"
               "local.set $r1\n\t"
               ".dpc .LI7\n\t"
               "local.set $dpc\n\t"
               "i32.const -1\n\t"
               "local.get $sp\n\t"
               "%1\n\t"
               "local.get $r1\n\t"
               "local.get $rpc\n\t"
               "local.get $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "call __sigjmp_save\n\t"
               "local.set $rp\n\t"
               "i32.const 3\n\t"
               "local.get $rp\n\t"
               "i32.and\n\t"
               "if[]\n\t"
               "throw\n\t"
               "end\n\t"
               ".wasmtextlabeldpcdef .LI7\n\t"
               : : "r" (0), "r" (env));
  return 0;
}
