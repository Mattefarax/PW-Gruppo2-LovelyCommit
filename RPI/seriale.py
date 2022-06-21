from ast import Bytes
from multiprocessing.reduction import send_handle
from ssl import MemoryBIO
from time import sleep
from unicodedata import numeric
from numpy import broadcast
import serial

def sendMessage(list):
    for x in list:
        s.write(x)

def Addresser(list,countId):
    if(list[0]==myId.to_bytes(1,'big'))and(list[1]==bytes(b'\xff'))and(list[2]==bytes(b'\x00')):  #Richiesta di indirizzamento
            sendAddress[0]=broadcastCode.to_bytes(1,'big')
            sendAddress[1]=myId.to_bytes(1,'big')
            sendAddress[2]=handshakeCode.to_bytes(1,'big')
            sendAddress[3]=countId.to_bytes(1,'big')
            sendAddress[4]=zero.to_bytes(1,'big')
            sendAddress[5]=zero.to_bytes(1,'big')
            sendAddress[6]=zero.to_bytes(1,'big')
            sendAddress[7]=zero.to_bytes(1,'big')
            sendMessage(sendAddress)
            print(sendAddress)
def Temperature(list):
    print('sono dentro temperatura')
def Humidity(list):
    print('Sono dentro Humidity')

countId=1
zero=0
handshakeCode=1
broadcastCode=255
s=serial.Serial(port='COM6',baudrate=115200, bytesize=8, parity='N', stopbits=1)
lista=[]
ncycles=10
myId=0
sendAddress=[-1,-1,-1,-1,-1,-1,-1,-1]
while 1:
    count=s.in_waiting    #conta il numero di byte presenti all'interno della seriale
    if count>0:
        numCycles=0
        BytestoRead=0
        LastBytestoRead=0
        while numCycles<ncycles:
            numCycles+=1
            BytestoRead=s.in_waiting

            if (BytestoRead!=LastBytestoRead):
                LastBytestoRead=BytestoRead
                numCycles=0
            sleep(0.005)
        for c in range(BytestoRead):
            lista.append(s.read(1))

        print(lista)

    if len(lista)==3:
        Addresser(lista,countId)
        countId+=1

    if len(lista)>3:
        if(lista[2]==bytes(b'\x20'))and(lista[3]):
            Temperature(lista)
    
        if(lista[2]==bytes(b'\x20'))and(lista[5]):
            Humidity(lista)

            # sendAddress=[]
            
    # sendMessage(lista)
    lista=[]

    

