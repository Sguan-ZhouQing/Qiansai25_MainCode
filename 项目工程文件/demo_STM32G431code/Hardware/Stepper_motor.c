/*
 * @Author: 星必尘Sguan
 * @Date: 2025-04-10 19:00:48
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-03 10:32:37
 * @FilePath: \demo_STM32G431code\Hardware\Stepper_motor.c
 * @Description: stm32使用HAL库驱动步进电机;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Stepper_motor.h"
#include <stdlib.h>  // 包含 abs() 函数的头文件
#include "tim.h"

/**
 * @description: 步进电机引脚宏定义
 * @return {*}
 */
#define MotorY_DIR GPIO_PIN_6
#define MotorY_DIR_Port GPIOA
#define MotorY_Speed GPIO_PIN_7
#define MotorY_Speed_Port GPIOA
#define MotorX_DIR GPIO_PIN_0
#define MotorX_DIR_Port GPIOB
#define MotorX_Speed GPIO_PIN_1
#define MotorX_Speed_Port GPIOB
#define Power_Switch_Pin GPIO_PIN_8
#define Power_Switch_Port GPIOA

/**
 * @description: 步进电机转动参数局部变量;
 * @return {*}
 */
static uint32_t tempY;
static uint32_t freqY_count;
static int32_t StepY_count;
static uint32_t tempX;
static uint32_t freqX_count;
static int32_t StepX_count;


/**
 * @description: 设置转速百分比,Step为NULL则不设置具体步数
 * @param {uint8_t} motor_ID    0为X轴，1为Y轴电机
 * @param {int32_t} Velocity    输入转动速度（90最佳）
 * @param {int32_t} Step        输入转动步长，0为一直旋转
 * @return {*}
 */
void StepperMotor_Control(uint8_t motor_ID,int32_t Velocity,int32_t Step)
{
    Stepper_TurnON();
    //需要设置10us定时中断一次
    __disable_irq();  // 关闭中断
    if (motor_ID == 0) {
        HAL_GPIO_WritePin(MotorX_DIR_Port, MotorX_DIR, (Velocity > 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        tempX = (uint32_t)abs(Velocity);
        if (Step != -1){
            StepX_count = (int32_t)Step;
        }
        else{
            StepX_count = -1;
        }
    }
    if (motor_ID == 1) {
        HAL_GPIO_WritePin(MotorY_DIR_Port, MotorY_DIR, (Velocity > 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        tempY = (uint32_t)abs(Velocity);
        if (Step != -1){
            StepY_count = (int32_t)Step;
        }
        else{
            StepY_count = -1;
        }
    }
    __enable_irq();   // 重新启用中断
}


//使用电机的时候开启步进电机模块电源
void Stepper_TurnON(void)
{
    HAL_GPIO_WritePin(Power_Switch_Port,Power_Switch_Pin,GPIO_PIN_SET);
}
//不使用步进电机时，关闭以省电
static void Stepper_TurnOFF(void)
{
    HAL_GPIO_WritePin(Power_Switch_Port,Power_Switch_Pin,GPIO_PIN_RESET);
}


/**
 * @description: 步进电机运转调节函数（每10us运行一次）
 * @return {*}
 */
void Stepper_Tick(void)
{
    if (tempX != 0) {
        if (StepX_count == -1) {
            freqX_count += 1;   // 在这里写你的定时任务代码
            if (freqX_count == 10000/tempX){
                HAL_GPIO_TogglePin(MotorX_Speed_Port,MotorX_Speed);
                freqX_count = 0;
            }
        }
        else if(StepX_count != 0) {
            freqX_count += 1;
            if (freqX_count == 10000/tempX){
                HAL_GPIO_TogglePin(MotorX_Speed_Port,MotorX_Speed);
                freqX_count = 0;
                StepX_count--;
            }
        }
        else if(StepX_count == 0) {
            tempX = 0;
            if (!StepY_count) {
                Stepper_TurnOFF();
            }
        }
    }
    if (tempY != 0) {
        if (StepY_count == -1) {
            freqY_count += 1;
            if (freqY_count == 10000/tempY){
                HAL_GPIO_TogglePin(MotorY_Speed_Port,MotorY_Speed);
                freqY_count = 0;
            }
        }
        else if(StepY_count != 0) {
            freqY_count += 1;
            if (freqY_count == 10000/tempY){
                HAL_GPIO_TogglePin(MotorY_Speed_Port,MotorY_Speed);
                freqY_count = 0;
                StepY_count--;
            }
        }
        else if(StepY_count == 0) {
            tempY = 0;
            if (!StepX_count) {
                Stepper_TurnOFF();
            }
        }
    }
}


/**
 * @description: TIM1的回调函数;
 * @param {TIM_HandleTypeDef} *htim
 * @return {*}
 */
// void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
// {
//     if (htim->Instance == TIM1 && temp != 0)  // 检查是否是 TIM1 触发的中断
//     {
//         Stepper_Tick();
//     }
// }

