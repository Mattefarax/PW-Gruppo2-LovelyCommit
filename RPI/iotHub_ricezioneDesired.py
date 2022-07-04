import os
import asyncio
import random
from azure.iot.device.aio import IoTHubDeviceClient
from send import send_to_queue 

# async def main():
#     os.environ["IOTHUB_DEVICE_CONNECTION_STRING"] = "HostName=Scapolan.azure-devices.net;DeviceId=rpiPW2Ciccia;SharedAccessKey=GSu0yw1qe+KtYilo4b9O44fW/c+Qs1Mukf89zKzmx9s="

#     conn_str = os.getenv("IOTHUB_DEVICE_CONNECTION_STRING")
#     # The client object is used to interact with your Azure IoT hub.
#     device_client = IoTHubDeviceClient.create_from_connection_string(conn_str)

#     # connect the client.
#     await device_client.connect()

#     # define behavior for receiving a twin patch
#     # NOTE: this could be a function or a coroutine
#     def twin_patch_handler(patch):
#         print("the data in the desired properties patch was: {}".format(patch))

#     # set the twin patch handler on the client
#     device_client.on_twin_desired_properties_patch_received = twin_patch_handler


async def main():
    # The connection string for a device should never be stored in code. For the sake of simplicity we're using an environment variable here.
    os.environ["IOTHUB_DEVICE_CONNECTION_STRING"] = "HostName=Scapolan.azure-devices.net;DeviceId=rpiPW2Ciccia;SharedAccessKey=GSu0yw1qe+KtYilo4b9O44fW/c+Qs1Mukf89zKzmx9s="

    conn_str = os.getenv("IOTHUB_DEVICE_CONNECTION_STRING")
    # The client object is used to interact with your Azure IoT hub.
    device_client = IoTHubDeviceClient.create_from_connection_string(conn_str)

    # connect the client.
    await device_client.connect()

    # define behavior for receiving a twin patch
    # NOTE: this could be a function or a coroutine
    def twin_patch_handler(patch):
        print("the data in the desired properties patch was: {}".format(patch))
        send_to_queue(patch,'commandQueue')
        print("sent to queue")


    # set the twin patch handler on the client
    device_client.on_twin_desired_properties_patch_received = twin_patch_handler

    # define behavior for halting the application
    def stdin_listener():
        while True:
            selection = input("Press Q to quit\n")
            if selection == "Q" or selection == "q":
                print("Quitting...")
                break

    # Run the stdin listener in the event loop
    loop = asyncio.get_running_loop()
    user_finished = loop.run_in_executor(None, stdin_listener)

    # Wait for user to indicate they are done listening for messages
    await user_finished

    # Finally, shut down the client
    await device_client.shutdown()


if __name__ == "__main__":
    asyncio.run(main())

    # If using Python 3.6 use the following code instead of asyncio.run(main()):
    # loop = asyncio.get_event_loop()
    # loop.run_until_complete(main())
    # loop.close()