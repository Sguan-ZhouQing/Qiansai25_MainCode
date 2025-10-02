/*
 * @Author: 星必尘Sguan
 * @Date: 2025-04-14 17:01:57
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-05-07 00:16:40
 * @FilePath: \test_2804FocMotor\Hardware\nRF24L01.c
 * @Description: nRF24L01无线模块驱动
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "nRF24L01.h"

#define TX_ADR_WIDTH    5     // 发送地址宽度(5字节)
#define RX_ADR_WIDTH    5     // 接收地址宽度(5字节)
#define TX_PLOAD_WIDTH  32    // 发送有效数据宽度(32字节)
#define RX_PLOAD_WIDTH  32    // 接收有效数据宽度(32字节)

// 默认发送和接收地址(全FF广播地址)
const uint8_t TX_ADDRESS[TX_ADR_WIDTH]={0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 
const uint8_t RX_ADDRESS[RX_ADR_WIDTH]={0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 

/**
 * @brief 设置CSN引脚电平
 * @param BitValue 电平值(0:低电平, 1:高电平)
 */
void W_SS(uint8_t BitValue)
{
    HAL_GPIO_WritePin(CSN_Port, CSN_Pin, (GPIO_PinState)BitValue);
} 

/**
 * @brief 设置CE引脚电平
 * @param BitValue 电平值(0:低电平, 1:高电平)
 */
void W_CE(uint8_t BitValue)
{
    HAL_GPIO_WritePin(CE_Port, CE_Pin, (GPIO_PinState)BitValue);
} 

/**
 * @brief 读取IRQ引脚状态
 * @return IRQ引脚电平(0:低电平, 1:高电平)
 */
uint8_t R_IRQ(void)
{
    return HAL_GPIO_ReadPin(IRQ_Port, IRQ_Pin);
}

/**
 * @brief SPI单字节交换(发送和接收一个字节)
 * @param Byte 要发送的字节
 * @return 接收到的字节
 */
uint8_t SPI_SwapByte(uint8_t Byte)
{
    uint8_t rxData;
    HAL_SPI_TransmitReceive(&hspi2, &Byte, &rxData, 1, HAL_MAX_DELAY);
    return rxData;
}

/**
 * @brief 向nRF24L01寄存器写入一个字节
 * @param Reg 寄存器地址
 * @param Value 要写入的值
 * @return 状态寄存器值
 */
uint8_t NRF24L01_Write_Reg(uint8_t Reg, uint8_t Value)
{
    uint8_t Status;
    
    W_SS(0);                  // 使能SPI通信
    Status = SPI_SwapByte(Reg); // 发送寄存器地址并获取状态
    SPI_SwapByte(Value);       // 发送要写入的值
    W_SS(1);                  // 禁用SPI通信
    
    return Status;
}

/**
 * @brief 从nRF24L01寄存器读取一个字节
 * @param Reg 要读取的寄存器地址
 * @return 读取到的寄存器值
 */
uint8_t NRF24L01_Read_Reg(uint8_t Reg)
{
    uint8_t Value;
    
    W_SS(0);                  // 使能SPI通信
    SPI_SwapByte(Reg);         // 发送寄存器地址
    Value = SPI_SwapByte(0xFF); // 发送NOP命令(0xFF)并读取返回值
    W_SS(1);                  // 禁用SPI通信
    
    return Value;
}

/**
 * @brief 从nRF24L01读取多个字节到缓冲区
 * @param Reg 要读取的起始寄存器地址
 * @param Buf 存储读取数据的缓冲区指针
 * @param Len 要读取的字节数
 * @return 状态寄存器值
 */
uint8_t NRF24L01_Read_Buf(uint8_t Reg, uint8_t *Buf, uint8_t Len)
{
    uint8_t Status;
    
    W_SS(0);                  // 使能SPI通信
    Status = SPI_SwapByte(Reg); // 发送寄存器地址并获取状态
    while(Len--)
    {
        *Buf++ = SPI_SwapByte(0xFF); // 连续读取多个字节(NOP命令用0xFF)
    }
    W_SS(1);                  // 禁用SPI通信
    
    return Status;
}

/**
 * @brief 向nRF24L01写入多个字节数据
 * @param Reg 要写入的起始寄存器地址
 * @param Buf 包含写入数据的缓冲区指针
 * @param Len 要写入的字节数
 * @return 状态寄存器值
 */
uint8_t NRF24L01_Write_Buf(uint8_t Reg, uint8_t *Buf, uint8_t Len)
{
    uint8_t Status;
    
    W_SS(0);                  // 使能SPI通信
    Status = SPI_SwapByte(Reg); // 发送寄存器地址并获取状态
    while(Len--)
    {
        SPI_SwapByte(*Buf++);  // 连续写入多个字节
    }
    W_SS(1);                  // 禁用SPI通信
    
    return Status;
}

/**
 * @brief 从接收缓冲区读取数据
 * @param Buf 存储接收数据的缓冲区指针
 * @return 0:读取成功 1:无数据可读
 */
uint8_t NRF24L01_GetRxBuf(uint8_t *Buf)
{
    uint8_t State;
    
    State = NRF24L01_Read_Reg(STATUS); // 读取状态寄存器
    NRF24L01_Write_Reg(nRF_WRITE_REG + STATUS, State); // 清除中断标志
    
    if(State & RX_OK) // 检查是否有数据接收成功
    {
        W_CE(1); // 使能接收
        NRF24L01_Read_Buf(RD_RX_PLOAD, Buf, RX_PLOAD_WIDTH); // 读取接收缓冲区
        NRF24L01_Write_Reg(FLUSH_RX, 0xFF); // 清空接收缓冲区
        W_CE(1); // 重新使能接收
        HAL_Delay(1); // 短暂延时
        return 0; // 读取成功
    }
    
    return 1; // 无数据可读
}

