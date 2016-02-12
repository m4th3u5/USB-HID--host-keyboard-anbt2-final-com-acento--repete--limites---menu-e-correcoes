#include "stm32f4xx.h"

uint8_t verificaracentos(uint8_t ascii_code){

	static uint8_t  acento;  // Armazena acento da tecla ascii anterior


	if((ascii_code==180 || ascii_code==94 || ascii_code==96 || ascii_code==126 || acento!=0) && ascii_code!='\0' && ascii_code!='\n'){   //Se ascii for um acento ou o anterior tiver sido acento

		if(acento==0){				//Se for o primeiro acento
			switch (ascii_code){
				case 96:    // "`"
					acento=1;
				break;
				case 180:	// "´"
					acento=2;
				break;
				case 94:	// "^"
					acento=3;
				break;
				case 126:	// "~"
					acento=4;
				break;}
			ascii_code='\0';		//evita a impressão
		}
		else{								// Se a tecla anterior tiver sido acento
			switch (ascii_code){			//Modifica a vogal pela vogal com acento
				case 97:	// "a"
					ascii_code=acento+223;
				break;
				case 101:	// "e"
					ascii_code=acento+231;
				break;
				case 105 :	// "i"
					ascii_code=acento+235;
				break;
				case 111 :	// "o"
					ascii_code=acento+241;
				break;
				case 117 :	// "u"
					ascii_code=acento+248;
				break;
				case 65 :	// "A"
					ascii_code=acento+191;
				break;
				case 69 :	// "E"
					ascii_code=acento+199;
				break;
				case 73 :	// "I"
					ascii_code=acento+203;
				break;
				case 79 :	// "O"
					ascii_code=acento+209;
				break;
				case 85 :	// "U"
					ascii_code=acento+216;
				break;}
			if(ascii_code==235 || ascii_code==239 || ascii_code==252 || ascii_code==203 || ascii_code==207 || ascii_code==220)			//Exceções dos acentos e,i,u não rcebem til
				ascii_code='\0';
			acento=0;
		}
	}
	return(ascii_code);}




/*	static uint8_t  ascii_code_acento=0;


if(ascii_code==180 || ascii_code==94 || ascii_code==96 || ascii_code==126){
    		 ascii_code_acento=ascii_code;}

if(ascii_code_acento!=0){
      		ascii_code=funcaoacentos(ascii_code,ascii_code_acento);
      		ascii_code_acento=0;
      	 }


}

uint8_t funcaoacentos(uint8_t ascii_code,uint8_t ascii_code_anterior){
	uint8_t acento=0;

	switch (ascii_code_anterior){
		case 96:    // "`"
			acento=1;
		break;
		case 180:	// "´"
			acento=2;
		break;
		case 94:	// "^"
			acento=3;
		break;
		case 126:	// "~"
			acento=4;
		break;}

	switch (ascii_code){
		case 97:	// "a"
			ascii_code=acento+223;
		break;
		case 101:	// "e"
			ascii_code=acento+231;
		break;
		case 105 :	// "i"
			ascii_code=acento+235;
		break;
		case 111 :	// "o"
			ascii_code=acento+241;
		break;
		case 117 :	// "u"
			ascii_code=acento+248;
		break;
		case 65 :	// "A"
			ascii_code=acento+191;
		break;
		case 69 :	// "E"
			ascii_code=acento+199;
		break;
		case 73 :	// "I"
			ascii_code=acento+203;
		break;
		case 79 :	// "O"
			ascii_code=acento+209;
		break;
		case 85 :	// "U"
			ascii_code=acento+216;
		break;
		default:
			ascii_code=ascii_code_anterior;
		}


return(ascii_code);
}*/
