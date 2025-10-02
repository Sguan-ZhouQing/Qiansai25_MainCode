/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-02 17:08:18
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 20:26:10
 * @FilePath: \demo_STM32H750code\Hardware\CAN_own.c
 * @Description: CAN总线收发来自STM32H750的数据，实现俩单片机的通信
 * @Key_GPIO: PD0 -> CAN1_RX; PD1 -> CAN1_TX;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "CAN_own.h"
#include "OLED.h"

extern FDCAN_HandleTypeDef hfdcan1;
uint8_t RxData[8];
FDCAN_RxHeaderTypeDef RxHeader;

/**
 * @description: 发送函数CAN通信（发送）
 * @param {uint8_t} news
 * @return {*}
 */
void CAN_SendNews(uint8_t news)
{
    FDCAN_TxHeaderTypeDef TxHeader;
    // uint8_t TxData[1] = {0xA2};

    TxHeader.Identifier = 0x321;  // 发送ID，与F4接收过滤器匹配
    TxHeader.IdType = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = FDCAN_DLC_BYTES_1;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, &news);
}

/**
 * @description: 接收函数初始化（接收）
 * @return {*}
 */
void CAN_ReceptionInit(void)
{
    // 初始化后添加接收过滤器配置
    FDCAN_FilterTypeDef sFilterConfig;
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = 0x000;  // 接收所有标准ID
    sFilterConfig.FilterID2 = 0x000;  // 掩码
    HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig);

    // 启动FDCAN
    HAL_FDCAN_Start(&hfdcan1);

    // 激活FIFO接收
    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
}


/**
 * @description: 接收回调函数
 * @param {FDCAN_HandleTypeDef} *hfdcan
 * @param {uint32_t} RxFifo0ITs
 * @return {*}
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {
    // 接收消息
    if(HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK)
    {
      // 检查接收到的数据是否为0xA1
      if(RxData[0] == 0xA1)
      {
        // 执行相应操作
        // 例如: HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        OLED_ShowString(0,25,"Init Yeah!",OLED_8X16);
        OLED_Update();
        CAN_SendNews(0xC1);
      }
    }
  }
}
