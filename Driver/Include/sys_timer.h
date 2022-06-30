#ifndef _SYS_TIMER_H
#define _SYS_TIMER_H

#include "sys_types.h"

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

#define F1C100S_TIMER_BASE (0x01C20C00)
#define TIMER_IRQ_EN F1C100S_TIMER_BASE + (0x00)
#define TIMER_IRQ_STA F1C100S_TIMER_BASE + (0x04)
#define TIMER_CTRL(x) F1C100S_TIMER_BASE + ((x + 1) * 0x10 + 0x00)
#define TIMER_INTV(x) F1C100S_TIMER_BASE + ((x + 1) * 0x10 + 0x04)
#define TIMER_CUR(x) F1C100S_TIMER_BASE + ((x + 1) * 0x10 + 0x08)

void Timer_Demo(void);
void Tdelay_ms(int ms);
void Timer_enable(u8 timer);
void Timer_disable(u8 timer);
void Timer_Init(u8 timer, u32_t time_us, u8 IRQ_EN);
unsigned int Read_time_ms(void);

#endif
