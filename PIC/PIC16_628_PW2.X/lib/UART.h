#ifndef UART_h
#define UART_h
#include <xc.h>
#define _XTAL_FREQ 8000000

#define RE_Pin 0x01
#define TX_Pin 0x40
#define RX_Pin 0x80

char UARTRead;

void UART_Init(long baudRate);
void UART_Send(char dataSend);
void UART_SendBuffer(char buff[], char len);

#endif
