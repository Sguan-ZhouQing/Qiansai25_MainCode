/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:23:40
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-30 14:58:13
 * @FilePath: \demo_STM32F407code\Hardware\Asppro.c
 * @Description: 使用串口通信，与语音模块功能交互
 * @Key_GPIO: PA0 -> UART4_TX; PA1 -> UART4_RX; PC3 -> GPIO_Input;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Asppro.h"

extern UART_HandleTypeDef huart4;
extern uint8_t Asppro_readBuffer[10];

void Asppro_Init(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart4, Asppro_readBuffer, sizeof(Asppro_readBuffer));
    __HAL_DMA_DISABLE_IT(huart4.hdmarx, DMA_IT_HT);
}

