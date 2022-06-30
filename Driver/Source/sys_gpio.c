#include "sys_gpio.h"
#include "sys_io.h"
#include "reg_ccu.h"

/*
GPIO 初始化
*/
void GPIO_Congif(
	GPIO_TypeDef *GPIOx,	   // GPIO
	unsigned int GPIO_Pin,	   // Pin?
	GPIOMode_TypeDef GPIOMode, //??????
	GPIOPuPd_TypeDef GPIO_PuPd //???
)
{
	GPIOx->CFG[GPIO_Pin / 8] &= ~(0xF << (GPIO_Pin % 8 * 4)); //????4?

	if (GPIOMode == GPIO_Mode_IN)
		GPIOx->CFG[GPIO_Pin / 8] &= ~(0x1 << (GPIO_Pin % 8 * 4)); //??
	else if (GPIOMode == GPIO_Mode_OUT)
		GPIOx->CFG[GPIO_Pin / 8] |= (0x1 << (GPIO_Pin % 8 * 4)); //??
	else
		GPIOx->CFG[GPIO_Pin / 8] |= (GPIOMode << (GPIO_Pin % 8 * 4)); //??
}

/*
GPIO输出1
*/
void GPIO_SET(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
)
{
	GPIOx->DAT |= (0x1 << GPIO_Pin);
}
/*
GPIO输出0
*/
void GPIO_RESET(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
)
{
	GPIOx->DAT &= ~(0x1 << GPIO_Pin);
}
/*
GPIO读 返回0-1
*/
u8 GPIO_READ(
	GPIO_TypeDef *GPIOx,  // GPIO
	unsigned int GPIO_Pin // Pin?
)
{
	if (GPIOx->DAT & ((1) << GPIO_Pin))
		return 1;
	else
		return 0;
}
