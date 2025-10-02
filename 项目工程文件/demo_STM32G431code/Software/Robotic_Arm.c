/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-28 21:15:48
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 17:29:12
 * @FilePath: \demo_STM32G431code\Software\Robotic_Arm.c
 * @Description: 调用PCA9685控制机械臂上的5个舵机（应用层实现）
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Robotic_Arm.h"

extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern UART_HandleTypeDef huart2;
PCA9685_HandleTypeDef hpca;


// 配置参数
static const float Single_Angle = 5.0f;
static const int8_t Motor_Velocity = 65;
static const uint8_t Single_Step = 50;
// 舵机角度计数器
static int8_t Angle_Count[5] = {0}; // B, L, U, R, X方向
static uint8_t Motor_Control_Count = 5;
//舵机测试局参
// static uint8_t DataOk[] = "Set Motor Yeah!";    // 语义上可能char更合适
 uint8_t Robotic_Readbuffer[256];
//步进电机绝对坐标（原点）
static int16_t CoordinateX,CoordinateY;
//控制X轴舵机夹取力度的初始角度
static float currentAngleX;
//控制X轴舵机夹取力度的结束角度
static float finalAngleX = 220.0f;
//Robotic_KeyControl函数的局部变量
static uint8_t KeyControl_Count;


/**
 * @description: 舵机and步进电机的绝对运动点位(宏定义)
 * @return {*}
 */
#define Central_Axis_BX -250     //0号位中轴线-距离原点(步进电机)
#define Take_Point_BY -200      //0号位Y轴坐标-距离原点(步进电机)
#define Locus_Point1_L 210.0f   //1号高度位置（L轴舵机）
#define Locus_Point1_U 110.0f   //1号高度位置（U轴舵机）
#define Locus_Point2_L 195.0f   //2号高度位置（L轴舵机）
#define Locus_Point2_U 180.0f   //2号高度位置（U轴舵机）
#define Locus_WaitTake_U 160.0f //0号位等待抓取（U轴舵机）
#define InputX_B 45.0f          //B轴朝向左方
#define OutputX_B 225.0f        //B轴朝向右方
#define OpenClaws_X 195.0f      //完全开合机械爪（X轴）
#define CloseClaws_Y 250.0f     //关闭机械夹爪（X轴）
//步进电机的活动范围是X(200,-1500),Y轴范围为(0,-200);


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
    HAL_UARTEx_ReceiveToIdle_DMA(&huart2,Robotic_Readbuffer,sizeof(Robotic_Readbuffer));
    __HAL_DMA_DISABLE_IT(&hdma_usart2_rx,DMA_IT_HT);
}


/**
 * @description: (私域)步进电机实际坐标到达函数
 * @param {int16_t} X   输入绝对X轴坐标
 * @param {int16_t} Y   输入绝对Y轴坐标
 * @return {*}
 */
static void Locus_StepperToXY(int16_t X,int16_t Y) {
    //与原来绝对坐标做差
    int16_t input_X = X - CoordinateX;
    int16_t input_Y = Y - CoordinateY;
    //更新XY轴目前的坐标
    CoordinateX = X;
    CoordinateY = Y;
    //XY轴方向判断
    int8_t DirX = (input_X >= 0) ? 1 : -1;
    int8_t DirY = (input_Y >= 0) ? 1 : -1;
    //设置电机转到对应位置
    StepperMotor_Control(0,DirX*Motor_Velocity,(uint16_t)abs(input_X));
    StepperMotor_Control(1,DirY*Motor_Velocity,(uint16_t)abs(input_Y));
}


/**
 * @description: (私域)舵机机械臂控制函数
 * @param {float} B_axis    B轴角度信息
 * @param {float} L_axis    L轴角度信息
 * @param {float} U_axis    U轴角度信息
 * @return {*}
 */
