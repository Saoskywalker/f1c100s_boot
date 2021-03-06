#ifndef _SYS_LCD_H
#define _SYS_LCD_H

#include "sys_types.h"

/*******************************常用色定义****************/
#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F //蓝
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40	 //棕色
#define BRRED 0XFC07	 //棕红色
#define GRAY 0X8430		 //灰色
#define DARKBLUE 0X01CF	 //深蓝色
#define LIGHTBLUE 0X7D7C //浅蓝色
#define GRAYBLUE 0X5458	 //灰蓝色
/********************************************************/

#define TCON_Base_Address (u32_t)0x01c0c000
#define CCU_Base_Address (u32_t)0x01C20000
#define CCU_TCON_CLK_REG (u32_t) CCU_Base_Address + 0x0118
#define CCU_BUS_SOFT_RST_REG0 (u32_t) CCU_Base_Address + 0x02C0
#define CCU_BUS_SOFT_RST_REG1 (u32_t) CCU_Base_Address + 0x02C4
#define CCU_BUS_CLK_GATING_REG0 (u32_t) CCU_Base_Address + 0x0060
#define CCU_BUS_CLK_GATING_REG1 (u32_t) CCU_Base_Address + 0x0064
#define DMA_Base_Address (u32_t)0x01C02000
#define DEBE_Base_Address (u32_t)0x01E60000
#define DEFE_Base_Address (u32_t)0x01E00000

#define C_BIT(addr, bit) write32(addr, read32(addr) & (~((u64_t)(1) << bit)))
#define S_BIT(addr, bit) write32(addr, read32(addr) | ((u64_t)(1) << bit))
#define C_Vlue(addr, bit, vlue) write32(addr, read32(addr) & (~((u64_t)(vlue) << bit)))
#define S_Vlue(addr, bit, vlue) write32(addr, read32(addr) | ((u64_t)(vlue) << bit))

struct fb_f1c100s_pdata_t
{
	virtual_addr_t virtdefe;
	virtual_addr_t virtdebe;
	virtual_addr_t virttcon;

	int mode;
	int width;
	int height;
	int pwidth;
	int pheight;
	int bits_per_pixel;
	int bytes_per_pixel;
	int index;
	void *vram[2];

	struct
	{
		int pixel_clock_hz;
		int h_front_porch;
		int h_back_porch;
		int h_sync_len;
		int v_front_porch;
		int v_back_porch;
		int v_sync_len;
		int h_sync_active;
		int v_sync_active;
		int den_active;
		int clk_active;
	} timing;
};

extern struct fb_f1c100s_pdata_t *lcd_pdat;

void Sys_LCD_Init(int width, int height, unsigned int *buff1, unsigned int *buff2);
void F1C100S_LCD_Init(int width, int height, unsigned int *buff1, unsigned int *buff2);

#endif
