#include "sys_uart.h"
#include "sys_gpio.h"
#include "sys_types.h"
#include <string.h>
#include <stdio.h>
#include "sys_io.h"

#define vaArg(list, type) ((type *)(list += sizeof(type)))[-1]
#define vaStart(list, param) list = (INT8 *)((INT)&param + sizeof(param))

/*
串口初始化
*/
void Sys_Uart0_Init(unsigned int Baudrate)
{
	u32_t addr;
	u32_t val, Div, APBclk;

	APBclk = 408000000 / 4;
	Div = APBclk / Baudrate / 16;

	//  配置输出脚/
	GPIO_Congif(GPIOE, GPIO_Pin_0, GPIO_Mode_101, GPIO_PuPd_NOPULL);
	GPIO_Congif(GPIOE, GPIO_Pin_1, GPIO_Mode_101, GPIO_PuPd_NOPULL);

	// Open the clock gate for uart0 时钟开//
	addr = 0x01c20068;
	val = read32(addr);
	val |= 1 << 20;
	write32(addr, val);

	// Deassert uart0 reset 复位//
	addr = 0x01c202d0;
	val = read32(addr);
	val |= 1 << 20;
	write32(addr, val);

	// Config uart0 to 115200-8-1-0//
	addr = 0x01c25000;
	write32(addr + 0x04, 0x0);
	write32(addr + 0x08, 0xf7);
	write32(addr + 0x10, 0x0);

	val = read32(addr + 0x0c); // DLAB为1
	val |= (1 << 7);
	write32(addr + 0x0c, val);

	write32(addr + 0x00, Div & 0xff); //写波特率 APB时钟=408/4=102M{波特率=时钟/(16*除数)}
	write32(addr + 0x04, (Div >> 8) & 0xff);

	val = read32(addr + 0x0c); // DLAB为0
	val &= ~(1 << 7);
	write32(addr + 0x0c, val);

	val = read32(addr + 0x0c); //写控制位
	val &= ~0x1f;
	val |= (0x3 << 0) | (0 << 2) | (0x0 << 3);
	write32(addr + 0x0c, val);
}

/*
串口输出
*/
void Sys_Uart_Putc(char c)
{
	u32_t addr = 0x01c25000;
	while ((read32(addr + 0x7c) & (0x1 << 1)) == 0)
		;
	write32(addr + 0x0, c);
}

VOID sysPutString(INT8 *string)
{
	while (*string != '\0')
	{
		Sys_Uart_Putc(*string);
		string++;
	}
}

static VOID sysPutRepChar(INT8 c, INT count)
{
	while (count--)
		Sys_Uart_Putc(c);
}

static VOID sysPutStringReverse(INT8 *s, INT index)
{
	while ((index--) > 0)
		Sys_Uart_Putc(s[index]);
}

static VOID sysPutNumber(INT value, INT radix, INT width, INT8 fill)
{
	INT8 buffer[40];
	INT bi = 0;
	UINT32 uvalue;
	UINT16 digit;
	UINT16 left = FALSE;
	UINT16 negative = FALSE;

	if (fill == 0)
		fill = ' ';

	if (width < 0)
	{
		width = -width;
		left = TRUE;
	}

	if (width < 0 || width > 80)
		width = 0;

	if (radix < 0)
	{
		radix = -radix;
		if (value < 0)
		{
			negative = TRUE;
			value = -value;
		}
	}

	uvalue = value;

	do
	{
		if (radix != 16)
		{
			digit = uvalue % radix;
			uvalue = uvalue / radix;
		}
		else
		{
			digit = uvalue & 0xf;
			uvalue = uvalue >> 4;
		}
		buffer[bi] = digit + ((digit <= 9) ? '0' : ('A' - 10));
		bi++;

		if (uvalue != 0)
		{
			if ((radix == 10) && ((bi == 3) || (bi == 7) || (bi == 11) | (bi == 15)))
			{
				buffer[bi++] = ',';
			}
		}
	} while (uvalue != 0);

	if (negative)
	{
		buffer[bi] = '-';
		bi += 1;
	}

	if (width <= bi)
		sysPutStringReverse(buffer, bi);
	else
	{
		width -= bi;
		if (!left)
			sysPutRepChar(fill, width);
		sysPutStringReverse(buffer, bi);
		if (left)
			sysPutRepChar(fill, width);
	}
}

static INT8 *FormatItem(INT8 *f, INT a)
{
	INT8 c;
	INT fieldwidth = 0;
	INT leftjust = FALSE;
	INT radix = 0;
	INT8 fill = ' ';

	if (*f == '0')
		fill = '0';

	while ((c = *f++) != 0)
	{
		if (c >= '0' && c <= '9')
		{
			fieldwidth = (fieldwidth * 10) + (c - '0');
		}
		else
			switch (c)
			{
			case '\000':
				return (--f);
			case '%':
				Sys_Uart_Putc('%');
				return (f);
			case '-':
				leftjust = TRUE;
				break;
			case 'c':
			{
				if (leftjust)
					Sys_Uart_Putc(a & 0x7f);

				if (fieldwidth > 0)
					sysPutRepChar(fill, fieldwidth - 1);

				if (!leftjust)
					Sys_Uart_Putc(a & 0x7f);
				return (f);
			}
			case 's':
			{
				if (leftjust)
					sysPutString((PINT8)a);

				if (fieldwidth > strlen((PINT8)a))
					sysPutRepChar(fill, fieldwidth - strlen((PINT8)a));

				if (!leftjust)
					sysPutString((PINT8)a);
				return (f);
			}
			case 'd':
			case 'i':
				radix = -10;
				break;
			case 'u':
				radix = 10;
				break;
			case 'x':
				radix = 16;
				break;
			case 'X':
				radix = 16;
				break;
			case 'o':
				radix = 8;
				break;
			default:
				radix = 3;
				break; /* unknown switch! */
			}
		if (radix)
			break;
	}

	if (leftjust)
		fieldwidth = -fieldwidth;

	sysPutNumber(a, radix, fieldwidth, fill);
	// open_LCD_LED();
	return (f);
}

void sysprintf(char *pcStr, ...)
{
	char *argP;
	vaStart(argP, pcStr); /* point at the end of the format string */
	while (*pcStr)
	{ /* this works because args are all ints */
		if (*pcStr == '%')
			pcStr = FormatItem(pcStr + 1, vaArg(argP, INT));
		else
			Sys_Uart_Putc(*pcStr++);
	}
}
