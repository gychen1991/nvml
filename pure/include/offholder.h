#include <stdint.h>

#define OFF void

#define OFF_MALLOC(o, type) (\
	{ malloc(o); \
	})
#define writeoh(paddr, oaddr) (\
	{(*paddr) = oaddr ? (void *)((((intptr_t)oaddr - (intptr_t)paddr))):0;})
#define readoh(param, type) (\
	{param ? (type *)(((intptr_t)(&param)) +(int)(((intptr_t)param))) : 0;})
	


