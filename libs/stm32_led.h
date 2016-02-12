//--------------------------------------------------------------
// File     : stm32_led.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F4_LED_H
#define __STM32F4_LED_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"




//--------------------------------------------------------------
// Lista dos LEDs
//--------------------------------------------------------------
typedef enum 
{
  LED_GREEN = 0,  // LED3  STM32F429-Discovery
  LED_RED = 1     // LED4  STM32F429-Discovery
}LED_NAME_t;

#define  LED_ANZ   2 // número de LED_NAME_t


//--------------------------------------------------------------
// Status LED
//--------------------------------------------------------------
typedef enum {
  LED_OFF = 0,
  LED_ON
}LED_STATUS_t;


//--------------------------------------------------------------
// Estrutura LED
//--------------------------------------------------------------
typedef struct {
  LED_NAME_t LED_NAME;    // Name
  GPIO_TypeDef* LED_PORT; // Port
  const uint16_t LED_PIN; // Pin
  const uint32_t LED_CLK; // Clock
  LED_STATUS_t LED_INIT;  // Init
}LED_t;


//--------------------------------------------------------------
// Função global
//--------------------------------------------------------------
void UB_Led_Init(void);
void UB_Led_Off(LED_NAME_t led_name);
void UB_Led_On(LED_NAME_t led_name);
void UB_Led_Toggle(LED_NAME_t led_name);
void UB_Led_Switch(LED_NAME_t led_name, LED_STATUS_t wert);



//--------------------------------------------------------------
#endif // __STM32F4_LED_H
