/*
 * @Author: 星必尘Sguan
 * @Date: 2025-07-03 16:06:29
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-07-03 16:50:01
 * @FilePath: \demo_STM32F407code\Hardware\RTC_Timer.c
 * @Description: 实现云平台下发时间戳，实现RTC时钟的校准
 * @Key_GPIO: NULL;
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "RTC_Timer.h"

extern uint32_t timer;
extern RTC_HandleTypeDef hrtc;

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

/**
 * @description: 时间戳转换HAL库RTC参数的函数
 * @param {uint32_t} timestamp
 * @param {RTC_TimeTypeDef} *sTime
 * @param {RTC_DateTypeDef} *sDate
 * @return {*}
 */
static void TimestampToRTC(uint32_t timestamp, RTC_TimeTypeDef *sTime, RTC_DateTypeDef *sDate) {
    struct tm *timeinfo;
    time_t t = (time_t)timestamp;
    timeinfo = localtime(&t);

    sTime->Hours = timeinfo->tm_hour;
    sTime->Minutes = timeinfo->tm_min;
    sTime->Seconds = timeinfo->tm_sec;
    sTime->TimeFormat = RTC_HOURFORMAT_24; // 24小时制

    sDate->Date = timeinfo->tm_mday;
    sDate->Month = timeinfo->tm_mon + 1;  // tm_mon范围是0-11
    sDate->Year = timeinfo->tm_year - 100; // RTC的Year是00-99（对应2000-2099）
    sDate->WeekDay = timeinfo->tm_wday + 1; // RTC的WeekDay是1-7
}

/**
 * @description: 更新一次RTC时钟的日期信息
 * @return {*}
 */
void RTC_TimerUpdate(void)
{
    // 转换时间戳
    TimestampToRTC(timer, &sTime, &sDate);

    // 设置RTC时间和日期
    HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}



