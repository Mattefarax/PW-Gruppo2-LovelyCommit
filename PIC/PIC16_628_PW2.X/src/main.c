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
#include "MENU.h"
#include "SENSORS.h"

#define preloadTMR 56
#define baudRate 9600

//Counters
char count = 0;
int countMilli = 0;
char lastReceiveSec = 0;

char *CharToLCD (char num);
unsigned long Power(char num, char times);
void PIC_Init(void);

void main(void) 
{
    
    PIC_Init();
    UART_Init(baudRate);
    LCD_Init();
    MENU_Home();
    SENSORS_Init();
    
    while(1)
    {
        MENU_Check();
        if ((countMilli/1000 >= sensorCheckSec))
        {
            SENSORS_Get();
        }
        if ( (countMilli/1000 >= payloadAddrRetryMs) && (addr == 0)) //Retry handshake until address is acquired
        {
            PROTO_HandshakeReq();
            countMilli = 0;
        }
        if ( (countMilli/1000 >= payloadSendS) && (addr != 0)) //Schedule payload transmission
        {
            PROTO_SendPayload(temp_1_2, temp_2_2, humidity_1_2, humidity_2_2);
            countMilli = 0;
        }
        if ( (lastReceiveSec >= payloadValidationTimeout) && (queueElement != 0)) //Validate the queue if a time of transmission-silence occurred
        {
            PROTO_QueueChecker();
        }
    }
    return;
}

void PIC_Init()
{
    //Interrupt configuration
    INTCON = 0x80; //GIE 
    INTCON |= 0x40; //PIEI
    INTCON |= 0x20; //TMR0IE
    
    //Value for 200us interrupt
    OPTION_REG = 0x00; //Prescaler
    TMR0 = preloadTMR; //Pre Load Timer Value
            
    TRISB = 0X00;
    TRISC = 0X00;
    TRISD = 0X00;
    TRISE = 0X00;
    TRISB |= 0X07; //Buttons
}

char *CharToLCD (char num)
{
    char res[4];
    for (char i = 0; i < 3; i++) 
    {
        res[3 - i - 1] = (num / Power(10, i)) % 10 + '0';
    }
    res[3] = "\0";
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
        lastReceiveSec = 0; //If something is received thru uart this counter is reset
    }
    if(INTCON & 0x04) //Timer 
    {
        //200us each interrupt
        count++;
        if (count >= 5) //Each ms
        {
            countMilli++;
            count = 0;
            if (lastReceiveSec <= payloadValidationTimeout) 
            {
                lastReceiveSec++;
            }
        }
        
        TMR0 = preloadTMR;
        INTCON &= ~0x04; //Reset T0IF to 0
    }
}