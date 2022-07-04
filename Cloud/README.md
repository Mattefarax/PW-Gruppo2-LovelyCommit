[< Home](../README.md)

[<p align="right">Cloud ></p>](./README.md)

**<h1 align="center">Cloud Programs Specification</h1>**

<div align="center">  
<h4>
    <a href="#back-end"> Back End </a>
  | <a href="#front-end"> Front End </a>
  | <a href="#db"> DB </a>
  | <a href="#mqtt-deprecated"> MQTT [Deprecated] </a>
  | <a href="#iot-hub"> IoT Hub </a>
  
</h4>
</div>

## **Back End**

## **Front End**

## **DB**

We decided to use a non-relational documental database for its flexibility: it will allow future implementation of different data.

We split datas in 4 collection where only 2 stores data sent from and to the train. The other 2 collections are purely organizational.

#### **Users**

<div align="center">
<table>
<thead>
<th align="center">username</th>
<th align="center">password</th>
<th align="center">train_management_permission</th>
<th align="center">creation_date</th>
<th align="center">last_access</th>
</thead>
<tbody>
<td align="center">ID</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tbody>
</table>
</div>

#### **Trains**

<div align="center">
<table>
<thead>
<th align="center">id_train</th>
<th align="center">number_of_wagons</th>
<th align="center">date_creation</th>
<th align="center">date_last_update</th>
</thead>
<tbody>
<td align="center">ID</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tbody>
</table>
</div>

#### **Telemetries**

<div align="center">
<table>
<thead>
<th align="center">id_telemetry</th>
<th align="center">id_train</th>
<th align="center">wagon_number</th>
<th align="center">current_temperature</th>
<th align="center">desired_temperature</th>
<th align="center">humidity</th>
<th align="center">emergency_status</th>
<th align="center">back_door</th>
<th align="center">front_door</th>
<th align="center">toilette_status</th>
<th align="center">timestamp</th>
</thead>
<tbody>
<td align="center">ID</td>
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
</tbody>
</table>
</div>

#### **Alarms**

<div align="center">
<table>
<thead>

<th align="center">id_alarm</th>
<th align="center">id_train</th>
<th align="center">sender</th>
<th align="center">emergency_message</th>
<th align="center">creation_date</th>
<th align="center">closing_date</th>
</thead>
<tbody>
<td align="center">ID</td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
<td align="center"></td>
</tbody>
</table>
</div>

## **MQTT** [*Deprecated*]

You will find more information [here](../MQTT/README.md).

## **IoT Hub**

You will find more information [here](../IoT_Hub/README.md)
