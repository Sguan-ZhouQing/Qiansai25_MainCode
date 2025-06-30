/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-08 10:53:12
 * @FilePath: \demo_STM32F407code\Hardware\Infrared_Sensor.c
 * @Description: 红外对射传感器Control函数简要封装
 * @Key_GPIO: PD11 -> GPIO_Input;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Infrared_Sensor.h"

/**
 * @description: 返回红外对射传感器数据
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


