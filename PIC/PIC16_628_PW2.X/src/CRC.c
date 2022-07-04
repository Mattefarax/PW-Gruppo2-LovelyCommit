#include "CRC.h"

char *CRC_Calc(char buff[], char queueElement) 
{
    unsigned short crc = 0xFFFF;
    for (char i = 0; i < queueElement; i++) //For each byte of the request crc is updated following the polynomial operations
    {
        crc = (crc ^ (buff[i] | 0x0000)); 
        for (int j = 8; j > 0; j--) //Polynomial operation for each bit
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
    
    //Big endian in buffer 0
    char HighCRC = crc >> 8;
    char LowCRC = crc & 0xFF;

    char crcArray[] = { LowCRC, HighCRC };

    return crcArray;
}

char CRC_Check(char buff[], char len)
{
    char *payload_crc = CRC_Calc(buff, len);
    if ((buff[len] == payload_crc[0])&&(buff[len+1] == payload_crc[1])) //Calculate the crc and check if is correct
    {
        return 1; //The CRC match
    }
    else
    {
        return 0; //The don't CRC match
    }
}

char *CRC_Add(char buff[], char len)
{
    char *payload_crc = CRC_Calc(buff, len); //Calculate the 2 byte of CRC  
    //Append them to the original array
    buff[len] = payload_crc[0];
    buff[len+1] = payload_crc[1];
    
    return buff;
}