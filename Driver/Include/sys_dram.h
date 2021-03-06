#ifndef __F1C100S_REG_DRAM_H__
#define __F1C100S_REG_DRAM_H__

#define F1C100S_DRAM_BASE (0x01c01000)

#define DRAM_SCONR (0x00)
#define DRAM_STMG0R (0x04)
#define DRAM_STMG1R (0x08)
#define DRAM_SCTLR (0x0c)
#define DRAM_SREFR (0x10)
#define DRAM_SEXTMR (0x14)
#define DRAM_DDLYR (0x24)
#define DRAM_DADRR (0x28)
#define DRAM_DVALR (0x2c)
#define DRAM_DRPTR0 (0x30)
#define DRAM_DRPTR1 (0x34)
#define DRAM_DRPTR2 (0x38)
#define DRAM_DRPTR3 (0x3c)
#define DRAM_SEFR (0x40)
#define DRAM_MAE (0x44)
#define DRAM_ASPR (0x48)
#define DRAM_SDLY0 (0x4C)
#define DRAM_SDLY1 (0x50)
#define DRAM_SDLY2 (0x54)
#define DRAM_MCR0 (0x100)
#define DRAM_MCR1 (0x104)
#define DRAM_MCR2 (0x108)
#define DRAM_MCR3 (0x10c)
#define DRAM_MCR4 (0x110)
#define DRAM_MCR5 (0x114)
#define DRAM_MCR6 (0x118)
#define DRAM_MCR7 (0x11c)
#define DRAM_MCR8 (0x120)
#define DRAM_MCR9 (0x124)
#define DRAM_MCR10 (0x128)
#define DRAM_MCR11 (0x12c)
#define DRAM_BWCR (0x140)

void sys_dram_init(void);

#endif /* __F1C100S_REG_DRAM_H__ */
