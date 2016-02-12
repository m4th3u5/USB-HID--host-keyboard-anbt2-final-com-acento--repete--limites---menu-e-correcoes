//"system_stm32f4xx.c" deve estar configurado em 168MHz
//--------------------------------------------------------------

//Arquivo main.c

#include "main.h"
#include "stm32_ub_lcd_ili9341.h"
#include "stm32_ub_touch_stmpe811.h"
#include "usbh_usr.h"
#include "stm32_ub_font.h"

int main(void)
{
	SystemInit();						// Configura��es e inicializa��o do clock

	UB_LCD_Init();					// Inicializa��o LCD

	UB_LCD_LayerInit_Fullscreen();	// Inicializa��o da camadas da tela

	UB_LCD_SetLayer_1();				// Inicializa��o da camadas do fundo

	UB_LCD_FillLayer(RGB_COL_WHITE);	// Cor do fundo

	UB_LCD_SetLayer_2();				// Inicializa��o da camadas em primeiro plano

	UB_LCD_FillLayer(RGB_COL_WHITE);	// Cor do primeiro plano

	CurrentFrameBuffer=LCD_FRAME_BUFFER + LCD_FRAME_OFFSET;  // Vari�veis de controle da tela
	aktColor=LCD_COLOR_BLUE;			// Vari�vel para armazenar cor de prefer�ncia

	menu=0;							//Programa inicia no menu inicial

	if(UB_Touch_Init()!=SUCCESS)	// Verifica se a inicializa��o da tela sens�vel ao toque ocorreu corretamente
	{
		UB_Font_DrawString(10,28,"Touch error",&Arial_11x20,RGB_COL_WHITE,RGB_COL_RED);		//Imprime mensagem de erro
		UB_Font_DrawString(10,46,"Reconecte a energia",&Arial_11x20,RGB_COL_WHITE,RGB_COL_RED);
	while(1);						//Impede o progresso das demais rotinas
	}

	USB_HID_HOST_STATUS_t host_status;	// Vari�vel para armazenar o estado da comunica��o USB

	USB_Init();							// Inicializa��es para utilizar USB

	while(1){

	  LCD_DrawFullRect(0, 0, 240, 320, LCD_COLOR_BLACK);	// Imprime ret�ngulo branco do tamanha da tela(apaga tudo)
	  imprimir_menu();										// Imprime grafismo do menu inicial

//--------------------------------------------------------------
	  while(menu==0)					// Enquanto menu==0 o programa fica no menu inicial
	  {

		  host_status=USB_Function();			// Esta fun��o deve ser chamada periodicamente para o funcionamento do teclado

		  if(host_status!=USB_HID_DEV_DETACHED)	// Se o USB n�o tiver sido desconectado
			  menu = arrow_function();			// Chama fun��o que controla o selecionamento do menu

		  UB_Touch_Read();						// L� informa��es do touch
		  if(Touch_Data.status==TOUCH_PRESSED) {
			  if((Touch_Data.yp < 130) && (Touch_Data.yp >= 70)) {			// Verifica limites da regi�o de um bot�o touch na tela
				  if((Touch_Data.xp < 215) && (Touch_Data.xp > 45)) {
					  menu=1;												// Se o toque ocorreu muda o estado do programa
				  }
			  }
		  }

		  if(Touch_Data.status==TOUCH_PRESSED) {
			  if((Touch_Data.yp < 260) && (Touch_Data.yp >= 200)) {			// Verifica limites da regi�o de um bot�o touch na tela
				  if((Touch_Data.xp < 215) && (Touch_Data.xp > 45)) {
		 					  menu=2;												// Se o toque ocorreu muda o estado do programa
				  }
			  }
		  }

		  if(menu==1){							// menu==1 equivale ao modo de Digita��o
			  pos.x = 10;						// Posi��es onde o cursor de digita��o come�a
			  pos.y = 10;
			  LCD_DrawFullRect(0, 0, 240, 320, LCD_COLOR_WHITE);	// Imprime ret�ngulo branco do tamanha da tela(apaga tudo)
		  }
		  if(menu==2){							// menu==2 equivale ao modo de Op��es
			  LCD_DrawFullRect(0, 0, 240, 320, LCD_COLOR_WHITE);	// Imprime ret�ngulo branco do tamanha da tela(apaga tudo)
			  UB_Font_DrawString(10,10,"Cor do texto",&Arial_11x20,aktColor,RGB_COL_WHITE);		//Imprime mensagem
		  }
	  }

	  while(menu==1)							// menu==1 equivale ao modo de Digita��o
	  {
		host_status=USB_Function();				//Esta fun��o deve ser chamada periodicamente para o funcionamento do teclado

		UB_Touch_Read();						//Leitura do Touch
		LCD_DrawLine(pos.x,pos.y, 20, LCD_DIR_VERTICAL, RGB_COL_WHITE);
		if(Touch_Data.status==TOUCH_PRESSED) {
			if((Touch_Data.yp < 317) && (Touch_Data.yp >= 3)) {		// Verifica se touch foi na tela( para evitar erros}
				if((Touch_Data.xp < 237) && (Touch_Data.xp > 3)) {
					pos.x=Touch_Data.xp;							// Posiciona o cursor sobre o local tocado
					pos.y=Touch_Data.yp;
					LCD_DrawLine(pos.x,pos.y, 20, LCD_DIR_VERTICAL, RGB_COL_WHITE);
				}
			}

		}

		if(host_status!=USB_HID_DEV_DETACHED)		//Se o USB n�o tiver sido desconectado
			pos = key_function(pos);				//Interpreta todas teclas e fun��es do teclado, retorna posi��o do cursor

		if(host_status==USB_HID_DEV_CONNECTED)		//Se o USB for reconectado
			LCD_DrawFullRect(0, 302, 240, 320, LCD_COLOR_WHITE);	//Apaga mensagem pedindo para conectar

		if(host_status==USB_HID_DEV_DETACHED)		//Se o USB for desconectado
			UB_Font_DrawString(10,302,"Teclado desconectado",&Arial_11x20,RGB_COL_RED,RGB_COL_WHITE);	//Imprime mensagem
	  }
	  while(menu==2)							// menu==2 equivale ao modo de Op��es
	  {
		  host_status=USB_Function();			//Esta fun��o deve ser chamada periodicamente para o funcionamento do teclado

		  if(host_status!=USB_HID_DEV_DETACHED)	//Se o USB n�o tiver sido desconectado
			  menu = opcoes();

	  }
	}
}

//--------------------------------------------------------------
/**
  * @brief  Est� rotina � chamada para imprimir o menu principal, ela apaga a tela completamente e
  * insere ret�ngulos dos bot�es e textos
  * @param  Nenhum
  * @retval Nenhum
  */
void imprimir_menu(void){
	LCD_DrawFullRect(45, 70, 150, 60, RGB_COL_WHITE);
	UB_Font_DrawString(65,90,"Digitar",&Arial_11x20,RGB_COL_BLACK,RGB_COL_WHITE);
	LCD_DrawFullRect(45, 200, 150, 60, RGB_COL_WHITE);
	UB_Font_DrawString(65,220,"Op��es",&Arial_11x20,RGB_COL_BLACK,RGB_COL_WHITE);
}
//--------------------------------------------------------------
