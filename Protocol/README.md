[< Home](../README.md)

<p align="right">Protocol ></p>

<h1 style="font-weight: bold; text-align:center">Protocol Specification</h1>

## **Message Exchange**

<table style='margin:0 auto'>
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
<td style="text-align:center">id(RPI)_<a href='#payload-telemetry'>Payload</a>_CRC</td>
<td style="text-align:center"></td>
</tr>

<tr>
<td style="text-align:center">Commands</td>
<td style="text-align:center"></td>
<td style="text-align:center">id(PIC/Broadcast)_<a href='#payload-commands'>Payload</a>_CRC</td>
</tr>

<tr>
<td style="text-align:center">Text message</td>
<td style="text-align:center"></td>
<td style="text-align:center">id(PIC/Broadcast)_<a href='#text-message'>Payload</a>_CRC</td>
</tr>

<tr>
<td style="text-align:center">Handshake</td>
<td style="text-align:center">id(RPI)_<a href='#handshake-request'>Payload</a>_CRC</td>
<td style="text-align:center">id(RPI)_<a href='#address-response'>Payload</a>_CRC</td>
</tr>

</tbody>
</table>

#### **Payload Telemetry**

The payloads will be sent in this (static) order: 
<table  style='margin:0 auto'>
<thead>

<tr>
<th style="text-align:center">1° Byte</th>
<th style="text-align:center">2° Byte</th>
<th style="text-align:center">3° Byte</th>
<th style="text-align:center">4° Byte</th>
<th style="text-align:center">5° Byte</th>
<th style="text-align:center">6° Byte</th>
<th colspan="3"style="text-align:center">7° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center">3° bit</th>
<th style="text-align:center">2° bit</th>
<th style="text-align:center">1° bit</th>
</tr>

<tr>
<td style="text-align:center">id(PIC)</td>
<td style="text-align:center">20</td>
<td colspan="2"style="text-align:center">Temperature</td>
<td colspan="2"style="text-align:center">Humidity</td>
<td style="text-align:center">Status back door</td>
<td style="text-align:center">Status front door</td>
<td style="text-align:center">Status bathroom</td>
</tr>
</tbody>
</table>

#### **Handshake Request**

<table  style='margin:0 auto'>
<thead>

<tr>
<th style="text-align:center">1° Byte</th>
<th style="text-align:center">2° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td style="text-align:center">255</td>
<td style="text-align:center">00</td>
</tr>

</tbody>
</table>

#### **Payload Commands**

<table  style='margin:0 auto'>
<thead>

<tr>
<th style="text-align:center">1° Byte</th>
<th style="text-align:center">2° Byte</th>
<th style="text-align:center">3° Byte</th>
<th style="text-align:center">4° Byte</th>
<th colspan="2" style="text-align:center">5° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center"></th>
<th style="text-align:center">2° bit</th>
<th style="text-align:center">1° bit</th>
</tr>

<tr>
<td style="text-align:center">id(RPI)</th>
<td style="text-align:center">10</th>
<td colspan="2" style="text-align:center">Target temperature</td>
<td style="text-align:center">Toggle back door</td>
<td style="text-align:center">Toggle front door</td>
</tr>

</tbody>
</table>

#### **Text Message**

<table  style='margin:0 auto'>
<thead>

<tr>
<th style="text-align:center">1° Byte</th>
<th style="text-align:center">2° Byte</th>
<th style="text-align:center">3° Byte - 22° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td style="text-align:center">id(RPI)</th>
<td style="text-align:center">11</th>
<td style="text-align:center">Text Message</td>
</tr>

</tbody>
</table>

#### **Address Response**

<table  style='margin:0 auto'>
<thead>

<tr>
<th style="text-align:center">1° Byte</th>
<th style="text-align:center">2° Byte</th>
<th style="text-align:center">3° Byte</th>
</tr>

</thead>
<tbody>

<tr>
<td style="text-align:center">id(RPI)</th>
<td style="text-align:center">01</th>
<td colspan="2" style="text-align:center">new id(PIC)</td>
</tr>

</tbody>
</table>

#### **CRC Calc**

Library?
