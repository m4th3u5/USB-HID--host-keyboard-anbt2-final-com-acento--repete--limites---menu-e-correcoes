// Adapdado para modelos ABNT2

#include "usbh_hid_keybd.h"


static void  KEYBRD_Init (void);
static void  KEYBRD_Decode(uint8_t *data);
uint8_t capslock(void);


#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
 #pragma pack(4) 
#endif


HID_cb_TypeDef HID_KEYBRD_cb= 
{
  KEYBRD_Init,
  KEYBRD_Decode
};

/*
*******************************************************************************
*                                             LOCAL CONSTANTS
*******************************************************************************
*/

static  const  uint8_t  HID_KEYBRD_Codes[] = {
  0,     0,    0,    0,   31,   50,   48,   33, 
  19,   34,   35,   36,   24,   37,   38,   39,       /* 0x00 - 0x0F */
  52,    51,   25,   26,   17,   20,   32,   21,
  23,   49,   18,   47,   22,   46,    2,    3,       /* 0x10 - 0x1F */
  4,    5,    6,    7,    8,    9,   10,   11, 
  43,  110,   15,   16,   61,   12,   13,   27,       /* 0x20 - 0x2F */
  28,   29,   42,   40,   41,    1,   53,   54,  
  55,   30,  112,  113,  114,  115,  116,  117,       /* 0x30 - 0x3F */
  118,  119,  120,  121,  122,  123,  124,  125,  
  126,   75,   80,   85,   76,   81,   86,   89,       /* 0x40 - 0x4F */
  79,   84,   83,   90,   95,  100,  105,  106,
  108,   93,   98,  103,   92,   97,  102,   91,       /* 0x50 - 0x5F */
  96,  101,   99,  104,   45,  129,    0,    0, 
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0x60 - 0x6F */
  0,    0,    0,    0,    0,    0,    0,    0,
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0x70 - 0x7F */
  0,    0,    0,    0,    0,  107,    0,   56,
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0x80 - 0x8F */
  0,    0,    0,    0,    0,    0,    0,    0,
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0x90 - 0x9F */
  0,    0,    0,    0,    0,    0,    0,    0,
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0xA0 - 0xAF */
  0,    0,    0,    0,    0,    0,    0,    0, 
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0xB0 - 0xBF */
  0,    0,    0,    0,    0,    0,    0,    0, 
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0xC0 - 0xCF */
  0,    0,    0,    0,    0,    0,    0,    0, 
  0,    0,    0,    0,    0,    0,    0,    0,       /* 0xD0 - 0xDF */
  58,   44,   60,  127,   64,   57,   62,  128        /* 0xE0 - 0xE7 */
};




#ifdef QWERTY_KEYBOARD
static  const  int8_t  HID_KEYBRD_Key[] = {
  '\0',  '\'',  '1',  '2',  '3',  '4',  '5',  '6',
  '7',  '8',  '9',  '0',  '-',  '=',  '\0', 2,				//2 backspace
  3,  'q',  'w',  'e',  'r',  't',  'y',  'u',				//3 tab
  'i',  'o',  'p',  '´',  '[',  '\0',
  '\0',  'a',  's',  'd',  'f',  'g',  'h',  'j',
  'k',  'l',  'ç',  '~', ']', 4,							//4 enter
  '\0',  '\\', 'z',  'x',  'c',  'v',  'b',  'n',
  'm',  ',',  '.',  ';',  '/', '\0',
  '\0',  '\0', '\0', ' ',  '\0', '\0', '\0', '\0',					// ç e ´ são ascii estendido
  '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
  '\0',  '\0', '\0', '\0', 5, '\r', '\0', '\0',					//5 esquerda 6 cima 7 baixo 8 direita
  6, 7, '\0', '\0', '\0', '\0',
  8,  '\0', '7',  '4',  '1',
  '\0',  '/',  '8',  '5',  '2',
  '0',   '*',  '9',  '6',  '3',
  ',',   '-',  '+',  '\0', 4, '\0', 1, '\0', '\0', '\0', '\0',				//4 enter 1 escape
  '\0',  '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
  '\0', '\0', '\0', '\0'
};