static void Locus_ServoToAngle(float BF_axis,float LF_axis,float UF_axis,float XF_claws) {
    PCA9685_SetServoAngle(&hpca, B_AXIS, SERVO_270_DEGREE, BF_axis);
    PCA9685_SetServoAngle(&hpca, L_AXIS, SERVO_270_DEGREE, LF_axis);
    PCA9685_SetServoAngle(&hpca, U_AXIS, SERVO_270_DEGREE, UF_axis);
    // R轴角度需要特殊处理，保持与L轴和U轴的联动关系
    PCA9685_SetServoAngle(&hpca, R_AXIS, SERVO_270_DEGREE, LF_axis + UF_axis - LU_R_Angle);
    PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, XF_claws);
}


/**
 * @description: (私域)舵机回零的状态函数
 * @param {bool} State
 * @return {*}
 */
static void Locus_ReturnZero(bool State) {
    if (State == true) {
        Locus_ServoToAngle(135.0f,210.0f,170.0f,finalAngleX);//回零位
        Locus_StepperToXY(0,0);                              //回零位
    }
    else {
        Locus_StepperToXY(0,0);                              //回零位
        Locus_ServoToAngle(135.0f,210.0f,170.0f,finalAngleX);//回零位
    }
}


/**
 * @description: (私域)控制舵机或步进电机
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
 * @description: 缓慢增加X轴夹爪角度直到接收到0xB1信号
 * @param {void}
 * @return {void}
 */
static void Robotic_IncreaseXClawsUntilSignal(void) {
    // 发送开始信号 0xB0
//    uint8_t startSignal = 0xB0;
//    HAL_UART_Transmit(&huart2, &startSignal, 1, HAL_MAX_DELAY);  // 发送 0xB0

    currentAngleX = 195.0f;  // 初始化起始角度
    const float targetAngle = 235.0f;  // 目标角度
    const float step = 0.5f;  // 每次增加的步长
    const uint16_t delayMs = 50;  // 每次增加后的延迟(ms)
    
    // 检查是否已收到0xB1信号
    uint8_t hasSignal = 0;
    while(currentAngleX < targetAngle) {
        // 检查接收缓冲区是否有0xB1信号
        for(uint16_t i = 0; i < sizeof(Robotic_Readbuffer); i++) {
            if(Robotic_Readbuffer[i] == 0xB1) {
                hasSignal = 1;
                break;
            }
        }
        if(hasSignal) {
            // 例如: 闪烁LED或发送通知
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            break;  // 如果收到信号，立即退出循环
        }
        // 缓慢增加角度
        currentAngleX += step;
        if(currentAngleX > targetAngle) {
            currentAngleX = targetAngle;
        }
        // 设置舵机角度
        PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, currentAngleX);
        // 短暂延迟
        HAL_Delay(delayMs);
    }
}



/**
 * @description: 测试函数（放到while循环中不间断运行）
 * @function: 按下按键1，切换控制的电机|按键2，电机正向旋转一定距离|按键3，电机反向旋转
 * @return {*}
 */
