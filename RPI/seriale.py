from ast import Bytes
from logging import raiseExceptions
from multiprocessing.reduction import send_handle
import random
from ssl import MemoryBIO
from time import sleep
from unicodedata import numeric
from numpy import broadcast
import serial
from send import send_to_queue
import datetime
from protoCRC import crc_calc

def create_Json(list):
    print("bisogna creare un json con le informazioni salvate nella lista")
    jsonfile = {"Telemetry":{"idVagone":list[1],"Current_Temperature": str(int.from_bytes(list[2], byteorder="big"))+","+str(int.from_bytes(list[3], byteorder="big")),"Desired_Temperature":str(int.from_bytes(list[4], byteorder="big"))+","+str(int.from_bytes(list[5], byteorder="big")),"Humidity":str(int.from_bytes(list[6], byteorder="big"))+","+str(int.from_bytes(list[7], byteorder="big")),"Emergency_Status":list[8].decode('utf-8'),"Back_Door":list[9].decode('utf-8'),"Front_Door":list[10].decode('utf-8'),"Toilette":list[11].decode('utf-8'),"Timestamp":str(datetime.datetime.now())}}

    return jsonfile
def sendMessage(list):
    for x in list:
        s.write(x)
def getIdPic(list):
    return int(list[3])
def getIdVagone(idPic):
    print('sono dentro la funzione che cicla sul dizionario finche non trova lid corrispondente e ritorna lid del vagone')
def Addresser(list,countId):
    if(list[1]==bytes(b'\xff'))and(list[2]==bytes(b'\x00')):  #Richiesta di indirizzamento  (list[0]==myId.to_bytes(1,'big'))and
            sendAddress.append(broadcastCode.to_bytes(1,'big'))
            sendAddress.append(myId.to_bytes(1,'big'))
            sendAddress.append(handshakeCode.to_bytes(1,'big'))
            sendAddress.append(countId.to_bytes(1,'big'))
            sendAddress.append(b'\xf0')
            sendAddress.append(b'\x60')
            sendMessage(sendAddress)
            print(sendAddress)
def sendTelemetry(list):
    print('sono dentro telemetria')
    idPic=list[1]
    idVagone=1       #getIdVagone(idPic)
    listTelemetry=[]
    listTelemetry.append(idPic)
    listTelemetry.append(idVagone)
    listTelemetry.append(list[3])
    listTelemetry.append(list[4])
    listTelemetry.append(list[5])
    listTelemetry.append(list[6])
    listTelemetry.append(list[7])
    listTelemetry.append(list[8])
    #print(type(list[9]))
    if  (int.from_bytes(list[9], byteorder="big") & 8) == 0:            
        listTelemetry.append(b"\x00")
    else:
        listTelemetry.append(b"\x01")
    if (int.from_bytes(list[9], byteorder="big") & 4)==0:
        listTelemetry.append(b"\x00")
    else:
        listTelemetry.append(b"\x01")
    if (int.from_bytes(list[9], byteorder="big") & 2)==0:
        listTelemetry.append(b"\x00")
    else:
        listTelemetry.append(b"\x01")
    if (int.from_bytes(list[9], byteorder="big") & 1)==0:
        listTelemetry.append(b'\x00')
    else:
        listTelemetry.append(b"\x01")

    #DA QUA FARE I CONTROLLI SU CHE DATO ARRIVA PER FARE IN MODO DI SAPERE CHE DATO MANDO E CON CHE VALORE byte 3 e 4 la temperatura, byte 5 e 6 la umidità, byte di controllo di check subito dopo
    
    print('ho finito la scrittura su coda')
    print(listTelemetry)
    jsonTelemetry=create_Json(listTelemetry)
    print(jsonTelemetry)
    send_to_queue(jsonTelemetry)




countId=1
zero=0
handshakeCode=1
broadcastCode=255
s=serial.Serial(port='COM8',baudrate=115200, bytesize=8, parity='N', stopbits=1)
lista=[]
ncycles=10
myId=0
sendAddress=[]
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
        if(lista[0]==myId.to_bytes(1,'big')):
            #crcList=crc_calc(lista)
            if len(lista)==5:
                Addresser(lista,countId)
                countId+=1
        
            if len(lista)>5:
                sendTelemetry(lista)
        # if(lista[2]==bytes(b'\x20'))and(lista[3]):
        #     Temperature(lista)
    
        # if(lista[2]==bytes(b'\x20'))and(lista[5]):
        #     Humidity(lista)

            # sendAddress=[]
            
    # sendMessage(lista)
    lista=[]

    

