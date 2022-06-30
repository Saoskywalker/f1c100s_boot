#ifndef _SYS_WDOG_H
#define _SYS_WDOG_H

#include "sys_types.h"

//看门狗超时时间
#define TimeOut_0_5s 0 // 0.5秒
#define TimeOut_1s 1
#define TimeOut_2s 2
#define TimeOut_3s 3
#define TimeOut_4s 4
#define TimeOut_5s 5
#define TimeOut_6s 6
#define TimeOut_8s 7
#define TimeOut_10s 8
#define TimeOut_12s 9
#define TimeOut_14s 10
#define TimeOut_16s 11
//看门狗模式
#define WDOG_WholeSystemMode 1
#define WDOG_OnlyInterruprMode 2

void Wdog_Demo(void);
void Wdog_enable(void);
void Wdog_Restart(void);
void Wdog_Init(u32_t TimeOutUs, u8 Mode, u8 IRQ_EN);

#endif
