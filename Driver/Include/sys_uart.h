#ifndef _SYS_UART_H
#define _SYS_UART_H

void Sys_Uart0_Init(unsigned int Baudrate);
void Sys_Uart_Putc(char c);
void sysprintf(char *pcStr, ...);

#endif
