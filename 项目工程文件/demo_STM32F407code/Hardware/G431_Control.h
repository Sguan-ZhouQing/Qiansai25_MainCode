/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-08 11:50:16
 * @FilePath: \demo_STM32F407code\Hardware\G431_Control.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#ifndef __G431_CONTROL_H
#define __G431_CONTROL_H

#include "gpio.h"
#include "usart.h"
#include "nRF24L01.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "StressSensing.h"

typedef struct {
    uint8_t cmd_received;      // 是否收到0xB0命令
    uint32_t check_start_time; // 开始检查的时间戳(ms)
    uint8_t response_sent;     // 是否已发送响应
} RoboticControl_State_t;

void G431_StopPower(void);
void G431_StartPower(void);
void G431_TogglePower(void);
void G431_Init(void);
void G431_SendCommand(uint8_t *command);
void G431_RoboticControl_Tick(void);


#endif // G431_CONTROL_H
