import numpy as np

def crc_calc(buff):
    crc = (0xFFFF)
    for i in buff:
        crc = (crc ^ (i | 0x0000));      #for every byte that compose the request update the crc following the polynomials operation
        for  j in range(8, 0, -1):
            if ((crc & 1) != 0):
                crc = (crc >> 0x0001)
                crc = (crc ^ 0xA001)
            else:
                crc = (crc >> 1)
    
    HighCRC = np.int8(crc >> 8)
    LowCRC = np.int8(crc & 0xFF)

    crcArray = [ LowCRC, HighCRC ]

    return crcArray;     #when che operation is over return the crc


buffer = [0x00, 0xff, 0x00]
print(crc_calc(buffer))