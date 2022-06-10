[< Home](../README.md)

[<p align="right">Cloud ></p>](../Cloud/README.md)

**<h1 align="center">MQTT Specification</h1>**

## **Pub Sub structure**

<div  align="center">
<table>
<thead>

<tr>
<th align="center"></th>
<th align="center">RaspberryPI</th>
<th align="center">Cloud</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">Telemetry</td>
<td align="center"><a href="#telemetry">lovelyCommit/idTrain/wagon/telemetry</a></td>
<td align="center"></td>
</tr>

<tr>
<td align="center">commands</td>
<td align="center"></td>
<td align="center"><a href="#comand">lovelyCommit/idTrain/wagon/cmd</a></td>
</tr>

<tr>
<td align="center">Text message</td>
<td align="center"></td>
<td align="center"><a href="#message">lovelyCommit/idTrain/wagon/msg</a></td>
</tr>

<tr>
<td align="center">Emergency</td>
<td align="center"><a href="#emergency">lovelyCommit/idTrain/wagon/emergency</a></td>
<td align="center"><a href="#emergency">lovelyCommit/idTrain/wagon/emergency</a></td>
</tr>

</tbody>
</table>
</div>

### **Telemetry**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Topic</th>
<th align="center">Message Structure</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">tempHum</td>
<td>

    {
        'Temperature': Decimal value,
        'Humidity': Decimal value
    }

</td>
</tr>

<tr>
<td align="center">door</td>
<td>

    {
        'FrontDoor': Bool value,
        'BackDoor': Bool value
    }

</td>
</tr>

<tr>
<td align="center">toilette</td>
<td>

    {
        'Status': Bool value
    }

</td>
</tr>

</tbody>
</table>
</div>

### **Comand**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Topic</th>
<th align="center">Message Structure</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">targetTemp</td>
<td>

    {
        'TargetTemperature': Decimal value
    }

</td>
</tr>

<tr>
<td align="center">toggleFrontDoor</td>
<td align="center">
anything
</td>
</tr>

<tr>
<td align="center">toggleBackDoor</td>
<td align="center">
anything
</td>
</tr>

</tbody>
</table>
</div>

### **Message**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Topic</th>
<th align="center">Message Structure</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center"></td>
<td>

    {
        'TextMessage': String value
    }

</td>
</tr>

</tbody>
</table>
</div>

### **Emergency**

<div  align="center">
<table>
<thead>

<tr>
<th align="center">Topic</th>
<th align="center">Message Structure</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">Set</td>
<td>

    {
        'EmergencyMessage': String value
        'Sender': IdSender
    }

</td>
</tr>

<tr>
<td align="center">Reset</td>
<td align="center">anything</td>
</tr>

<tr>
<td align="center">Status</td>
<td>

    {
        'EmergencyStatus': Bool value
    }

</td>
</tr>

</tbody>
</table>
</div>

##### **IdSender**


<div  align="center">
<table>
<thead>

<tr>
<th align="center">Component</th>
<th align="center">Id</th>
</tr>

</thead>
<tbody>

<tr>
<td align="center">Cloud</td>
<td  align="center">-1</td>
</tr>

<tr>
<td align="center">RPI</td>
<td align="center">0</td>
</tr>

<tr>
<td align="center">PIC</td>
<td align="center">1-254</td>
</tr>

</tbody>
</table>
</div>
