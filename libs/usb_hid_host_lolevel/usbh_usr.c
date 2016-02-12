//--------------------------------------------------------------
//              PB13  -> USB_OTG_VBUS
//              PB12  -> USB_OTG_ID
//              PB14  -> USB_OTG_DM
//              PB15  -> USB_OTG_DP
//              PC4   -> USB_VBUS_Enable
//--------------------------------------------------------------



#include "usbh_usr.h"
#include "usbh_hid_keybd.h"


USB_OTG_CORE_HANDLE          USB_OTG_Core_dev;	// Variável global
USBH_HOST                    USB_Host;			// Variável global


USBH_Usr_cb_TypeDef USR_Callbacks =
{
  USBH_USR_Init,
  USBH_USR_DeInit,
  USBH_USR_DeviceAttached,
  USBH_USR_ResetDevice,
  USBH_USR_DeviceDisconnected,
  USBH_USR_OverCurrentDetected,
  USBH_USR_DeviceSpeedDetected,
  USBH_USR_Device_DescAvailable,
  USBH_USR_DeviceAddressAssigned,
  USBH_USR_Configuration_DescAvailable,
  USBH_USR_Manufacturer_String,
  USBH_USR_Product_String,
  USBH_USR_SerialNum_String,
  USBH_USR_EnumerationDone,
  USBH_USR_UserInput,
  NULL,
  USBH_USR_DeviceNotSupported,
  USBH_USR_UnrecoveredError
};


void USBH_USR_Init(void)  // Função chamado apenas na inicialização do host USB
{

}


void USBH_USR_DeviceAttached(void) // Chamada quando conecta Dispositivo
{   
  USB_HID_HOST_STATUS=USB_HID_DEV_DETACHED;
}


void USBH_USR_UnrecoveredError (void)
{
  USB_HID_HOST_STATUS=USB_HID_DEV_DETACHED;
}


void USBH_USR_DeviceDisconnected (void) // É chamada quando dispositivo é removido
{
  USB_HID_HOST_STATUS=USB_HID_DEV_DETACHED; // dispositivo desconectado
}


void USBH_USR_ResetDevice(void)
{

}


void USBH_USR_DeviceSpeedDetected(uint8_t DeviceSpeed) //Leitura de velocidade do dispositivo
{
  if ((DeviceSpeed != HPRT0_PRTSPD_FULL_SPEED)&&(DeviceSpeed != HPRT0_PRTSPD_LOW_SPEED))
  {
    USB_HID_HOST_STATUS=USB_HID_SPEED_ERROR;
  }
  else {
    USB_HID_HOST_STATUS=USB_HID_SPEED_OK;
  }
}


void USBH_USR_Device_DescAvailable(void *DeviceDesc)
{

}


void USBH_USR_DeviceAddressAssigned(void)
{

}


void USBH_USR_Configuration_DescAvailable(USBH_CfgDesc_TypeDef * cfgDesc,
                                          USBH_InterfaceDesc_TypeDef *itfDesc,
                                          USBH_EpDesc_TypeDef *epDesc)
{

}


void USBH_USR_Manufacturer_String(void *ManufacturerString)
{

}


void USBH_USR_Product_String(void *ProductString)
{

}


void USBH_USR_SerialNum_String(void *SerialNumString)
{

} 


void USBH_USR_EnumerationDone(void)
{
  USB_HID_HOST_STATUS=USB_HID_DEV_CONNECTED;
} 


void USBH_USR_DeviceNotSupported(void) // É chamado pelo host USB se o dispositivo não é suportado
{
  USB_HID_HOST_STATUS=USB_HID_DEV_NOT_SUPPORTED;
}  


USBH_USR_Status USBH_USR_UserInput(void)
{

  USBH_USR_Status usbh_usr_status;

  usbh_usr_status = USBH_USR_NO_RESP;


  if(hid_autoconnect != 0)    // Verificar se o dispositivo USB está conectado
  {
    usbh_usr_status = USBH_USR_RESP_OK;
    hid_autoconnect=0;
  }

  return usbh_usr_status;
}


