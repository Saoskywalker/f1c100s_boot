#ifndef _SYS_INTERRUPT_H
#define _SYS_INTERRUPT_H

#include "sys_types.h"

/*F1C100S中断源*/
typedef enum int_source_e
{
	IRQ_NMI = 0,
	IRQ_UART0 = 1,
	IRQ_UART1 = 2,
	IRQ_UART2 = 3,
	//
	IRQ_OWA = 5,
	IRQ_CIR = 6,
	IRQ_TWI0 = 7,
	IRQ_TWI1 = 8,
	IRQ_TWI2 = 9,
	IRQ_SPI0 = 10,
	IRQ_SPI1 = 11,
	//
	IRQ_Timer0 = 13,
	IRQ_Timer1 = 14,
	IRQ_Timer2 = 15,
	IRQ_Watchdog = 16,
	IRQ_RSB = 17,
	IRQ_DMA = 18,
	//
	IRQ_Touch_Panel = 20,
	IRQ_Aucio_Codec = 21,
	IRQ_KEYADC = 22,
	IRQ_SDC0 = 23,
	IRQ_SDC1 = 24,
	//
	IRQ_USG_OTG = 26,
	IRQ_TVD = 27,
	IRQ_TVE = 28,
	IRQ_TCON = 29,
	IRQ_DE_FE = 30,
	IRQ_DE_BE = 31,
	IRQ_CSI = 32,
	IRQ_DE_interlace = 33,
	IRQ_VE = 34,
	IRQ_DAUDIO = 35,
	//
	//
	IRQ_PIOD = 38,
	IRQ_PIOE = 39,
	IRQ_PIOF = 40,

} INT_SOURCE_E;

/* sysSetInterruptPriorityLevel() 的参数
   sysInstallISR() use */
#define FIQ_LEVEL_0 0
#define IRQ_LEVEL_1 1
#define IRQ_LEVEL_2 2
#define IRQ_LEVEL_3 3
#define IRQ_LEVEL_4 4
#define IRQ_LEVEL_5 5
#define IRQ_LEVEL_6 6
#define IRQ_LEVEL_7 7

/* The parameters for sysSetLocalInterrupt() use */
#define ENABLE_IRQ 0x7F
#define ENABLE_FIQ 0xBF
#define ENABLE_FIQ_IRQ 0x3F
#define DISABLE_IRQ 0x80
#define DISABLE_FIQ 0x40
#define DISABLE_FIQ_IRQ 0xC0

#define INTC_Base_Address (u32_t)0x01C20400
PVOID IRQ_Init(INT32 nIntTypeLevel, INT_SOURCE_E eIntNo, PVOID pvNewISR, CHAR Priority);
// VOID sysIrqHandler();
INT32 sysSetLocalInterrupt(INT32 nIntState);

#endif
