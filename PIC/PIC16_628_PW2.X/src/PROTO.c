#include "PROTO.h"
#include "UART.h"
#include "QUEUE.h"
#include "CRC.h"
#include "LCD.h"
#include "SENSORS.h"

void PROTO_HandshakeReq()
{
    char handshake[5] = { 0x00, 0xff, 0x00 }; //  ID RPI - ID Broadcast - Code
    UART_SendBuffer(CRC_Add(handshake, 3), 5);
    /*
    UART_Send(0x00); //ID RPI
    UART_Send(0xff); //ID Broadcast
    UART_Send(0x00); //Code
    */
    addrRequested = 1;
}
void PROTO_SendPayload(char temp_1_2, char temp_2_2, char humidity_1_2, char humidity_2_2)
{   
    char payload[12] = { 0x00, addr, 0x20, temp_1_2, temp_2_2, setTemp_1_2, setTemp_2_2, humidity_1_2, humidity_2_2, protoStatusByte};
    UART_SendBuffer(CRC_Add(payload, 10), 12);
    //payload[10] = CRC_Calc(payload, 10)[0];
    //payload[11] = CRC_Calc(payload, 10)[1];
}


void PROTO_QueueChecker()
{
    if (queue[1] == 0x00) //RPI Addr
    {
        if ((addrRequested == 1) && (queue[0] == 0xff) && (queue[2] == 0x01) && (CRC_Check(queue, 4))) //My request //On Broadcast //With IDResponse Code //CRC Check
        {
            //ADDRESS
            addr = queue[3];
            addrRequested = 0;
        }
        else if (((queue[0] == addr)||(queue[0] == 0xff)) && (addr != 0))
        {
            if ((queue[2] == 0x10)&&(CRC_Check(queue, 4)))
            {
                //EMERGENCY
                if (queue[3] & 0x01) //Set emergency
                {
                    protoStatusByte |= EMERGENCY_BIT;
                }
                else if(queue[3] & 0x02)//Reset emergency
                {
                    protoStatusByte &= ~EMERGENCY_BIT;
                }
            }
            else if ((queue[2] == 0x11) && (CRC_Check(queue, 5)))
            {
                //TARGET TEMP
                SENSORS_SetTemp(queue[3], queue[4]);
            }
            else if ((queue[2] == 0x12) && (CRC_Check(queue, 4)))
            {
                //DOORS
                queue[3] &= 0x03;
                protoStatusByte ^= (queue[3] << 1);
            }
            else if ((queue[2] == 0x13) && (CRC_Check(queue, 23)) && (queueElement >= 23))
            {
                //TEXT
                for(char chr = 0; chr < 20; chr++)
                {
                    displayText[chr] = queue[chr+3];
                }
                displayText[19] = '\0';
                LCD_Send(0xD4, 1);
                LCD_Write(displayText);
            }
            else if ((queue[2] == 0x14) && (CRC_Check(queue, 4)))
            {
                //WAGON NUMBER
                wagonNumber = queue[3];
            }
        }
    }
    queueElement = 0;
}

