#include "CRC.h"

char *CRC_calc(char buff[], char queueElement) //big endian in buffer 0
{
    unsigned short crc = 0xFFFF;
    for (char i = 0; i < queueElement; i++)
    {
        crc = (crc ^ (buff[i] | 0x0000));      //for every byte that compose the request update the crc following the polynomials operation
        for (int j = 8; j > 0; j--)
        {
            if ((crc & 1) != 0)
            {
                crc = (crc >> 0x0001);
                crc = (crc ^ 0xA001);
            }
            else
            {
                crc = (crc >> 1);
            }
        }
    }
    
    char HighCRC = crc >> 8;
    char LowCRC = crc & 0xFF;

    char crcArray[] = { LowCRC, HighCRC };

    return crcArray;     //when che operation is over return the crc
}