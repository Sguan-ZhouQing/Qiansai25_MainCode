/*
 * @Author: 星必尘Sguan
 * @Date: 2025-04-16 16:32:32
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-27 23:57:23
 * @FilePath: \demo_STM32F407code\Hardware\StressSensing.c
 * @Description: HAL库使用DMA的ADC采样读取压力传感器的压力值;
 * @Key_GPIO: PA4 -> ADC1 Line4;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "StressSensing.h"

extern ADC_HandleTypeDef hadc1;
static float Srress_Float = 5.0f;
static uint32_t adcBuffer[ADC_BUFFER_SIZE];
// float Stress_voltage;


/**
 * @description: DMA开启函数，要在cubeMX中开启DMA循环模式;
 * @return {*}
 */
void StressSensing_Init(void) 
{
    // 启动DMA前先清零缓冲区
    memset(adcBuffer, 0, sizeof(adcBuffer));
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcBuffer, 1); // 单通道改为长度1
}

/**
 * @description: ADC采样，读取模拟电压值变化大小;
 * @return {*}
 */
float Stress_GetValue(void)
{
    float temp;
    HAL_ADC_Start(&hadc1);
    if(HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        uint32_t raw_val = HAL_ADC_GetValue(&hadc1);
        temp = raw_val * Srress_Float / 4095.0f;
        return temp;
    }
    return 0.0f; // 错误处理
}


/**
 * @description: (ADC模拟电压)直接读取DMA缓冲区的最新值
 * @return {*}
 */
float Stress_GetValue_DMA(void) 
{
    // 单通道采样时，数据始终在adcBuffer[0]
    uint32_t raw_val = adcBuffer[0] & 0xFFF;  // 修正索引为0
    return raw_val * Srress_Float / 4095.0f;
}


/**
 * @description: DMA方式的ADC采样回调函数（可选用）
 * @param {ADC_HandleTypeDef*} hadc
 * @return {*}
 */
// void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) 
// {
//     if (hadc == &hadc1) {
//         uint32_t raw_val = adcBuffer[0] & 0xFFF;  // 获取最新值
//         Stress_voltage = raw_val * Srress_Float / 4095.0f;
//         // 在这里处理电压值（例如发送到串口或触发逻辑）
//     }
// }

