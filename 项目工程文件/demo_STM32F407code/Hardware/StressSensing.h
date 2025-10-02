#ifndef __STRESSSENSING_H
#define __STRESSSENSING_H

#include "stm32f4xx_hal.h"

// 压力传感器参数
#define PRESSURE_RANGE_NEWTON  5.0f  // 量程5牛顿
#define ADC_MAX_VALUE         4095   // 12位ADC最大值

// 初始化函数
void StressSensing_Init(void);

// 获取压力值（牛顿）
float Pressure_GetValue_Newton(void);

// 获取原始ADC值（0-4095）
uint32_t Pressure_GetRawValue(void);

//单次使用ADC采样函数
float Stress_GetValue(void);

#endif
