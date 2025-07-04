#ifndef __ROBOTIC_ARM_H
#define __ROBOTIC_ARM_H

#include "stm32g4xx_hal.h"
#include "pca9685.h"
#include "Key.h"
#include "Stepper_motor.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 舵机轴定义
typedef enum {
    B_AXIS = 0,    // B轴
    L_AXIS = 1,    // L轴
    U_AXIS = 12,   // U轴
    R_AXIS = 4,    // R轴
    X_CLAWS = 5    // X夹爪
} ServoAxis;

// 初始角度定义
#define B_INIT_ANGLE 135.0f
#define L_INIT_ANGLE 200.0f
#define U_INIT_ANGLE 200.0f
#define R_INIT_ANGLE 230.0f
#define X_INIT_ANGLE 240.0f
#define LU_R_Angle 158.0f

void Robotic_Init(void);
void Robotic_KeyTest(void);
void Robotic_UartTest(void);
void Robotic_KeyControl(void);

#endif // ROBOTIC_ARM_H
