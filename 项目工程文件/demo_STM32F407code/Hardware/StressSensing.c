/*
 * @Author: 星必尘Sguan
 * @Date: 2025-04-16 16:32:32
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-10 03:35:20
 * @FilePath: \demo_STM32F407code\Hardware\StressSensing.c
 * @Description: HAL库使用DMA的ADC采样读取压力传感器的压力值;
 * @Key_GPIO: PA4 -> ADC1 Line4;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "StressSensing.h"
#include <string.h>

extern ADC_HandleTypeDef hadc1;  // CubeMX生成的ADC句柄
static uint32_t adcRawValue = 0; // 存储原始ADC值

/**
 * @description: （循环模式的启动方式）初始化ADC和DMA
 * @return {*}
 */
void StressSensing_Init(void) {
    // 校准ADC（提高精度）
    // HAL_ADCEx_Calibration_Start(&hadc1);
    
    // 启动DMA传输（循环模式）
    HAL_ADC_Start_DMA(&hadc1, &adcRawValue, 1);
}

// 获取压力值（牛顿）
float Pressure_GetValue_Newton(void) {
    // 转换为牛顿：adcRawValue / 4095 * 5.0
    return 5.0f - (float)(adcRawValue * PRESSURE_RANGE_NEWTON / ADC_MAX_VALUE);
}

// 获取原始ADC值（0-4095）
uint32_t Pressure_GetRawValue(void) {
    return adcRawValue;
}

/**
 * @description: （单次模式的启动方式）初始化ADC
 * @return {*}
 */
float Stress_GetValue(void)
{
    uint16_t adc_value = 0;
    // 启动ADC
    HAL_ADC_Start(&hadc1);
    // 等待转换完成
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
    adc_value = HAL_ADC_GetValue(&hadc1);
    }
    // 停止ADC
    HAL_ADC_Stop(&hadc1);
    return 5.0f - (float)(adc_value * PRESSURE_RANGE_NEWTON / ADC_MAX_VALUE);
}

