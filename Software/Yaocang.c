/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-28 00:52:07
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-04 15:05:18
 * @FilePath: \demo_STM32F407code\Software\Yaocang.c
 * @Description: 药仓的应用层（用于任务的逻辑处理）
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Yaocang.h"

extern uint8_t command;


/**
 * @description: (串口控制)药仓用于上传压力传感器数值的测试函数
 * @return {*}
 */
void Yaocang_Stress_UartTest(void)
{
    float temp = Pressure_GetValue_Newton();
    float count = Pressure_GetRawValue();
    float sensor_data[] = {temp, 5.0f,count};
    UART_SendFloats(sensor_data,3,2);
}


/**
 * @description: (按键控制)测试药仓的IOT功能
 * @return {*}
 */
void Yaocang_ESP_KeyTest(void)
{
    uint8_t count = Key_GetNum();
    if (count == 1)
    {
        uint8_t my_data[6] = {0,1,0,0,1,0};
        ESP_SendMQTTArray("warehouse_left",my_data,6);
        HAL_Delay(5000);
        ESP_SendMQTTVar("humi",41.4f);
        HAL_Delay(5000);
        ESP_SendMQTTBool("power_flag",false);
        HAL_Delay(5000);
        ESP_SendMQTTInt("device_ID",346464);
    }
    if (count == 2)
    {
        Buzzer_Control();
    }
    if (count == 3 && command == 7)
    {
        Buzzer_Control();
    }
}


