#ifndef _ARM32_H
#define _ARM32_H

#include <stdint.h>

uint32_t arm32_read_p15_c1(void);
void arm32_write_p15_c1(uint32_t value);
void arm32_mmu_enable(void);
void arm32_mmu_disable(void);
void arm32_dcache_enable(void);
void arm32_dcache_disable(void);
void arm32_icache_enable(void);
void arm32_icache_disable(void);
void arm32_ttb_set(uint32_t base);
void arm32_domain_set(uint32_t domain);
void arm32_tlb_invalidate(void);
uint32_t arm32_read_p15_c0(uint32_t ld);

#endif
