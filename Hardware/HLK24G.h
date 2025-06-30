#ifndef HLK24G_H
#define HLK24G_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>

// 模块配置
#define HLK24G_DEFAULT_BAUDRATE 256000  // 默认波特率
#define HLK24G_UART_TIMEOUT 1000        // 串口超时时间(ms)

// 协议常量
#define HLK24G_CMD_HEADER 0xFAFBFCFD    // 命令帧头
#define HLK24G_CMD_FOOTER 0x01020304    // 命令帧尾
#define HLK24G_DATA_HEADER 0xF1F2F3F4   // 数据帧头
#define HLK24G_DATA_FOOTER 0xF5F6F7F8   // 数据帧尾

// 命令字定义
typedef enum {
    HLK_CMD_ENABLE_CONFIG = 0x00FF,     // 使能配置
    HLK_CMD_END_CONFIG = 0x00FE,        // 结束配置
    HLK_CMD_SET_DISTANCE_PARAM = 0x0060,// 设置距离参数
    HLK_CMD_READ_PARAM = 0x0061,        // 读取参数
    HLK_CMD_ENABLE_ENG_MODE = 0x0062,   // 使能工程模式
    HLK_CMD_DISABLE_ENG_MODE = 0x0063,  // 关闭工程模式
    HLK_CMD_SET_SENSITIVITY = 0x0064,   // 设置灵敏度
    HLK_CMD_READ_FW_VERSION = 0x00A0,   // 读取固件版本
    HLK_CMD_SET_BAUDRATE = 0x00A1,      // 设置波特率
    HLK_CMD_FACTORY_RESET = 0x00A2,     // 恢复出厂设置
    HLK_CMD_REBOOT = 0x00A3             // 重启模块
} HLK_Command_t;

// 目标状态定义
typedef enum {
    HLK_TARGET_NONE = 0x00,             // 无目标
    HLK_TARGET_MOVING = 0x01,           // 运动目标
    HLK_TARGET_STATIC = 0x02,           // 静止目标
    HLK_TARGET_BOTH = 0x03              // 运动+静止目标
} HLK_TargetStatus_t;

// 模块数据结构
typedef struct {
    HLK_TargetStatus_t status;          // 目标状态
    uint16_t moving_distance;           // 运动目标距离(cm)
    uint8_t moving_energy;              // 运动目标能量值
    uint16_t static_distance;           // 静止目标距离(cm)
    uint8_t static_energy;              // 静止目标能量值
    uint16_t detection_distance;        // 探测距离(cm)
    uint8_t light_sensor;               // 光敏检测值
    bool out_state;                     // OUT脚输出状态
} HLK_Data_t;

// 初始化函数
bool HLK24G_Init(UART_HandleTypeDef *huart);

// 基础通信函数
bool HLK24G_SendCommand(HLK_Command_t cmd, uint8_t *params, uint16_t param_len);
bool HLK24G_ReceiveData(HLK_Data_t *data);

// 功能函数
bool HLK24G_EnableConfig(void);
bool HLK24G_EndConfig(void);
bool HLK24G_ReadParameters(void);
bool HLK24G_EnableEngineeringMode(void);
bool HLK24G_DisableEngineeringMode(void);
bool HLK24G_SetSensitivity(uint8_t distance_gate, uint8_t moving_sens, uint8_t static_sens);
bool HLK24G_ReadFirmwareVersion(uint16_t *fw_type, uint16_t *major, uint32_t *minor);

#endif /* HLK24G_H */
