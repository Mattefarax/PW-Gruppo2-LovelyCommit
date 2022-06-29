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

4 collection

* users
  * username
  * password
  * train management permissions
  * creation date
  * last access
* trains
  * id train
  * number of wagons
  * date creation
  * date last update
* telemetries
  * id telemetry
  * id train
  * wagon number
  * current temperature
  * desired temperature
  * humidity
  * emergency status
  * back door
  * front door
  * toilette status
  * timestamp
* alarms
  * id train
  * sender
  * emergency message
  * creation date
  * closing date

## **MQTT** [*Deprecated*]

You will find more information [here](../MQTT/README.md).

## **IoT Hub**

You will find more information [here](../IoT_Hub/README.md)