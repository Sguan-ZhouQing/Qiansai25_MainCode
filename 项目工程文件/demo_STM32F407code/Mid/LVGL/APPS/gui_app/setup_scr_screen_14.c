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



void setup_scr_screen_14(lv_ui *ui)
{
    //Write codes screen_14
    ui->screen_14 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_14, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_14, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_6
    ui->screen_14_btn_6 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_6, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_6_label = lv_label_create(ui->screen_14_btn_6);
    lv_label_set_text(ui->screen_14_btn_6_label, "6");
    lv_label_set_long_mode(ui->screen_14_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_6, 144, 233);
    lv_obj_set_size(ui->screen_14_btn_6, 64, 74);

    //Write style for screen_14_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_6, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_5
    ui->screen_14_btn_5 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_5, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_5_label = lv_label_create(ui->screen_14_btn_5);
    lv_label_set_text(ui->screen_14_btn_5_label, "5");
    lv_label_set_long_mode(ui->screen_14_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_5, 72, 233);
    lv_obj_set_size(ui->screen_14_btn_5, 65, 73);

    //Write style for screen_14_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_5, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_4
    ui->screen_14_btn_4 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_4_label = lv_label_create(ui->screen_14_btn_4);
    lv_label_set_text(ui->screen_14_btn_4_label, "3");
    lv_label_set_long_mode(ui->screen_14_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_4, 72, 152);
    lv_obj_set_size(ui->screen_14_btn_4, 64, 75);

    //Write style for screen_14_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_4, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_3
    ui->screen_14_btn_3 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_3_label = lv_label_create(ui->screen_14_btn_3);
    lv_label_set_text(ui->screen_14_btn_3_label, "4");
    lv_label_set_long_mode(ui->screen_14_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_3, 144, 153);
    lv_obj_set_size(ui->screen_14_btn_3, 64, 74);

    //Write style for screen_14_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_3, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_2
    ui->screen_14_btn_2 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_2_label = lv_label_create(ui->screen_14_btn_2);
    lv_label_set_text(ui->screen_14_btn_2_label, "2");
    lv_label_set_long_mode(ui->screen_14_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_2, 144, 73);
    lv_obj_set_size(ui->screen_14_btn_2, 63, 73);

    //Write style for screen_14_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_2, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_1
    ui->screen_14_btn_1 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_1_label = lv_label_create(ui->screen_14_btn_1);
    lv_label_set_text(ui->screen_14_btn_1_label, "1");
    lv_label_set_long_mode(ui->screen_14_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_1, 72, 73);
    lv_obj_set_size(ui->screen_14_btn_1, 65, 72);

    //Write style for screen_14_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_1, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_12
    ui->screen_14_btn_12 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_12, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_12_label = lv_label_create(ui->screen_14_btn_12);
    lv_label_set_text(ui->screen_14_btn_12_label, "12");
    lv_label_set_long_mode(ui->screen_14_btn_12_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_12_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_12, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_12_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_12, 346, 236);
    lv_obj_set_size(ui->screen_14_btn_12, 61, 71);

    //Write style for screen_14_btn_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_12, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_12, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_12, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_11
    ui->screen_14_btn_11 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_11, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_11_label = lv_label_create(ui->screen_14_btn_11);
    lv_label_set_text(ui->screen_14_btn_11_label, "11");
    lv_label_set_long_mode(ui->screen_14_btn_11_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_11_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_11, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_11_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_11, 275, 236);
    lv_obj_set_size(ui->screen_14_btn_11, 64, 70);

    //Write style for screen_14_btn_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_11, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_11, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_11, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_10
    ui->screen_14_btn_10 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_10, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_10_label = lv_label_create(ui->screen_14_btn_10);
    lv_label_set_text(ui->screen_14_btn_10_label, "10");
    lv_label_set_long_mode(ui->screen_14_btn_10_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_10_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_10, 345, 154);
    lv_obj_set_size(ui->screen_14_btn_10, 61, 74);

    //Write style for screen_14_btn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_10, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_9
    ui->screen_14_btn_9 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_9, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_9_label = lv_label_create(ui->screen_14_btn_9);
    lv_label_set_text(ui->screen_14_btn_9_label, "9");
    lv_label_set_long_mode(ui->screen_14_btn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_9_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_9, 275, 154);
    lv_obj_set_size(ui->screen_14_btn_9, 63, 72);

    //Write style for screen_14_btn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_9, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_8
    ui->screen_14_btn_8 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_8, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_8_label = lv_label_create(ui->screen_14_btn_8);
    lv_label_set_text(ui->screen_14_btn_8_label, "8\n");
    lv_label_set_long_mode(ui->screen_14_btn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_8_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_8, 346, 73);
    lv_obj_set_size(ui->screen_14_btn_8, 61, 76);

    //Write style for screen_14_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_8, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_7
    ui->screen_14_btn_7 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_7, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_7_label = lv_label_create(ui->screen_14_btn_7);
    lv_label_set_text(ui->screen_14_btn_7_label, "7\n");
    lv_label_set_long_mode(ui->screen_14_btn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_7_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_7, 275, 71);
    lv_obj_set_size(ui->screen_14_btn_7, 64, 77);

    //Write style for screen_14_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_7, lv_color_hex(0xD4CBB2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_13
    ui->screen_14_btn_13 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_13, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_13_label = lv_label_create(ui->screen_14_btn_13);
    lv_label_set_text(ui->screen_14_btn_13_label, "存药");
    lv_label_set_long_mode(ui->screen_14_btn_13_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_13_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_13, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_13_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_13, 72, 15);
    lv_obj_set_size(ui->screen_14_btn_13, 132, 45);

    //Write style for screen_14_btn_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_13, lv_color_hex(0x88B3AE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_13, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_13, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_btn_14
    ui->screen_14_btn_14 = lv_btn_create(ui->screen_14);
    lv_obj_add_flag(ui->screen_14_btn_14, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_14_btn_14_label = lv_label_create(ui->screen_14_btn_14);
    lv_label_set_text(ui->screen_14_btn_14_label, "取药");
    lv_label_set_long_mode(ui->screen_14_btn_14_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_14_btn_14_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_14_btn_14, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_14_btn_14_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_14_btn_14, 275, 15);
    lv_obj_set_size(ui->screen_14_btn_14, 132, 45);

    //Write style for screen_14_btn_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_14_btn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_14_btn_14, lv_color_hex(0x88B3AE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_14_btn_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_14_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_14_btn_14, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_14_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_14_btn_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_14_btn_14, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_14_btn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_14_btn_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_line_1
    ui->screen_14_line_1 = lv_line_create(ui->screen_14);
    static lv_point_t screen_14_line_1[] = {{0, 0},{0, 95},};
    lv_line_set_points(ui->screen_14_line_1, screen_14_line_1, 2);
    lv_obj_set_pos(ui->screen_14_line_1, 239, -29);
    lv_obj_set_size(ui->screen_14_line_1, 1, 91);

    //Write style for screen_14_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_14_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_14_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_14_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_14_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_14_line_2
    ui->screen_14_line_2 = lv_line_create(ui->screen_14);
    static lv_point_t screen_14_line_2[] = {{0, 0},{1000, 0},};
    lv_line_set_points(ui->screen_14_line_2, screen_14_line_2, 2);
    lv_obj_set_pos(ui->screen_14_line_2, -10, 64);
    lv_obj_set_size(ui->screen_14_line_2, 531, 4);

    //Write style for screen_14_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_14_line_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_14_line_2, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_14_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_14_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_14.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_14);

    //Init events for screen.
    events_init_screen_14(ui);
}
