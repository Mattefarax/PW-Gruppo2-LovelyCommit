from ast import Bytes
from doctest import ELLIPSIS_MARKER
import json
from logging import raiseExceptions
from multiprocessing.reduction import send_handle
import random
from ssl import MemoryBIO
from time import sleep
from unicodedata import numeric
from psycopg2 import Timestamp
import serial
from send import send_to_queue
import datetime
from protoCRC import crc_calc,crc_calc1
import pika




countId=1

oldEmergencyTimestamp=""
oldTelemetryTimestamp=""
zero=0
handshakeCode=1
broadcastCode=255
s=serial.Serial(port='COM8',baudrate=115200, bytesize=8, parity='N', stopbits=1)

ncycles=10
myId=0
emergencycode=19
sendAddress=[]

def send_to_pic(message):
    global oldEmergencyTimestamp
    global oldTelemetryTimestamp
    emergencyList=[]
    comandsList=[]
    emergencyList.append(broadcastCode.to_bytes(1,'big'))
    emergencyList.append(myId.to_bytes(1,'big'))
    emergencyList.append(emergencycode.to_bytes(1,'big'))
    emergencyTimestamp=""
    telemetryTimestamp=""
    print(type(message))
    strMessage=message.decode('utf-8')
    print(type(strMessage))
    print("Messaggio da mandare al Pic",strMessage)
    jsonMessage=json.loads(strMessage)
    emergencyTimestamp=jsonMessage["Emergency_Set"]["Timestamp"]
    telemetryTimestamp=jsonMessage["Comands"]["Timestamp"]
    if(emergencyTimestamp!=oldEmergencyTimestamp):
        print("funzione di invio delle emergenze")
        strCiccia=jsonMessage['Emergency_Set']['EmergencyMessage']
        print('cicciata',strCiccia)
        print(type(strCiccia))
        if(len(strCiccia)<20):
            ciccia=20-len(strCiccia)
            while(ciccia):
                strCiccia=strCiccia+' '
                ciccia-=1

        print('nuova stringa',strCiccia)
        for i in strCiccia:
            emergencyList.append(bytes(i,'utf-8'))
        print(emergencyList)
        CRCList=crc_calc1(emergencyList)
        emergencyList.append(int(CRCList[1],16).to_bytes(1,'big'))
        emergencyList.append(int(CRCList[0],16).to_bytes(1,'big'))                   
        sendMessage(emergencyList)
        print("Ciccia ultrapasticciata",emergencyList)
        oldEmergencyTimestamp=emergencyTimestamp
    if(telemetryTimestamp!=oldTelemetryTimestamp):
        print("funzione di invio delle telemetrie")
        oldTelemetryTimestamp=telemetryTimestamp




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
            sendAddress.clear()
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
    send_to_queue(jsonTelemetry,'telemetryQueue')
    listTelemetry.clear()


def serial_to_amqp():
    while(1):
        lista=[]
        global countId
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
                crcList=crc_calc(lista)
                if(crcList==0):             #[0]==lista[len(lista)-1]) and (crcList[1]==lista[len(lista)])):
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
        lista.clear()
        break

def amqp_to_serial():
    # connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
    # channel = connection.channel()
    connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
    channel = connection.channel()

    channel.queue_declare(queue='commandQueue')
    method_frame, header_frame, body = channel.basic_get(queue='commandQueue',auto_ack=True)
    if method_frame:
          send_to_pic(body)
    connection.close()

while 1:
    serial_to_amqp()
    amqp_to_serial()