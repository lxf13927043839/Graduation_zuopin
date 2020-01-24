#ifndef UART_H_
#define UART_H_

//UART0 initialize
// desired baud rate: 9600
// actual: baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
void uart0_init(void);


//UART1 initialize
// desired baud rate:9600
// actual baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
void uart1_init(void);


void UartSendByte(unsigned char data);

void PrintString(unsigned char *pstr);
unsigned char espgetline(unsigned char *p);
#endif