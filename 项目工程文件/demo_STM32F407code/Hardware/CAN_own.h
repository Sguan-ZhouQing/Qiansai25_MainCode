#ifndef __CAN_OWN_H
#define __CAN_OWN_H

#include "stm32f4xx_hal.h"

void CAN_SendMessage(uint8_t message);
void CAN_ReceiveInit(void);


#endif // CAN_OWN_H
