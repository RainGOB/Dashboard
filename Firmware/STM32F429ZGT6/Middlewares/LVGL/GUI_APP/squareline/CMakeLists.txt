SET(SOURCES screens/ui_main_sreen.c
    screens/ui_startup.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_2095113354.c
    images/ui_img_iot_png.c
    images/ui_img_guage_bg_png.c
    images/ui_img_group_4_png.c
    images/ui_img_group_5_png.c
    images/ui_img_line1_png.c
    images/ui_img_line2_png.c
    images/ui_img_line3_png.c
    images/ui_img_line4_png.c
    images/ui_img_line5_png.c
    images/ui_img_line6_png.c
    images/ui_img_ly_icon_png.c
    fonts/ui_font_Anton_75_bpp4.c
    fonts/ui_font_Anton_bpp4_35.c
    fonts/ui_font_Anton_bpp4_40.c
    fonts/ui_font_mashanzheng_60_bpp4.c)

add_library(ui ${SOURCES})
