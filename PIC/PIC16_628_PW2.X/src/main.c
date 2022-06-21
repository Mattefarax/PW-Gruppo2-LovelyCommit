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


char UARTRead;
int baudRate = 115200;
char stringa[20];

char *CharToLCD (char num);
unsigned long Power(char num, char times);


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
                PROTO_QueueChecker();
                LCD_Write(CharToLCD(addr));
                PROTO_SendPayload();
            }
        }
    }
    return;
}

char *CharToLCD (char num)
{
    char res[4];
    for (char i = 0; i < 3; i++) 
    {
        res[3 - i - 1] = (num / Power(10, i)) % 10 + '0';
    }
    res[4] = "\0";
    return res;
}
unsigned long Power(char num, char times) {
    unsigned long result = 1;
    for (char i = 0; i < times; i++) {
        result *= num;
    }
    return result;
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