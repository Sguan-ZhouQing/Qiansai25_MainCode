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
