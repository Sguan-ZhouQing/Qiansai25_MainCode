/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-30 15:06:03
 * @FilePath: \demo_STM32F407code\Hardware\HLK24G.c
 * @Description: 使用串口通信，实现与24G毫米波通信，获取人体距离药仓的距离;
 * @Key_GPIO: PD8 -> USART3_TX; PD9 -> UASRT3_RX; PD10 -> GPIO_Input;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "HLK24G.h"
#include <string.h>

static UART_HandleTypeDef *hlk_huart;
static uint8_t rx_buffer[64];
static HLK_Data_t current_data;

// 初始化模块
bool HLK24G_Init(UART_HandleTypeDef *huart) {
    hlk_huart = huart;
    // 设置默认波特率
    hlk_huart->Init.BaudRate = HLK24G_DEFAULT_BAUDRATE;
    if (HAL_UART_Init(hlk_huart) != HAL_OK) {
        return false;
    }
    return true;
}

// 发送命令到模块
// 修改后的发送命令函数
bool HLK24G_SendCommand(HLK_Command_t cmd, uint8_t *params, uint16_t param_len) {
    uint8_t tx_buffer[64];
    uint16_t frame_len = 0;
    
    // 构建帧头 (小端序) - 修改为直接使用字节数组
    const uint8_t cmd_header[] = {0xFD, 0xFC, 0xFB, 0xFA}; // 小端序
    memcpy(tx_buffer + frame_len, cmd_header, 4);
    frame_len += 4;
    
    // 数据长度 (2字节小端序)
    uint16_t data_len = 2 + param_len; // 命令字2字节 + 参数长度
    memcpy(tx_buffer + frame_len, &data_len, 2);
    frame_len += 2;
    
    // 命令字 (2字节小端序)
    memcpy(tx_buffer + frame_len, &cmd, 2);
    frame_len += 2;
    
    // 参数 (如果有)
    if (params != NULL && param_len > 0) {
        memcpy(tx_buffer + frame_len, params, param_len);
        frame_len += param_len;
    }
    
    // 帧尾 (小端序) - 修改为直接使用字节数组
    const uint8_t cmd_footer[] = {0x04, 0x03, 0x02, 0x01}; // 小端序
    memcpy(tx_buffer + frame_len, cmd_footer, 4);
    frame_len += 4;
    
    // 发送数据
    if (HAL_UART_Transmit(hlk_huart, tx_buffer, frame_len, HLK24G_UART_TIMEOUT) != HAL_OK) {
        return false;
    }
    
    return true;
}

