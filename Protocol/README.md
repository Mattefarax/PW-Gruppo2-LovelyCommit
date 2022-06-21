[< Home](../README.md)

[<p align="right">Raspberry Pi ></p>](../RPI/README.md)

**<h1 align="center">Protocol Specification</h1>**

## **Addressing**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Id Reciver</th>
<th align="center">Id Sender</th>
<th align="center">Payload</th>
<th align="center">CRC</th>
</tr>

</thead>
</table>
</div>

## **Addresses**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Device</th>
<th align="center">Id Given</th>
<th align="center">Id Available</th>
</tr>

</thead>

<tbody>

<tr>
<td align="center">RPI</td>
<td align="center">00</td>
<td align="center"></td>
</tr>

<tr>
<td align="center">PIC</td>
<td align="center"></td>
<td align="center">01-fe</td>
</tr>

<tr>
<td align="center">broadcast</td>
<td align="center">ff</td>
<td align="center"></td>
</tr>

</tbody>
</table>
</div>

## **Transmission Code**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Message Type</th>
<th align="center">Code</th>
<th align="center">Sender</th>
</tr>

</thead>

<tbody>

<tr>
<td align="center">Telemetry</td>
<td align="center">20</td>
<td align="center">PIC</td>
</tr>

<tr>
<td align="center">Comands</td>
<td align="center">10</td>
<td align="center">RPI</td>
</tr>

<tr>
<td align="center">Text</td>
<td align="center">11</td>
<td align="center">RPI</td>
</tr>

<tr>
<td align="center">Handshake Request</td>
<td align="center">00</td>
<td align="center">broadcast(PIC before </br> having any id assigned)</td>
</tr>

<tr>
<td align="center">Handshake Response</td>
<td align="center">01</td>
<td align="center">RPI</td>
</tr>

</tbody>
</table>
</div>

## **Protocol Summary**

<div  align="center">
<table>
<thead>

<tr>
<th align="center"></th>
<th align="center">PIC</th>
<th align="center">RaspberryPI</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">Telemetry</td>
<td align="center"><a href='#payload-telemetry'>More here</a></td>
<td align="center"></td>
</tr>

<tr>
<td align="center">Commands</td>
<td align="center"></td>
<td align="center"><a href='#payload-commands'>More here</a></td>
</tr>

<tr>
<td align="center">Text message</td>
<td align="center"></td>
<td align="center"><a href='#payload-text-message'>More here</a></td>
</tr>

<tr>
<td align="center">Handshake</td>
<td align="center"><a href='#handshake-request'>More here (request)</a></td>
<td align="center"><a href='#handshake-response'>More here (response)</a></td>
</tr>

</tbody>
</table>
</div>

#### **Payload Telemetry**

The payloads will be sent in this (static) order:

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th align="center">4° Byte</th>
<th align="center">5° Byte</th>
<th align="center">6° Byte</th>
<th align="center">7° Byte</th>
<th colspan="4" align="center">8° Byte</th>
<th align="center">9° Byte</th>
<th align="center">10° Byte</th>
</tr>

<tr>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center">4° bit</th>
<th align="center">3° bit</th>
<th align="center">2° bit</th>
<th align="center">1° bit</th>
<th align="center"></th>
<th align="center"></th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(RPI)</td>
<td align="center">id(PIC)</td>
<td align="center">code</td>
<td colspan="2" align="center">Temperature</td>
<td colspan="2" align="center">Humidity</td>
<td align="center">Emergency status</td>
<td align="center">Status back door</td>
<td align="center">Status front door</td>
<td align="center">Status toilette</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center">00</td>
<td align="center"></td>
<td align="center">20</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
</div>

#### **Payload Commands**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th colspan="2" align="center">4° Byte</th>
<th align="center">5° Byte</th>
<th align="center">6° Byte</th>
</tr>

<tr>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center">2° bit</th>
<th align="center">1° bit</th>
<th align="center"></th>
<th align="center"></th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(PIC)</td>
<td align="center">id(RPI)</td>
<td align="center">code</td>
<td align="center">Emergency reset</td>
<td align="center">Emergency set</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center"></td>
<td align="center">00</td>
<td align="center">10</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
<!--=========================================-->
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th align="center">4° Byte</th>
<th align="center">5° Byte</th>
<th align="center">6° Byte</th>
<th align="center">7° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(PIC)</td>
<td align="center">id(RPI)</td>
<td align="center">code</td>
<td colspan="2" align="center">Target temperature</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center"></td>
<td align="center">00</td>
<td align="center">11</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
<!--=========================================-->
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th colspan="2" align="center">4° Byte</th>
<th align="center">5° Byte</th>
<th align="center">6° Byte</th>
</tr>

<tr>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center">2° bit</th>
<th align="center">1° bit</th>
<th align="center"></th>
<th align="center"></th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(PIC)</td>
<td align="center">id(RPI)</td>
<td align="center">code</td>
<td align="center">Toggle back door</td>
<td align="center">Toggle front door</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center"></td>
<td align="center">00</td>
<td align="center">12</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
</div>

#### **Text Message**

To send the text message we decided to send 20 comands formatted in the following manner:

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th align="center">4°-23° Byte</th>
<th align="center">24° Byte</th>
<th align="center">25° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(PIC)</td>
<td align="center">id(RPI)</td>
<td align="center">code</td>
<td align="center">Character</td>
<td  colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center"></td>
<td align="center">00</td>
<td align="center">11</td>
<td align="center"></td>
<td colspan="2" align="center"></td>
</tr>

</tbody>
</table>
</div>

Every comand contains a single character that will be added to the buffer of the message in the uC . When the buffer for the 20 character is full and is sent a new character the buffer will be wyped and repopulated with the next 20 character.

#### **Handshake Request**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th align="center">4° Byte</th>
<th align="center">5° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(RPI)</td>
<td align="center">id(broadcast)</td>
<td align="center">code</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center">00</td>
<td align="center">ff</td>
<td align="center">00</td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
</div>

#### **Handshake Response**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
<th align="center">4° Byte</th>
<th align="center">5° Byte</th>
<th align="center">6° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(broadcast)</td>
<td align="center">id(RPI)</td>
<td align="center">code</td>
<td align="center">new id(PIC)</td>
<td colspan="2" align="center">CRC</td>
</tr>

<tr>
<td align="center">ff</td>
<td align="center">00</td>
<td align="center">01</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tr>

</tbody>
</table>
</div>

#### **CRC Calc**

Library?
