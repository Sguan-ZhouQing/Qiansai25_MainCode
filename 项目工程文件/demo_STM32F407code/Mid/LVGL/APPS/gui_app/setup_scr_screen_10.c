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



void setup_scr_screen_10(lv_ui *ui)
{
    //Write codes screen_10
    ui->screen_10 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_10, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_10, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_10, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_10_img_1
    ui->screen_10_img_1 = lv_img_create(ui->screen_10);
    lv_obj_add_flag(ui->screen_10_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_10_img_1, &_99_alpha_70x60);
    lv_img_set_pivot(ui->screen_10_img_1, 50,50);
    lv_img_set_angle(ui->screen_10_img_1, 0);
    lv_obj_set_pos(ui->screen_10_img_1, 133, 108);
    lv_obj_set_size(ui->screen_10_img_1, 70, 60);

    //Write style for screen_10_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_10_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_10_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_10_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_10_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_10_label_1
    ui->screen_10_label_1 = lv_label_create(ui->screen_10);
    lv_label_set_text(ui->screen_10_label_1, "OneNET");
    lv_label_set_long_mode(ui->screen_10_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_10_label_1, 200, 108);
    lv_obj_set_size(ui->screen_10_label_1, 130, 60);

    //Write style for screen_10_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_10_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_10_label_1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_10_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_10_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_10_label_1, 251, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_10_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_10_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_10_label_1, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_10_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_10.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_10);

    //Init events for screen.
    events_init_screen_10(ui);
}
