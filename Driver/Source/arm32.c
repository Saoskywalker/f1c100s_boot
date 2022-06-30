#include "arm32.h"

/*
读 cp15-c0
*/
uint32_t arm32_read_p15_c0(uint32_t ld)
{
	uint32_t value;
	if (ld == 0)
	{
		__asm
		{
			mrc p15, 0, value, c0, c0, 0
		}
	}
	else
	{
		__asm
		{
			mrc p15, 0, value, c0, c0, 1
		}
	}
	return value;
}
/*
读 cp15-c1
*/
uint32_t arm32_read_p15_c1(void)
{
	uint32_t value;
	__asm
	{
		mrc p15, 0, value, c1, c0, 0
	}
	return value;
}
/*
写 cp15-c1
*/
void arm32_write_p15_c1(uint32_t value)
{
	__asm
	{
		mcr p15, 0, value, c1, c0, 0
	}
}

void arm32_mmu_enable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value | (1 << 0));
}

void arm32_mmu_disable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value & ~(1 << 0));
}

void arm32_dcache_enable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value | (1 << 2));
}

void arm32_dcache_disable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value & ~(1 << 2));
}

void arm32_icache_enable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value | (1 << 12));
}

void arm32_icache_disable(void)
{
	uint32_t value = arm32_read_p15_c1();
	arm32_write_p15_c1(value & ~(1 << 12));
}
/*
写 cp15-c2 页表地址
*/
void arm32_ttb_set(uint32_t base)
{
	__asm
	{
		mcr p15, 0, base, c2, c0, 0
	}
}
/*
写 cp15-c3 域权限
*/
void arm32_domain_set(uint32_t domain)
{
	__asm
	{
		mcr p15, 0, domain, c3, c0, 0
	}
}
/*
写 cp15- tlb无效
*/
void arm32_tlb_invalidate(void)
{
	uint32_t value = 0;
	__asm
	{
		mcr p15, 0, value, c7, c10, 4

		mcr p15, 0, value, c8, c6, 0
		mcr p15, 0, value, c8, c5, 0
	}
}
