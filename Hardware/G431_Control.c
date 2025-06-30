/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-30 16:59:48
 * @FilePath: \demo_STM32F407code\Hardware\G431_Control.c
 * @Description: 控制G431电控板工作的函数封装（无线通信or串口通信可选）
 * @Key_GPIO: PC2 -> GPIO_Output; PA9 -> USART1_TX; PA10 -> USART1_RX;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "G431_Control.h"

extern UART_HandleTypeDef huart1;
extern uint8_t G431_Buffer[2];

/**
 * @description: 定义一些药仓点位的宏定义
 * @funcation: 便于后期对电控板的直接控制
 * @return {*}
 */
#define TakeON_1A 0x00
#define TakeON_2A 0x01    //可用的药仓2A(存药)
#define TakeON_3A 0x02
#define TakeON_4A 0x03    //可用的药仓4A(存药)
#define TakeON_5A 0x04
#define TakeON_6A 0x05    
#define TakeON_1B 0x06    //可用的药仓1B(存药)
#define TakeON_2B 0x07
#define TakeON_3B 0x08    //可用的药仓3B(存药)
#define TakeON_4B 0x09
#define TakeON_5B 0x0A
#define TakeON_6B 0x0B

#define TakeOFF_1A 0x10
#define TakeOFF_2A 0x11    //可用的药仓2A(取药)
#define TakeOFF_3A 0x12
#define TakeOFF_4A 0x13    //可用的药仓4A(取药)
#define TakeOFF_5A 0x14
#define TakeOFF_6A 0x15    
#define TakeOFF_1B 0x16    //可用的药仓1B(取药)
#define TakeOFF_2B 0x17
#define TakeOFF_3B 0x18    //可用的药仓3B(取药)
#define TakeOFF_4B 0x19
#define TakeOFF_5B 0x1A
#define TakeOFF_6B 0x1B


/**
 * @description: 手动关闭G431电控板的电源，控制继电器开合(默认电源开启)
 * @return {*}
 */
void G431_StopPower(void)
{
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
}


/**
 * @description: 在使用了上述G431_StopPower(void)函数之后，重新开启电控板电源
 * @return {*}
 */
void G431_StartPower(void)
{
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
}


void G431_Init(void)
{
    // 重新启动接收，使用Ex函数，接收不定长数据
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, G431_Buffer, sizeof(G431_Buffer));
    // 关闭DMA传输过半中断（HAL库默认开启，但我们只需要接收完成中断）
    __HAL_DMA_DISABLE_IT(huart1.hdmarx, DMA_IT_HT);
}


void G431_SendCommand(uint8_t *command)
{
    HAL_UART_Transmit(&huart1,command,sizeof(command),500);
}