// 接收并解析模块数据
bool HLK24G_ReceiveData(HLK_Data_t *data) {
    uint8_t header[4];
    uint16_t data_len;
    
    // 接收数据头
    if (HAL_UART_Receive(hlk_huart, header, 4, HLK24G_UART_TIMEOUT) != HAL_OK) {
        return false;
    }
    
    // 检查帧头 - 修改为直接比较字节数组
    const uint8_t data_header[] = {0xF4, 0xF3, 0xF2, 0xF1};
    if (memcmp(header, data_header, 4) != 0) {
        return false;
    }
    
    // 接收数据长度
    if (HAL_UART_Receive(hlk_huart, (uint8_t*)&data_len, 2, HLK24G_UART_TIMEOUT) != HAL_OK) {
        return false;
    }
    
    // 接收剩余数据 (帧头4字节 + 长度2字节已经接收)
    uint16_t remaining_len = data_len + 4; // 数据 + 帧尾4字节
    if (HAL_UART_Receive(hlk_huart, rx_buffer, remaining_len, HLK24G_UART_TIMEOUT) != HAL_OK) {
        return false;
    }
    
    // 检查帧尾 - 修改为直接比较字节数组
    const uint8_t data_footer[] = {0xF8, 0xF7, 0xF6, 0xF5};
    if (memcmp(rx_buffer + data_len, data_footer, 4) != 0) {
        return false;
    }
    
    // 解析数据
    uint8_t data_type = rx_buffer[0];
    if (data_type == 0x02) { // 基础数据模式
        current_data.status = (HLK_TargetStatus_t)rx_buffer[2];
        memcpy(&current_data.moving_distance, rx_buffer + 3, 2);
        current_data.moving_energy = rx_buffer[5];
        memcpy(&current_data.static_distance, rx_buffer + 6, 2);
        current_data.static_energy = rx_buffer[8];
        memcpy(&current_data.detection_distance, rx_buffer + 9, 2);
    } 
    else if (data_type == 0x01) { // 工程模式
        // 解析基础数据部分 (与上面相同)
        current_data.status = (HLK_TargetStatus_t)rx_buffer[2];
        memcpy(&current_data.moving_distance, rx_buffer + 3, 2);
        current_data.moving_energy = rx_buffer[5];
        memcpy(&current_data.static_distance, rx_buffer + 6, 2);
        current_data.static_energy = rx_buffer[8];
        memcpy(&current_data.detection_distance, rx_buffer + 9, 2);
        
        // 解析工程模式特有数据
        uint8_t offset = 11; // 基础数据结束位置
        uint8_t max_moving_gate = rx_buffer[offset];
        uint8_t max_static_gate = rx_buffer[offset + 1];
        offset += 2;
        
        // 跳过距离门能量值 (2*N字节)
        offset += max_moving_gate + max_static_gate;
        
        // 获取光敏值和OUT状态
        current_data.light_sensor = rx_buffer[offset];
        current_data.out_state = (rx_buffer[offset + 1] == 0x01);
    }
    
    if (data != NULL) {
        memcpy(data, &current_data, sizeof(HLK_Data_t));
    }
    
    return true;
}

// 使能配置模式
bool HLK24G_EnableConfig(void) {
    uint8_t param = 0x01;
    return HLK24G_SendCommand(HLK_CMD_ENABLE_CONFIG, &param, 1);
}

// 结束配置模式
bool HLK24G_EndConfig(void) {
    return HLK24G_SendCommand(HLK_CMD_END_CONFIG, NULL, 0);
}

// 读取模块参数
bool HLK24G_ReadParameters(void) {
    return HLK24G_SendCommand(HLK_CMD_READ_PARAM, NULL, 0);
}

// 使能工程模式
bool HLK24G_EnableEngineeringMode(void) {
    return HLK24G_SendCommand(HLK_CMD_ENABLE_ENG_MODE, NULL, 0);
}

// 关闭工程模式
bool HLK24G_DisableEngineeringMode(void) {
    return HLK24G_SendCommand(HLK_CMD_DISABLE_ENG_MODE, NULL, 0);
}

// 设置灵敏度
bool HLK24G_SetSensitivity(uint8_t distance_gate, uint8_t moving_sens, uint8_t static_sens) {
    uint8_t params[12];
    
    // 距离门设置 (0xFFFF表示所有距离门)
    uint16_t gate = (distance_gate == 0xFF) ? 0xFFFF : distance_gate;
    memcpy(params, &gate, 2);
    
    // 运动灵敏度
    uint32_t moving_val = moving_sens;
    memcpy(params + 4, &moving_val, 4);
    
    // 静止灵敏度
    uint32_t static_val = static_sens;
    memcpy(params + 8, &static_val, 4);
    
    return HLK24G_SendCommand(HLK_CMD_SET_SENSITIVITY, params, 12);
}

// 读取固件版本
bool HLK24G_ReadFirmwareVersion(uint16_t *fw_type, uint16_t *major, uint32_t *minor) {
    if (!HLK24G_SendCommand(HLK_CMD_READ_FW_VERSION, NULL, 0)) {
        return false;
    }
    
    // 等待并解析ACK响应
    // 这里需要实现ACK接收和解析逻辑
    // 实际实现中需要根据ACK帧格式解析版本信息
    
    return true;
}

