#include "UART.h"

void UART_Init(long baudRate)
{
    TXSTA = 0x20; //Enable UART TX //TXEN 
    RCSTA = 0x90; //Enable UART RX  //CREAN SPEN
    PIE1 = 0X20; // Interrupt trig configuration //RCIE 
    SPBRG =(_XTAL_FREQ/(long)(64UL * baudRate))-1;
    
    
}
void UART_Send(char dataSend)
{
    while(!(PIR1 & 0x10));
    PIR1 &= ~0x10;
    TXREG = dataSend;
}