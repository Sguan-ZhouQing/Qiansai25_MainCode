/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-26 15:32:04
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-27 17:35:32
 * @FilePath: \demo_STM32F407code\Hardware\json.c
 * @Description: 实现json数据的接收和解析
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "json.h"

/**
 * @description: （提前创建）全局变量定义
 * @return {*}
 */
bool led = false;
uint8_t humi = 0;
uint8_t temp = 0;
float voltage = 0.0;


// 更新全局变量的通用函数
void update_global_variable(const char *key, cJSON *value) {
    if (value == NULL || key == NULL) return;

    if (strcmp(key, "led") == 0 && cJSON_IsBool(value)) {
        led = cJSON_IsTrue(value);
        // printf("LED updated: %s\n", led ? "ON" : "OFF");
    } 
    else if (strcmp(key, "humi") == 0 && cJSON_IsNumber(value)) {
        humi = (uint8_t)cJSON_GetNumberValue(value);
        // printf("Humi updated: %d\n", humi);
    } 
    else if (strcmp(key, "temp") == 0 && cJSON_IsNumber(value)) {
        temp = (uint8_t)cJSON_GetNumberValue(value);
        // printf("Temp updated: %d\n", temp);
    }
    else if (strcmp(key, "voltage") == 0 && cJSON_IsNumber(value)) {
        voltage = (float)cJSON_GetNumberValue(value);
        // printf("Voltage updated: %.2f\n", voltage);
    }
    else {
        // printf("Unknown key or invalid type: %s\n", key);
    }
}

// 解析 MQTT 数据包
void parse_mqtt_data(const char *json_str) {
    cJSON *root = cJSON_Parse(json_str);
    if (root == NULL) {
        printf("JSON parse error!\n");
        return;
    }

    // 提取 "params" 对象
    cJSON *params = cJSON_GetObjectItem(root, "params");
    if (params == NULL) {
        printf("No 'params' field!\n");
        cJSON_Delete(root);
        return;
    }

    // 遍历 params 的所有键值对
    cJSON *item = NULL;
    cJSON_ArrayForEach(item, params) {
        update_global_variable(item->string, item);
    }

    cJSON_Delete(root);
}


/**
* @description: 解析json文件示例（使用方法）
* @return {*}
*/
// 1.模拟接收到的 MQTT 数据（包含 JSON 部分）
// const char *test_data = 
//     "+MQTTSUBRECV:0,\"$sys/device/update\",49,"
//     "{\"id\":\"1\",\"version\":\"1.0\",\"params\":{"
//     "\"led\":true,\"humi\":20,\"temp\":30,\"voltage\":3.3}}";

// 2.提取 JSON 部分（跳过 MQTT 头部）
// const char *json_start = strchr(test_data, '{');
// if (json_start == NULL) {
//     printf("No JSON data found!\n");
//     return -1;
// }
// 3.调用解析函数
// parse_mqtt_data(json_start);

