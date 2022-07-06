import numpy as np
import libscrc
def crc_calc(buff):
    # lista=[b'\x00', b'\xff', b'\x00']
    cast=[]
    # list1=[ 0xff, 0x00,0x01,0x01 ]
    print(type(0xff))
    for x in buff:
        cast.append(int.from_bytes(x,'big'))
    crc16 = libscrc.modbus(bytearray(cast))
    list=[]
    list.append(hex(int(crc16/256)))
    list.append(hex(int(crc16%256)))
    return crc16

def crc_calc1(buff):
    cast=[]
    # list1=[ 0xff, 0x00,0x01,0x01 ]
    print(type(0xff))
    for x in buff:
        cast.append(int.from_bytes(x,'big'))
    crc16 = libscrc.modbus(bytearray(cast))
    list=[]
    list.append(hex(int(crc16/256)))
    list.append(hex(int(crc16%256)))
    return list











    # crc = (0xFFFF)
    # for i in buff:
    #     crc = crc ^ (crc ^ (i | 0x0000))      #for every byte that compose the request update the crc following the polynomials operation
    #     for  j in range(8, 0, -1):
    #         if ((crc & 1) != 0):
    #             crc = (crc >> 0x0001)
    #             crc = (crc ^ 0xA001)
    #         else:
    #             crc = (crc >> 1)
    
    # HighCRC = bytes(crc >> 8)
    # LowCRC = bytes(crc & 0xFF)

    # crcArray = [ LowCRC, HighCRC ]

    # return crcArray;     #when che operation is over return the crc


# buffer = [0x00, 0xff, 0x00]
# print(crc_calc(buffer))

#crc16 = libscrc.modbus(b'1234')       # Calculate ASCII of modbus

