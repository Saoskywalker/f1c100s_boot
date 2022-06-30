#ifndef _SYS__GPIO_H
#define _SYS__GPIO_H

#include "sys_types.h"

typedef struct
{
	__IO u32_t CFG[4];
	__IO u32_t DAT;
	__IO u32_t DRV[2];
	__IO u32_t PUL[2];
} GPIO_TypeDef;

typedef enum
{
	GPIO_Mode_IN = 0x0,	 /*!< GPIO Input Mode              */
	GPIO_Mode_OUT = 0x1, /*!< GPIO Output Mode             */
	GPIO_Mode_010 = 0x2,
	GPIO_Mode_011 = 0x3,
	GPIO_Mode_100 = 0x4,
	GPIO_Mode_101 = 0x5,
	GPIO_Mode_110 = 0x6,
	GPIO_Mode_111 = 0x7,
} GPIOMode_TypeDef;

typedef enum
{
	GPIO_PuPd_NOPULL = 0x00,
	GPIO_PuPd_UP = 0x01,
	GPIO_PuPd_DOWN = 0x02
} GPIOPuPd_TypeDef;
/** @defgroup GPIO_pins_define
 * @{
 */
#define GPIO_Pin_0 0
#define GPIO_Pin_1 1
#define GPIO_Pin_2 2
#define GPIO_Pin_3 3
#define GPIO_Pin_4 4
#define GPIO_Pin_5 5
#define GPIO_Pin_6 6
#define GPIO_Pin_7 7
#define GPIO_Pin_8 8
#define GPIO_Pin_9 9
#define GPIO_Pin_10 10
#define GPIO_Pin_11 11
#define GPIO_Pin_12 12
#define GPIO_Pin_13 13
#define GPIO_Pin_14 14
#define GPIO_Pin_15 15
#define GPIO_Pin_16 16
#define GPIO_Pin_17 17
#define GPIO_Pin_18 18
#define GPIO_Pin_19 19
#define GPIO_Pin_20 20
#define GPIO_Pin_21 21
#define GPIO_Pin_22 22
#define GPIO_Pin_23 23
#define GPIO_Pin_24 24
#define GPIO_Pin_25 25
#define GPIO_Pin_26 26
#define GPIO_Pin_27 27
#define GPIO_Pin_28 28
#define GPIO_Pin_29 29
#define GPIO_Pin_30 30
#define GPIO_Pin_31 31

#define GPIO_Pin_All 0xff

#define CPU_PORT_BASE 0x01C20800
#define GPIOA_BASE (CPU_PORT_BASE + 0x24 * 0)
#define GPIOB_BASE (CPU_PORT_BASE + 0x24 * 1)
#define GPIOC_BASE (CPU_PORT_BASE + 0x24 * 2)
#define GPIOD_BASE (CPU_PORT_BASE + 0x24 * 3)
#define GPIOE_BASE (CPU_PORT_BASE + 0x24 * 4)
#define GPIOF_BASE (CPU_PORT_BASE + 0x24 * 5)

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)

/*
GPIO 锟斤拷始锟斤拷
*/
void GPIO_Congif(
	GPIO_TypeDef *GPIOx,	   // GPIO
	unsigned int GPIO_Pin,	   // Pin?
	GPIOMode_TypeDef GPIOMode, //??????
	GPIOPuPd_TypeDef GPIO_PuPd //???
);
/*
GPIO锟斤拷锟�1
*/
void GPIO_SET(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
);
/*
GPIO锟斤拷锟�0
*/
void GPIO_RESET(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
);
/*
GPIO锟斤拷 锟斤拷锟斤拷0-1
*/
u8 GPIO_READ(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
);

#endif
