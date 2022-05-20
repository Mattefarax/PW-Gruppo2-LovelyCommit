# PW-Gruppo2-LovelyCommit
Project Work 2022 Group 2 Corso Diqu
Faraoni Matteo, Gatto Alessandro, Pizzato Davide, Scapolan Davide

To be able to view any .drowio file open [this](https://draw.io), than open the file from the repository

|![Flow schema of the system](./Images/FlowSchema.jpg)|
|-|

## Protocol PIC-RPI Structure
***
|- |PIC|RaspberryPI|
|:-------------:|:-------------:|:-----:|
|Data sent from PIC to a RPI|id(RPI)_Payload()_CRC|id(PIC)_OK_CRC|
|Data sent from RPI to a PIC|id(RPI)_OK_CRC|id(PIC/Broadcast)_Payload_CRC|
|Handashake between PIC and RPI|id(RPI)_handshakeCode_CRC|id(RPI)_newId(PIC)_CRC|

#### Payload Telemetry
The payloads will be sent in this (static) order: 
|1° and 2° Byte|3° and 4° Byte|5° Byte 3° bit|5° Byte 2° bit|5° Byte 1° bit|
|:---:|:---:|:---:|:---:|:---:|
|Temperature|Humidity|Status back door|Status front door|Status bathroom|

#### Payload Commands
|1° e 2° Byte|3° Byte 2° bit|3° Byte 1° bit|4° Byte|5° to X° Byte|
|:---:|:---:|:---:|:---:|:---:|
|Target temperature|Status back door|Status front door|Length of the message (number of byte)|Message (if te Length is greater then 0)|

#### CRC Calc
Library?

## AMQP RPI
***

## Mqtt RPI-Azure
***