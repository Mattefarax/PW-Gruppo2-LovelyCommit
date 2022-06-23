[< Home](../README.md)

[<p align="right">Cloud ></p>](../Cloud/README.md)

**<h1 align="center">MQTT Specification</h1>**

<div align="center">  
<h4>
    <a href="#pub-sub-structure"> Pub Sub structure </a>
  | <a href="#idsender"> IdSender </a>
</h4>
</div>

## **Pub Sub structure**

For the topic structure we decided to have in all of them a **common base** composed of the name of the company and the id of the train.

From there we added the wagon id or the word "all" to discriminate wether the commands or the text messages will be recived from a determinated wagon or to all of them.   
The telemetry is specific bounded to the wagon so there is no way to not have it on the topic.   
The emrgency dont have any wagon specification on the topic but the status has it inside the message.

Then we have the specification on what the message is devided in telemetry, cmd, msg and emergency.

Here you can find some links to fastly travel in the documentatione:

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
<td align="center"><a href="#command">lovelyCommit/idTrain/wagon/cmd</br>or</br>lovelyCommit/idTrain/all/cmd</a></td>
</tr>

<tr>
<td align="center">Text message</td>
<td align="center"></td>
<td align="center"><a href="#message">lovelyCommit/idTrain/wagon/msg</br>or</br>lovelyCommit/idTrain/all/msg</a></td>
</tr>

<tr>
<td align="center">Emergency</td>
<td align="center"><a href="#emergency">lovelyCommit/idTrain/emergency</a></td>
<td align="center"><a href="#emergency">lovelyCommit/idTrain/emergency</a></td>
</tr>

</tbody>
</table>
</div>

### **Telemetry**

To have a better flexibility for future requests from the client we decided to split the topics in per macro-argument.

Bounding together telemetry values and the relative Timestamps we have the chance to keep trace of all alteration.

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
        'Timestamp': String value,
        'Current Temperature': Decimal value,
        'Set Temperature': Decimal value,
        'Current Humidity': Decimal value
    }

</td>
</tr>

<tr>
<td align="center">door</td>
<td>

    {
        'Timestamp': String value,
        'FrontDoor': Bool value,
        'BackDoor': Bool value
    }

</td>
</tr>

<tr>
<td align="center">toilette</td>
<td>

    {
        'Timestamp': String value,
        'Status': Bool value
    }

</td>
</tr>

</tbody>
</table>
</div>

### **Command**

Like for the telemetry, the command's topic are splitted, so we decided to put every command in a dedicated topic to keep values apart inside arguments.

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

The message is sent in a topic that can be directed to all uC or to a specific one depending on the topic's wagon.

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

For the Emergency we opted to allow to only set remotely, the reset is allowed only from the RPI interface for security reason.

To keep the base topic identical among the Emergency's topics, we decided to put the wagon's id inside the message of the Status topic together with the Timestamp.

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
        'Timestamp': String value,
        'EmergencyMessage': String value,
        'Sender': IdSender
    }

</td>
</tr>

<tr>
<td align="center">Status</td>
<td>

    {
        'Timestamp': String value,
        'Sender': IdSender,
        'EmergencyStatus': Bool value
    }

</td>
</tr>

</tbody>
</table>
</div>

## **IdSender**

The Id sender here rappresented is used in the set topic of the emergency to indicate who sent it and in the status topic of the emergency to show whose belonging the status.

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
