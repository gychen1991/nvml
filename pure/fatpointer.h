#include <stdint.h>

int64_t region_base;
typedef struct fat_pointer{
	int64_t base;
	int64_t off;
}fatp;

#define FATP_MALLOC(o) (\
	{void *p = malloc(o); \
	fatp *res = (fatp *)malloc(sizeof(fatp)); \
	res->base = region_base; \
	res->off = (uintptr_t)p - region_base; \
	res;})

#define R_FAT(o,type) (\
	{(type *)(o->base + o->off);})

