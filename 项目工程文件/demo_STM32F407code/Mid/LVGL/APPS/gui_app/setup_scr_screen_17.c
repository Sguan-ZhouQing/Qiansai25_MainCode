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



void setup_scr_screen_17(lv_ui *ui)
{
    //Write codes screen_17
    ui->screen_17 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_17, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_17, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_17, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_17, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_17_tileview_1
    ui->screen_17_tileview_1 = lv_tileview_create(ui->screen_17);
    ui->screen_17_tileview_1_tile = lv_tileview_add_tile(ui->screen_17_tileview_1, 0, 0, LV_DIR_RIGHT);
    lv_obj_set_pos(ui->screen_17_tileview_1, 30, 2);
    lv_obj_set_size(ui->screen_17_tileview_1, 409, 699);
    lv_obj_set_scrollbar_mode(ui->screen_17_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_17_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_17_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_17_tileview_1, lv_color_hex(0xB7A8B8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_17_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_17_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_17_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_17_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_17_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_17_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_17_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_17_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes screen_17_label_1
    ui->screen_17_label_1 = lv_label_create(ui->screen_17_tileview_1_tile);
//    lv_label_set_text(ui->screen_17_label_1, "深夜焊台边的特别鸣谢\n\n首先举起沾满松香的烙铁，向ST公司行一个工程师的最高敬礼——感谢STM32H7这位\"算法诗人\"和STM32F407这位\"机电指挥家\"，让药仓能用纳秒级思考演绎出精准抓药的机械芭蕾\n\n必须给单片机家族颁发\"劳模奖章\"，是你们在毫安与兆赫间永不掉线的值守，撑起了整个系统的数字脊梁。\n\n机械结构请收下\"钢铁艺术家\"称号——那丝滑的伺服臂弯是高精度导轨写就的十四行诗，而模块化药格分明是空间收纳的毕加索。\n\n电路系统的功绩藏在线路板的星河流转里：从传感器阵列的神经末梢（感谢 红外感应模块当门神），到电源管理的温柔供血，每一枚电容都是稳住电压江湖的定海神针。\n\n当然不能忘记实验室的工作桌——这张焊过电路、洒过奶茶、量过玄学的\"战损版\"圣坛，承载了比示波器波纹更汹涌的灵感。示波器的探头见证过逻辑分析的狂喜，万用表的表笔丈量过理想与现实的距离。\n\n最后彩蛋献给：\n凌晨三点的波霸奶茶——灵感喷射的液体燃料\n焊台里那缕青烟——祭奠英勇牺牲的0欧电阻\n永远少一字的螺丝刀——机械组永恒的未解之谜\n迷之有效的\"玄学拍打“——专治不明EMC干扰的东方秘术\n是代码与齿轮的共舞，让冷冰冰的硬件吐露治愈的温度");
    lv_label_set_text(ui->screen_17_label_1, "深夜焊台边的特别鸣谢\n\n首先举起沾满松香的烙铁， "
    "向ST公司行一个工程师的最高敬礼——感谢STM32H7这位算法诗人和STM32F407这位机电指挥家，让药仓能用纳秒级 "
    "思考演绎出精准抓药的机械芭蕾\n必须给单片机家族颁发劳模奖章，是你们在毫安与兆赫间永不掉线的值守，撑起了整 "
    "个系统的数字脊梁。\n机械结构请收下钢铁艺术家称号,那丝滑的伺服臂弯是高精度导轨写就的十四行诗，而模块化药格分明 "
    "是空间收纳的毕加索。\n电路系统的功绩藏在线路板的星河流转里：从传感器阵列的神经末梢（感谢红外感应模块当门神），到电源 "
    "管理的温柔供血，每一枚电容都是稳住电压江湖的定海神针。\n当然不能忘记实验室的工作桌——这张焊过电路、洒过奶茶、量过 "
    "玄学的战损版圣坛，承载了比示波器波纹更汹涌的灵感。示波器的探头见证过逻辑分析的狂喜，万用表的表笔丈量过理想与现实"
    "的距离。\n最后彩蛋献给：\n凌晨三点的波霸奶茶，灵感喷射的液体燃料；焊台里那缕青烟——祭奠英勇牺牲的0欧电阻；永远少一"
    "字的螺丝刀，机械组永恒的未解之谜迷之有效的玄学拍打专治不明EMC干扰的东方秘术；是代码与齿轮的共舞，让冷冰 "
    "冰的硬件吐露治愈的温度。 ");
		lv_label_set_long_mode(ui->screen_17_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_17_label_1, 8, 17);
    lv_obj_set_size(ui->screen_17_label_1, 397, 651);

    //Write style for screen_17_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_17_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_17_label_1, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_17_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_17_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_17_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_17.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_17);

    //Init events for screen.
    events_init_screen_17(ui);
}
