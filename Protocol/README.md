[< Home](../README.md)

<p align="right">Protocol ></p>

**<h1 align="center">Protocol Specification</h1>**

## **Message Exchange**

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
<td align="center">id(RPI)_<a href='#payload-telemetry'>Payload</a>_CRC</td>
<td align="center"></td>
</tr>

<tr>
<td align="center">Commands</td>
<td align="center"></td>
<td align="center">id(PIC/Broadcast)_<a href='#payload-commands'>Payload</a>_CRC</td>
</tr>

<tr>
<td align="center">Text message</td>
<td align="center"></td>
<td align="center">id(PIC/Broadcast)_<a href='#text-message'>Payload</a>_CRC</td>
</tr>

<tr>
<td align="center">Handshake</td>
<td align="center">id(RPI)_<a href='#handshake-request'>Payload</a>_CRC</td>
<td align="center">id(RPI)_<a href='#address-response'>Payload</a>_CRC</td>
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
<th colspan="3"align="center">7° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center">3° bit</th>
<th align="center">2° bit</th>
<th align="center">1° bit</th>
</tr>

<tr>
<td align="center">id(PIC)</td>
<td align="center">20</td>
<td colspan="2"align="center">Temperature</td>
<td colspan="2"align="center">Humidity</td>
<td align="center">Status back door</td>
<td align="center">Status front door</td>
<td align="center">Status bathroom</td>
</tr>
</tbody>
</table>
</div>

#### **Handshake Request**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">255</td>
<td align="center">00</td>
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
<th align="center">4° Byte</th>
<th colspan="2" align="center">5° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center"></th>
<th align="center">2° bit</th>
<th align="center">1° bit</th>
</tr>

<tr>
<td align="center">id(RPI)</th>
<td align="center">10</th>
<td colspan="2" align="center">Target temperature</td>
<td align="center">Toggle back door</td>
<td align="center">Toggle front door</td>
</tr>

</tbody>
</table>
</div>

#### **Text Message**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte - 22° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(RPI)</th>
<td align="center">11</th>
<td align="center">Text Message</td>
</tr>

</tbody>
</table>
</div>

#### **Address Response**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">1° Byte</th>
<th align="center">2° Byte</th>
<th align="center">3° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">id(RPI)</th>
<td align="center">01</th>
<td colspan="2" align="center">new id(PIC)</td>
</tr>

</tbody>
</table>
</div>

#### **CRC Calc**

Library?
