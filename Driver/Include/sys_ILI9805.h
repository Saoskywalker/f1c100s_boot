#ifndef _SYS_ILI9805_H
#define _SYS_ILI9805_H

#include "sys_types.h"

#define LCD_Width 480
#define LCD_Height 800

#define LCD_RESET0 GPIO_RESET(GPIOD, GPIO_Pin_0)
#define LCD_RESET1 GPIO_SET(GPIOD, GPIO_Pin_0)
#define LCD_CS0 GPIO_RESET(GPIOD, GPIO_Pin_21)
#define LCD_CS1 GPIO_SET(GPIOD, GPIO_Pin_21)
#define LCD_WR0 GPIO_RESET(GPIOD, GPIO_Pin_18)
#define LCD_WR1 GPIO_SET(GPIOD, GPIO_Pin_18)
#define LCD_RD0 GPIO_RESET(GPIOD, GPIO_Pin_20)
#define LCD_RD1 GPIO_SET(GPIOD, GPIO_Pin_20)
#define LCD_RS0 GPIO_RESET(GPIOD, GPIO_Pin_19)
#define LCD_RS1 GPIO_SET(GPIOD, GPIO_Pin_19)

//方向控制
#define L2R_U2D 0 //从左到右,从上到下
#define L2R_D2U 1 //从左到右,从下到上
#define R2L_U2D 2 //从右到左,从上到下
#define R2L_D2U 3 //从右到左,从下到上
#define U2D_L2R 4 //从上到下,从左到右
#define U2D_R2L 5 //从上到下,从右到左
#define D2U_L2R 6 //从下到上,从左到右
#define D2U_R2L 7 //从下到上,从右到左

void LCD_ILI9805_Init(void);
void LCD_Clear(u16 color);

#endif
