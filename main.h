#ifndef __STM32F4_MAIN_H
#define __STM32F4_MAIN_H


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"

uint32_t CurrentFrameBuffer;
uint16_t aktColor;
uint8_t menu;

typedef struct {
  uint16_t x;
  uint16_t y;
}Posicao_t;
Posicao_t pos;


void P_drawScreen(void);
void P_drawClear(void);
void LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t color);
void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction, uint16_t color);
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width, uint16_t color);
void LCD_DrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t color);
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t color);
Posicao_t key_function(Posicao_t temp);
uint8_t arrow_function(void);
void imprimir_menu(void);
uint8_t opcoes(void);

//--------------------------------------------------------------
// Cores pré-definidas
//--------------------------------------------------------------
#define LCD_COLOR_WHITE          0xFFFF
#define LCD_COLOR_BLACK          0x0000
#define LCD_COLOR_GREY           0xF7DE
#define LCD_COLOR_BLUE           0x001F
#define LCD_COLOR_BLUE2          0x051F
#define LCD_COLOR_RED            0xF800
#define LCD_COLOR_MAGENTA        0xF81F
#define LCD_COLOR_GREEN          0x07E0
#define LCD_COLOR_CYAN           0x7FFF
#define LCD_COLOR_YELLOW         0xFFE0

#define LCD_DIR_HORIZONTAL       0x0000
#define LCD_DIR_VERTICAL         0x0001


//--------------------------------------------------------------
#endif // __STM32F4_MAIN_H