/**
 * @brief 发送数据缓冲区
 * @param Buf 包含发送数据的缓冲区指针
 * @return 发送状态: MAX_TX(达到最大重发次数), TX_OK(发送成功), 0xFF(其他错误)
 */
uint8_t NRF24L01_SendTxBuf(uint8_t *Buf)
{
    uint8_t State;
    
    W_CE(0); // 禁用发送/接收
    NRF24L01_Write_Buf(WR_TX_PLOAD, Buf, TX_PLOAD_WIDTH); // 写入发送缓冲区
    W_CE(1); // 使能发送
    
    while(R_IRQ() == 1); // 等待发送完成(IRQ变低)
    
    State = NRF24L01_Read_Reg(STATUS); // 读取状态寄存器
    NRF24L01_Write_Reg(nRF_WRITE_REG + STATUS, State); // 清除中断标志
    
    if(State & MAX_TX) // 检查是否达到最大重发次数
    {
        NRF24L01_Write_Reg(FLUSH_TX, 0xFF); // 清空发送缓冲区
        return MAX_TX;
    }
    if(State & TX_OK) // 检查是否发送成功
    {
        return TX_OK;
    }
    
    return 0xFF; // 其他错误
}

/**
 * @brief 检查nRF24L01是否存在
 * @return 0:模块存在 1:模块不存在
 */
uint8_t NRF24L01_Check(void)
{
    uint8_t check_in_buf[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
    uint8_t check_out_buf[5] = {0x00};
    
    W_SS(1); // 确保SPI禁用
    W_CE(0); // 禁用发送/接收
    
    // 写入测试数据到TX_ADDR寄存器
    NRF24L01_Write_Buf(nRF_WRITE_REG + TX_ADDR, check_in_buf, 5);
    // 从TX_ADDR寄存器读取数据
    NRF24L01_Read_Buf(nRF_READ_REG + TX_ADDR, check_out_buf, 5);
    
    // 比较写入和读取的数据是否一致
    if((check_out_buf[0] == 0x11) && 
       (check_out_buf[1] == 0x22) && 
       (check_out_buf[2] == 0x33) && 
       (check_out_buf[3] == 0x44) && 
       (check_out_buf[4] == 0x55))
    {
        return 0; // 模块存在
    }
    else
    {
        return 1; // 模块不存在
    }
}

/**
 * @brief 初始化nRF24L01为接收模式
 */
void NRF24L01_RT_Init(void) 
{	
    W_CE(0); // 禁用发送/接收
    NRF24L01_Write_Reg(nRF_WRITE_REG+RX_PW_P0, RX_PLOAD_WIDTH); // 设置接收数据长度
    NRF24L01_Write_Reg(FLUSH_RX, NOP); // 清空接收缓冲区
    NRF24L01_Write_Buf(nRF_WRITE_REG + TX_ADDR, (uint8_t*)TX_ADDRESS, TX_ADR_WIDTH); // 设置发送地址
    NRF24L01_Write_Buf(nRF_WRITE_REG + RX_ADDR_P0, (uint8_t*)RX_ADDRESS, RX_ADR_WIDTH); // 设置接收地址
    NRF24L01_Write_Reg(nRF_WRITE_REG + EN_AA, 0x01); // 使能通道0自动应答
    NRF24L01_Write_Reg(nRF_WRITE_REG + EN_RXADDR, 0x01); // 使能通道0接收
    NRF24L01_Write_Reg(nRF_WRITE_REG + SETUP_RETR, 0x1A); // 设置自动重发(500us+10次)
    NRF24L01_Write_Reg(nRF_WRITE_REG + RF_CH, 0); // 设置射频通道0
    NRF24L01_Write_Reg(nRF_WRITE_REG + RF_SETUP, 0x0F); // 设置发射功率和速率(0dBm, 2Mbps)
    NRF24L01_Write_Reg(nRF_WRITE_REG + CONFIG, 0x0F); // 配置为接收模式, 使能CRC(2字节)
    W_CE(1); // 使能接收
}

/**
 * @brief nRF24L01初始化函数
 */
void NRF24L01_Init(void)
{
    while(NRF24L01_Check()); // 等待模块就绪
    NRF24L01_RT_Init(); // 初始化为接收模式
}

/**
 * @brief 发送数据
 * @param Buf 包含发送数据的缓冲区指针
 */
void NRF24L01_SendBuf(uint8_t *Buf)
{
    W_CE(0); // 禁用发送/接收
    NRF24L01_Write_Reg(nRF_WRITE_REG + CONFIG, 0x0E); // 配置为发送模式
    W_CE(1); // 使能发送
    HAL_Delay(15); // 等待稳定
    NRF24L01_SendTxBuf(Buf); // 发送数据
    W_CE(0); // 禁用发送
    NRF24L01_Write_Reg(nRF_WRITE_REG + CONFIG, 0x0F); // 恢复为接收模式
    W_CE(1); // 使能接收
}

/**
 * @brief 获取IRQ标志状态
 * @return IRQ引脚状态(0:有中断, 1:无中断)
 */
uint8_t NRF24L01_Get_Value_Flag(void)
{
    return R_IRQ();
}

