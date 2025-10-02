/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_ta_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_btn_1;
	lv_obj_t *screen_1_btn_1_label;
	lv_obj_t *screen_1_btn_2;
	lv_obj_t *screen_1_btn_2_label;
	lv_obj_t *screen_1_btn_4;
	lv_obj_t *screen_1_btn_4_label;
	lv_obj_t *screen_1_img_2;
	lv_obj_t *screen_1_img_4;
	lv_obj_t *screen_1_img_5;
	lv_obj_t *screen_2;
	bool screen_2_del;
	lv_obj_t *screen_2_label_1;
	lv_obj_t *screen_2_ta_1;
	lv_obj_t *screen_2_label_2;
	lv_obj_t *screen_2_ddlist_1;
	lv_obj_t *screen_2_label_3;
	lv_obj_t *screen_2_btn_2;
	lv_obj_t *screen_2_btn_2_label;
	lv_obj_t *screen_3;
	bool screen_3_del;
	lv_obj_t *screen_3_label_1;
	lv_obj_t *screen_3_label_2;
	lv_obj_t *screen_3_roller_1;
	lv_obj_t *screen_3_btn_2;
	lv_obj_t *screen_3_btn_2_label;
	lv_obj_t *screen_4;
	bool screen_4_del;
	lv_obj_t *screen_4_label_3;
	lv_obj_t *screen_4_btn_1;
	lv_obj_t *screen_4_btn_1_label;
	lv_obj_t *screen_4_label_4;
	lv_obj_t *screen_4_spangroup_1;
	lv_span_t *screen_4_spangroup_1_span;
	lv_obj_t *screen_4_img_1;
	lv_obj_t *screen_4_datetext_1;
	lv_obj_t *screen_5;
	bool screen_5_del;
	lv_obj_t *screen_5_tileview_1;
	lv_obj_t *screen_5_tileview_1_tile;
	lv_obj_t *screen_5_imgbtn_2;
	lv_obj_t *screen_5_imgbtn_2_label;
	lv_obj_t *screen_5_imgbtn_4;
	lv_obj_t *screen_5_imgbtn_4_label;
	lv_obj_t *screen_5_imgbtn_5;
	lv_obj_t *screen_5_imgbtn_5_label;
	lv_obj_t *screen_5_imgbtn_6;
	lv_obj_t *screen_5_imgbtn_6_label;
	lv_obj_t *screen_5_imgbtn_7;
	lv_obj_t *screen_5_imgbtn_7_label;
	lv_obj_t *screen_5_label_1;
	lv_obj_t *screen_5_label_2;
	lv_obj_t *screen_5_label_3;
	lv_obj_t *screen_5_label_4;
	lv_obj_t *screen_5_label_5;
	lv_obj_t *screen_5_label_6;
	lv_obj_t *screen_5_label_7;
	lv_obj_t *screen_5_imgbtn_8;
	lv_obj_t *screen_5_imgbtn_8_label;
	lv_obj_t *screen_5_imgbtn_9;
	lv_obj_t *screen_5_imgbtn_9_label;
	lv_obj_t *screen_7;
	bool screen_7_del;
	lv_obj_t *screen_7_label_1;
	lv_obj_t *screen_7_label_2;
	lv_obj_t *screen_7_line_1;
	lv_obj_t *screen_7_line_2;
	lv_obj_t *screen_7_line_3;
	lv_obj_t *screen_7_line_4;
	lv_obj_t *screen_7_line_5;
	lv_obj_t *screen_7_line_6;
	lv_obj_t *screen_7_line_7;
	lv_obj_t *screen_7_line_8;
	lv_obj_t *screen_7_line_9;
	lv_obj_t *screen_7_line_11;
	lv_obj_t *screen_7_line_16;
	lv_obj_t *screen_7_line_18;
	lv_obj_t *screen_7_line_19;
	lv_obj_t *screen_7_line_20;
	lv_obj_t *screen_7_btn_1;
	lv_obj_t *screen_7_btn_1_label;
	lv_obj_t *screen_7_btn_5;
	lv_obj_t *screen_7_btn_5_label;
	lv_obj_t *screen_7_btn_6;
	lv_obj_t *screen_7_btn_6_label;
	lv_obj_t *screen_7_btn_4;
	lv_obj_t *screen_7_btn_4_label;
	lv_obj_t *screen_7_btn_3;
	lv_obj_t *screen_7_btn_3_label;
	lv_obj_t *screen_7_btn_2;
	lv_obj_t *screen_7_btn_2_label;
	lv_obj_t *screen_7_btn_7;
	lv_obj_t *screen_7_btn_7_label;
	lv_obj_t *screen_7_btn_8;
	lv_obj_t *screen_7_btn_8_label;
	lv_obj_t *screen_7_btn_9;
	lv_obj_t *screen_7_btn_9_label;
	lv_obj_t *screen_7_btn_10;
	lv_obj_t *screen_7_btn_10_label;
	lv_obj_t *screen_7_btn_11;
	lv_obj_t *screen_7_btn_11_label;
	lv_obj_t *screen_7_btn_12;
	lv_obj_t *screen_7_btn_12_label;
	lv_obj_t *screen_8;
	bool screen_8_del;
	lv_obj_t *screen_8_btn_1;
	lv_obj_t *screen_8_btn_1_label;
	lv_obj_t *screen_8_btn_2;
	lv_obj_t *screen_8_btn_2_label;
	lv_obj_t *screen_8_btn_3;
	lv_obj_t *screen_8_btn_3_label;
	lv_obj_t *screen_8_ddlist_1;
	lv_obj_t *screen_8_ddlist_2;
	lv_obj_t *screen_8_ddlist_3;
	lv_obj_t *screen_6;
	bool screen_6_del;
	lv_obj_t *screen_6_label_1;
	lv_obj_t *screen_6_label_2;
	lv_obj_t *screen_14;
	bool screen_14_del;
	lv_obj_t *screen_14_btn_6;
	lv_obj_t *screen_14_btn_6_label;
	lv_obj_t *screen_14_btn_5;
	lv_obj_t *screen_14_btn_5_label;
	lv_obj_t *screen_14_btn_4;
	lv_obj_t *screen_14_btn_4_label;
	lv_obj_t *screen_14_btn_3;
	lv_obj_t *screen_14_btn_3_label;
	lv_obj_t *screen_14_btn_2;
	lv_obj_t *screen_14_btn_2_label;
	lv_obj_t *screen_14_btn_1;
	lv_obj_t *screen_14_btn_1_label;
	lv_obj_t *screen_14_btn_12;
	lv_obj_t *screen_14_btn_12_label;
	lv_obj_t *screen_14_btn_11;
	lv_obj_t *screen_14_btn_11_label;
	lv_obj_t *screen_14_btn_10;
	lv_obj_t *screen_14_btn_10_label;
	lv_obj_t *screen_14_btn_9;
	lv_obj_t *screen_14_btn_9_label;
	lv_obj_t *screen_14_btn_8;
	lv_obj_t *screen_14_btn_8_label;
	lv_obj_t *screen_14_btn_7;
	lv_obj_t *screen_14_btn_7_label;
	lv_obj_t *screen_14_btn_13;
	lv_obj_t *screen_14_btn_13_label;
	lv_obj_t *screen_14_btn_14;
	lv_obj_t *screen_14_btn_14_label;
	lv_obj_t *screen_14_line_1;
	lv_obj_t *screen_14_line_2;
	lv_obj_t *screen_11;
	bool screen_11_del;
	lv_obj_t *screen_11_label_1;
	lv_obj_t *screen_11_label_2;
	lv_obj_t *screen_10;
	bool screen_10_del;
	lv_obj_t *screen_10_img_1;
	lv_obj_t *screen_10_label_1;
	lv_obj_t *screen_15;
	bool screen_15_del;
	lv_obj_t *screen_15_tileview_1;
	lv_obj_t *screen_15_tileview_1_tile;
	lv_obj_t *screen_15_imgbtn_5;
	lv_obj_t *screen_15_imgbtn_5_label;
	lv_obj_t *screen_15_imgbtn_6;
	lv_obj_t *screen_15_imgbtn_6_label;
	lv_obj_t *screen_15_imgbtn_7;
	lv_obj_t *screen_15_imgbtn_7_label;
	lv_obj_t *screen_15_label_1;
	lv_obj_t *screen_15_label_4;
	lv_obj_t *screen_15_label_5;
	lv_obj_t *screen_15_label_6;
	lv_obj_t *screen_15_label_7;
	lv_obj_t *screen_15_imgbtn_9;
	lv_obj_t *screen_15_imgbtn_9_label;
	lv_obj_t *screen_15_slider_1;
	lv_obj_t *screen_16;
	bool screen_16_del;
	lv_obj_t *screen_16_tileview_1;
	lv_obj_t *screen_16_tileview_1_tile;
	lv_obj_t *screen_16_label_1;
	lv_obj_t *screen_17;
	bool screen_17_del;
	lv_obj_t *screen_17_tileview_1;
	lv_obj_t *screen_17_tileview_1_tile;
	lv_obj_t *screen_17_label_1;
	lv_obj_t *g_kb_top_layer;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
