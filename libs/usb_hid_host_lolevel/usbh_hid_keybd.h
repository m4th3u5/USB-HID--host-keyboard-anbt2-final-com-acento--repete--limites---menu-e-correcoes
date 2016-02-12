//--------------------------------------------------------------
// File     : usbh_hid_keybd.h
//--------------------------------------------------------------


#ifndef __USBH_HID_KEYBD_H
#define __USBH_HID_KEYBD_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "usb_conf.h"
#include "usbh_hid_core.h"


//--------------------------------------------------------------
// Layout do teclado (apenas um ativado)
//--------------------------------------------------------------
//define QWERTZ_KEYBOARD
#define QWERTY_KEYBOARD
//#define AZERTY_KEYBOARD


#define  KBD_LEFT_CTRL                                  0x01
#define  KBD_LEFT_SHIFT                                 0x02
#define  KBD_LEFT_ALT                                   0x04
#define  KBD_LEFT_GUI                                   0x08
#define  KBD_RIGHT_CTRL                                 0x10
#define  KBD_RIGHT_SHIFT                                0x20
#define  KBD_RIGHT_ALT                                  0x40
#define  KBD_RIGHT_GUI                                  0x80

#define  KBR_MAX_NBR_PRESSED                            6



extern HID_cb_TypeDef HID_KEYBRD_cb;

void  USR_KEYBRD_Init (void);
void  USR_KEYBRD_ProcessData (uint8_t pbuf);
void  USR_KEYBRD_teclaliberada (uint8_t pbuf);

#endif /* __USBH_HID_KEYBD_H */

