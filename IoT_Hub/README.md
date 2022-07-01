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
{
    "deviceId": "rpiPW2Ciccia",
    "etag": "AAAAAAAAAAc=",
    "deviceEtag": "ODc1MTI5NzIx",
    "status": "enabled",
    "statusUpdateTime": "0001-01-01T00:00:00Z",
    "connectionState": "Disconnected",
    "lastActivityTime": "2022-07-01T08:08:10.019485Z",
    "cloudToDeviceMessageCount": 0,
    "authenticationType": "sas",
    "x509Thumbprint": {
        "primaryThumbprint": null,
        "secondaryThumbprint": null
    },
    "modelId": "",
    "version": 28,
    "properties": {
        "desired": {
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
            },
            "$metadata": {
                "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                "$lastUpdatedVersion": 7,
                "Comands": {
                    "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                    "$lastUpdatedVersion": 7,
                    "IdVagone": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "Desired_Temperature": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "Timestamp": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "Toggle_Back_Door": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "Toggle_Front_Door": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "Text_Message": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    }
                },
                "Emergency_Set": {
                    "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                    "$lastUpdatedVersion": 7,
                    "Timestamp": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    },
                    "EmergencyMessage": {
                        "$lastUpdated": "2022-07-01T08:51:16.9517118Z",
                        "$lastUpdatedVersion": 7
                    }
                }
            },
            "$version": 7
        },
        "reported": {
            "temperature": "null",
            "Telemetry": {
                "idVagone": 1,
                "Current_Temperature": "27,3",
                "Toilette": "\u0001",
                "Timestamp": "2022-07-01 10:51:08.085507",
                "Desired_Temperature": "28,5",
                "Emergency_Status": "\u0000",
                "Back_Door": "\u0000",
                "Front_Door": "\u0001",
                "Humidity": "30,5"
            },
            "Emergency": {
                "IdSender": 1,
                "CreationDate": "2022-06-29 15:16:28.042769",
                "EmergencyMessage": "Generic Error"
            },
            "$metadata": {
                "$lastUpdated": "2022-07-01T08:51:06.5992083Z",
                "temperature": {
                    "$lastUpdated": "2022-07-01T07:54:51.0925442Z"
                },
                "Telemetry": {
                    "$lastUpdated": "2022-07-01T08:51:06.5992083Z",
                    "idVagone": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Current_Temperature": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Toilette": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Timestamp": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Desired_Temperature": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Emergency_Status": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Back_Door": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Front_Door": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    },
                    "Humidity": {
                        "$lastUpdated": "2022-07-01T08:51:06.5992083Z"
                    }
                },
                "Emergency": {
                    "$lastUpdated": "2022-07-01T08:23:53.3451453Z",
                    "IdSender": {
                        "$lastUpdated": "2022-07-01T08:23:53.3451453Z"
                    },
                    "CreationDate": {
                        "$lastUpdated": "2022-07-01T08:23:53.3451453Z"
                    },
                    "EmergencyMessage": {
                        "$lastUpdated": "2022-07-01T08:23:53.3451453Z"
                    }
                }
            },
            "$version": 21
        }
    },
    "capabilities": {
        "iotEdge": false
    }
}
```