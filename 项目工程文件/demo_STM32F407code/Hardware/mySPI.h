/*
 * @Author: �Ǳس�Sguan
 * @Date: 2025-05-20 13:08:06
 * @LastEditors: �Ǳس�Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-07 12:45:13
 * @FilePath: \demo_STM32F407code\Hardware\mySPI.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#ifndef _SPI_H_
#define _SPI_H_

#include "spi.h"
#include "sys.h"
#include "stm32f4xx_hal.h"

//����SPIʱ���ź��Լ�SPI����д�ź����Ų��ɸ��ģ��������Ŷ����Ը���
//SPI��ʱ�����Ŷ���̶�ΪPB3
//SPI�Ķ��������Ŷ���̶�ΪPB4
//SPI��д�������Ŷ���̶�ΪPB5
 
uint8_t SPI_WriteByte(SPI_TypeDef* SPIx,uint8_t Byte);
void SPI_SetSpeed(SPI_TypeDef* SPIx,uint8_t SpeedSet);
void SPI1_Init(void);


#endif
