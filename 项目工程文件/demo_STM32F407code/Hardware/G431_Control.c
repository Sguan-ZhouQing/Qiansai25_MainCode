/*
 * @Author: 星必尘Sguan
 * @Date: 2025-05-27 16:24:09
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-10 13:20:50
 * @FilePath: \demo_STM32F407code\Hardware\G431_Control.c
 * @Description: 控制G431电控板工作的函数封装（无线通信or串口通信可选）
 * @Key_GPIO: PC2 -> GPIO_Output; PA9 -> USART1_TX; PA10 -> USART1_RX;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "G431_Control.h"
#include "Infrared_Sensor.h"

extern UART_HandleTypeDef huart1;
extern uint8_t G431_Buffer[10];
extern uint8_t Infrared;

static RoboticControl_State_t robotic_state = {0};


/**
 * @description: 手动关闭G431电控板的电源，控制继电器开合(默认电源开启)
 * @return {*}
 */
void G431_StopPower(void)
{
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
}


/**
 * @description: 在使用了上述G431_StopPower(void)函数之后，重新开启电控板电源
 * @return {*}
 */
void G431_StartPower(void) {
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
}

/**
 * @description: 翻转G431的电源，用于电机控制
 * @return {*}
 */
void G431_TogglePower(void)
{
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_2);
}

/**
 * @description: 电控板控制串口初始化
 * @return {*}
 */
void G431_Init(void) {
    // 重新启动接收，使用Ex函数，接收不定长数据
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, G431_Buffer, sizeof(G431_Buffer));
    // 关闭DMA传输过半中断（HAL库默认开启，但我们只需要接收完成中断）
    __HAL_DMA_DISABLE_IT(huart1.hdmarx, DMA_IT_HT);
}

/**
 * @description: 发送命令的函数
 * @param {uint8_t} *command
 * @return {*}
 */
void G431_SendCommand(uint8_t *command) {
    HAL_UART_Transmit(&huart1,command,sizeof(command),500);
}

/**
 * @description: (主循环调用)根据压力传感器控制X夹爪的力度（暂时用不到，有些问题）
 * @return {*}
 */
void G431_RoboticControl_Tick(void) {
    // // 检查接收缓冲区是否有0xB0命令
    // for(uint16_t i = 0; i < sizeof(G431_Buffer); i++) {
    //     // 遇到结束符停止检查
    //     if(G431_Buffer[i] == '\0' || G431_Buffer[i] == '\r' || G431_Buffer[i] == '\n') {
    //         break;
    //     }
        
    //     // 检查是否是0xB0命令
    //     if(G431_Buffer[i] == 0xB0) {
    //         robotic_state.cmd_received = 1;
    //         robotic_state.check_start_time = HAL_GetTick();
    //         robotic_state.response_sent = 0;
            
    //         // 清空缓冲区以便接收新数据
    //         memset(G431_Buffer, 0, sizeof(G431_Buffer));
    //         break; // 找到命令后退出循环
    //     }
    // }

    // // 如果收到命令且未发送响应
    // if(robotic_state.cmd_received && !robotic_state.response_sent) {
    //     // 计算已过去的时间(ms)
    //     uint32_t elapsed_time = HAL_GetTick() - robotic_state.check_start_time;
        
    //     // 检查是否在4秒时间窗口内
    //     if(elapsed_time < 4000) {
    //         // 读取压力传感器值(牛顿)
    //         float pressure = Stress_GetValue();
            
    //         // 如果压力大于4.0牛顿
    //         if(pressure > 0.5f && Infrared == 1) {
    //             // 发送0xB1响应
    //             uint8_t response = 0xB1;
    //             HAL_UART_Transmit(&huart1, &response, 1, 100);
    //             robotic_state.response_sent = 1;
                
    //             // 可选: 打印调试信息
    //             // printf("Pressure: %.2f N, Sent 0xB1\n", pressure);
    //         }
    //     } else {
    //         // 超过4秒未检测到足够压力，重置状态
    //         robotic_state.cmd_received = 0;
    //     }
    // }
    float pressure = Stress_GetValue();
    
    // 如果压力大于4.0牛顿
    if(pressure > 0.3f && Infrared == 1) {
        // 发送0xB1响应
        uint8_t response = 0xB1;
        HAL_UART_Transmit(&huart1, &response, 1, 100);
        robotic_state.response_sent = 1;
        
        // 可选: 打印调试信息
        // printf("Pressure: %.2f N, Sent 0xB1\n", pressure);
    }
}



