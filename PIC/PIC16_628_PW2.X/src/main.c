/*
 * File:   main.c
 * Author: Pizzato Davide
 *
 * Created on 15 maggio 2022, 14.55
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "LCD.h"
#include "UART.h"
#include "QUEUE.h"
#include "PROTO.h"
#include <string.h>


char UARTRead;
int baudRate = 115200;
char stringa[20];


void main(void) {
    INTCON |= 0xC0; //Interrupt configuration //GIE PIEI
    TRISC = 0X80;
    TRISD = 0X00;
    TRISE = 0X00;
    UART_Init(baudRate);
    LCD_Init();
    PROTO_HandshakeReq();
    
    while(1)
    {
        if (queueElement >= queueLenght)
        {       
            if (addrRequested == 1)
            {
                LCD_Write("ID:");
            }
            PROTO_QueueChecker();

            //0xff 0x00 0x01 0x07 0x00 0x00 0x00 0x00
            //0x07 0x00 0x10 0x00 0x00 0x00 0x00 0x00
        }
    }
    return;
}





void __interrupt() ISR()
{
    if(PIR1 & 0x20)
    {
        UARTRead = RCREG;
        //PIR1 &= ~0x20;
        if ((queueElement < queueLenght) )
        {
            QUEUE_Insert(UARTRead);
        }
    }
}

/*
if( (UARTRead != ' ') & (!mem_r))
{
    LCD_Send(UARTRead, 0);
    sendUart(UARTRead);
    mem_r = 1;
}
//sendUart('d');
*/