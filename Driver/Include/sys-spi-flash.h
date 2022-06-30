#ifndef _SYS_SPI_FLASH_H
#define _SYS_SPI_FLASH_H

void sys_spi_flash_read(int addr, void *buf, int count);
void sys_spi_flash_init(void);

#endif
