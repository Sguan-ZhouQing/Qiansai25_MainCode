/*
 * @Author: �Ǳس�Sguan
 * @Date: 2025-04-27 21:49:28
 * @LastEditors: �Ǳس�Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-09 11:49:44
 * @FilePath: \demo_STM32F407code\Hardware\lcd.c
 * @Description: [�����]LCD��Ļ��ʾ����������
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "lcd.h"
#include "stdlib.h"
#include "delay.h"	 
#include "Yaocang.h"
#include "tim.h"

extern TIM_HandleTypeDef htim1;
extern uint16_t current_brightness_value;
	   
//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;
extern DMA_HandleTypeDef hdma_spi1_tx;

//������ɫ,������ɫ
uint16_t POINT_COLOR = 0x0000,BACK_COLOR = 0xFFFF;  
uint16_t DeviceCode;	 

/**
 * @brief ��LCDд��Ĵ�������
 * @param data Ҫд��ļĴ�������ֵ
 */
void LCD_WR_REG(uint8_t data)
{ 
	LCD_CS_CLR;     
	LCD_RS_CLR;	  
	SPI_WriteByte(SPI1,data);
	LCD_CS_SET;	
}

/**
 * @brief ��LCDд������
 * @param data Ҫд�������ֵ
 */
void LCD_WR_DATA(uint8_t data)
{
	LCD_CS_CLR;
	LCD_RS_SET;
	SPI_WriteByte(SPI1,data);
	LCD_CS_SET;
}

/**
 * @brief ��LCD��ȡ����
 * @return ��ȡ��������
 */
uint8_t LCD_RD_DATA(void)
{
	uint8_t data;
	LCD_CS_CLR;
	LCD_RS_SET;
	SPI_SetSpeed(SPI1,0);
	data = SPI_WriteByte(SPI1,0xFF);
	SPI_SetSpeed(SPI1,1);
	LCD_CS_SET;
	return data;
}

/**
 * @brief ��ָ���Ĵ���д��ֵ
 * @param LCD_Reg �Ĵ�����ַ
 * @param LCD_RegValue Ҫд��ļĴ���ֵ
 */
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue)
{	
	LCD_WR_REG(LCD_Reg);  
	LCD_WR_DATA(LCD_RegValue);	    		 
}	   

/**
 * @brief ��ȡָ���Ĵ�����ֵ
 * @param LCD_Reg Ҫ��ȡ�ļĴ�����ַ
 * @return ��ȡ���ļĴ���ֵ
 */
uint8_t LCD_ReadReg(uint8_t LCD_Reg)
{
	LCD_WR_REG(LCD_Reg);
	return LCD_RD_DATA();
}

/**
 * @brief ׼��д��GRAM(�Դ�)
 */
void LCD_WriteRAM_Prepare(void)
{
	LCD_WR_REG(lcddev.wramcmd);
}	 

/**
 * @brief ׼����ȡGRAM(�Դ�)
 */
void LCD_ReadRAM_Prepare(void)
{
	LCD_WR_REG(lcddev.rramcmd);
}	 

/**
 * @brief ��LCDд��16λ����
 * @param Data Ҫд���16λ����
 */
void Lcd_WriteData_16Bit(uint16_t Data)
{	
	LCD_CS_CLR;
	LCD_RS_SET;
	SPI_WriteByte(SPI1,Data>>8);
	SPI_WriteByte(SPI1,Data);
	LCD_CS_SET;
}

/**
 * @brief ��LCD��ȡ16λ����
 * @return ��ȡ����16λ����
 */
uint16_t Lcd_ReadData_16Bit(void)
{
	uint16_t r,g;
	LCD_CS_CLR;
	LCD_RS_CLR;	  
	SPI_WriteByte(SPI1,lcddev.rramcmd);
	SPI_SetSpeed(SPI1,0);
	LCD_RS_SET;
	SPI_WriteByte(SPI1,0xFF);
	r = SPI_WriteByte(SPI1,0xFF);
	g = SPI_WriteByte(SPI1,0xFF);
	SPI_SetSpeed(SPI1,1);
	LCD_CS_SET;
	r<<=8;
	r|=g;
	return r;
}

/**
 * @brief ��ָ�����껭��
 * @param x X����
 * @param y Y����
 */
void LCD_DrawPoint(uint16_t x,uint16_t y)
{
	LCD_SetCursor(x,y);//���ù��λ�� 
	Lcd_WriteData_16Bit(POINT_COLOR); 
}

/**
 * @brief ��ȡָ����������ɫֵ
 * @param x X����
 * @param y Y����
 * @return �õ����ɫֵ
 */
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y)
{
	uint16_t color;
	LCD_SetCursor(x,y);//���ù��λ�� 
	color = Lcd_ReadData_16Bit();
	return color;
}

/**
 * @brief ��������
 * @param Color ������ɫ
 */
