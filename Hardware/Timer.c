/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-08 19:26:48
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-28 21:00:32
 * @FilePath: \demo_STM32G431code\Hardware\Timer.c
 * @Description: TIM定时中断统一管理函数;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Timer.h"


/**
 * @description: TIM2中断回调函数，10us的定时器定时中断;
 * @param {TIM_HandleTypeDef*} htim
 * @return {*}
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) 
{
    if (htim->Instance == TIM1)  // 检查是否是 TIM1 触发的中断
    {
        Stepper_Tick();
    }
    else if (htim->Instance == TIM2)
    {
        Key_Tick();
    }
}



