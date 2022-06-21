[< Home](./README.md)

[<p align="right">uController ></p>](./PIC/README.md)

<!--![Train gif](./Images/train.gif)-->
<p align="center"><img src="Images/train.gif" alt="Train gif" width="500" height="auto"/></p>

**<h1 align="center">PW-Gruppo2-LovelyCommit</h1>**

<p align="center">
    <a href="./LICENSE"><img src="https://img.shields.io/badge/License-GPLv3-blue.svg"></a>
</p>

<div align="center">  
<h4>
    <a href="#project-trace"> Project Trace </a>
  | <a href="#schemas"> Schemas </a>
  | <a href="#ucontroller"> uController</a>
  | <a href="#raspberrypi"> RaspberryPi </a>
  | <a href="#cloud"> Cloud </a>
  | <a href="#documents"> Documents </a>
</h4>
</div>
Project Work 2022 Group 2 Corso Diqu

<div  align="center">
<table>
<thead>

<tr>
<th style="text-align:center">Name</th>
<th style="text-align:center">E-mail</th>
</tr>

</thead>
<tbody>

<tr>
<td style="text-align:center">Faraoni Matteo</td>
<td style="text-align:center">matteo.faraoni@stud.tecnicosuperiorekennedy.it</td>
</tr>
    
<tr>
<td style="text-align:center">Gatto Alessandro</td>
<td style="text-align:center">alessandro.gatto@stud.tecnicosuperiorekennedy.it</td>
</tr>
    
<tr>
<td style="text-align:center">Pizzato Davide</td>
<td style="text-align:center">davide.pizzato@stud.tecnicosuperiorekennedy.it</td>
</tr>
   
<tr>
<td style="text-align:center">Scapolan Davide</td>
<td style="text-align:center">davide.scapolan@stud.tecnicosuperiorekennedy.it</td>
</tr>
    
</table>
</div>

## **Project Trace**

The **UAR**, Upper Adriatic Railroad, requires the creation of a system to monitor the status of the wagons and to be able to control their behavior both from a booth inside the train and remotely.
It was decided to implement an RS485 BUS system that connects each carriage, in which there is a custom uC card capable of detecting **temperature**, **humidity**, and **door closing status**, in addition to verifying if someone's in the **toilet** compartment.
In addition, the microcontroller can **independently control the air conditioning** for each wagon, the **opening of the doors** and the **emergency signals**. An LCD display is also required for each wagon, it must be capable of displaying messages sent by the remote controller, reading the sensors and modifying the operating parameters.

All this information then is sent and received with a proprietary protocol by an RPI that acts as a Gateway connected to a network with internet access, then it will publish it. Publishing it will allow a remote operator to check the status and possibly modify the states of the actuators.
An information queue must also be provided if the connection with the cloud fails while crossing tunnels.

Additional features may be proposed by individual groups.

## **Schemas**

`To be able to view any .drowio file open [this link](https://draw.io), than open the file from the repository`

<table>
    
<tr>
<td style="text-align:center" valign="center">
<img src="./Images/FlowSchema.jpg " 
alt="Flow Schema"
width="400" 
height="auto" />
</td>

<td style="text-align:center" valign="center">
<img src="./Images/StructureSchema.jpg " 
alt="Structure Schema"
width="400" 
height="auto" />
</td>
</tr>
    
</table>

## **uController**

### **Hardware component**

*Elements on the list supplied*:

* GY-BME280 barometric sensor for temperature, humidity and air pressure

* Motion sensor HC-SR501 PIR motion detection module  
 `Used for automatic presence detection in bathrooms` 

*External element*:

* 20 microswitches with debouncing pullup components  
 `Used for open/closed detection of all the doors in the wagon`

* led 3.3V

*Already in our possession*:

* 4 2004 LCD Display

* 2 servomotor

* 4 rotary encoder

### **Protocol PIC-RPI Structure**

<div  align="center">
<table>
<thead>

<tr>
<th style="text-align:center"></th>
<th style="text-align:center">PIC</th>
<th style="text-align:center">RaspberryPI</th>
</tr>

</thead>
<tbody>

<tr>
<td style="text-align:center">Telemetry</td>
<td style="text-align:center">id(RPI)_Payload_CRC</td>
<td style="text-align:center"></td>
</tr>

<tr>
<td style="text-align:center">Commands</td>
<td style="text-align:center"></td>
<td style="text-align:center">id(PIC/Broadcast)_Payload_CRC</td>
</tr>

<tr>
<td style="text-align:center">Text message</td>
<td style="text-align:center"></td>
<td style="text-align:center">id(PIC/Broadcast)_Payload_CRC</td>
</tr>

<tr>
<td style="text-align:center">Handshake</td>
<td style="text-align:center">id(RPI)_Payload_CRC</td>
<td style="text-align:center">id(RPI)_Payload_CRC</td>
</tr>

</tbody>
</table>
</div>

[Here](./Protocol/README.md) you can finde more specification about how does this protocl works and wor does it has been developped

## **RaspberryPi**

### **AMQP RPI**

### **Mqtt RPI-Azure**

## **Cloud**

## **Documents**

* [uController section](./PIC/)
* [Protocol section](./Protocol/)
* [RaspberryPi section](./RPI/)
* [MQTT section](./MQTT/)
* [Cloud section](./Cloud/)

## **LICENSE**

LovelyCommit is provided under the [GNU General Public License Version 3](./LICENSE)
