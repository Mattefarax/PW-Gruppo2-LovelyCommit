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
#define baudRate 115200
#define preloadTMR 131

char count = 0;
int countMilli = 0;
char lastReceiveSec = 0;

char *CharToLCD (char num);
unsigned long Power(char num, char times);


void main(void) {
    //Interrupt configuration
    INTCON = 0x80; //GIE 
    INTCON |= 0x40; //PIEI
    INTCON |= 0x20; //TMR0IE
    
    //Value for 200us interrupt
    OPTION_REG = 0x02; //Prescaler
    TMR0 = preloadTMR; //Pre Load Timer Value
            
    TRISC = 0X80;
    TRISD = 0X00;
    TRISE = 0X00;
    UART_Init(baudRate);
    LCD_Init();
    
    while(1)
    {
        if ( (countMilli/1000 >= payloadAddrRetry) && (addr == 0)) 
        {
            PROTO_HandshakeReq();
            countMilli = 0;
        }
        if ( (countMilli/1000 >= payloadSendSecond) && (addr != 0))
        {
            PROTO_SendPayload();
            countMilli = 0;
        }
        if ( (lastReceiveSec >= messageOffsetTimeout) && (queueElement != 0))
        {
            PROTO_QueueChecker();   
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
    if(PIR1 & 0x20) //UART Receive
    {
        UARTRead = RCREG;
        //PIR1 &= ~0x20;
        if ((queueElement < queueLenght) )
        {
            QUEUE_Insert(UARTRead);
        }
        lastReceiveSec = 0;
    }
    if(INTCON & 0x04) //Timer 
    {
        //200us each interrupt
        count++;
        if (count >= 5)
        {
            countMilli++;
            count = 0;
        }
        if (lastReceiveSec <= messageOffsetTimeout)
        {
            lastReceiveSec++;
        }
        
        TMR0 = preloadTMR;
        INTCON &= ~0x04; //Reset T0IF to 0
    }
}