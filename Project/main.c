#include "sys_uart.h"
#include "sys_clock.h"
#include "sys_dram.h"
#include "sys_gpio.h"
#include "sys_delay.h"
#include "sys_lcd.h"
#include <string.h>
#include <stdio.h>
#include <sys-spi-flash.h>
#include <TMPA900.H>
#include "main.h"

void (*fw_func)(void);
__align(4) unsigned short *BT;
/*————————————————————————————————————————————————————————————————
	开背光
*/
void open_LCD_LED(void)
{
	GPIO_Congif(GPIOE, GPIO_Pin_5, GPIO_Mode_OUT, GPIO_PuPd_NOPULL);
	GPIO_SET(GPIOE, GPIO_Pin_5);
	GPIO_Congif(GPIOE, GPIO_Pin_6, GPIO_Mode_OUT, GPIO_PuPd_NOPULL);
	GPIO_SET(GPIOE, GPIO_Pin_6);
}
/*————————————————————————————————————————————————————————————————
	关背光
*/
void close_LCD_LED(void)
{
	GPIO_RESET(GPIOE, GPIO_Pin_5);
	GPIO_RESET(GPIOE, GPIO_Pin_6);
}
/*————————————————————————————————————————————————————————————————
//打开LCD电源
*/
void open_LCD_Power(void)
{
	GPIO_Congif(GPIOE, GPIO_Pin_11, GPIO_Mode_OUT, GPIO_PuPd_NOPULL);
	GPIO_SET(GPIOE, GPIO_Pin_11);
}
/*————————————————————————————————————————————————————————————————
画16位 位图
*/
void _Draw16bmp(int x, int y, int w, int h, short *p)
{
	int Xn, Yn;
	unsigned short *T_BT;
	T_BT = BT;
	for (Yn = 0; Yn < h; Yn++)
	{
		T_BT = BT + (y + Yn) * LCD_W + x;
		for (Xn = 0; Xn < w; Xn++)
			*(T_BT + Xn) = *p++; //连续写入图片数据
	}
}

/*---------------------------------------------------
AHB 时钟为204MHZ(LCD)
APB 时钟为102MHZ(UART)
---- main
---- main
----------------------------------------------------*/
int main(void)
{
	int i;
	unsigned int spiaddr = 0;
	unsigned int LOGO_F = 0;
	char file_h[32];
	unsigned int file_size = 0;
	unsigned int BMP_W = 0, BMP_H = 0, BMP_bit = 0;

	sys_dram_init(); //初始化必须在时钟初始化以前，延时原因
	sys_clock_init();
	sys_spi_flash_init();
	Sys_Uart0_Init(115200);
	sysprintf("\r\n\r\n\r\n");
	sysprintf("Copyright MTF by Aysi-E. All Rights Reserved\r\n");
	sysprintf("773917760@qq.com\r\n\r\n");
	//读文件头
	sys_spi_flash_read(spireadAddr, file_h, 32);
	//判断类型
	for (i = 0; i < 8; i++)
		if (file_h[4 + i] != BOOTBMP[i])
			break;
	if (i == 8) // LOGO BMP
	{
		sysprintf("Read Logo bmp...\r\n");
		//读文件大小
		file_size = file_h[0x13] << 24 | file_h[0x12] << 16 | file_h[0x11] << 8 | file_h[0x10];
		file_size = file_size - 32 - 8;
		sysprintf("Bmp at Flash 0x%08x\r\n", spireadAddr);
		sysprintf("File Size %d\r\n", file_size);
		//读,色位宽,BMP宽,高
		BMP_bit = file_h[0x19];
		BMP_W = file_h[0x1b] << 8 | file_h[0x1a];
		BMP_H = file_h[0x1d] << 8 | file_h[0x1c];
		sysprintf("BMP-bit=%d\r\n", BMP_bit);
		sysprintf("BMP-W=%d\r\n", BMP_W);
		sysprintf("BMP-H=%d\r\n", BMP_H);
		//读入BMP文件
		sysprintf("Read bmp to RAM 0x%08x \r\n", bmpAddr);
		sys_spi_flash_read(spireadAddr + 32 + 8, (unsigned int *)bmpAddr, file_size);
		//初始化LCD
		open_LCD_Power();
		BT = (unsigned short *)(LCDbuffAddr);
		i = LCD_W * LCD_H;
		for (; i >= 0; i--)
			*(((unsigned short *)LCDbuffAddr) + i) = BLACK;
		Sys_LCD_Init(LCD_W, LCD_H, (unsigned int *)LCDbuffAddr, (unsigned int *)LCDbuffAddr);
		//图片内存写入显存
		_Draw16bmp((LCD_W - BMP_W) / 2, (LCD_H - BMP_H) / 2, BMP_W, BMP_H, (short *)bmpAddr);
		//开LCD背光
		delay_ms(300);
		sysprintf("Show logo...\r\n");
		open_LCD_LED();
		//
		LOGO_F = 1;
	}

	if (LOGO_F == 1)
	{
		spiaddr = spireadAddr + spiReadExecPo;
		sys_spi_flash_read(spiaddr, file_h, 32); //读文件头
	}
	for (i = 0; i < 8; i++)
		if (file_h[4 + i] != BOOTEXE[i])
			break;
	if (i == 8) //可执行文件
	{
		sysprintf("\r\nRead EXEC...\r\n");
		//读文件大小
		file_size = file_h[0x13] << 24 | file_h[0x12] << 16 | file_h[0x11] << 8 | file_h[0x10];
		file_size = file_size - 32;
		sysprintf("Exec at Flash 0x%08x\r\n", spiaddr);
		sysprintf("File Size %d \r\n", file_size);
		//读文件
		sysprintf("Read exec to RAM 0x%08x \r\n", executeAddr);
		sys_spi_flash_read(spiaddr + 32, (unsigned int *)(executeAddr), file_size);
		//延时
		delay_ms(2000);
		//执行
		sysprintf("EXEC 0X80000000...\r\n");
		delay_ms(20);
		fw_func = (void (*)(void))(executeAddr);
		fw_func();
	}

	sysprintf("OUT...\r\n");
	while (1)
	{
	}
}
