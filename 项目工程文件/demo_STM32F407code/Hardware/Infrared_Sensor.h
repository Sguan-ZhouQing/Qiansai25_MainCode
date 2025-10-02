#ifndef __INFRARED_SENSOR_H
#define __INFRARED_SENSOR_H

#include "gpio.h"
#include <stdbool.h>

bool Infrared_ReadPin(void);
bool Infrared_GetPin(void);
void Infrared_Tick(void);


#endif // INFRARED_SENSOR_H
