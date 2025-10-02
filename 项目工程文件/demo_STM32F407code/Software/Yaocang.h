#ifndef __YAOCANG_H
#define __YAOCANG_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h> // 需要使用strcmp函数
#include "json.h"
#include "esp.h"
#include "printf.h"
#include "StressSensing.h"
#include "Key.h"
#include "Buzzer.h"
#include "G431_Control.h"

//存药药物类别汇总
#define gpw 1   //归脾丸
#define shlkfy 2   //双黄连口服液
#define yszxtlqp 3  //盐酸左西替利嗪片
#define sjgml 4 //三九感冒灵
#define axzp 5  //奥硝唑片
#define fgmlp 6 //复方感冒灵片
#define pzzkkl 7    //枇杷止咳颗粒
#define hxzqkfy 8   //藿香正气口服液
#define zhhy 9      //藏红花油
#define ynbyckt 10  //云南白药创可贴
#define ymckl 11    //益母草颗粒


//临时测试函数
void Moment_Stress_UartTest(void);
void Moment_ESP_KeyTest(void);
void Moment_ButtonTest(void);
//实际核心函数
void Yaocang_Command_Tick(void);
void Yaocang_Button_Tick(void);


#endif // YAOCANG_H
