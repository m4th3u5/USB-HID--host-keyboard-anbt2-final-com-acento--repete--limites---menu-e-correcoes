// Função : Texto-LCD


#include "stm32_ub_font.h"
#include "stm32_ub_lcd_ili9341.h"



//--------------------------------------------------------------
// Imprime um caracteres ASCII em uma fonte nas posição x, y
// com primeiro plano e cor de fundo(Fonte max de 16 pixels de largura)
// ->Fonte deve ser entregue com operador &
//--------------------------------------------------------------
void UB_Font_DrawChar(uint16_t x, uint16_t y, uint8_t ascii, UB_Font *font, uint16_t vg, uint16_t bg)
{
  uint16_t xn,yn,start_maske,maske;
  const uint16_t *wert;
  

  ascii -= 32;
  wert=&font->table[ascii * font->height];

  if(LCD_DISPLAY_MODE==PORTRAIT) {
    start_maske=0x80;
    if(font->width>8) start_maske=0x8000;
    
    for(yn = 0; yn < font->height; yn++) {
      maske=start_maske;
      // mova o cursor
      UB_LCD_SetCursor2Draw(x,yn+y);
      for(xn = 0; xn < font->width; xn++) {
        if((wert[yn] & maske) == 0x00) {
          // Desenhe pixels em cor de fundo
          UB_LCD_DrawPixel(bg);
        }
        else {
          // Desenhe pixels na cor do primeiro plano
          UB_LCD_DrawPixel(vg);
        }
        maske=(maske>>1);
      }
    }
  }
  else {
    start_maske=0x80;
    if(font->width>8) start_maske=0x8000;

    for(yn = 0; yn < font->height; yn++) {
      maske=start_maske;
      // mova o cursor
      UB_LCD_SetCursor2Draw(x+font->height-yn,y);
      for(xn = 0; xn < font->width; xn++) {
        if((wert[yn] & maske) == 0x00) {
          // Desenhe pixels em cor de fundo
          UB_LCD_DrawPixel(bg);
        }
        else {
          // Desenhe pixels na cor do primeiro plano
          UB_LCD_DrawPixel(vg);
        }
        maske=(maske>>1);
      }
    }
  }
}


//--------------------------------------------------------------
// Imprime uma seqüência de uma fonte nas posição x, y
// com primeiro plano e cor de fundo (fonte max de 16 pixels de largura)
// ->Fonte deve ser entregue com operador &
//--------------------------------------------------------------
void UB_Font_DrawString(uint16_t x, uint16_t y,char *ptr, UB_Font *font, uint16_t vg, uint16_t bg)
{
  uint16_t pos;

  if(LCD_DISPLAY_MODE==PORTRAIT) {
    pos=x;
    while (*ptr != 0) {
      UB_Font_DrawChar(pos,y,*ptr,font,vg,bg);
      pos+=font->width;
      ptr++;
    }
  }
  else {
    pos=y;
    while (*ptr != 0) {
      UB_Font_DrawChar(x,pos,*ptr,font,vg,bg);
      pos+=font->width;
      ptr++;
    }
  }
}


//--------------------------------------------------------------
// Imprime um caracteres ASCII em uma fonte nas posição de x, y
// com primeiro plano e cor de fundo (fonte máximo de 32 pixels de largura)
// ->Fonte deve ser entregue com operador &
//--------------------------------------------------------------
void UB_Font_DrawChar32(uint16_t x, uint16_t y, uint8_t ascii, UB_Font32 *font, uint16_t vg, uint16_t bg)
{
  uint16_t xn,yn;
  uint32_t start_maske,maske;
  const uint32_t *wert;


  ascii -= 32;
  wert=&font->table[ascii * font->height];

  if(LCD_DISPLAY_MODE==PORTRAIT) {
    start_maske=0x80;
    if(font->width>8) start_maske=0x8000;
    if(font->width>16) start_maske=0x80000000;

    for(yn = 0; yn < font->height; yn++) {
      maske=start_maske;
      // mova o cursor
      UB_LCD_SetCursor2Draw(x,yn+y);
      for(xn = 0; xn < font->width; xn++) {
        if((wert[yn] & maske) == 0x00) {
          // Desenhe pixels em cor de fundo
          UB_LCD_DrawPixel(bg);
        }
        else {
          // Desenhe pixels na cor de primeiro plano
          UB_LCD_DrawPixel(vg);
        }
        maske=(maske>>1);
      }
    }
  }
  else {
    start_maske=0x80;
    if(font->width>8) start_maske=0x8000;
    if(font->width>16) start_maske=0x80000000;

    for(yn = 0; yn < font->height; yn++) {
      maske=start_maske;
      // mova o cursor
      UB_LCD_SetCursor2Draw(x+font->height-yn,y);
      for(xn = 0; xn < font->width; xn++) {
        if((wert[yn] & maske) == 0x00) {
          // Desenhe pixels em cor de fundo
          UB_LCD_DrawPixel(bg);
        }
        else {
          // Desenhe pixels na cor de primeiro plano
          UB_LCD_DrawPixel(vg);
        }
        maske=(maske>>1);
      }
    }
  }
}


//--------------------------------------------------------------
// Imprime uma seqüência de uma fonte nas posição x, y
// com primeiro plano e cor de fundo (fonte máximo de 32 pixels de largura)
// ->Fonte deve ser entregue com operador &
//--------------------------------------------------------------
void UB_Font_DrawString32(uint16_t x, uint16_t y,char *ptr, UB_Font32 *font, uint16_t vg, uint16_t bg)
{
  uint16_t pos;

  if(LCD_DISPLAY_MODE==PORTRAIT) {
    pos=x;
    while (*ptr != 0) {
      UB_Font_DrawChar32(pos,y,*ptr,font,vg,bg);
      pos+=font->width;
      ptr++;
    }
  }
  else {
    pos=y;
    while (*ptr != 0) {
      UB_Font_DrawChar32(x,pos,*ptr,font,vg,bg);
      pos+=font->width;
      ptr++;
    }
  }
}
