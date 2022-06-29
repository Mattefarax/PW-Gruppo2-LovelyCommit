[< Home](../README.md)

[<p align="right">Cloud ></p>](../Cloud/README.md)

**<h1 align="center">IoT Hub Specification</h1>**

<div align="center">  
<h4>
<a href="#why-iot-hub"> Why IoT Hub </a>
| <a href="#device-twin"> Device Twin </a>
</h4>
</div>

## **Why IoT Hub**

We decide to switch from MQTT to the Azure's IoT Hub beacuse it would be easier to manage comand's and telemtry.   
Also the management of all the devices that would have requires a differnet topic in each train would have created a big mess.

## **Device Twin**

Every train will have it's own twin configuration where you'll find wevry telemetry values sent from every wagon, you can find more information on the telemetry sent from uCs that controls the wagons [here](../Protocol/README.md#payload-telemetry)

#### **Configuration Structure**

``` JSON

```