void LCD_Clear(uint16_t Color)
{
	unsigned int i,m;  
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);   
	LCD_CS_CLR;
	LCD_RS_SET;
	for(i=0;i<lcddev.height;i++)
	{
    for(m=0;m<lcddev.width;m++)
    {	
			SPI_WriteByte(SPI1,Color>>8);
			SPI_WriteByte(SPI1,Color);
		}
	}
	LCD_CS_SET;
} 

/**
 * @brief LCD GPIO��ʼ��
 */
void LCD_GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	      
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitStruct.Pin =  LCD_RST_Pin| LCD_RS_Pin| LCD_CS_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;//��ͨ���ģʽ
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//����
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	// LCD_LED=1;  //��������
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, current_brightness_value);
}

/**
 * @brief LCD��λ����
 */
void LCD_RESET(void)
{
	LCD_RST_CLR;
	delay_ms(100);	
	LCD_RST_SET;
	delay_ms(50);
}

/**
 * @brief LCD��ʼ������
 * ����SPI��ʼ����GPIO��ʼ������λ�ͼĴ�������
 */
void LCD_Init(void)
{  
	// SPI1_Init(); //Ӳ��SPI��ʼ��
	LCD_GPIOInit();//LCD GPIO��ʼ��										 
 	LCD_RESET(); //LCD ��λ
//*************3.5 ST7796S IPS��ʼ��**********//	
	LCD_WR_REG(0x11);     

	delay_ms(120);                //Delay 120ms

	LCD_WR_REG(0x36);     // Memory Data Access Control MY,MX~~
	LCD_WR_DATA(0x48);   

	LCD_WR_REG(0x3A);     
	LCD_WR_DATA(0x55);   

	LCD_WR_REG(0xF0);     // Command Set Control
	LCD_WR_DATA(0xC3);   

	LCD_WR_REG(0xF0);     
	LCD_WR_DATA(0x96);   

	LCD_WR_REG(0xB4);     
	LCD_WR_DATA(0x02);   

	LCD_WR_REG(0xB7);     
	LCD_WR_DATA(0xC6);   

	LCD_WR_REG(0xC0);     
	LCD_WR_DATA(0xC0);   
	LCD_WR_DATA(0x00);   

	LCD_WR_REG(0xC1);     
	LCD_WR_DATA(0x13);   

	LCD_WR_REG(0xC2);     
	LCD_WR_DATA(0xA7);   

	LCD_WR_REG(0xC5);     
	LCD_WR_DATA(0x21);   

	LCD_WR_REG(0xE8);     
	LCD_WR_DATA(0x40);   
	LCD_WR_DATA(0x8A);   
	LCD_WR_DATA(0x1B);   
	LCD_WR_DATA(0x1B);   
	LCD_WR_DATA(0x23);   
	LCD_WR_DATA(0x0A);   
	LCD_WR_DATA(0xAC);   
	LCD_WR_DATA(0x33);   

	LCD_WR_REG(0xE0);     
	LCD_WR_DATA(0xD2);   
	LCD_WR_DATA(0x05);   
	LCD_WR_DATA(0x08);   
	LCD_WR_DATA(0x06);   
	LCD_WR_DATA(0x05);   
	LCD_WR_DATA(0x02);   
	LCD_WR_DATA(0x2A);   
	LCD_WR_DATA(0x44);   
	LCD_WR_DATA(0x46);   
	LCD_WR_DATA(0x39);   
	LCD_WR_DATA(0x15);   
	LCD_WR_DATA(0x15);   
	LCD_WR_DATA(0x2D);   
	LCD_WR_DATA(0x32);   

	LCD_WR_REG(0xE1);     
	LCD_WR_DATA(0x96);   
	LCD_WR_DATA(0x08);   
	LCD_WR_DATA(0x0C);   
	LCD_WR_DATA(0x09);   
	LCD_WR_DATA(0x09);   
	LCD_WR_DATA(0x25);   
	LCD_WR_DATA(0x2E);   
	LCD_WR_DATA(0x43);   
	LCD_WR_DATA(0x42);   
	LCD_WR_DATA(0x35);   
	LCD_WR_DATA(0x11);   
	LCD_WR_DATA(0x11);   
	LCD_WR_DATA(0x28);   
	LCD_WR_DATA(0x2E);   

	LCD_WR_REG(0xF0);     
	LCD_WR_DATA(0x3C);   
	LCD_WR_REG(0xF0);     
	LCD_WR_DATA(0x69);  

	delay_ms(120);                
	LCD_WR_REG(0x21);     
	LCD_WR_REG(0x29);

	LCD_direction(USE_HORIZONTAL);//����LCD��ʾ���� 
	LCD_Clear(WHITE);//��ȫ����ɫ
}

