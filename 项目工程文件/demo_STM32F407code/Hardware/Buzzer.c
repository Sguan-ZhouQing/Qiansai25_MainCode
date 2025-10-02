/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:21:14
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 20:32:39
 * @FilePath: \demo_STM32F407code\Hardware\Buzzer.c
 * @Description: 蜂鸣器的声音信号的控制控制;
 * @Key_GPIO: PD15 -> GPIO_Output;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Buzzer.h"
#include "cmsis_os.h"

#define Beep_time 300    //设置单次蜂鸣时间

/**
 * @description: 蜂鸣器鸣叫开启函数，鸣叫时间为Beep_time
 * @return {*}
 */
void Buzzer_Control(void)
{
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
		// HAL_Delay(Beep_time);
    osDelay(Beep_time); //仅限在FreeRTOS系统中使用
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
}


/**
 * @description: 蜂鸣器自定义鸣叫函数；
 * @param {uint32_t} time
 * @return {*}
 */
void Buzzer_Own(uint32_t time)
{
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
		HAL_Delay(time);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
}

