#ifndef __CAN_OWN_H
#define __CAN_OWN_H

#include "stm32h7xx_hal.h"

void CAN_SendNews(uint8_t news);
void CAN_ReceptionInit(void);

#endif // CAN_OWN_H
