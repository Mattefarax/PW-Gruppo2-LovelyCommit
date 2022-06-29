#ifndef UART_h
#define UART_h
#include <xc.h>
#define _XTAL_FREQ 20000000

//Declarations
#define baudRate 115200

char UARTRead;

void UART_Init(long baudRate);
void UART_Send(char dataSend);
void UART_SendBuffer(char buff[], char len);

#endif
