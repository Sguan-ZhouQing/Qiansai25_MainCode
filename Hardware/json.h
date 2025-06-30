/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-26 15:32:04
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-05-26 15:39:57
 * @FilePath: \demo_STM32F407code\Hardware\json.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#ifndef __JSON_H
#define __JSON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>  // 添加此头文件以使用 uint8_t
#include "cJSON.h"

void update_global_variable(const char *key, cJSON *value);
void parse_mqtt_data(const char *json_str);

#endif // JSON_H
