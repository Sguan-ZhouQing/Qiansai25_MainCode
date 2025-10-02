/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-08 17:34:56
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-11 14:23:32
 * @FilePath: \demo_STM32F407code\Hardware\Flash_own.c
 * @Description: 实现STM32掉电不丢失数据，向扇区11号写入数据(同时系统代码从扇区0号开始写入)
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "Flash_own.h"

#define VAR_SECTOR    FLASH_SECTOR_11  // Sector 11
#define VAR_ADDR      0x080E0000      // Sector 11 起始地址

/**
 * @description: 写擦F407主FLASH扇区11位
 * @param {uint32_t} data
 * @return {*}
 */
void Flash_Write_Variable(uint32_t data) {
    FLASH_EraseInitTypeDef erase;
    uint32_t sectorError = 0;

    // 擦除 Sector 11（16KB）
    erase.TypeErase = FLASH_TYPEERASE_SECTORS;
    erase.Sector = VAR_SECTOR;
    erase.NbSectors = 1;
    erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    HAL_FLASH_Unlock();
    HAL_FLASHEx_Erase(&erase, &sectorError);
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, VAR_ADDR, data);
    HAL_FLASH_Lock();
}


/**
 * @description: 读取扇区11位的数据(一般是系统刚开机时读取)
 * @return {*}
 */
uint32_t Flash_Read_Variable(void) {
    return *((volatile uint32_t*)VAR_ADDR);  // 直接读取
}

