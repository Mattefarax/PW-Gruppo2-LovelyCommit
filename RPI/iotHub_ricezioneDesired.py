import os
import asyncio
import random
from azure.iot.device.aio import IoTHubDeviceClient

async def main():
    os.environ["IOTHUB_DEVICE_CONNECTION_STRING"] = "HostName=LovelyCommitIotHub.azure-devices.net;DeviceId=Rpi-train1;SharedAccessKey=dcvdrkfRKc1r5RaD/f4k+2EqUE8Kow8YA1Mynzqi8oU="

    conn_str = os.getenv("IOTHUB_DEVICE_CONNECTION_STRING")
    # The client object is used to interact with your Azure IoT hub.
    device_client = IoTHubDeviceClient.create_from_connection_string(conn_str)

    # connect the client.
    await device_client.connect()

    # define behavior for receiving a twin patch
    # NOTE: this could be a function or a coroutine
    def twin_patch_handler(patch):
        print("the data in the desired properties patch was: {}".format(patch))

    # set the twin patch handler on the client
    device_client.on_twin_desired_properties_patch_received = twin_patch_handler