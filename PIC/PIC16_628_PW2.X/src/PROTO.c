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
        }
        else if ((queue[0] == addr)||(queue[0] == 0xff))
        {
            if (queue[2] == 0x10)
            {
                //CMD
            }
            else if (queue[2] == 0x11)
            {
                //TEXT

            }
        }
    }
    queueElement = 0;
}

