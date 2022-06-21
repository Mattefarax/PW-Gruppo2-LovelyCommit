#include "PROTO.h"
#include "UART.h"
#include "QUEUE.h"
//Da togliere
#include "LCD.h"

char *CharToLCD (char num);
unsigned long Power(char num, char times);

void PROTO_HandshakeReq()
{
    UART_Send(0x00); //ID RPI
    UART_Send(0xff); //ID Broadcast
    UART_Send(0x00); //Code
    addrRequested = 1;
}

void PROTO_SendPayload()
{
    
}

void PROTO_QueueChecker()
{
    if (queue[1] == 0x00) //RPI Addr
    {
        if ((addrRequested == 1) && (queue[0] == 0xff) && (queue[2] == 0x01)) //My request //On Broadcast //With IDResponse Code
        {
            addr = queue[3];
            addrRequested = 0;
            LCD_Write(CharToLCD(addr));
        }
        else if (queue[0] == addr)
        {
            if (queue[2] == 0x10)
            {
                //CMD
                LCD_Write("cmd");
            }
            else if (queue[2] == 0x11)
            {
                //TEXT
                LCD_Write("text");

            }
        }
    }
    queueElement = 0; //Da togliere!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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