void setup_scr_screen_2(lv_ui *ui);
void setup_scr_screen_3(lv_ui *ui);
void setup_scr_screen_4(lv_ui *ui);
void setup_scr_screen_5(lv_ui *ui);
void setup_scr_screen_7(lv_ui *ui);
void setup_scr_screen_8(lv_ui *ui);
void setup_scr_screen_6(lv_ui *ui);
void setup_scr_screen_14(lv_ui *ui);
void setup_scr_screen_11(lv_ui *ui);
void setup_scr_screen_10(lv_ui *ui);
void setup_scr_screen_15(lv_ui *ui);
void setup_scr_screen_16(lv_ui *ui);
void setup_scr_screen_17(lv_ui *ui);
LV_IMG_DECLARE(_63_alpha_50x50);
LV_IMG_DECLARE(_65_alpha_50x50);
LV_IMG_DECLARE(_33_alpha_50x50);
LV_IMG_DECLARE(_37_alpha_50x50);
LV_IMG_DECLARE(_31_alpha_50x50);
LV_IMG_DECLARE(_72_alpha_50x50);
LV_IMG_DECLARE(_38_alpha_70x70);
LV_IMG_DECLARE(_39_alpha_70x70);
LV_IMG_DECLARE(_41_alpha_70x70);
LV_IMG_DECLARE(_40_alpha_70x70);
LV_IMG_DECLARE(_36_alpha_70x70);
LV_IMG_DECLARE(_34_alpha_70x70);
LV_IMG_DECLARE(_32_alpha_70x70);
LV_IMG_DECLARE(_99_alpha_70x60);
LV_IMG_DECLARE(_56_alpha_100x100);
LV_IMG_DECLARE(_53_alpha_100x100);
LV_IMG_DECLARE(_55_alpha_100x100);
LV_IMG_DECLARE(_55_alpha_100x100);
LV_IMG_DECLARE(_53_alpha_100x100);
LV_IMG_DECLARE(_57_alpha_100x100);
LV_IMG_DECLARE(_2_alpha_100x100);
LV_IMG_DECLARE(_1_alpha_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_21)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_40)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_19)
LV_FONT_DECLARE(lv_font_montserratMedium_27)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
