#include <sys_mmu.h>
#include "arm32.h"
#include "sys_io.h"

//测试只用一级映射更快

// Cache写机制
#define F1C100S_CACHE_WRITE_BACK 3	  //写回模式
#define F1C100S_CACHE_WRITE_THROUGH 2 //写通模式
//
#define SZ_1M (unsigned int)(1024 * 1024)
#define SZ_2G (unsigned int)(2048 * SZ_1M)

__align(0x4000) unsigned int mmuTable[4096];
/*
页表初始化
virt 虚拟地址
phys 物理地址
size 大小
type 写机制类型
*/
static void map_l1_section(uint32_t *ttb, virtual_addr_t virt, physical_addr_t phys, physical_size_t size, unsigned char type)
{
	physical_size_t i;

	virt >>= 20;
	phys >>= 20;
	size >>= 20;
	type &= 0x3;

	for (i = size; i > 0; i--, virt++, phys++)
		ttb[virt] = (phys << 20) | (0x3 << 10) | (0x0 << 5) | (0x1 << 4) | (type << 2) | (0x2 << 0); //位5-全部域0
}

/*
mmu初始化
*/
void sys_mmu_init(void)
{
	unsigned int *ttb;
	ttb = mmuTable;
	//	map_l1_section(ttb, 0x00000000, 0x00000000, SZ_2G, 0);
	map_l1_section(ttb, 0x80000000, 0x80000000, SZ_2G, 0);
	//	map_l1_section(ttb, 0x80000000, 0x80000000, SZ_1M * 32, F1C100S_CACHE_WRITE_BACK);
	map_l1_section(ttb, 0x80000000, 0x80000000, SZ_1M * 32, F1C100S_CACHE_WRITE_THROUGH);

	arm32_ttb_set((uint32_t)(ttb)); //写入页表地址
	arm32_tlb_invalidate();
	arm32_domain_set(0x1); //设置域不进行权限检查
	arm32_mmu_enable();
	arm32_icache_enable();
	arm32_dcache_enable();
}
