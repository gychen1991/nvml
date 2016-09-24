#include <stdint.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <stdio.h>

int RIV_REGION;
uint64_t base;

#define l1 15
#define l2 18
#define l3 31
#define l4 28
#define l3_l4() l3-l4
#define RIV void
#define generateMask(num)((num >= (sizeof(unsigned long long) * 8) ? -1 : (1ULL <<  num) - 1ULL))

#define add_RIV_entry(base, RID)({unsigned long long l2_mask = 0ULL;\
  unsigned long long l1_mask = 0ULL;\
  unsigned long long nvbase = 0ULL;\
  unsigned long long ridAddr = 0ULL;\
  int *rid = 0;\
  l2_mask = generateMask(l2); \
  unsigned long long shifted = (l2_mask << l3);\
  nvbase = ((unsigned long long)base)&shifted;\
  l1_mask = (1ULL << 46);\
  ridAddr = ((nvbase>>l3_l4())|l1_mask);\
  rid = ridAddr;\
  rid = mmap((unsigned long long *)(rid), sizeof(rid), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED|MAP_FIXED , 0, 0);\
  *rid = RID;\
  add_NVbase_entry(nvbase, RID);\
})


#define add_NVbase_entry(nvbase, RID)({ unsigned long long l1_mask = 1ULL << 46;\
  unsigned long long l3__l4 = 1ULL << (l4+l2);\
  unsigned long long baseAddr = 0ULL;\
  unsigned long long *nvbase_p = 0ULL;\
  baseAddr = ((unsigned long long)RID << l2)|l3__l4|l1_mask;\
  nvbase_p = mmap((unsigned long long *)(baseAddr), sizeof(baseAddr), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED|MAP_FIXED , 0, 0);\
  *nvbase_p = (unsigned long long)nvbase;\
})
 

#define getBase(RID) (\
	{\
		unsigned long long l1_mask = 0ULL;\
		l1_mask = (1ULL << 46);\
		unsigned long long l3__l4 = 1ULL << (l4+l2);\
		unsigned long long baseAddr = 0ULL;\
		unsigned long long *nvbase_p = 0ULL;\
		baseAddr = ((unsigned long long)RID << l2)|l3__l4|l1_mask;\
		*((uint64_t *)baseAddr);\
	})
		

#define RIV_MALLOC(o, type) (\
	{void *p = malloc(o); \
	 unsigned long long newp = 0ULL;\
	 if((uint64_t)p>(1ULL<<l3)) {printf("error\n"); exit(0);}\
	 newp = ((uint64_t)p - getBase(RIV_REGION)) | ((unsigned long long)RIV_REGION)<<l3; \
	 (RIV *)newp; \
	})

#define RIV_OFFSET(riv) ({unsigned long long riv_1 = (uintptr_t)riv;\
((riv_1)&generateMask(l3));})

#define RIV_RID(riv) ((((uintptr_t)riv)&(~generateMask(l3)))>>(l3))

static inline void * 
direct_riv(void *value) 
{ 
  uint64_t actual_value = ((uintptr_t)value);//&0x1fffffffffffffffULL; 
  uint64_t pool_id = RIV_RID(actual_value); 
  uint64_t offset = RIV_OFFSET(actual_value); 
  /* 
  if (offset == 0 || pool_id == 0) 
    return NULL; 
  */
  return (void *)((uintptr_t)((getBase(pool_id)))+ offset); 
} 
#define R_RIV(o,type) (\
	{\
	(type *)direct_riv(o);\
	})

