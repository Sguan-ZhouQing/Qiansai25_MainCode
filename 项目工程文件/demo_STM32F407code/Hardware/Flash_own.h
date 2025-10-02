#ifndef __FLASH_OWN_H
#define __FLASH_OWN_H

#include "stm32f4xx_hal.h"

void Flash_Write_Variable(uint32_t data);
uint32_t Flash_Read_Variable(void);


#endif // FLASH_OWN_H
