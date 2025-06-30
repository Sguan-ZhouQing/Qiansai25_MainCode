#ifndef __G431_CONTROL_H
#define __G431_CONTROL_H

#include "gpio.h"
#include "usart.h"
#include "nRF24L01.h"
#include <stdint.h>
#include <stdio.h>

void G431_StopPower(void);
void G431_StartPower(void);
void G431_Init(void);
void G431_SendCommand(uint8_t *command);


#endif // G431_CONTROL_H
