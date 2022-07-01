[< Home](../README.md)

[<p align="right">MQTT Specification [Deprecated] ></p>](../MQTT/README.md)

**<h1 align="center">RPI Programs Specification</h1>**

<div align="center">  
<h4>
    <a href="#quick-start"> Quick Start </a>
  | <a href="#protocol"> Protocol </a>
  | <a href="#mqtt-deprecated"> MQTT [Deprecated] </a>
  | <a href="#amqp"> AMQP </a>
  | <a href="#iot-hub"> IoT Hub </a>
  
</h4>
</div>

## **Quick Start**

To run the code on a reaspeberry py you need to install the following librarys:

<ul>
<li>
For connecting to the device on the Azure&#39;s IoT Hub you can find the documentation <a href="https://github.com/Azure/azure-iot-sdk-python">here</a>
<pre>
<code>pip <span class="hljs-keyword">install</span> azure-iot-device</code>
</pre>
The program that connect to the IoT Hub requires an environment variable, you can set it with the following comands:

<ul>
<li>
Windows comand
<pre>
<code class="lang-cmd"><span class="hljs-keyword">set</span> IOTHUB_DEVICE_CONNECTION_STRING=&lt;your connection string here&gt;</code>
</pre>
</li>

<li>
Linux comand
<pre>
<code class="lang-bash"><span class="hljs-keyword">export</span> IOTHUB_DEVICE_CONNECTION_STRING=<span class="hljs-string">"&lt;your connection string here&gt;"</span></code>
</pre>
</li>
</ul>

<li>
For connecting through serial to the uC you can find the documentation <a href="https://github.com/pyserial/pyserial">here</a>
<pre>
<code class="lang-cmd">pip <span class="hljs-keyword">install</span> pyserial</code>
</pre>
</li>

<li>
To host the AMQP queue manager on a docker compose you can issue the following comand:
<pre><code class="lang-bash">docker run -it --rm --name rabbitmq -<span class="hljs-selector-tag">p</span> <span class="hljs-number">5672</span>:<span class="hljs-number">5672</span> -<span class="hljs-selector-tag">p</span> <span class="hljs-number">15672</span>:<span class="hljs-number">15672</span> rabbitmq:<span class="hljs-number">3.10</span>-management
</code></pre>
</li>
</ul>

## **Protocol**

You will find more information [here](../Protocol/README.md).

## **AMQP**

We decided to implement AMQP in our project to benefit from it's queue system.   
Using this functionality we've been able to detach the serial receiver program from the IoT Hub's device code.   
Thanks to it we managed to create a micro-service alike structure inside the Raspberry.

We created a queue called "telemetryQueue" where travels a JSON formatted like this:

``` JSON
{
    "Telemetry":{
        "idVagone":1,
        "Current_Temperature":"27,3",
        "Desired_Temperature":"28,5",
        "Humidity":"30,5",
        "Emergency_Status":"\\u0000",
        "Back_Door":"\\u0000",
        "Front_Door":"\\u0001",
        "Toilette":"\\u0001",
        "Timestamp":"2022-06-29 15:16:28.042769"
    },
    "Emergency":{
        "IdSender":1,
        "CreationDate":"2022-06-29 15:16:28.042769",
        "EmergencyMessage":"Generic Error"
    }
}
```

Where travels the updates for the device twin configurations with the newly received telemetry.

We used also a queue called "commandQueue" where travels a JSON formatted like this:

``` JSON
{
    "Comands": {
        "IdVagone": 1,
        "Desired_Temperature": "28,5",
        "Timestamp": "2022-06-29 15:16:28.042769",
        "Toggle_Back_Door": false,
        "Toggle_Front_Door": false,
        "Text_Message": "Prova 1 2 3 Prova"
    },
    "Emergency_Set": {
        "Timestamp": "2022-06-29 15:16:28.042769",
        "EmergencyMessage": "Generic Error"
    }
}
```

Where travels the new comands comming from the desired section of the device twin configuration.

## **MQTT** [*Deprecated*]

You will find more information [here](../MQTT/README.md).

## **IoT Hub**

You will find more information [here](../IoT_Hub/README.md)