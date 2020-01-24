// Crystal: 16.000Mhz

#include <iom64v.h>
#include <macros.h>
#include <string.h>
#include "uart.h"

//unsigned char espbuf[1024];
unsigned long espbufcount = 0;
unsigned char esplineflag = 0;
 int j=0,q=0;
 unsigned char str[1024];
 unsigned char str1[1024];
//UART0 initialize
// desired baud rate: 9600
// actual: baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
void uart0_init(void)//���ӵ���
{
 UCSR0B = 0x00; //disable while setting baud rate
 UCSR0A = 0x00;
 UCSR0C = 0x06;
 UBRR0L = 0x67; //set baud rate lo
 UBRR0H = 0x00; //set baud rate hi
 UCSR0B = 0x98;
}

#pragma interrupt_handler uart0_rx_isr:iv_USART0_RXC
void uart0_rx_isr(void)
{
	 //uart has received a character in UDR
	 unsigned char data;
	 int k,i;
	 data=UDR0;
	 str[j]=data;
	 j++;
	 if(str[j]=='\0')
	 {
		 PrintString1(str);
		 for(k=0;k<j;k++)
		 {
			str[k]=0;
		 }
		 j=0;
	 }
}

//UART1 initialize
// desired baud rate:9600
// actual baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
void uart1_init(void)
{
 UCSR1B = 0x00; //disable while setting baud rate
 UCSR1A = 0x00;
 UCSR1C = 0x06;
 UBRR1L = 0x67; //set baud rate lo
 UBRR1H = 0x00; //set baud rate hi
 UCSR1B = 0x98;
}
/*
void uart1_init(void)
{
 UCSR1B = 0x00; //disable while setting baud rate
 UCSR1A = 0x00;
 UCSR1C = 0x06;
 UBRR1L = 0x67; //set baud rate lo
 UBRR1H = 0x00; //set baud rate hi
 UCSR1B = 0x98;
}
*/
//unsigned char buf[1024];//////////
#pragma interrupt_handler uart1_rx_isr:iv_USART1_RXC
void uart1_rx_isr(void)
{
 //uart has received a character in UDR
 unsigned char data;
 int k;
 data = UDR1;
 str1[q]=data;
 q++;
 if(str1[q]=='\0')
 {
 PrintString(str1);
 for(k=0;k<q;k++)
 {
  	str1[k]=0;
 }
 q=0;
 }
}

void UartSendByte(unsigned char data)
{
   UDR0 = data;
   while(!(UCSR0A&(1<<5)));
}

void PrintString(unsigned char *pstr)
{
   while(*pstr)
   {	  
      UartSendByte(*pstr);
      pstr++;
   }
}

void UartSendByte1(unsigned char data)
{
   UDR1 = data;
   while(!(UCSR1A&(1<<5)));
}

void PrintString1(unsigned char *pstr)
{
   while(*pstr)
   {	  
      UartSendByte1(*pstr);
      pstr++;
   }
}