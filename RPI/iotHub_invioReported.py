import os
import asyncio
import random
from azure.iot.device.aio import IoTHubDeviceClient


async def main():
    os.environ["IOTHUB_DEVICE_CONNECTION_STRING"] = "HostName=LovelyCommitIotHub.azure-devices.net;DeviceId=Rpi-train1;SharedAccessKey=dcvdrkfRKc1r5RaD/f4k+2EqUE8Kow8YA1Mynzqi8oU="

    conn_str = os.getenv("IOTHUB_DEVICE_CONNECTION_STRING")
    device_client = IoTHubDeviceClient.create_from_connection_string(conn_str)

    # connect the client.
    await device_client.connect()

    # update the reported properties
    reported_properties = {"temperature": random.randint(320, 800) / 10}
    print("Setting reported temperature to {}".format(reported_properties["temperature"]))
    await device_client.patch_twin_reported_properties(reported_properties)

    # Finally, shut down the client
    await device_client.shutdown()


if __name__ == "__main__":
    asyncio.run(main())