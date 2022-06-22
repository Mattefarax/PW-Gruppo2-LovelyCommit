#include "PROTO.h"
#include "UART.h"
#include "QUEUE.h"

void PROTO_HandshakeReq()
{
    UART_Send(0x00); //ID RPI
    UART_Send(0xff); //ID Broadcast
    UART_Send(0x00); //Code
    addrRequested = 1;
}

void PROTO_SendPayload()
{
    UART_Send(0x00); //ID RPI
    UART_Send(addr); //ID PIC
    UART_Send(0x20); //Code
    UART_Send(27); //Temp_1_2
    UART_Send(15); //Temp_2_2
    UART_Send(0x00); //Humidity_1_2
    UART_Send(0x00); //Humidity_2_2
    UART_Send(0x07); //8th
}

void PROTO_QueueChecker()
{
    if (queue[1] == 0x00) //RPI Addr
    {
        if ((addrRequested == 1) && (queue[0] == 0xff) && (queue[2] == 0x01)) //My request //On Broadcast //With IDResponse Code
        {
            addr = queue[3];
            addrRequested = 0;
            UART_Send(0x01);
        }
        else if (((queue[0] == addr)||(queue[0] == 0xff)) && (addr != 0))
        {
            if (queue[2] == 0x10)
            {
                //EMERGENCY
                UART_Send(0x10);
            }
            else if (queue[2] == 0x11)
            {
                //TARGET TEMP
                UART_Send(0x11);
            }
            else if (queue[2] == 0x12)
            {
                //DOORS
                UART_Send(0x12);
            }
            else if (queue[2] == 0x13)
            {
                //TEXT
                UART_Send(0x13);
            }
        }
    }
    queueElement = 0;
}