static  const  int8_t  HID_KEYBRD_ShiftKey[] = {
  '\0', '"',  '!',  '@',  '#',  '$',  '%',  '¨',  '&',  '*',  '(',  ')',
  '_',  '+',  '\0', 2, 3, 'Q',  'W',  'E',  'R',  'T',  'Y',  'U',				//2 backspace   3 tab
  'I',  'O',  'P',  '`',  '{',  '}', '\0', 'A',  'S',  'D',  'F',  'G',
  'H',  'J',  'K',  'L',  'Ç',  '^',  '}', 4, '\0', '|', 'Z',  'X',				//Ç e ¨ são ascii estendido
  'C',  'V',  'B',  'N',  'M',  '<',  '>',  ':',  '?', '\0',  '\0', '\0',
  '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
  '\0', '\0', '\0', '\0', '\0', '\0', '\0', 5, '\0', '\0', '\0', 6,
  7, '\0', '\0', '\0', '\0', 8, '\0', '\0', 5, '\0', '\0', '/',
  6, '\0', 7, '0', '*', '\0', 8, '\0', '\0', '-', '+', '\0',
  4, '\0', 1, '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',		//4 enter  1 escape
  '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};
#endif



//--------------------------------------------------------------
static void  KEYBRD_Init (void)
{
  USR_KEYBRD_Init();
}

//--------------------------------------------------------------
static void KEYBRD_Decode(uint8_t *pbuf)      //pbuf=Packet Buffer
{


  static  uint8_t   shift;
  static  uint8_t   keys[KBR_MAX_NBR_PRESSED];
  static  uint8_t   keys_new[KBR_MAX_NBR_PRESSED];
  static  uint8_t   keys_last[KBR_MAX_NBR_PRESSED];
  static  uint8_t   key_newest;
  static  uint8_t   nbr_keys;
  static  uint8_t   nbr_keys_new;
  static  uint8_t   nbr_keys_last;
  static  uint8_t    caps=0;		// CapsLock inicia desligado
  static  uint8_t    numl=1;		// NumLock inicia ligado
  uint8_t   ix;
  uint8_t   jx;
  uint8_t   output;

  
  nbr_keys      = 0;                 //number of keys
  nbr_keys_new  = 0;
  //nbr_keys_last = 0;
  key_newest    = 0x00;
  
  
 //Check if Shift key is pressed
  if ((pbuf[0] == KBD_LEFT_SHIFT) || (pbuf[0] == KBD_RIGHT_SHIFT)) {
    shift = TRUE;
  } else {
    shift = FALSE;
  }

  for (ix = 2; ix < 2 + KBR_MAX_NBR_PRESSED; ix++) {
    if (pbuf[ix] != 0) {
      keys[nbr_keys] = pbuf[ix];
      nbr_keys++;
      for (jx = 0; jx < nbr_keys_last; jx++) {
        if (pbuf[ix] == keys_last[jx]) {
          break;
        }
      }

      if (jx == nbr_keys_last) {
        keys_new[nbr_keys_new] = pbuf[ix];
        nbr_keys_new++;
      }
    }
  }

  if (nbr_keys_new > 0) {

    key_newest = keys_new[0];


    if(key_newest==0x53){
        		  if(numl==0){								//Alerna entre os estados da variável numl
        			  numl=1;}
        		  else{
        			  numl=0;}}


    if(HID_KEYBRD_Codes[key_newest]==30){
    		  if(caps==0){								//Alterna entre os estados da variável caps
    			  caps=1;}
    		  else{
    			  caps=0;}}

    if (((caps ^ shift ) && key_newest<0x1D) || (key_newest>0x1D && shift) || (numl==0 && key_newest<0x64 && key_newest>0x58))   {
      output =  HID_KEYBRD_ShiftKey[HID_KEYBRD_Codes[key_newest]];
    } else {
      output =  HID_KEYBRD_Key[HID_KEYBRD_Codes[key_newest]];
    }
    USR_KEYBRD_ProcessData(output);
      } else {
    USR_KEYBRD_teclaliberada (TRUE);
	  key_newest = 0x00;
  }

  nbr_keys_last  = nbr_keys;
  for (ix = 0; ix < KBR_MAX_NBR_PRESSED; ix++) {
    keys_last[ix] = keys[ix];
  }
}


