/*
 * @Author: �Ǳس�Sguan
 * @Date: 2025-04-27 21:48:56
 * @LastEditors: �Ǳس�Sguan|3464647102@qq.com
 * @LastEditTime: 2025-04-29 16:16:04
 * @FilePath: \test_SPIscreen\System\delay.c
 * @Description: ʵ��΢�뼶��ʱ
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
// delay.c (HAL �򻯰�)
#include "stm32f4xx_hal.h"

// ΢����ʱ��ѭ����ָ��ʵ�֣�
void delay_us(uint32_t us) {
    uint32_t start = HAL_GetTick() * 1000;  // ��ǰʱ�䣨΢�룩
    while ((HAL_GetTick() * 1000 - start) < us) { /* �ȴ� */ }
}

// ������ʱֱ�ӵ��� HAL
// ע������ʵ�� delay_ms��ֱ���� HAL_Delay()
