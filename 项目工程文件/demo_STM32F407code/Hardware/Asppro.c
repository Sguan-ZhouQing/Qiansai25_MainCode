/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:23:40
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 15:09:56
 * @FilePath: \demo_STM32F407code\Hardware\Asppro.c
 * @Description: 使用串口通信，与语音模块功能交互
 * @Key_GPIO: PA0 -> UART4_TX; PA1 -> UART4_RX; PC3 -> GPIO_Input;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Asppro.h"
#include "json.h"

extern UART_HandleTypeDef huart4;
extern uint8_t Asppro_readBuffer[10];
extern uint8_t command;

/**
 * @description: 开启串口4的DMA接收功能
 * @return {*}
 */
void Asppro_Init(void)
{
    MX_UART4_Init();
    HAL_UARTEx_ReceiveToIdle_DMA(&huart4, Asppro_readBuffer, sizeof(Asppro_readBuffer));
    __HAL_DMA_DISABLE_IT(huart4.hdmarx, DMA_IT_HT);
}


/**
 * @description: 串口指令收发
 * @return {*}
 */
void Asppro_Update(void) {
    // 检查接收缓冲区是否有有效命令
    for(uint16_t i = 0; i < sizeof(Asppro_readBuffer); i++) {
        if(Asppro_readBuffer[i] == '\0' || Asppro_readBuffer[i] == '\r' || Asppro_readBuffer[i] == '\n') {
            break;  // 遇到结束符停止检查
        }
        // 检查是否是有效的命令字节
        if(Asppro_readBuffer[i] >= 0x01 && Asppro_readBuffer[i] <= 0x08) {
            uint8_t command_temp = Asppro_readBuffer[i];    // 根据命令执行相应的轨迹函数
            switch(command_temp) {
                case 0x01:
                    command = 2;
                    break;
                case 0x02:
                    command = 7;
                    break;
                case 0x03:
                    command = 4;
                    break;
                case 0x04:
                    command = 9;
                    break;
                case 0x05:
                    command = 14;
                    break;
                case 0x06:
                    command = 19;
                    break;
                case 0x07:
                    command = 16;
                    break;
                case 0x08:
                    command = 21;
                    break;
                default:
                    break;
            }
            Asppro_readBuffer[i] = 0;  // 清除已处理的命令
            break;  // 一次只处理一个命令，避免重复执行
        }
    }
    HAL_UARTEx_ReceiveToIdle_DMA(&huart4, Asppro_readBuffer, sizeof(Asppro_readBuffer));
    __HAL_DMA_DISABLE_IT(huart4.hdmarx, DMA_IT_HT);
}

