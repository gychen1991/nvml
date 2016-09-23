#include <stdint.h>

int64_t base;

#define Based void

#define BASED_MALLOC(o, type) (\
	{void *p = malloc(o); \
	 (void *)((intptr_t)p - base); \
	})

#define R_Based(o,type) (\
	{(type *)(o + base);})

