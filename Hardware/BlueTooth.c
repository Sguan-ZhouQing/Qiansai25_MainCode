/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:21:14
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-27 17:24:54
 * @FilePath: \demo_STM32F407code\Hardware\BlueTooth.c
 * @Description: 蓝牙通信，可以实现与上位机互联
 * @Key_GPIO: PC6 -> USART6_TX; PC7 -> USART6_RX;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "BlueTooth.h"

extern UART_HandleTypeDef huart6;
extern uint8_t BlueTooth_readBuffer[10];

void BlueTooth_Init(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart6, BlueTooth_readBuffer, sizeof(BlueTooth_readBuffer));
    __HAL_DMA_DISABLE_IT(huart6.hdmarx, DMA_IT_HT);
}

