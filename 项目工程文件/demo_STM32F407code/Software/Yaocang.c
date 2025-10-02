/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-28 00:52:07
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 21:59:07
 * @FilePath: \demo_STM32F407code\Software\Yaocang.c
 * @Description: 药仓的应用层（用于任务的逻辑处理）
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Yaocang.h"

//其他函数包含
#include "G431_Control.h"
#include "cmsis_os.h"
#include "freertos.h"
#include "Asppro.h"
#include "CAN_own.h"

//声明使用到的外部变量
extern UART_HandleTypeDef huart1;
extern uint8_t command;
extern osThreadId mianTask_ThreeHandle;
//电控板对应机械臂操作的指令集（用于轨迹控制）
static uint8_t Command_Buffer[8] = {0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8};
//用于按键切换的全局变量
uint8_t Yaocang_Count;
//用于电机控制的LVGL全局变量
uint8_t Take_Medicine_Value;
uint8_t Take_Medicine_Flag;
//屏幕背光的LVGL全局变量(0-100)
uint16_t current_brightness_value = 100;
//屏幕存药输入文本框全局变量
char input_text[32];
//屏幕存药输入药仓号
uint8_t Save_Medicine_id;
uint8_t Save_Medicine_Count;
uint8_t Save_Medicine_Flag;


/**
 * @description: (串口控制)药仓用于上传压力传感器数值的测试函数
 * @return {*}
 */
void Moment_Stress_UartTest(void)
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
void Moment_ESP_KeyTest(void)
{
    uint8_t count = Key_GetNum();
    if (count == 1)
    {
        ESP_SendMQTTVar("temp",3.14f);
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


/**
 * @description: 按键控制，手动触发轨迹路线
 * @return {*}
 */
void Moment_ButtonTest(void)
{
    uint8_t temp = Key_GetNum();
    uint8_t single_byte1 = 0xA1;
    uint8_t single_byte2 = 0xA3;
    uint8_t single_byte3 = 0xB0;
    switch (temp)
    {
    case 1:
        HAL_UART_Transmit(&huart1, &single_byte1, 1, HAL_MAX_DELAY);
        break;
    case 2:
        HAL_UART_Transmit(&huart1, &single_byte2, 1, HAL_MAX_DELAY);
        break;
    case 3:
        HAL_UART_Transmit(&huart1, &single_byte3, 1, HAL_MAX_DELAY);
        break;
    
    default:
        break;
    }
}


/**
 * @description: （私域）配合IOT控制电控板的函数
 * @param {uint8_t} *buffer
 * @return {*}
 */
static void Command_SendArray(const uint8_t *buffer)
{
    HAL_UART_Transmit(&huart1, buffer, 1, HAL_MAX_DELAY);
    command = 0;
    // ESP_SendMQTTInt("command",command);
}


static void Command_SendUint(const char *str)
{
    if (Save_Medicine_Count == 1)
    {
        uint8_t input_temp;
        Save_Medicine_Count = 0;
        if (strcmp(input_text, "gpw") == 0) {
            input_temp = gpw;
        } 
        else if (strcmp(input_text, "shlkfy") == 0) {
            input_temp = shlkfy;
        }
        else if (strcmp(input_text, "yszxtlqp") == 0) {
            input_temp = yszxtlqp;
        }
        else if (strcmp(input_text, "sjgml") == 0) {
            input_temp = sjgml;
        }
        else if (strcmp(input_text, "axzp") == 0) {
            input_temp = axzp;
        }
        else if (strcmp(input_text, "fgmlp") == 0) {
            input_temp = fgmlp;
        }
        else if (strcmp(input_text, "pzzkkl") == 0) {
            input_temp = pzzkkl;
        }
        else if (strcmp(input_text, "hxzqkfy") == 0) {
            input_temp = hxzqkfy;
        }
        else if (strcmp(input_text, "zhhy") == 0) {
            input_temp = zhhy;
        }
        else if (strcmp(input_text, "ynbyckt") == 0) {
            input_temp = ynbyckt;
        }
        else if (strcmp(input_text, "ymckl") == 0) {
            input_temp = ymckl;
        }
        ESP_SendMQTTInt(str,input_temp);
    }
}

/**
 * @description: （广域）在电控板控制任务函数中反复调用
 * @return {*}
 */
void Yaocang_Command_Tick(void) {
    if (Take_Medicine_Flag == 1) {
        command = Take_Medicine_Value + 13;
        Take_Medicine_Flag = 0;
    }
    if (Save_Medicine_Flag == 1) {
        command = Save_Medicine_id + 1;
        Save_Medicine_Flag = 0;
    }
    switch (command) {
    case 2:
        Command_SendArray(&Command_Buffer[0]);
        Command_SendUint("yaocang_2");
        break;
    case 4:
        Command_SendArray(&Command_Buffer[2]);
        Command_SendUint("yaocang_4");
        break;
    case 7:
        Command_SendArray(&Command_Buffer[1]);
        Command_SendUint("yaocang_7");
        break;
    case 9:
        Command_SendArray(&Command_Buffer[3]);
        Command_SendUint("yaocang_9");
        break;
    case 14:
        Command_SendArray(&Command_Buffer[4]);
        break;
    case 16:
        Command_SendArray(&Command_Buffer[6]);
        break;
    case 19:
        Command_SendArray(&Command_Buffer[5]);
        break;
    case 21:
        Command_SendArray(&Command_Buffer[7]);
        break;
    
    default:
        break;
    }
}

/**
 * @description: （广域）按键控制核心板函数
 * @return {*}
 */
void Yaocang_Button_Tick(void) {
    uint8_t own = Key_GetNum();
    if (own == 1) {
        Yaocang_Count++;
        Buzzer_Control();
        if (Yaocang_Count == 5) {
            Yaocang_Count = 0;
        } 
    }
    if (own == 2) {
        switch (Yaocang_Count)
        {
        case 0:
            G431_TogglePower(); //1.按键控制G431电源开断
            break;
        case 1:
            HAL_UART_Transmit(&huart1, &Command_Buffer[0], 1, HAL_MAX_DELAY);
            break;
        case 2:
            ESP_Init();         //2.按键初始化esp模块
            osThreadResume(mianTask_ThreeHandle);
            break;
        case 3:
            // CAN_SendMessage(0xA1);
            uint8_t own_byte = 0x01;
            HAL_UART_Transmit(&huart3, &own_byte, 1, HAL_MAX_DELAY);
            break;
        case 4:
            Buzzer_Control();
            break;
        
        default:
            break;
        }
    }
}