void USBH_USR_OverCurrentDetected (void)
{
  USB_HID_HOST_STATUS=USB_HID_OVER_CURRENT;
}


void USBH_USR_DeInit(void)
{
  USB_HID_HOST_STATUS=USB_HID_DEV_DETACHED;
}



//----------------------------------------------------------------------------------------------------------------------
//Controles específicos do teclado
//----------------------------------------------------------------------------------------------------------------------



void  USR_KEYBRD_Init (void) //chamado uma vez quando o teclado USB inicializa
{
	USB_HID_HOST_STATUS=USB_HID_KEYBOARD_CONNECTED;
	USB_KEY_DATA.tecla_press=0;
	USB_KEY_DATA.tecla_liberada=0;
}


void  USR_KEYBRD_ProcessData (uint8_t data) // É chamado ao final da decodificoção, cada vez que uma tecla é pressionada no teclado USB
{
	USB_KEY_DATA.tecla_press=data;
}

void  USR_KEYBRD_teclaliberada (uint8_t data2) // É chamado cada vez que uma tecla é liberada
{
	USB_KEY_DATA.tecla_liberada=data2;
}


/**
  * @brief  Está rotina é chamada para inicializar a porta USB e
  * redefinir as variáveis: hid_autoconnect=0, tecla_press=0 e tecla_liberada=0
  * @param  Nenhum
  * @retval Nenhum
  */
void USB_Init(void)
{
  USB_HID_HOST_STATUS=USB_HID_DEV_DETACHED; //Modifica o estado da comunicação USB para desconectado

  //Redefinir todas as variáveis
  hid_autoconnect=0;
  USB_KEY_DATA.tecla_press=0;
  USB_KEY_DATA.tecla_liberada=0;

 //Inicialição da porta USB OTG como HOST de dispositivos HID
  USBH_Init(&USB_OTG_Core_dev, USB_OTG_HS_CORE_ID, &USB_Host, &HID_cb, &USR_Callbacks);
}



/**
  * @brief  Está rotina é chamada para realizar o processo USB
  * detecção, enumeração, transferências e controle de classe
  * @param  Nenhum
  * @retval Estado da comunicação
  */
USB_HID_HOST_STATUS_t USB_Function(void)

{
  static uint32_t timeout_cnt=0;
  if(USB_HID_HOST_STATUS!=USB_HID_DEV_NOT_SUPPORTED) {  // Se o dispositivo USB não é suportado,a função não é chamada e assim o software não trava
	  USBH_Process(&USB_OTG_Core_dev, &USB_Host);       //controla o estado da comunicação USB
  }

  // Erro de tempo limite (se o dispositivo não é reconhecido por muito tempo)
  if((USB_HID_HOST_STATUS==USB_HID_SPEED_OK) || (USB_HID_HOST_STATUS==USB_HID_SPEED_ERROR)) {
    timeout_cnt++;
    if(timeout_cnt>USB_HID_HOST_TIMEOUT)
    {
      // Se limite expirou -> erro
    	USB_HID_HOST_STATUS=USB_HID_DEV_NOT_SUPPORTED;
    }
  }
  else {
    timeout_cnt=0;
  }

  // Autoconectar quando o dispositivo HID foi inserido
  if(USB_HID_HOST_STATUS==USB_HID_DEV_CONNECTED) {
    hid_autoconnect=1;
   }

  if(USB_HID_HOST_STATUS==USB_HID_DEV_DETACHED) {
     }


  return(USB_HID_HOST_STATUS);
}



uint8_t GetKey(void)
{
  uint8_t aux=0;

  if(USB_KEY_DATA.tecla_press>0) {
    	aux=USB_KEY_DATA.tecla_press;
      USB_KEY_DATA.tecla_press=0;
  }
  return(aux);
}

uint8_t GetKey2(void)
{
  uint8_t aux;

    if(USB_KEY_DATA.tecla_liberada>0) {
    	aux=USB_KEY_DATA.tecla_liberada;
        USB_KEY_DATA.tecla_liberada=0;
  }
  return(aux);
}


