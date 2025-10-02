/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_16(lv_ui *ui)
{
    //Write codes screen_16
    ui->screen_16 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_16, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_16, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_16, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_16, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_16_tileview_1
    ui->screen_16_tileview_1 = lv_tileview_create(ui->screen_16);
    ui->screen_16_tileview_1_tile = lv_tileview_add_tile(ui->screen_16_tileview_1, 0, 0, LV_DIR_RIGHT);
    lv_obj_set_pos(ui->screen_16_tileview_1, 25, 2);
    lv_obj_set_size(ui->screen_16_tileview_1, 409, 718);
    lv_obj_set_scrollbar_mode(ui->screen_16_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_16_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_16_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_16_tileview_1, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_16_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_16_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_16_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_16_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_16_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_16_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_16_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_16_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes screen_16_label_1
    ui->screen_16_label_1 = lv_label_create(ui->screen_16_tileview_1_tile);
    lv_label_set_text(ui->screen_16_label_1, "智能药仓结合机电一体化硬件、AI中枢和云端协同网络，全面覆盖医院药房管理和家庭健康监护的场景需求。 "
"系统以STM32H7高性能处理器为核心，搭载轻量化AI视觉识别模型；主控STM32F407负责协调药仓的机电控制系统，可选择无线透传模块或有线通信方式， "
"与控制单元及其执行器交互，实现药品的精准抓取和配送。机械结构采用模块化设计，分隔式药仓可灵活调整，可根据适用场景做出调整。/n"
"药仓还配备多模态传感器阵列，用于实时监控药品存储环境，智能感知用户接近自动唤醒系统；服药智能提醒系统可自定义服药时间，通过语音播报、LED指示灯和手机APP推送等提醒方式； "
"系统基于药品数据库自动分析药物配伍禁忌，在取药时提供安全警示；嵌入式图形化操作界面采用触控屏实现交互，提升面向对象的使用体验。/n"
"除基础功能的实现，药仓配套跨平台手机APP，允许用户远程管理药仓。 "
"所有数据通过MQTT协议同步至OneNET云平台，实现多设备间的数据共享。 ");

		lv_label_set_long_mode(ui->screen_16_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_16_label_1, 6, 16);
    lv_obj_set_size(ui->screen_16_label_1, 398, 749);

    //Write style for screen_16_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_16_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_16_label_1, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_16_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_16_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_16_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_16.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_16);

    //Init events for screen.
    events_init_screen_16(ui);
}
