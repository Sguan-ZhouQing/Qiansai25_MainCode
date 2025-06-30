#ifndef __STEPPER_MOTOR_H
#define __STEPPER_MOTOR_H

#include "stm32g4xx_hal.h"

void StepperMotor_Control(uint8_t motor_ID,int32_t Velocity,int32_t Step);
//每次使用前提前开启
void Stepper_TurnON(void);
void Stepper_Tick(void);


#endif // __STEPPER_MOTOR_H
