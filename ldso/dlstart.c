#include <stddef.h>
#include "dynlink.h"

#ifndef START
#define START "_dlstart"
#endif

#define SHARED

#include "crt_arch.h"

__attribute__((__visibility__("hidden")))
void _dlstart_c(size_t *sp, size_t *dynv)
{
}
