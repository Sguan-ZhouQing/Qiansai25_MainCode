/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-10 04:13:56
 * @FilePath: \demo_STM32F407code\Hardware\Infrared_Sensor.c
 * @Description: 红外对射传感器Control函数简要封装
 * @Key_GPIO: PD11 -> GPIO_Input;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Infrared_Sensor.h"
static bool Infrared_Temp = false;
uint8_t Infrared;


/**
 * @description: (单独使用)返回红外对射传感器数据
 * @return {*}
 */
bool Infrared_ReadPin(void)
{
    GPIO_PinState temp = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_11);
    if (temp == GPIO_PIN_SET)
    {
        return true;
    }
    return false;
}


/**
 * @description: (配合定时器使用)返回红外对射传感器数据
 * @return {*}
 */
bool Infrared_GetPin(void)
{
    if (Infrared_Temp == true)
    {
        Infrared_Temp = false;
        return true;
    }
    return false;
}

/**
 * @description: (配合定时器使用)实时更新红外对射传感器值
 * @return {*}
 */
void Infrared_Tick(void)
{
    GPIO_PinState temp = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_11);
    if (temp == GPIO_PIN_SET)
    {
        Infrared = 1;
    }
    else
    {
        Infrared = 0;
    }
}


