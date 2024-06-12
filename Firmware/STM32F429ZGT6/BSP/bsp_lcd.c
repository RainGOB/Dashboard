#include "bsp_lcd.h"

void rgblcd_init(void){
	rgblcd_DISP_set();
	MX_LTDC_Init();
	HAL_Delay(50);
	lcd_clear(BLACK);
}

/*    不用DMA2D了，因为没什么动画，现阶段就两个页面    */
void rgblcd_DISP_set(void){
	HAL_GPIO_WritePin(rgblcd_DISP_port,rgblcd_DISP_pin,GPIO_PIN_SET);
	
}

//画点
void ltdc_draw_point(uint16_t x, uint16_t y, uint16_t color)
{
    uint32_t pos;
    uint16_t *ptr;

    // check position.
    if (x > LCD_WIDTH || y > LCD_HEIGHT) {
        return;
    }

    // calculate the position offset in framebuffer.
    pos = x + y*LCD_WIDTH;
    ptr = (uint16_t*)LAYER_FB_ADDR;

    // modify the framebuffer.
#if USE_DMA2D_EN
    dma2d_transfer_data_r2m((uint32_t *)(ptr+pos), 1, 1, 0, color);
#else
    *(ptr+pos) = color;
#endif /* USE_DMA2D_EN */
}

//读点
uint16_t ltdc_read_point(uint16_t x, uint16_t y)
{
    uint32_t pos;
    uint16_t *ptr, data;

    // check position.
    if (x > LCD_WIDTH || y > LCD_HEIGHT) {
        return 0;
    }

    // calculate the position offset in framebuffer.
    pos = x + y*LCD_WIDTH;
    ptr = (uint16_t*)LAYER_FB_ADDR;

    // read the framebuffer.
    data = *(ptr+pos);

    return data;
}

/**
  * @breif    画直线
  * @param    x1:画线端点1x坐标
  * @param    y1:画线端点1y坐标
  * @param    x2:画线端点2x坐标ccxxz
  * @param    y2:画线端点2y坐标
  * @param    color画线颜色
  * @retval   
  */

void lcd_draw_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
    uint16_t x_delta;
    uint16_t y_delta;
    int16_t x_sign;
    int16_t y_sign;
    int16_t error;
    int16_t error2;
    
    x_delta = (x1 < x2) ? (x2 - x1) : (x1 - x2);
    y_delta = (y1 < y2) ? (y2 - y1) : (y1 - y2);
    x_sign = (x1 < x2) ? 1 : -1;
    y_sign = (y1 < y2) ? 1 : -1;
    error = x_delta - y_delta;
    
    ltdc_draw_point(x2, y2, color);
    
    while ((x1 != x2) || (y1 != y2))
    {
        ltdc_draw_point(x1, y1, color);
        
        error2 = error << 1;   			//将error乘以2,这样会更快
        if (error2 > -y_delta) 
        { 
            error -= y_delta;
            x1 += x_sign;
        }
        
        if (error2 < x_delta)
        {
            error += x_delta;
            y1 += y_sign;
        }
    }
}
/************************
void lcd_draw_line_DIY(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint32_t color){  //斜率小于1，大于0
	uint16_t x;
	uint16_t y;
	uint8_t error = 0;
	if(x1>x2){
		x = x1; x1 = x2; x2 = x;
	}
	if(y1>y2)
	{
		y = y1; y1 = y2; y2 = y;
		error = 1;
	}
	int16_t dx = x2-x1,dy = y2 - y1;
	if(dx>dy){
		x = x1; x1 = y1; y1 = x;
		y = x2; x2 = y1; y2 = y;
	}
	x = x1;
	y = y1;
	int16_t P = 2*dy - dx;
	
	
	while(x < x2)
	{
		if(error ==1){
			y = -y;
		ltdc_draw_point(x,y,color);
			y = -y;
		}
		x++;
		if(P<0)
			P = P + 2*dy;
		else{
			P = P + 2*dy - 2*dx;
			y++;
		} 
	}
}
*************************/

