/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-02 17:08:18
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 19:48:52
 * @FilePath: \demo_STM32F407code\Hardware\CAN_own.c
 * @Description: CAN总线收发来自STM32H750的数据，实现俩单片机的通信
 * @Key_GPIO: PD0 -> CAN1_RX; PD1 -> CAN1_TX;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "CAN_own.h"
#include "Buzzer.h"

extern CAN_HandleTypeDef hcan1;
uint8_t F4RxData[8];
CAN_RxHeaderTypeDef F4RxHeader;

/**
 * @description: CAN总线通信（发送信号）
 * @param {uint8_t} message
 * @return {*}
 */
void CAN_SendMessage(uint8_t message)
{
    CAN_TxHeaderTypeDef F4TxHeader;
    // uint8_t F4TxData[1] = {0xA1};
    uint32_t F4TxMailbox;
    F4TxHeader.StdId = 0x123;  // 标准ID，与H7接收过滤器匹配
    F4TxHeader.ExtId = 0x00;
    F4TxHeader.RTR = CAN_RTR_DATA;
    F4TxHeader.IDE = CAN_ID_STD;
    F4TxHeader.DLC = 1;
    F4TxHeader.TransmitGlobalTime = DISABLE;
    if(HAL_CAN_AddTxMessage(&hcan1, &F4TxHeader, &message, &F4TxMailbox) != HAL_OK) {
        // Error_Handler();
    }
}

/**
 * @description: CAN总线接收消息（接收初始化）
 * @return {*}
 */
void CAN_ReceiveInit(void)
{
    // 初始化后配置接收过滤器(USER CODE BEGIN 2)
    CAN_FilterTypeDef F4FilterConfig;

    F4FilterConfig.FilterBank = 0;
    F4FilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    F4FilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    F4FilterConfig.FilterIdHigh = 0x0000;  // 匹配H7发送的ID 0x321
    F4FilterConfig.FilterIdLow = 0x0000;
    F4FilterConfig.FilterMaskIdHigh = 0x0000;
    F4FilterConfig.FilterMaskIdLow = 0x0000;
    F4FilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    F4FilterConfig.FilterActivation = ENABLE;
    F4FilterConfig.SlaveStartFilterBank = 14;
    if(HAL_CAN_ConfigFilter(&hcan1, &F4FilterConfig) != HAL_OK) {
        // Error_Handler();
    }
    // 启动CAN并激活通知(USER CODE BEGIN 2)
    if(HAL_CAN_Start(&hcan1) != HAL_OK) {
        // Error_Handler();
    }
    if(HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK) {
        // Error_Handler();
    }
}


/**
 * @description: 接收回调函数（CAN1）
 * @param {CAN_HandleTypeDef} *hcan
 * @return {*}
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  if(HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &F4RxHeader, F4RxData) == HAL_OK)
  {
    // 检查接收到的数据是否为0xA2
    if(F4RxData[0] == 0xC1)
    {
      // 执行相应操作，如切换LED
      // HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
      Buzzer_Own(300);
    }
  }
}
