/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-28 21:15:48
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-30 18:18:06
 * @FilePath: \demo_STM32G431code\Software\Robotic_Arm.c
 * @Description: 调用PCA9685控制机械臂上的5个舵机（应用层实现）
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Robotic_Arm.h"

extern I2C_HandleTypeDef hi2c1;
PCA9685_HandleTypeDef hpca;


// 配置参数
static const float Single_Angle = 5.0f;
static const int8_t Motor_Velocity = 65;
static const uint8_t Single_Step = 200;
// 舵机角度计数器
static int8_t Angle_Count[5] = {0}; // B, L, U, R, X方向
static uint8_t Motor_Control_Count = 0;


/**
 * @description: 初始化机械臂（B轴,L轴,U轴,R轴,X夹爪）
 * @return {*}
 */
void Robotic_Init(void) {
    PCA9685_Init(&hpca, &hi2c1, PCA9685_ADDRESS, PCA9685_SERVO_FREQ);
    // 初始化所有舵机角度
    PCA9685_SetServoAngle(&hpca, B_AXIS, SERVO_270_DEGREE, B_INIT_ANGLE);
    PCA9685_SetServoAngle(&hpca, L_AXIS, SERVO_270_DEGREE, L_INIT_ANGLE);
    PCA9685_SetServoAngle(&hpca, U_AXIS, SERVO_270_DEGREE, U_INIT_ANGLE);
    PCA9685_SetServoAngle(&hpca, R_AXIS, SERVO_270_DEGREE, L_INIT_ANGLE+U_INIT_ANGLE-LU_R_Angle);
    PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, X_INIT_ANGLE);
}


/**
 * @description: 控制舵机或步进电机
 * @param {uint8_t} count
 * @param {int8_t} direction
 * @return {*}
 */
static void ControlDevice(uint8_t count, int8_t direction) {
    if (count < 5) { // 舵机控制
        Angle_Count[count] += direction;
        float angle,temp;
        switch(count) {
            case 0: 
                angle = B_INIT_ANGLE;
                PCA9685_SetServoAngle(&hpca, B_AXIS, SERVO_270_DEGREE, 
                            angle + Single_Angle * Angle_Count[count]);
                break;
            case 1: 
                angle = L_INIT_ANGLE; 
                PCA9685_SetServoAngle(&hpca, L_AXIS, SERVO_270_DEGREE, 
                            angle + Single_Angle * Angle_Count[count]);
                temp = U_INIT_ANGLE;
                PCA9685_SetServoAngle(&hpca, R_AXIS, SERVO_270_DEGREE, 
                            angle + temp + Single_Angle * (Angle_Count[1]+Angle_Count[2]) - LU_R_Angle);
                break;
            case 2: 
                angle = U_INIT_ANGLE; 
                PCA9685_SetServoAngle(&hpca, U_AXIS, SERVO_270_DEGREE, 
                            angle + Single_Angle * Angle_Count[count]);
                temp = L_INIT_ANGLE; 
                PCA9685_SetServoAngle(&hpca, R_AXIS, SERVO_270_DEGREE, 
                            angle + temp + Single_Angle * (Angle_Count[1]+Angle_Count[2]) - LU_R_Angle);
                break;
            case 3: 
                HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
                break;
            case 4: 
                angle = X_INIT_ANGLE; 
                PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, 
                            angle + Single_Angle * Angle_Count[count]);
                break;
        }
    } 
    else if (count < 7) { // 步进电机控制
        StepperMotor_Control(count - 5, direction * Motor_Velocity, Single_Step);
    }
}


/**
 * @description: 测试函数（放到while循环中不间断运行）
 * @function: 按下按键1，切换控制的电机|按键2，电机正向旋转一定距离|按键3，电机反向旋转
 * @return {*}
 */
void Robotic_Test(void) {
    uint8_t Key_count = Key_GetNum();
    switch (Key_count) {
        case 1:
            Motor_Control_Count = (Motor_Control_Count + 1) % 7;
            break;
        case 2:
            ControlDevice(Motor_Control_Count, 1);
            break;
        case 3:
            ControlDevice(Motor_Control_Count, -1);
            break;
        default:
            break;
    }
}



/**
 * @description: 运行路线1的前半阶段
 * @return {*}
 */
static void ControlTransport_Way1(void)
{
    if (count == 1)
    {
        
    }
    
}




/**
 * @description: 根据命令，执行机械臂运输的函数实现
 * @param {uint8_t} *command
 * @return {*}
 */
void Robotic_Transport(uint8_t *command)
{
    switch (command)
    {
    case 0x02:
        /* code */
        break;
    case 0x04:
        /* code */
        break;
    case 0x07:
        /* code */
        break;
    case 0x09:
        /* code */
        break;

    case 0x12:
        /* code */
        break;
    case 0x14:
        /* code */
        break;
    case 0x17:
        /* code */
        break;
    case 0x19:
        /* code */
        break;

    default:
        break;
    }
}


