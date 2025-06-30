/*
 * @Author: �Ǳس�Sguan
 * @Date: 2025-04-27 21:49:12
 * @LastEditors: �Ǳس�Sguan|3464647102@qq.com
 * @LastEditTime: 2025-04-29 21:53:01
 * @FilePath: \test_SPIscreen\Hardware\ft6336.c
 * @Description: [�����]��������I2C��д�Ĵ����ĺ���
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "ft6336.h"
#include "touch.h"
#include "delay.h" 
#include "string.h" 
#include "lcd.h"

extern uint8_t touch_flag;
extern I2C_HandleTypeDef hi2c2;

#define FT6336_I2C        hi2c2  // �滻Ϊ���I2C���
#define FT6336_ADDR       0x38   // FT6336��I2C��ַ��7λ��ַ��������дλ��

uint8_t FT6336_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
		uint8_t data[len + 1];
    data[0] = reg & 0xFF;  // �Ĵ�����ַ����8λ��
    memcpy(&data[1], buf, len);  // д�������

    // ʹ��HAL_I2C_Master_Transmit
    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(
        &FT6336_I2C,          // I2C�������hi2c1��
        FT6336_ADDR << 1,     // �豸��ַ������1λ��HAL���Զ������дλ��
        data,                 // ���ݻ���������ַ+���ݣ�
        len + 1,              // ���ݳ��ȣ���ַ1�ֽ� + ����len�ֽڣ�
        HAL_MAX_DELAY         // ��ʱʱ�䣨���Զ��壩
    );

    return (status == HAL_OK) ? 0 : 1;  // �ɹ�����0��ʧ�ܷ���1
}
		  
void FT6336_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t reg_addr = reg & 0xFF;
	HAL_I2C_Master_Transmit(
		&FT6336_I2C,
		FT6336_ADDR << 1,
		&reg_addr,  // �Ĵ�����ַ
		1,          // ��ַ���ȣ�1�ֽڣ�
		HAL_MAX_DELAY
	);

	// �ٶ�ȡ���ݣ���ģʽ��
	HAL_I2C_Master_Receive(
		&FT6336_I2C,
		FT6336_ADDR << 1 | 0x01,  // ��ģʽ����ַ | 0x01��
		buf,                       // ���ݻ�����
		len,                       // ��ȡ����
		HAL_MAX_DELAY
	);
} 

uint8_t FT6336_Init(void)
{
	uint8_t temp[2]; 	
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitStruct.Pin = CTP_INT_Pin;				 //PB1
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;//����
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//100MHz
	GPIO_InitStruct.Pull = GPIO_PULLUP;//���� 
	HAL_GPIO_Init(CTP_INT_GPIO_Port, &GPIO_InitStruct);		  

	GPIO_InitStruct.Pin = CTP_RST_Pin;				 //PC5
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; 	 		//���	  
	HAL_GPIO_Init(CTP_RST_GPIO_Port, &GPIO_InitStruct);	
	
	FT_RST=0;				//��λ
	delay_ms(10);
 	FT_RST=1;				//�ͷŸ�λ		    
	delay_ms(500); 
	FT6336_RD_Reg(FT_ID_G_FOCALTECH_ID,&temp[0],1);
	if(temp[0]!=0x11)
	{
		return 1;
	}
	FT6336_RD_Reg(FT_ID_G_CIPHER_MID,&temp[0],2);
	if(temp[0]!=0x26)
	{
		return 1;
	}
	if((temp[1]!=0x00)&&(temp[1]!=0x01)&&(temp[1]!=0x02))
	{
		return 1;
	}
	FT6336_RD_Reg(FT_ID_G_CIPHER_HIGH,&temp[0],1);
	if(temp[0]!=0x64)
	{
		return 1;
	}
	return 0;
}

const uint16_t FT6336_TPX_TBL[2]={FT_TP1_REG,FT_TP2_REG};

uint8_t FT6336_Scan(void)
{
	uint8_t buf[4];
	uint8_t i=0;
	uint8_t res=0;
	uint8_t temp;
	uint8_t mode;
	static uint8_t t=0;//���Ʋ�ѯ���,�Ӷ�����CPUռ����   
	t++;
	if((t%10)==0||t<10)//����ʱ,ÿ����10��CTP_Scan�����ż��1��,�Ӷ���ʡCPUʹ����
	{
		FT6336_RD_Reg(FT_REG_NUM_FINGER,&mode,1);//��ȡ�������״̬  
		if(mode&&(mode<3))
		{
			temp=0XFF<<mode;//����ĸ���ת��Ϊ1��λ��,ƥ��tp_dev.sta���� 
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES; 
			for(i=0;i<CTP_MAX_TOUCH;i++)
			{
				FT6336_RD_Reg(FT6336_TPX_TBL[i],buf,4);	//��ȡXY����ֵ 
				if(tp_dev.sta&(1<<i))	//������Ч?
				{
					switch(lcddev.dir)
					{
						case 0:
							tp_dev.x[i]=((uint16_t)(buf[0]&0X0F)<<8)+buf[1];
							tp_dev.y[i]=((uint16_t)(buf[2]&0X0F)<<8)+buf[3];						
							break;
						case 1:
							tp_dev.y[i]=lcddev.height-(((uint16_t)(buf[0]&0X0F)<<8)+buf[1]);
							tp_dev.x[i]=((uint16_t)(buf[2]&0X0F)<<8)+buf[3];						
							break;
						case 2:
							tp_dev.x[i]=lcddev.width-(((uint16_t)(buf[0]&0X0F)<<8)+buf[1]);
							tp_dev.y[i]=lcddev.height-(((uint16_t)(buf[2]&0X0F)<<8)+buf[3]);								
							break;
						case 3:
							tp_dev.y[i]=((uint16_t)(buf[0]&0X0F)<<8)+buf[1];
							tp_dev.x[i]=lcddev.width-(((uint16_t)(buf[2]&0X0F)<<8)+buf[3]);	
							break;
					}
				}			
			} 
			res=1;
			if(tp_dev.x[0]==0 && tp_dev.y[0]==0)mode=0;	//���������ݶ���0,����Դ˴�����
			t=0;		//����һ��,��������������10��,�Ӷ����������
		}
	}
	if(mode==0)//�޴����㰴��
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//֮ǰ�Ǳ����µ�
		{
			tp_dev.sta&=~(1<<7);	//��ǰ����ɿ�
		}else						//֮ǰ��û�б�����
		{ 
			tp_dev.x[0]=0xffff;
			tp_dev.y[0]=0xffff;
			tp_dev.sta&=0XE0;	//�������Ч���	
		}	 
	} 
	if(t>240)t=10;//���´�10��ʼ����
	return res;
}
 
