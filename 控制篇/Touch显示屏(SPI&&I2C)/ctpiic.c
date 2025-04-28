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
#include "ctpiic.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;  // �������������ط�������I2C1�ľ��

/*****************************************************************************
 * @name       :void CTP_Delay(void)
 * @date       :2020-05-13 
 * @function   :Delay in controlling IIC speed
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_Delay(void)
{
    HAL_Delay(1);
} 

/*****************************************************************************
 * @name       :void CTP_IIC_Init(void)
 * @date       :2020-05-13 
 * @function   :Initialize IIC
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Init(void)
{
    // HAL����I2C��ʼ��ͨ����MX_I2C1_Init()�����
    // ���ﲻ��Ҫ����ĳ�ʼ������
}

/*****************************************************************************
 * @name       :void CTP_IIC_Start(void)
 * @date       :2020-05-13 
 * @function   :Generating IIC starting signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Start(void)
{
    // HAL���Զ�������ʼ����
}

/*****************************************************************************
 * @name       :void CTP_IIC_Stop(void)
 * @date       :2020-05-13 
 * @function   :Generating IIC stop signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/   
void CTP_IIC_Stop(void)
{
    // HAL���Զ�����ֹͣ����
}

/*****************************************************************************
 * @name       :u8 CTP_IIC_Wait_Ack(void)
 * @date       :2020-05-13 
 * @function   :Wait for the response signal
 * @parameters :None
 * @retvalue   :0-receive response signal successfully
               1-receive response signal unsuccessfully
******************************************************************************/ 
uint8_t CTP_IIC_Wait_Ack(void)
{
    // HAL���Զ�����ACK/NACK
    return 0;  // ���Ƿ��سɹ���ʵ�ʴ�������HAL_I2C_Master_Transmit�Ⱥ�����
}

/*****************************************************************************
 * @name       :void CTP_IIC_Ack(void)
 * @date       :2020-05-13 
 * @function   :Generate ACK response signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/ 
void CTP_IIC_Ack(void)
{
    // HAL���Զ�����ACK
}

/*****************************************************************************
 * @name       :void CTP_IIC_NAck(void)
 * @date       :2020-05-13 
 * @function   :Don't generate ACK response signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/    
void CTP_IIC_NAck(void)
{
    // HAL���Զ�����NACK
}

/*****************************************************************************
 * @name       :void CTP_IIC_Send_Byte(u8 txd)
 * @date       :2020-05-13 
 * @function   :send a byte data by IIC bus
 * @parameters :txd:Data to be sent
 * @retvalue   :None
******************************************************************************/                     
void CTP_IIC_Send_Byte(uint8_t txd)
{
    // ��HAL���У��ֽڷ���ͨ��HAL_I2C_Master_Transmit�Ⱥ������
    // ��������һ���ֽڲ�������ͨ����Ҫ����豸��ַ�ͼĴ�����ַ
}

/*****************************************************************************
 * @name       :u8 CTP_IIC_Read_Byte(unsigned char ack)
 * @date       :2020-05-13 
 * @function   :read a byte data by IIC bus
 * @parameters :ack:0-send nACK
                 1-send ACK
 * @retvalue   :Data to be read
******************************************************************************/     
uint8_t CTP_IIC_Read_Byte(unsigned char ack)
{
    uint8_t data = 0;
    // ��HAL���У��ֽڶ�ȡͨ��HAL_I2C_Master_Receive�Ⱥ������
    return data;
}

/*****************************************************************************
 * @name       :HAL_StatusTypeDef CTP_IIC_Write_Reg(u8 dev_addr, u8 reg, u8 value)
 * @date       :2020-05-13 
 * @function   :Write data to IIC device register
 * @parameters :dev_addr: device address
 *              reg: register address
 *              value: data to write
 * @retvalue   :HAL status
******************************************************************************/
HAL_StatusTypeDef CTP_IIC_Write_Reg(uint8_t dev_addr, uint8_t reg, uint8_t value)
{
    return HAL_I2C_Mem_Write(&hi2c1, dev_addr, reg, I2C_MEMADD_SIZE_8BIT, &value, 1, HAL_MAX_DELAY);
}

/*****************************************************************************
 * @name       :HAL_StatusTypeDef CTP_IIC_Read_Reg(u8 dev_addr, u8 reg, u8 *buf, u16 len)
 * @date       :2020-05-13 
 * @function   :Read data from IIC device register
 * @parameters :dev_addr: device address
 *              reg: register address
 *              buf: buffer to store data
 *              len: data length
 * @retvalue   :HAL status
******************************************************************************/
HAL_StatusTypeDef CTP_IIC_Read_Reg(uint8_t dev_addr, uint8_t reg, uint8_t *buf, uint16_t len)
{
    return HAL_I2C_Mem_Read(&hi2c1, dev_addr, reg, I2C_MEMADD_SIZE_8BIT, buf, len, HAL_MAX_DELAY);
}




























