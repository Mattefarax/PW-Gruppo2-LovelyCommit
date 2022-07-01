#include "UART.h"

void UART_Init(long baudRate)
{
    TRISC &= ~TX_Pin;
    TRISC |= RX_Pin;
    //TRISE &= ~RE_Pin;
    TXSTA = 0x24; //Enable UART TX //TXEN //BRGH
    RCSTA = 0x90; //Enable UART RX  //CREAN SPEN
    PIE1 = 0X20; // Interrupt trig configuration //RCIE 
    SPBRG =(_XTAL_FREQ/(long)(16UL * baudRate))-1;
    
    
}
void UART_Send(char dataSend)
{
    //PORTE &= ~RE_Pin;
    while(!(PIR1 & 0x10));
    PIR1 &= ~0x10;
    TXREG = dataSend;
    //PORTE |= RE_Pin;

}
void UART_SendBuffer(char buff[], char len)
{
    for (char ind = 0; ind < len; ind++)
    {
        UART_Send(buff[ind]);
    }
}