void Robotic_KeyTest(void) {
    uint8_t Key_count = Key_GetNum();
    switch (Key_count) {
        case 1:
            // Motor_Control_Count = (Motor_Control_Count + 1) % 7;
            if (Motor_Control_Count == 5)
            {
                Motor_Control_Count = 6;
                break;
            }
            if (Motor_Control_Count == 6)
            {
                Motor_Control_Count = 5;
                break;
            }
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
 * @description: 处理串口接收到的数据并控制机械臂
 * @return {*}
 */
void Robotic_UartTest(void) {
    // 检查是否有完整的数据接收（7个数字，每个数字用空格分隔）
    uint8_t spaceCount = 0;
    for (uint8_t i = 0; i < sizeof(Robotic_Readbuffer); i++) {
        if (Robotic_Readbuffer[i] == ' ') {
            spaceCount++;
        }
        if (Robotic_Readbuffer[i] == '\0' || Robotic_Readbuffer[i] == '\r' || Robotic_Readbuffer[i] == '\n') {
            break;
        }
    }
    
    // 如果有6个空格，说明有7个数字
    if (spaceCount == 6) {
        float servoAngles[5];
        int16_t stepperSteps[2];
        char *token = (char *)strtok((char *)Robotic_Readbuffer, " ");
        uint8_t index = 0;
        
        // 解析接收到的数据
        while (token != NULL && index < 7) {
            if (index < 5) {
                servoAngles[index] = (float)atof(token);
            } else {
                stepperSteps[index - 5] = (int16_t)atoi(token);
            }
            token = (char *)strtok(NULL, " ");
            index++;
        }
        //设置舵机角度
        Locus_ServoToAngle(servoAngles[0],servoAngles[1],servoAngles[2],servoAngles[4]);
        // 控制步进电机
        int8_t direction0 = (stepperSteps[0] >= 0) ? 1 : -1;
        int8_t direction1 = (stepperSteps[1] >= 0) ? 1 : -1;
        StepperMotor_Control(0, direction0 * Motor_Velocity, (uint16_t)abs(stepperSteps[0]));
        StepperMotor_Control(1, direction1 * Motor_Velocity, (uint16_t)abs(stepperSteps[1]));
        // 更新角度计数器（如果需要）
        Angle_Count[0] = (int8_t)((servoAngles[0] - B_INIT_ANGLE) / Single_Angle);
        Angle_Count[1] = (int8_t)((servoAngles[1] - L_INIT_ANGLE) / Single_Angle);
        Angle_Count[2] = (int8_t)((servoAngles[2] - U_INIT_ANGLE) / Single_Angle);
        Angle_Count[4] = (int8_t)((servoAngles[4] - X_INIT_ANGLE) / Single_Angle);
    }
}


/**
 * @description: 运行轨迹其一（0号位到2号厂库）
 * Locus_StepperToXY函数和Locus_ServoToAngle函数
 * @return {*}
 */
static void Locus_RunWay1(void)
{
    Locus_StepperToXY(-250,-130);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,195.0f);
    HAL_Delay(1000);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,195.0f);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f);
    HAL_Delay(700);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, 220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(500);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,currentAngleX);
    HAL_Delay(500);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,190.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,205.0f,190.0f,currentAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,195.0f,190.0f,currentAngleX);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2500);
    Locus_ServoToAngle(38.0f,195.0f,190.0f,currentAngleX);
    HAL_Delay(300);
    Locus_StepperToXY(-500,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(38.0f,195.0f,190.0f,195.0f); //放下
    HAL_Delay(600);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(135.0f,195.0f,190.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ReturnZero(true); //回零位
}


static void Locus_RunWay2(void)
{
    Locus_StepperToXY(-250,-130);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,195.0f);
    HAL_Delay(1000);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,195.0f);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f);
    HAL_Delay(700);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, 220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(500);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,currentAngleX);
    HAL_Delay(500);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,190.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,205.0f,190.0f,currentAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,195.0f,190.0f,currentAngleX);
    Locus_StepperToXY(300,0);
    HAL_Delay(1100);
    Locus_ServoToAngle(232.0f,195.0f,190.0f,currentAngleX);
    HAL_Delay(300);
    Locus_StepperToXY(-700,0);
    HAL_Delay(1900);
    Locus_ServoToAngle(232.0f,195.0f,190.0f,195.0f); //放下
    HAL_Delay(600);
    Locus_StepperToXY(300,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(135.0f,210.0f,190.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ReturnZero(true); //回零位
}


static void Locus_RunWay3(void)
{
    Locus_StepperToXY(-250,-130);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,195.0f);
    HAL_Delay(1000);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,195.0f);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f);
    HAL_Delay(700);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, 220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(600);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2500);
    Locus_ServoToAngle(38.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(38.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-720,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(38.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(600);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(38.0f,210.0f,135.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,finalAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,155.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ReturnZero(true); //回零位
}



static void Locus_RunWay4(void)
{
    Locus_StepperToXY(-250,-130);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,195.0f);
    HAL_Delay(1000);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,195.0f);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f);
    HAL_Delay(700);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // PCA9685_SetServoAngle(&hpca, X_CLAWS, SERVO_270_DEGREE, 220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(600);
    Locus_StepperToXY(300,0);
    HAL_Delay(1100);
    Locus_ServoToAngle(232.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(232.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-480,0);
    HAL_Delay(1900);
    Locus_ServoToAngle(232.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(600);
    Locus_StepperToXY(300,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(232.0f,210.0f,135.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,finalAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,155.0f,finalAngleX);
    HAL_Delay(800);
    Locus_ReturnZero(true); //回零位
}


/**
 * @description: 运行轨迹其五（2号厂库到0号位）
 * @return {*}
 */
static void Locus_RunWay5(void)
{
    Locus_StepperToXY(-1500,0);
    Locus_ServoToAngle(135.0f,195.0f,190.0f,220.0f);
    HAL_Delay(3000);
    Locus_ServoToAngle(38.0f,195.0f,190.0f,195.0f);
    HAL_Delay(600);
    Locus_StepperToXY(-500,0);
    HAL_Delay(2000);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // Locus_ServoToAngle(35.0f,195.0f,190.0f,220.0f); // 抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(600);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-250,-130);
    HAL_Delay(3500);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,195.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,195.0f);
    HAL_Delay(800);
    Locus_ReturnZero(false); //回零位
}


static void Locus_RunWay6(void)
{
    Locus_StepperToXY(300,0);
    Locus_ServoToAngle(135.0f,195.0f,190.0f,220.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(232.0f,195.0f,190.0f,195.0f);
    HAL_Delay(600);
    Locus_StepperToXY(-700,0);
    HAL_Delay(2000);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // Locus_ServoToAngle(235.0f,195.0f,190.0f,220.0f); // 抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(600);
    Locus_StepperToXY(300,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-250,-130);
    HAL_Delay(1500);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,195.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,195.0f);
    HAL_Delay(800);
    Locus_ReturnZero(false); //回零位
}


static void Locus_RunWay7(void)
{
    Locus_StepperToXY(-1500,0);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,220.0f);
    HAL_Delay(3000);
    Locus_ServoToAngle(40.0f,210.0f,135.0f,220.0f);
    HAL_Delay(800);
    Locus_ServoToAngle(40.0f,210.0f,120.0f,195.0f);
    HAL_Delay(800);
    Locus_StepperToXY(-720,0);
    HAL_Delay(2000);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // Locus_ServoToAngle(35.0f,210.0f,120.0f,220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(600);
    Locus_StepperToXY(-1500,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(40.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(900);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-250,-130);
    HAL_Delay(1500);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,195.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,195.0f);
    HAL_Delay(800);
    Locus_ReturnZero(false); //回零位
}



static void Locus_RunWay8(void)
{
    Locus_StepperToXY(300,0);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,220.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(230.0f,210.0f,135.0f,220.0f);
    HAL_Delay(800);
    Locus_ServoToAngle(230.0f,210.0f,120.0f,195.0f);
    HAL_Delay(800);
    Locus_StepperToXY(-480,0);
    HAL_Delay(2000);
    //这里抓取的力度需要串口传参返回，做特殊处理
    // Locus_ServoToAngle(235.0f,210.0f,120.0f,220.0f); //抓取
    Robotic_IncreaseXClawsUntilSignal();
    //接收到力度调控消息后，继续运行后面的轨迹
    HAL_Delay(600);
    Locus_StepperToXY(300,0);
    HAL_Delay(2000);
    Locus_ServoToAngle(230.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,currentAngleX);
    HAL_Delay(900);
    Locus_ServoToAngle(135.0f,210.0f,170.0f,currentAngleX);
    HAL_Delay(800);
    Locus_StepperToXY(-250,-130);
    HAL_Delay(1500);
    Locus_ServoToAngle(135.0f,210.0f,145.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,currentAngleX);
    HAL_Delay(700);
    Locus_ServoToAngle(135.0f,210.0f,120.0f,195.0f); //放下
    HAL_Delay(800);
    Locus_ServoToAngle(135.0f,210.0f,135.0f,195.0f);
    HAL_Delay(600);
    Locus_ServoToAngle(135.0f,210.0f,150.0f,195.0f);
    HAL_Delay(800);
    Locus_ReturnZero(false); //回零位
}


/**
 * @description: (广域)按键控制运行轨迹，用于演示轨迹可行性
 * @return {*}
 */
void Robotic_KeyControl(void) {
    uint8_t temp = Key_GetNum();
    switch (temp) {
    case 1:
        KeyControl_Count++;
        if (KeyControl_Count == 8)
        {
            KeyControl_Count = 7;
        }
        break;
    case 2:
        if (KeyControl_Count) {
            KeyControl_Count--;
        }
        break;
    case 3:
        switch (KeyControl_Count) {
        case 0:
            Locus_RunWay1();    //存药到2号药仓
            break;
        case 1:
            Locus_RunWay2();    //存药到4号药仓
            break;
        case 2:
            Locus_RunWay3();    //存药到7号药仓
            break;
        case 3:
            Locus_RunWay4();    //存药到9号药仓
            break;
        case 4:
            Locus_RunWay5();    //从2号药仓取药
            break;
        case 5:
            Locus_RunWay6();    //从4号药仓取药
            break;
        case 6:
            Locus_RunWay7();    //从7号药仓取药
            break;
        case 7:
            Locus_RunWay8();    //从9号药仓取药
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}


/**
 * @description: 串口控制主循环函数，根据接收到的命令执行相应轨迹
 * @return {void}
 */
void Robotic_UartControl_Tick(void)
{
    // 检查接收缓冲区是否有有效命令
    for(uint16_t i = 0; i < sizeof(Robotic_Readbuffer); i++) {
        if(Robotic_Readbuffer[i] == '\0' || Robotic_Readbuffer[i] == '\r' || Robotic_Readbuffer[i] == '\n') {
            break;  // 遇到结束符停止检查
        }
        // 检查是否是有效的命令字节
        if(Robotic_Readbuffer[i] >= 0xA1 && Robotic_Readbuffer[i] <= 0xA8) {
            uint8_t command_temp = Robotic_Readbuffer[i];    // 根据命令执行相应的轨迹函数
            switch(command_temp) {
                case 0xA1:
                    Locus_RunWay1();
                    break;
                case 0xA2:
                    Locus_RunWay2();
                    break;
                case 0xA3:
                    Locus_RunWay3();
                    break;
                case 0xA4:
                    Locus_RunWay4();
                    break;
                case 0xA5:
                    Locus_RunWay5();
                    break;
                case 0xA6:
                    Locus_RunWay6();
                    break;
                case 0xA7:
                    Locus_RunWay7();
                    break;
                case 0xA8:
                    Locus_RunWay8();
                    break;
                default:
                    break;
            }
            Robotic_Readbuffer[i] = 0;  // 清除已处理的命令
            break;  // 一次只处理一个命令，避免重复执行
        }
    }
}


/**
 * @description: 串口回调函数（用于发送命令）
 * @param {UART_HandleTypeDef} *huart
 * @param {uint16_t} Size
 * @return {*}
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
    if (huart == &huart2) {
        // 处理接收到的数据
        // Robotic_UartTest();
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
        //重新开启DMA串口中断
        HAL_UARTEx_ReceiveToIdle_DMA(&huart2,Robotic_Readbuffer,sizeof(Robotic_Readbuffer));
        __HAL_DMA_DISABLE_IT(&hdma_usart2_rx,DMA_IT_HT);
    }
}