//画矩形
void lcd_draw_rectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	lcd_draw_line(x1,y1,x1,y2,color);
	lcd_draw_line(x1,y2,x2,y2,color);
	lcd_draw_line(x1,y2,x2,y2,color);
	lcd_draw_line(x1,y1,x2,y1,color);
}

//画圆
void lcd_draw_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color)
{
    int32_t x_t;
    int32_t y_t;
    int32_t error;
    int32_t error2;
    
    x_t = -r;
    y_t = 0;
    error = 2 - 2 * r;
    
    do {
        ltdc_draw_point(x - x_t, y + y_t, color);
        ltdc_draw_point(x + x_t, y + y_t, color);
        ltdc_draw_point(x + x_t, y - y_t, color);
        ltdc_draw_point(x - x_t, y - y_t, color);
        
        error2 = error;
        if (error2 <= y_t)
        {
            y_t++;
            error = error + (y_t * 2 + 1);
            if ((-x_t == y_t) && (error2 <= x_t))
            {
                error2 = 0;
            }
        }
        
        if (error2 > x_t)
        {
            x_t++;
            error = error + (x_t * 2 + 1);
        }
    } while (x_t <= 0);
}


//填充颜色
void lcd_fill(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint16_t *color)
{
uint16_t height,width;
	uint16_t i,j;
	width=xe-xs+1; 			//得到填充的宽度
    height=ye-ys+1;			//高度
    uint32_t pos;
    uint16_t *ptr;
	  //f (xe >= 800)
		//{
		//	xe = 800-1;
		//}
		//if (ye >= 480)
		//{
		//	ye = 480-1;
		//}
		//uint16_t x_index;
		//uint16_t y_index;
		//
		//for (x_index=xs ; x_index<xe+1 ; x_index++)
		//	for (y_index=ys ; y_index<ye+1 ; y_index++){
		//		ltdc_draw_point(x_index,y_index,color[x_index*width+y_index]);
		//		}
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            // check position.
            if (j+xs > LCD_WIDTH || i+ys > LCD_HEIGHT) {
            return;
            }
			// calculate the position offset in framebuffer.
			pos = (j+xs) + (i+ys)*LCD_WIDTH;
			ptr = (uint16_t*)LAYER_FB_ADDR;

			// modify the framebuffer.
			#if USE_DMA2D
				dma2d_transfer_data_r2m((uint32_t *)(ptr+pos), 1, 1, 0, color[i*width+j]);
			#else
				*(ptr+pos) = color[i*width+j];
			#endif /* USE_DMA2D_EN */
		//ltdc_draw_point(j+xs,i+ys,color[i*width+j]); //写入数据
		}
    }
}


//清屏
void lcd_clear(uint16_t color)
{
#if USE_DMA2D
    dma2d_transfer_data_r2m((uint32_t *)LAYER_FB_ADDR, LCD_WIDTH, LCD_HEIGHT, 0, color);
#else
    uint16_t *ptr = (uint16_t*)LAYER_FB_ADDR;
    uint32_t i = 0;

    while (i++ < LCD_WIDTH*LCD_HEIGHT) {
        *(ptr+i) = color;
    }
#endif /* USE_DMA2D_EN */
}

static void dma2d_transfer_data_r2m(uint32_t *addr, uint32_t xSize, uint32_t ySize, uint32_t offsetLine, uint16_t color)
{
    DMA2D->CR = DMA2D_R2M;   // dma2d mode: register to memory.
    DMA2D->OPFCCR = DMA2D_OUTPUT_RGB565;

    DMA2D->OCOLR = color;
    DMA2D->OMAR = (uint32_t)addr;
    DMA2D->OOR = offsetLine;
    DMA2D->NLR = (uint32_t)(xSize << 16) | (uint16_t)ySize;
    
    DMA2D->CR |= DMA2D_CR_START;
    while (DMA2D->CR & DMA2D_CR_START);
}
