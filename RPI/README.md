[< Home](../README.md)

[<p align="right">MQTT Specification ></p>](../MQTT/README.md)

**<h1 align="center">RPI Programs Specification</h1>**

<div align="center">  
<h4>
    <a href="#quick-start"> Quick Start </a>
  | <a href="#protocol"> Protocol </a>
  | <a href="#amqp"> AMQP </a>
  | <a href="#mqtt"> MQTT </a>
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
</ul>

## **Protocol**

You will find more information [here](../Protocol/README.md).

## **AMQP**



## **MQTT**

You will find more information [here](../MQTT/README.md).
