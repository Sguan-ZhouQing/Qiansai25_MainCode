//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STM32F407ZGT6,����ԭ��Explorer STM32F4������,��Ƶ168MHZ������12MHZ
//QDtech-TFTҺ������ for STM32 IOģ��
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtft.com
//�Ա���վ��http://qdtech.taobao.com
//wiki������վ��http://www.lcdwiki.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com 
//����֧��QQ:3002773612  3002778157
//��������QQȺ:324828016
//��������:2018/08/09
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================��Դ����================================================//
//     LCDģ��                STM32��Ƭ��
//      VCC          ��        DC5V/3.3V      //��Դ
//      GND          ��          GND          //��Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������ΪSPI����
//     LCDģ��                STM32��Ƭ��    
//    SDI(MOSI)      ��          PB5          //Һ����SPI��������д�ź�
//    SDO(MISO)      ��          PB4          //Һ����SPI�������ݶ��źţ��������Ҫ�������Բ�����
//=======================================Һ���������߽���==========================================//
//     LCDģ�� 					      STM32��Ƭ�� 
//       LED         ��          PB13         //Һ������������źţ��������Ҫ���ƣ���5V��3.3V
//       SCK         ��          PB3          //Һ����SPI����ʱ���ź�
//     LCD_RS        ��          PB14         //Һ��������/��������ź�
//     LCD_RST       ��          PB12         //Һ������λ�����ź�
//     LCD_CS        ��          PB15         //Һ����Ƭѡ�����ź�
//=========================================������������=========================================//
//���ģ�鲻���������ܻ��ߴ��д������ܣ����ǲ���Ҫ�������ܣ�����Ҫ���д���������
//	   LCDģ��                STM32��Ƭ�� 
//     CTP_INT       ��          PB1          //���ݴ������ж��ź�
//     CTP_SDA       ��          PF11         //���ݴ�����IIC�����ź�
//     CTP_RST       ��          PC5          //���ݴ�������λ�ź�
//     CTP_SCL       ��          PB0          //���ݴ�����IICʱ���ź�
**************************************************************************************************/	
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#include "mySPI.h"

extern SPI_HandleTypeDef hspi1;  // SPI1���

/*****************************************************************************
 * @name       :u8 SPI_WriteByte(SPI_TypeDef* SPIx, u8 Byte)
 * @date       :2018-08-09 
 * @function   :Write a byte of data using STM32's hardware SPI
 * @parameters :SPIx: SPI����(ʵ��ʹ��hspi1���)
                Byte:Ҫд�������
 * @retvalue   :���߽��յ�������
******************************************************************************/
uint8_t SPI_WriteByte(SPI_HandleTypeDef* SPIx, uint8_t Byte)
{
    uint8_t received = 0;
    HAL_SPI_TransmitReceive(&hspi1, &Byte, &received, 1, HAL_MAX_DELAY);
    return received;
}

/*****************************************************************************
 * @name       :void SPI_SetSpeed(SPI_TypeDef* SPIx, u8 SpeedSet)
 * @date       :2018-08-09 
 * @function   :����Ӳ��SPI�ٶ�
 * @parameters :SPIx: SPI����(ʵ��ʹ��hspi1���)
                SpeedSet:0-����
                         1-����
 * @retvalue   :None
******************************************************************************/
void SPI_SetSpeed(SPI_HandleTypeDef* SPIx, uint8_t SpeedSet)
{
    hspi1.Instance->CR1 &= ~SPI_CR1_BR;  // ���Ԥ��Ƶλ
    
    if(SpeedSet == 1) // ����
    {
        hspi1.Instance->CR1 |= SPI_BAUDRATEPRESCALER_2;  // Fpclk/2
    }
    else // ����
    {
        hspi1.Instance->CR1 |= SPI_BAUDRATEPRESCALER_16; // Fpclk/16
    }
    
    __HAL_SPI_ENABLE(&hspi1);  // ʹ��SPI
}

/*****************************************************************************
 * @name       :void SPI1_Init(void)    
 * @date       :2018-08-09 
 * @function   :��ʼ��STM32Ӳ��SPI1
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void SPI1_Init(void)    
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // 1. ʹ��ʱ��
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_SPI1_CLK_ENABLE();
    
    // 2. ����GPIO
    // PB3(SCK), PB4(MISO), PB5(MOSI)
    GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    // 3. ����SPI
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
    hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;
    if (HAL_SPI_Init(&hspi1) != HAL_OK)
    {
        // ��ʼ��������
        while(1);
    }
    
    // 4. ʹ��SPI
    __HAL_SPI_ENABLE(&hspi1);
}
