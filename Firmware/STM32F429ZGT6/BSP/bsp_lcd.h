#ifndef _BSP_LCD_H_
#define _BSP_LCD_H_

#include "main.h"
#include "ltdc.h"
#include "Variable.h"

#define pixel 2
#define pwidth 800
#define rgblcd_DISP_port LTDC_DISP_GPIO_Port
#define rgblcd_DISP_pin LTDC_DISP_Pin

#define LCD_WIDTH 800
#define LCD_HEIGHT 480
#define LAYER_FB_ADDR 	0xC0000000


#define BLACK   0x0000
#define BLUE    0x001F
#define GREEN   0x07E0
#define GBLUE   0X07FF
#define GRAY    0X8430
#define BROWN   0XBC40
#define RED     0xF800
#define PINK    0XF81F
#define BRRED   0XFC07
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define USE_DMA2D  1


void rgblcd_init(void);
void rgblcd_DISP_set(void);
void ltdc_draw_point(uint16_t x, uint16_t y, uint16_t color);
uint16_t ltdc_read_point(uint16_t x, uint16_t y);
void lcd_draw_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void lcd_draw_rectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void lcd_draw_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color);
void lcd_fill(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint16_t *color);
void lcd_clear(uint16_t color);
static void dma2d_transfer_data_r2m(uint32_t *addr, uint32_t xSize, uint32_t ySize, uint32_t offsetLine, uint16_t color);

#endif
