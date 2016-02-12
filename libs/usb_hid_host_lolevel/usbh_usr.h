//--------------------------------------------------------------
// File     : usbh_usr.h
//--------------------------------------------------------------



#ifndef __USH_USR_H__
#define __USH_USR_H__


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "usbh_core.h"
#include "usb_conf.h"
#include <stdio.h>
#include "usbh_hid_core.h"
#include "stm32f4xx.h"



extern  USBH_Usr_cb_TypeDef USR_Callbacks;


//--------------------------------------------------------------
void USBH_USR_Init(void);
void USBH_USR_DeviceAttached(void);
void USBH_USR_ResetDevice(void);
void USBH_USR_DeviceDisconnected (void);
void USBH_USR_OverCurrentDetected (void);
void USBH_USR_DeviceSpeedDetected(uint8_t DeviceSpeed); 
void USBH_USR_Device_DescAvailable(void *);
void USBH_USR_DeviceAddressAssigned(void);
void USBH_USR_Configuration_DescAvailable(USBH_CfgDesc_TypeDef * cfgDesc,
                                          USBH_InterfaceDesc_TypeDef *itfDesc,
                                          USBH_EpDesc_TypeDef *epDesc);
void USBH_USR_Manufacturer_String(void *);
void USBH_USR_Product_String(void *);
void USBH_USR_SerialNum_String(void *);
void USBH_USR_EnumerationDone(void);
USBH_USR_Status USBH_USR_UserInput(void);
void USBH_USR_DeInit(void);
void USBH_USR_DeviceNotSupported(void);
void USBH_USR_UnrecoveredError(void);


#endif /* __USBH_USR_H */




//--------------------------------------------------------------
// Estado da conexão USB
//--------------------------------------------------------------
typedef enum {
  USB_HID_HOST_NO_INIT =0,   // Interface USB ainda não inicializada
  USB_HID_DEV_DETACHED,      // Nenhum dispositivo conectado
  USB_HID_SPEED_OK,          // USB-Speed é suportado
  USB_HID_SPEED_ERROR,       // USB-Speed não suportado
  USB_HID_DEV_NOT_SUPPORTED, // Device não suportado
  USB_HID_OVER_CURRENT,      // sobrecorrente detectado
  USB_HID_DEV_CONNECTED,     // Device conectado, mas não está pronto
  USB_HID_KEYBOARD_CONNECTED // Teclado ligado e pronto
}USB_HID_HOST_STATUS_t;
USB_HID_HOST_STATUS_t USB_HID_HOST_STATUS;


#define   USB_HID_HOST_TIMEOUT   500000 // Não reduzir o tempo!!

//--------------------------------------------------------------
// Variáveis globais
//--------------------------------------------------------------
uint32_t hid_autoconnect;


//--------------------------------------------------------------
// Estrutura global dos dados Keyboard
//--------------------------------------------------------------
typedef struct {
  uint8_t tecla_press;
  uint8_t tecla_liberada;
}USB_KEY_DATA_t;
USB_KEY_DATA_t USB_KEY_DATA;


//--------------------------------------------------------------
// Funções Globais
//--------------------------------------------------------------
void USB_Init(void);
USB_HID_HOST_STATUS_t USB_Function(void);
uint8_t GetKey(void);
uint8_t GetKey2(void);
uint8_t verificaracentos(uint8_t);
uint8_t capslock(void);
//--------------------------------------------------------------

