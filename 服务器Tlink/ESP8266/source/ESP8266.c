#include <iom64v.h>
#include <macros.h>
#include "ESP8266.h"

void espdelay(void)
{
  int i;
  for(i=0;i<2000;i++)
  {
    NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
	NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
  }
}

void ESPSendByte(unsigned char data)
{
   UDR1 = data;
   while(!(UCSR1A&(1<<5)));
   espdelay();
}

void ESPSendString(unsigned char *pstr)
{
   while(*pstr)
   {	  
      ESPSendByte(*pstr);
      pstr++;
   }
}