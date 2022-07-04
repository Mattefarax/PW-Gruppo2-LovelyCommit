import asyncio
import random
import pika, sys, os
from paho.mqtt.client import Client
import json
from iotHub_invioReported import asyncall, main as sender

from sqlalchemy import null

import tracemalloc
from azure.iot.device.aio import IoTHubDeviceClient
tracemalloc.start()
jsonMessage=""


connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')


def callback(channel, method_frame, header_frame,body): 
    print(" [x] Received %r" %body)

    print("Successfully passed to IotHub sender "%body)
    global jsonMessage
    jsonMessage=body
    print("jsonMessage dentro callback {}", jsonMessage)

    
    asyncio.run(send())


channel.basic_consume(queue='hello', on_message_callback=callback, auto_ack=True)

async def send():
    global jsonMessage
    os.environ["IOTHUB_DEVICE_CONNECTION_STRING"] ="HostName=Scapolan.azure-devices.net;DeviceId=rpiPW2Ciccia;SharedAccessKey=GSu0yw1qe+KtYilo4b9O44fW/c+Qs1Mukf89zKzmx9s="
             #"HostName=LovelyCommitIotHub.azure-devices.net;DeviceId=Rpi-train1;SharedAccessKey=dcvdrkfRKc1r5RaD/f4k+2EqUE8Kow8YA1Mynzqi8oU="

    conn_str = os.getenv("IOTHUB_DEVICE_CONNECTION_STRING")
    device_client = IoTHubDeviceClient.create_from_connection_string("HostName=Scapolan.azure-devices.net;DeviceId=rpiPW2Ciccia;SharedAccessKey=GSu0yw1qe+KtYilo4b9O44fW/c+Qs1Mukf89zKzmx9s=")#conn_str)
    # connect the client.
    await device_client.connect()

    property = json.loads(jsonMessage)
    await device_client.patch_twin_reported_properties(property)

    # Finally, shut down the client
    await device_client.shutdown()
    print("succesfully")

channel.start_consuming()