/**
 * @brief ������ʾ��������
 * @param xStar ��ʼX����
 * @param yStar ��ʼY����
 * @param xEnd ����X����
 * @param yEnd ����Y����
 */
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd)
{	
	LCD_WR_REG(lcddev.setxcmd);	
	LCD_WR_DATA(xStar>>8);
	LCD_WR_DATA(0x00FF&xStar);		
	LCD_WR_DATA(xEnd>>8);
	LCD_WR_DATA(0x00FF&xEnd);

	LCD_WR_REG(lcddev.setycmd);	
	LCD_WR_DATA(yStar>>8);
	LCD_WR_DATA(0x00FF&yStar);		
	LCD_WR_DATA(yEnd>>8);
	LCD_WR_DATA(0x00FF&yEnd);

	LCD_WriteRAM_Prepare();	//��ʼд��GRAM			
}   

/**
 * @brief ���ù��λ��
 * @param Xpos X����
 * @param Ypos Y����
 */
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
{	  	    			
	LCD_SetWindows(Xpos,Ypos,Xpos,Ypos);	
} 

/**
 * @brief ����LCD��ʾ����
 * @param direction �������(0-3)
 */
void LCD_direction(uint8_t direction)
{ 
	lcddev.setxcmd=0x2A;
	lcddev.setycmd=0x2B;
	lcddev.wramcmd=0x2C;
	lcddev.rramcmd=0x2E;
	lcddev.dir = direction%4;
	switch(lcddev.dir){		  
		case 0:						 	 		
			lcddev.width=LCD_W;
			lcddev.height=LCD_H;		
			LCD_WriteReg(0x36,(1<<3)|(1<<6));
		break;
		case 1:
			lcddev.width=LCD_H;
			lcddev.height=LCD_W;
			LCD_WriteReg(0x36,(1<<3)|(1<<5));
		break;
		case 2:						 	 		
			lcddev.width=LCD_W;
			lcddev.height=LCD_H;	
			LCD_WriteReg(0x36,(1<<3)|(1<<7));
		break;
		case 3:
			lcddev.width=LCD_H;
			lcddev.height=LCD_W;
			LCD_WriteReg(0x36,(1<<3)|(1<<7)|(1<<6)|(1<<5));
		break;	
		default:break;
	}		
}	 

/**
 * @brief ��ȡLCD ID
 * @return LCD��IDֵ
 */
uint16_t LCD_Read_ID(void)
{
	uint8_t i,val[3] = {0};
	LCD_WR_REG(0xF0);     // Command Set Control
	LCD_WR_DATA(0xC3);   
	LCD_WR_REG(0xF0);     
	LCD_WR_DATA(0x96);  
	LCD_CS_CLR;
	for(i=1;i<4;i++)
	{
		LCD_RS_CLR;	  
		SPI_WriteByte(SPI1,0xFB);
		LCD_RS_SET;
		SPI_WriteByte(SPI1,0x10+i);
		LCD_RS_CLR;	  
		SPI_WriteByte(SPI1,0xD3);
		SPI_SetSpeed(SPI1,0);
		LCD_RS_SET;
		val[i-1] = SPI_WriteByte(SPI1,0xFF);
		SPI_SetSpeed(SPI1,1);
		LCD_RS_CLR;	  
		SPI_WriteByte(SPI1,0xFB);
		LCD_RS_SET;
		SPI_WriteByte(SPI1,0x00);	
	}
	LCD_CS_SET;
	LCD_WR_REG(0xF0);     // Command Set Control
	LCD_WR_DATA(0x3C);   
	LCD_WR_REG(0xF0);     
	LCD_WR_DATA(0x69);  
	lcddev.id=val[1];
	lcddev.id<<=8;
	lcddev.id|=val[2];
	return lcddev.id;
}


/**
 * @brief ʹ��DMA�����ɫ����
 * @param x1 ������ʼX����
 * @param y1 ������ʼY����
 * @param x2 �������X����
 * @param y2 �������Y����
 * @param color_p ��ɫ��������(RGB565��ʽ)
 */
void lcd_color_fill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t *color_p)
{
    uint32_t size = (x2 - x1 + 1) * (y2 - y1 + 1);
    LCD_SetWindows(x1, y1, x2, y2);
    LCD_CS_CLR;
    LCD_RS_SET;
    
    // ���建������С�����ݿ����ڴ������
    #define BUF_SIZE 256
    uint8_t buffer[BUF_SIZE * 2];
    uint32_t processed = 0;
    
    while(processed < size) {
        uint32_t chunk = (size - processed) > BUF_SIZE ? BUF_SIZE : (size - processed);
        // Ԥ�������ݵ�������
        for(uint32_t i = 0; i < chunk; i++) {
            buffer[i*2] = color_p[processed + i] >> 8;    // ���ֽ�
            buffer[i*2+1] = color_p[processed + i] & 0xFF; // ���ֽ�
        }
        // ��������
        HAL_SPI_Transmit_DMA(&hspi1, buffer, chunk * 2);
        // �ȴ��������
        while (HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
        processed += chunk;
    }
    LCD_CS_SET;
}
