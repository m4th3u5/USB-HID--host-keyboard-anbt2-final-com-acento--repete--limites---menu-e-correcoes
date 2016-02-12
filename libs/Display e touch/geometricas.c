
#include "main.h"
#include "stm32_ub_lcd_ili9341.h"
#include "stm32f4xx_dma2d.h"


void P_drawClear(void)
{
	LCD_DrawRect(180, 270, 48, 50, LCD_COLOR_BLACK);
	LCD_DrawFullRect(182, 272, 46, 46, aktColor);
}


//--------------------------------------------------------------
/**
  * @brief  Está rotina é chamada para imprimir um retângulo preenchido
  * @param  Posição X, Posição Y, largura, altura , cor
  * @retval Nenhum
  */
void LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t color)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;

  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0;

  Red_Value = (0xF800 & color) >> 11;
  Blue_Value = 0x001F & color;
  Green_Value = (0x07E0 & color) >> 5;

  Xaddress = CurrentFrameBuffer + 2*(LCD_MAXX*Ypos + Xpos);

  /* configure DMA2D */
  DMA2D_DeInit();
  DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
  DMA2D_InitStruct.DMA2D_CMode = DMA2D_RGB565;
  DMA2D_InitStruct.DMA2D_OutputGreen = Green_Value;
  DMA2D_InitStruct.DMA2D_OutputBlue = Blue_Value;
  DMA2D_InitStruct.DMA2D_OutputRed = Red_Value;
  DMA2D_InitStruct.DMA2D_OutputAlpha = 0x0F;
  DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;
  DMA2D_InitStruct.DMA2D_OutputOffset = (LCD_MAXX - Width);
  DMA2D_InitStruct.DMA2D_NumberOfLine = Height;
  DMA2D_InitStruct.DMA2D_PixelPerLine = Width;
  DMA2D_Init(&DMA2D_InitStruct);

  /* Start Transfer */
  DMA2D_StartTransfer();

  /* Wait for CTC Flag activation */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  }
}

//--------------------------------------------------------------
void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction, uint16_t color)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;

  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0;

  Xaddress = CurrentFrameBuffer + 2*(LCD_MAXX*Ypos + Xpos);

  Red_Value = (0xF800 & color) >> 11;
  Blue_Value = 0x001F & color;
  Green_Value = (0x07E0 & color) >> 5;

  /* Configure DMA2D */
  DMA2D_DeInit();
  DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
  DMA2D_InitStruct.DMA2D_CMode = DMA2D_RGB565;
  DMA2D_InitStruct.DMA2D_OutputGreen = Green_Value;
  DMA2D_InitStruct.DMA2D_OutputBlue = Blue_Value;
  DMA2D_InitStruct.DMA2D_OutputRed = Red_Value;
  DMA2D_InitStruct.DMA2D_OutputAlpha = 0x0F;
  DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;

  if(Direction == LCD_DIR_HORIZONTAL)
  {
    DMA2D_InitStruct.DMA2D_OutputOffset = 0;
    DMA2D_InitStruct.DMA2D_NumberOfLine = 1;
    DMA2D_InitStruct.DMA2D_PixelPerLine = Length;
  }
  else
  {
    DMA2D_InitStruct.DMA2D_OutputOffset = LCD_MAXX - 1;
    DMA2D_InitStruct.DMA2D_NumberOfLine = Length;
    DMA2D_InitStruct.DMA2D_PixelPerLine = 1;
  }

  DMA2D_Init(&DMA2D_InitStruct);
  /* Start Transfer */
  DMA2D_StartTransfer();
  /* Wait for CTC Flag activation */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  }

}


//--------------------------------------------------------------
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width, uint16_t color)
{
  /* draw horizontal lines */
  LCD_DrawLine(Xpos, Ypos, Width, LCD_DIR_HORIZONTAL, color);
  LCD_DrawLine(Xpos, (Ypos+ Height), Width, LCD_DIR_HORIZONTAL, color);

  /* draw vertical lines */
  LCD_DrawLine(Xpos, Ypos, Height, LCD_DIR_VERTICAL, color);
  LCD_DrawLine((Xpos + Width), Ypos, Height, LCD_DIR_VERTICAL, color);
}


//--------------------------------------------------------------
void LCD_DrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t color)
{
  int32_t  D;    /* Decision Variable */
  uint32_t  CurX;/* Current X Value */
  uint32_t  CurY;/* Current Y Value */

  D = 3 - (Radius << 1);

  CurX = 0;
  CurY = Radius;

  while (CurX <= CurY)
  {
    if(CurY > 0)
    {
      LCD_DrawLine(Xpos - CurX, Ypos - CurY, 2*CurY, LCD_DIR_VERTICAL, color);
      LCD_DrawLine(Xpos + CurX, Ypos - CurY, 2*CurY, LCD_DIR_VERTICAL, color);
    }

    if(CurX > 0)
    {
      LCD_DrawLine(Xpos - CurY, Ypos - CurX, 2*CurX, LCD_DIR_VERTICAL, color);
      LCD_DrawLine(Xpos + CurY, Ypos - CurX, 2*CurX, LCD_DIR_VERTICAL, color);
    }
    if (D < 0)
    {
      D += (CurX << 2) + 6;
    }
    else
    {
      D += ((CurX - CurY) << 2) + 10;
      CurY--;
    }
    CurX++;
  }

  LCD_DrawCircle(Xpos, Ypos, Radius, color);
}


//--------------------------------------------------------------
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t color)
{
    int x = -Radius, y = 0, err = 2-2*Radius, e2;
    do {
        *(__IO uint16_t*) (CurrentFrameBuffer + (2*((Xpos-x) + LCD_MAXX*(Ypos+y)))) = color;
        *(__IO uint16_t*) (CurrentFrameBuffer + (2*((Xpos+x) + LCD_MAXX*(Ypos+y)))) = color;
        *(__IO uint16_t*) (CurrentFrameBuffer + (2*((Xpos+x) + LCD_MAXX*(Ypos-y)))) = color;
        *(__IO uint16_t*) (CurrentFrameBuffer + (2*((Xpos-x) + LCD_MAXX*(Ypos-y)))) = color;

        e2 = err;
        if (e2 <= y) {
            err += ++y*2+1;
            if (-x == y && e2 <= x) e2 = 0;
        }
        if (e2 > x) err += ++x*2+1;
    }
    while (x <= 0);
}
