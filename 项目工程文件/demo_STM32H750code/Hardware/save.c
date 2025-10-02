/*
 * @Author: 星必尘Sguan
 * @Date: 2025-07-17 19:51:02
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-17 20:02:39
 * @FilePath: \demo_STM32H750code\Hardware\save.c
 * @Description: 保存照片到SD卡中的函数封装
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "save.h"

#include "fatfs.h"
#include "memorymap.h"
#include "sdmmc.h"
#include <string.h>
#include <stdio.h>
#include "OLED.h"
#include "lcd_spi_154.h"
#include "dcmi_ov2640.h"
#include "sccb.h"

#define SAVE_INTERVAL_MS 10000
uint32_t last_save_time = 0;
uint8_t image_count = 0;
uint8_t save_in_progress = 0;

/**
 * @description: 添加安全的SD卡读写函数
 * @param {uint32_t} frame_count
 * @param {void*} buffer
 * @param {uint32_t} size
 * @return {*}
 */
uint8_t SaveImageToSD(uint32_t frame_count, void* buffer, uint32_t size)
{
    FRESULT res;
    FIL file;
    UINT bytes_written;
    char filename[32];
    
    // 暂停DCMI DMA传输
    OV2640_DCMI_Suspend();
    // 确保DMA传输完成
    while(DCMI_FrameState == 0);
    DCMI_FrameState = 0;
    // 创建文件命名
    sprintf(filename, "IMG/IMG%03lu.RAW", (unsigned long)frame_count);
    // 打开文件
    res = f_open(&file, filename, FA_WRITE | FA_CREATE_ALWAYS);
    if(res != FR_OK)
    {
        OLED_ShowNum(0,40,(uint32_t)res,3,OLED_8X16);
        OLED_Update();
        OV2640_DCMI_Resume();
        return 0;
    }
    // 写入数据
    res = f_write(&file, buffer, size, &bytes_written);
    f_close(&file);
    // 恢复DCMI DMA传输
    OV2640_DCMI_Resume();
    return (res == FR_OK) && (bytes_written == size);
}


/**
 * @description: 每隔一段时间保存一次照片到SD卡中;
 * @return {*}
 */
void Save_ImgToCard(void)
{
    // SAVE_INTERVAL_MS秒保存一张图片，且确保没有正在进行的保存操作
    if((HAL_GetTick() - last_save_time >= SAVE_INTERVAL_MS) && !save_in_progress) {
        save_in_progress = 1;
        last_save_time = HAL_GetTick();
        if(SaveImageToSD(image_count, (void*)Camera_Buffer, OV2640_BufferSize*4)) {
            image_count++;
        }
        save_in_progress = 0;
    }
    OLED_ShowNum(0,20,image_count,3,OLED_8X16);
}

