/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-27 15:28:47
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-27 15:32:45
 * @FilePath: \demo_STM32F407code\Hardware\Analysis.c
 * @Description: 计算usart串口数据包(校验)
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Analysis.h"


/**
 * @description: 校验和计算：所有字节（除校验和外）的和，取低8位
 * @param {uint8_t} *data
 * @param {uint8_t} length
 * @return {*}
 */
uint8_t calculate_checksum(const uint8_t *data, uint8_t length) {
    uint8_t sum = 0;
    for (uint8_t i = 0; i < length - 1; i++) {  // 不算校验和本身
        sum += data[i];
    }
    return sum;
}


/**
 * @description: 解析数据包
 * @param {uint8_t} *packet
 * @param {uint8_t} *data_out
 * @return {*}
 */
int parse_packet(const uint8_t *packet, uint8_t *data_out) {
    // 1. 检查包头
    if (packet[0] != 0xAA) {
        printf("Error: Invalid packet header (0x%02X)\n", packet[0]);
        return -1;
    }
    // 2. 获取数据包长度（包括包头、长度、数据和校验和）
    uint8_t packet_length = packet[1];
    if (packet_length < 3) {  // 至少包头(1) + 长度(1) + 校验和(1)
        printf("Error: Packet too short (length=0x%02X)\n", packet_length);
        return -2;
    }
    // 3. 计算校验和是否匹配
    uint8_t expected_checksum = calculate_checksum(packet, packet_length);
    uint8_t received_checksum = packet[packet_length - 1];
    if (expected_checksum != received_checksum) {
        printf("Error: Checksum mismatch (expected=0x%02X, received=0x%02X)\n",
               expected_checksum, received_checksum);
        return -3;
    }
    // 4. 提取有效数据（去掉包头、长度和校验和）
    uint8_t data_length = packet_length - 3;  // 数据长度 = 总长度 - 包头(1) - 长度(1) - 校验和(1)
    for (uint8_t i = 0; i < data_length; i++) {
        data_out[i] = packet[2 + i];  // 数据从第3字节开始
    }

    return data_length;  // 返回实际数据长度
}

