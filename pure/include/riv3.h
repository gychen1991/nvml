#include <stdint.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <stdio.h>

uint64_t RIV_REGION;

uint64_t base;

#define l1 15
#define l2 18
#define l3 31
#define l4 28
#define l3_l4() l3-l4
#define RIV void
#define generateMask(num)((num >= (sizeof(uint64_t) * 8) ? -1 : (1ULL <<  num) - 1ULL))
#define l1_mask     0x0000400000000000 //0xfffe000000000000
#define l2_mask     0x0001ffff80000000
#define l3_mask     0x000000007fffffff
#define l3__l4      0x0000400000000000
#define l3__l2      0x0001fffffffc0000
uint64_t newvalue = l3__l4;



#define add_RIV_entry(base, RID)({\
  uint64_t nvbase = 0ULL;\
  uint64_t ridAddr = 0ULL;\
  int *rid = 0;\
  nvbase = ((uint64_t)base)&l2_mask;\
  ridAddr = ((nvbase>>l3_l4())|l1_mask);\
  rid = ridAddr;\
  rid = mmap((uint64_t *)(rid), sizeof(rid), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED|MAP_FIXED , 0, 0);\
  *rid = RID;\
  add_NVbase_entry(nvbase, RID);\
})


#define add_NVbase_entry(nvbase, RID)({ \
  uint64_t baseAddr = 0ULL;\
  uint64_t *nvbase_p = 0ULL;\
  baseAddr = (RID << l2)|l3__l4;\
  nvbase_p = mmap((uint64_t *)(baseAddr), sizeof(baseAddr), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED|MAP_FIXED , 0, 0);\
  printf("%p %p %p\n",(void *)nvbase_p, (void *)baseAddr, (void *)RID);\
  *nvbase_p = (uint64_t)nvbase;\
})
 
//baseAddr = ((uint64_t)RID << l2)|l3__l4|l1_mask;
#define getBase(RID) (\
	{\
		uint64_t baseAddr = 0ULL;\
		baseAddr = (RID << l2) | l3__l4;\
		*((uint64_t *)baseAddr);\
	})
#define getBaseFromRIV(riv) (\
	{\
		uint64_t baseAddr = 0ULL;\
		baseAddr = (riv >>(l3- l2) & l3__l2) | newvalue;\
		*(uint64_t *)baseAddr;\
	})
		

#define RIV_MALLOC(o, type) (\
	{void *p = malloc(o); \
	 uint64_t newp = 0ULL;\
	 if((uint64_t)p>(1ULL<<l3)) {printf("error\n"); exit(0);}\
	 newp = ((uint64_t)p - getBase(RIV_REGION)) | ((uint64_t)RIV_REGION)<<l3; \
	 (RIV *)newp; \
	})

#define RIV_OFFSET(riv) ({\
(riv&l3_mask);})

#define RIV_RID(riv) (((riv)&(~l3_mask))>>(l3))

static __attribute__ ((noinline)) void * 
direct_riv(void *value) 
{ 
  uint64_t actual_value = ((uintptr_t)value);//&0x1fffffffffffffffULL; 
  uint64_t pool_id = actual_value;// >> l3;//RIV_RID(actual_value); 
  uint64_t offset = RIV_OFFSET(actual_value); 
  /* 
  if (offset == 0 || pool_id == 0) 
    return NULL; 
  */
  return (void *)(getBaseFromRIV(pool_id)+ offset); 
} 
#define R_RIV(o,type) (\
	{\
	(type *)direct_riv(o);\
	})

