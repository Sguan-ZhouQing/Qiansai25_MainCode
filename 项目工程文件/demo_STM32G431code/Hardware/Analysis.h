/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-27 15:28:47
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-27 15:34:20
 * @FilePath: \demo_STM32F407code\Hardware\Analysis.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#ifndef __ANALYSIS_H
#define __ANALYSIS_H

#include <stdint.h>
#include <stdio.h>

uint8_t calculate_checksum(const uint8_t *data, uint8_t length);
int parse_packet(const uint8_t *packet, uint8_t *data_out);


#endif // ANALYSIS_H
