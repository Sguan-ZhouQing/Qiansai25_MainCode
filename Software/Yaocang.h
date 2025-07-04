#ifndef __YAOCANG_H
#define __YAOCANG_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "json.h"
#include "esp.h"
#include "printf.h"
#include "StressSensing.h"
#include "Key.h"
#include "Buzzer.h"



void Yaocang_Stress_UartTest(void);
void Yaocang_ESP_KeyTest(void);


#endif // YAOCANG_H
