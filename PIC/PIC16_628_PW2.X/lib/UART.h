#ifndef UART_h
#define UART_h
#include <xc.h>
#define _XTAL_FREQ 20000000

//Declarations

void UART_Init(long baudRate);
void UART_Send(char dataSend);

#endif
