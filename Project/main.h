#ifndef _MAIN_H
#define _MAIN_H

//配置LCD
//#define LCD_TYPE_RGB43_480_272
// #define LCD_TYPE_Vga_1024_768
#define LCD_TYPE_RGB43_800_480

//-------------------------------------------
#ifdef LCD_TYPE_RGB43_480_272
#define LCD_W (unsigned int)480
#define LCD_H (unsigned int)272
#endif
//
////-------------------------------------------
#ifdef LCD_TYPE_Vga_1024_768
#define LCD_W (unsigned int)1024
#define LCD_H (unsigned int)768
#endif
//-------------------------------------------
//
////-------------------------------------------
#ifdef LCD_TYPE_RGB43_800_480
#define LCD_W (unsigned int)800
#define LCD_H (unsigned int)480
#endif
////-------------------------------------------

#define BOOTBMP "eGON.BMP"
#define BOOTEXE "eGON.EXE"
#define executeAddr 0x80000000 // RAM 程序执行地址
#define bmpAddr 0x81000000	   // RAM 16M处 Logo bmp 存储地址
#define LCDbuffAddr 0x81B00000 // RAM 24M显存地址
#define spireadAddr 0x6000	   // FLASH 24k位置 没有LOGO则为程序地址
#define spiReadExecPo 0x8000   // FLASH 有Logo时读程序的偏移位置

#endif
