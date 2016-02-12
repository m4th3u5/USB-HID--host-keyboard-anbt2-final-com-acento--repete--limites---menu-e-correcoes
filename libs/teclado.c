#include "stm32_ub_font.h"
#include "main.h"
#include "usbh_usr.h"
#include "stm32_ub_lcd_ili9341.h"


/**
  * @brief  Est� rotina interpreta comando do teclado,
  * realiza a impress�o na tela dos caracteres e controla
  * todas as fu��es de digita��o Enter, BackSpace, Etc.
  * Chama as rotinas para acentua��o e realiza o controle de repeti��o de teclas
  * @param  Posi��o X e Y
  * @retval Posi��o X e Y
  */

Posicao_t key_function(Posicao_t aux)
{

	uint16_t x=aux.x;
	uint16_t y=aux.y;


	uint8_t   ascii_code=0;			// Vari�vel para receber valor ascii
	uint8_t   tecla_liberada=0;		// Vari�vel para receber libera��o da tecla
	static uint32_t contador=0;		// Vari�vel para atraso na repeti��o de tecla
	static uint8_t  key=0;			// Vari�vel auxiliar para valor do ascii

	ascii_code=GetKey();        // GetKey retorna valor ascii apenas 1 vez quando tem algum novo
	tecla_liberada=GetKey2();	// GetKey2 retorna valor 1(true) se tecla ascii for liberada



	if(ascii_code!='\0' && ascii_code!='\n'){		// Se alguma tecla foi pressionada
		key=ascii_code;						// memoriza valor ascii
		contador=1;}						// Iniciar contador(ser� desativado na borda de subida)

	if(contador!=0){						// Se j� tiver iniciado o contador
		contador++;}						// contar +1

	if(contador>1000){						// Se contador atingir o atraso necess�rio
		ascii_code=key;						// a tecla salva � carregada novamente
		contador=900;}						// reinicia o contador com menor per�odo

	if (tecla_liberada==1){						// Verifica se a tecla ascii foi liberada
		contador=0;}						// cancela contador


  LCD_DrawLine(x,y, 20, LCD_DIR_VERTICAL, RGB_COL_WHITE); 						//Apaga o cursor de texto

     ascii_code=verificaracentos(ascii_code);									//Chama fun��o de modifica��o para acentua��o

     if(ascii_code>31 && ascii_code!='\0' && ascii_code!='\n'){   				//Verifica se o valor ascii � de um caractere gr�fico

    	 UB_Font_DrawChar(x,y,ascii_code,&Arial_11x20,aktColor,RGB_COL_WHITE);  //Chama fun��o que imprime caractere
    	 x=x+11;}																//Realiza deslocamento horizontal

   switch (ascii_code){			//Decide entre as teclas com fun��o qual delas foi prescionada

   case 1:
	   menu=0;
   break;

   case 2:								//Fun��o backspace
	   if(x>10){								//Verifica se tem espa�o na esquerda do cursor
		   x-=11;								//Volta o cursos para esquerda
	   }else if(y>20){							//Caso o cursor esteja na esquerda verifica se tem espa�o na linha de cima
		   x=230;								//Vai ao final na linha
		   y-=20;}								//na linha superior
	   LCD_DrawFullRect(x, y, 11, 20, RGB_COL_WHITE); //Apaga um caractere
	  break;

   case 3:		 						//Fun��o tab

   break;

   case 4:		 						//Fun��o enter
	   x=10;									//Vai ao come�o da linha
	   if(y<280)								//Verifica se tem espa�o em baixo do cursor
	   y+=20;									//Desce uma linha
   break;

   case 5:       						//Seta esqerda
	   if(x>11)									//Verifica se tem espa�o para deslocamento
	   x-=11;									//move cursor
   break;
   case 6:		 						//Seta cima
	   if(y>20)									//Verifica se tem espa�o para deslocamento
	   y-=20;									//move cursor
   break;
   case 7:								//Seta baixo
	   if(y<280)								//Verifica se tem espa�o para deslocamento
	   y+=20;									//move cursor
   break;
   case 8:		 						//Seta direita
	   if(x<229)								//Verifica se tem espa�o para deslocamento
	   x+=11;									//move cursor
   break;
   }


   if(x>230){        		//Verifica se � o �ltimo caractere da linha?
	   if(y<290){      		//Verifica se � antes da �ltima linha?
          x=10;	y+=20;}     // Se for, volta pro come�o, na pr�xima linha
	   else x-=11;}  		//Se for �ltimo caractere da �ltima linha, apenas volta o espa�o de um caractere

   LCD_DrawLine(x,y, 20, LCD_DIR_VERTICAL, aktColor);		// Desenha cursor de texto



     aux.x=x;
     aux.y=y;


 return(aux);

}


/**
  * @brief  Est� rotina interpreta comandos do teclado e
  * controla menu pelo uso das setas.
  * @param  Nenhum
  * @retval Se pressionado enter, retorna a escolhas feita no menu
  */

uint8_t arrow_function(void){


	uint8_t   ascii_code=0;			// Vari�vel para receber valor ascii
	static uint8_t   menu=0;			// Vari�vel para definir qual a escolhas ser� feita no menu
	ascii_code=GetKey();        // GetKey retorna valor ascii apenas 1 vez quando tem algum novo

	if (ascii_code==6){
		menu=1;
		LCD_DrawFullRect(0, 0, 240, 320, LCD_COLOR_BLACK);	//Imprime ret�ngulo branco do tamanha da tela(apaga tudo)
		LCD_DrawFullRect(35, 60, 170, 80, aktColor);
		imprimir_menu();
	}
	if (ascii_code==7){
		menu=2;
		LCD_DrawFullRect(0, 0, 240, 320, LCD_COLOR_BLACK);	//Imprime ret�ngulo branco do tamanha da tela(apaga tudo)
		LCD_DrawFullRect(35, 190, 170, 80, aktColor);
		imprimir_menu();
	}

	if (ascii_code==4)
	return(menu);
	else
	return(0);
}



/**
  * @brief  Est� rotina interpreta comandos do teclado e
  * controla pelas setas qual a cor do texto
  * @param  Nenhum
  * @retval Se pressionado enter, retorna a escolhas feita para a cor texto
  */

uint8_t opcoes(void){


	uint8_t   ascii_code=0;			// Vari�vel para receber valor ascii
	ascii_code=GetKey();        // GetKey retorna valor ascii apenas 1 vez quando tem algum novo
	static uint16_t   cor=4;

	uint16_t cor_Table [] = {
			LCD_COLOR_WHITE, LCD_COLOR_BLACK, LCD_COLOR_GREY, LCD_COLOR_BLUE, LCD_COLOR_BLUE2,
			LCD_COLOR_RED, LCD_COLOR_MAGENTA, LCD_COLOR_GREEN, LCD_COLOR_CYAN, LCD_COLOR_YELLOW
	};

	if (ascii_code==6 || ascii_code==8){
		cor+=1;
		aktColor=cor_Table[cor];
		UB_Font_DrawString(10,10,"Cor do texto",&Arial_11x20,aktColor,RGB_COL_WHITE);
		}
		if (ascii_code==7 || ascii_code==5){
			cor-=1;
			aktColor=cor_Table[cor];
			UB_Font_DrawString(10,10,"Cor do texto",&Arial_11x20,aktColor,RGB_COL_WHITE);
			}


	if (ascii_code==4 || ascii_code==1)
	return(0);
	else
	return(2);
}





