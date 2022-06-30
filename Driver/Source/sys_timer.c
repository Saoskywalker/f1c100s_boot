#include "sys_timer.h"
#include "sys_interrupt.h"
#include "sys_uart.h"
#include "sys_gpio.h"
#include "sys_delay.h"
#include "sys_io.h"

/*
定时器初始化
timer=TIMER0,TIMER1,TIMER2【f1c100s有三个定时器】
IRQ_EN=中断使能
time_us=中断时间 us
*/
void Timer_Init(u8 timer, u32_t time_us, u8 IRQ_EN)
{
	int val = 0;
	write32(TIMER_CTRL(timer), 0);
	// Timer 模式 0连续 1单
	val = 0;
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) | ((val) << 7));
	// Timer 分频
	val = 0;
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) | ((val) << 4));
	// Timer 时钟源
	val = 1; // 24Mhz
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) | ((val) << 2));
	// Timer 重装计数值
	val = 1; //=1重装计数值
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) | ((val) << 1));

	// Timer 计数值
	val = 24 * time_us;
	write32(TIMER_INTV(timer), val);

	//使能中断
	if (IRQ_EN == 1)
	{
		write32(TIMER_IRQ_EN, read32(TIMER_IRQ_EN) | (1 << timer));
	}
}
/*
定时器开
*/
void Timer_enable(u8 timer)
{
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) | ((1) << 0));
}
/*
定时器关
*/
void Timer_disable(u8 timer)
{
	write32(TIMER_CTRL(timer), read32(TIMER_CTRL(timer)) & (~((1) << 0)));
}
/*
定时器中断
*/
unsigned int sys_count_timer0 = 0;
void TIMER0_ISR(void)
{
	//清中断
	write32(TIMER_IRQ_STA, read32(TIMER_IRQ_STA) | (1 << TIMER0));
	//
	sys_count_timer0++;
	if (sys_count_timer0 >= 0xffffffff)
		sys_count_timer0 = 0;
}
void TIMER1_ISR(void)
{
	//清中断
	write32(TIMER_IRQ_STA, read32(TIMER_IRQ_STA) | (1 << TIMER1));
	sys_count_timer0++;
	if (sys_count_timer0 >= 0xffffffff)
		sys_count_timer0 = 0;
}
void TIMER2_ISR(void)
{
	//清中断
	write32(TIMER_IRQ_STA, read32(TIMER_IRQ_STA) | (1 << TIMER2));
	//
}
/*
读定时器计数
*/
unsigned int Read_time_ms(void)
{
	return sys_count_timer0;
}
/*
延时函数(定时器)
*/
void Tdelay_ms(int ms)
{
	unsigned int time = 0;
	time = sys_count_timer0;
	while ((sys_count_timer0 - time) < ms)
		;
}
/*
定时器测试
*/
void Timer_Demo(void)
{
	Timer_Init(TIMER1, 1000, 1);
	IRQ_Init(IRQ_LEVEL_1, IRQ_Timer1, TIMER1_ISR, 3);
	Timer_enable(TIMER1);
	sysSetLocalInterrupt(ENABLE_IRQ); //开IRQ中断
	//	while(1)
	//	{
	//		sysprintf("TIMER %d \r\n",sys_count_timer0);
	//		delay_ms(1000);
	//	}
}
