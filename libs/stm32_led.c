// File     : stm32_led.c

#include "stm32_led.h"


//--------------------------------------------------------------
// Definição de todos os LEDs
//
// Init : [LED_OFF,LED_ON]
//--------------------------------------------------------------
LED_t LED[] = {
  // Name    ,PORT , PIN       , CLOCK              , Init
  {LED_GREEN ,GPIOG,GPIO_Pin_13,RCC_AHB1Periph_GPIOG,LED_OFF},   // PG13=LED Verde na Discovery-Board
  {LED_RED   ,GPIOG,GPIO_Pin_14,RCC_AHB1Periph_GPIOG,LED_OFF},   // PG14=LED Vermelho na Discovery-Board
};



//--------------------------------------------------------------
// Init LEDs
//--------------------------------------------------------------
void UB_Led_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  LED_NAME_t led_name;
  
  for(led_name=0;led_name<LED_ANZ;led_name++) {
    // Clock Enable
    RCC_AHB1PeriphClockCmd(LED[led_name].LED_CLK, ENABLE);

    // Configuração como saída digital
    GPIO_InitStructure.GPIO_Pin = LED[led_name].LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED[led_name].LED_PORT, &GPIO_InitStructure);

    // Definição do valor padrão
    if(LED[led_name].LED_INIT==LED_OFF) {
      UB_Led_Off(led_name);
    }
    else {
      UB_Led_On(led_name);
    }
  }
}

//--------------------------------------------------------------
//Ligar
//--------------------------------------------------------------
void UB_Led_Off(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->BSRRH = LED[led_name].LED_PIN;
}

//--------------------------------------------------------------
//Desligar
//--------------------------------------------------------------

void UB_Led_On(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->BSRRL = LED[led_name].LED_PIN;
} 

//--------------------------------------------------------------
//Toggle
//--------------------------------------------------------------

void UB_Led_Toggle(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->ODR ^= LED[led_name].LED_PIN;
}

//--------------------------------------------------------------
// LED on ou off
//--------------------------------------------------------------
void UB_Led_Switch(LED_NAME_t led_name, LED_STATUS_t wert)
{
  if(wert==LED_OFF) {
    UB_Led_Off(led_name);
  }
  else {
    UB_Led_On(led_name);
  }
}
