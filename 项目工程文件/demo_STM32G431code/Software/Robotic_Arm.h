/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-28 21:15:48
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-10 13:10:44
 * @FilePath: \demo_STM32G431code\Software\Robotic_Arm.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#ifndef __ROBOTIC_ARM_H
#define __ROBOTIC_ARM_H

#include "stm32g4xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pca9685.h"
#include "Key.h"
#include "Stepper_motor.h"

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

//机械臂的控制函数
void Robotic_Init(void);
void Robotic_KeyTest(void);
void Robotic_UartTest(void);
void Robotic_KeyControl(void);
//主函数需反复调用的核心函数
void Robotic_UartControl_Tick(void);


#endif // ROBOTIC_ARM_H
