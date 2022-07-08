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
oldEmergencyResetTimestamp=""
zero=0
handshakeCode=1
broadcastCode=255
s=serial.Serial(port='COM8',baudrate=115200, bytesize=8, parity='N', stopbits=1)

ncycles=10
myId=0
payloademergencycode=19
resetEmergencycode=16
targetTemperaturecode=17
doorscode=18
sendAddress=[]

def send_to_pic(message):
    global oldEmergencyTimestamp
    global oldTelemetryTimestamp
    global oldEmergencyResetTimestamp
    emergencyList=[]
    commandTempList=[]
    commandDoorList=[]
    resetList=[]
    statusEmergencyList=[]
    emergencyList.append(broadcastCode.to_bytes(1,'big'))
    emergencyList.append(myId.to_bytes(1,'big'))
    emergencyList.append(payloademergencycode.to_bytes(1,'big'))
    emergencyTimestamp=""
    telemetryTimestamp=""
    print(type(message))
    strMessage=message.decode('utf-8')
    print(type(strMessage))
    print("Messaggio da mandare al Pic",strMessage)
    jsonMessage=json.loads(strMessage)
    idPic=jsonMessage["Comands"]["IdVagone"]
    emergencyTimestamp=jsonMessage["Emergency_Set"]["Timestamp"]
    emergencyResetTimestamp=jsonMessage["Emergency_Reset"]["Timestamp"]
    telemetryTimestamp=jsonMessage["Comands"]["Timestamp"]
    if(emergencyTimestamp!=oldEmergencyTimestamp):
        print("funzione di invio delle emergenze")
        strDecode=jsonMessage['Emergency_Set']['EmergencyMessage']
        print('cicciata',strDecode)
        print(type(strDecode))
        if(len(strDecode)<20):
            lenMessage=20-len(strDecode)
            while(lenMessage):
                strDecode=strDecode+' '
                lenMessage-=1

        print('nuova stringa',strDecode)
        for i in strDecode:
            emergencyList.append(bytes(i,'utf-8'))
        print(emergencyList)
        CRCList=crc_calc1(emergencyList)
        emergencyList.append(int(CRCList[1],16).to_bytes(1,'big'))
        emergencyList.append(int(CRCList[0],16).to_bytes(1,'big'))
        sleep(0.06)                   
        sendMessage(emergencyList)

        statusEmergencyList.append(int(idPic).to_bytes(1,'big'))
        statusEmergencyList.append(myId.to_bytes(1,'big'))
        statusEmergencyList.append(resetEmergencycode.to_bytes(1,'big'))
        statusEmergencyList.append(b'\x01')
        CRCSetList=[]
        CRCSetList=crc_calc1(statusEmergencyList)
        statusEmergencyList.append(int(CRCSetList[1],16).to_bytes(1,'big'))
        statusEmergencyList.append(int(CRCSetList[0],16).to_bytes(1,'big')) 

        sleep(0.06)                   
        sendMessage(statusEmergencyList)

        oldEmergencyTimestamp=emergencyTimestamp
    
    if(emergencyResetTimestamp!=oldEmergencyResetTimestamp):
        print("funzione invio reset emergenze")
        resetList.append(int(idPic).to_bytes(1,'big'))
        resetList.append(myId.to_bytes(1,'big'))
        resetList.append(resetEmergencycode.to_bytes(1,'big'))
        resetList.append(b'\x02')
        CRCResetList=crc_calc1(resetList)
        resetList.append(int(CRCResetList[1],16).to_bytes(1,'big'))
        resetList.append(int(CRCResetList[0],16).to_bytes(1,'big')) 
        sleep(0.06)  
        sendMessage(resetList)

        oldEmergencyResetTimestamp=emergencyResetTimestamp


    if(telemetryTimestamp!=oldTelemetryTimestamp):
        print("funzione di invio delle telemetrie")
        commandDoorList.append((int(idPic).to_bytes(1,'big')))
        commandTempList.append((int(idPic).to_bytes(1,'big')))
        commandTempList.append(myId.to_bytes(1,'big'))
        commandDoorList.append(myId.to_bytes(1,'big'))
        commandTempList.append(targetTemperaturecode.to_bytes(1,'big'))
        commandDoorList.append(doorscode.to_bytes(1,'big'))
        targetTemp=jsonMessage["Comands"]["Desired_Temperature"]
        backDoor=jsonMessage["Comands"]["Toggle_Back_Door"]
        frontDoor=jsonMessage["Comands"]["Toggle_Front_Door"]
        targetTempSplit=str(targetTemp).split(',')
        targetTempInt=int(targetTempSplit[0])
        targetTempDec=int(targetTempSplit[1])
        commandTempList.append(targetTempInt.to_bytes(1,'big'))
        commandTempList.append(targetTempDec.to_bytes(1,'big'))
        commandTempCRC=crc_calc1(commandTempList)
        commandTempList.append(int(commandTempCRC[1],16).to_bytes(1,'big'))
        commandTempList.append(int(commandTempCRC[0],16).to_bytes(1,'big'))
        print("messaggio desired temperature", commandTempList)
        sleep(0.06)
        sendMessage(commandTempList)

        if(backDoor==True and frontDoor==True):
            commandDoorList.append(b'\x03')
        if(backDoor==True and frontDoor==False):
            commandDoorList.append(b'\x02')
        if(backDoor==False and frontDoor==True):
            commandDoorList.append(b'\x01')
        commandDoorCRC=crc_calc1(commandDoorList)
        commandDoorList.append(int(commandDoorCRC[1],16).to_bytes(1,'big'))
        commandDoorList.append(int(commandDoorCRC[0],16).to_bytes(1,'big'))

        print("messaggio di invio delle porte",commandDoorList)
        sleep(0.06)
        sendMessage(commandDoorList)


        oldTelemetryTimestamp=telemetryTimestamp




def create_Json(list):
    print("bisogna creare un json con le informazioni salvate nella lista")
    jsonfile = {"Telemetry":{"idVagone":list[1],"Current_Temperature": str(int.from_bytes(list[2], byteorder="big"))+","+str(int.from_bytes(list[3], byteorder="big")),"Desired_Temperature":str(int.from_bytes(list[4], byteorder="big"))+","+str(int.from_bytes(list[5], byteorder="big")),"Humidity":str(int.from_bytes(list[6], byteorder="big"))+","+str(int.from_bytes(list[7], byteorder="big")),"Emergency_Status":list[8].decode('utf-8'),"Back_Door":list[9].decode('utf-8'),"Front_Door":list[10].decode('utf-8'),"Toilette":list[11].decode('utf-8'),"Timestamp":str(datetime.datetime.now())}}

    return jsonfile
def sendMessage(list):
    #sleep(2)
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