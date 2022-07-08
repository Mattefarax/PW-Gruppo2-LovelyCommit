'use strict';

var config = require('./config.json');
var Registry = require('azure-iothub').Registry;
let model = require('./MongoDb/mongoClient');

var connectionString = config.connectionString;
var registry = Registry.fromConnectionString(connectionString);
var deviceName = 'Rpi-train1';

var LastTimestampTel = new Date();
var LastTimestampAlert = new Date();

var LastidVagone = 0;
var LastCurrent_Temperature = "0,00";
var LastToilette = "\u0000";
var LastDesired_Temperature = "0,00";
var LastEmergency_Status = "\u0000";
var LastBack_Door = "\u0000";
var LastFront_Door = "\u0000";
var LastHumidity = "0,00";

var LastIdSender = 0;
var LastEmergencyMessage = "";


var getTwinData = function () {

    registry.getTwin(deviceName, function (err, twin) {

        if (twin.properties.reported.Telemetry.Timestamp != LastTimestampTel) {
            if (err) {
                console.error('Could not query twins: ' + err.constructor.name + ': ' + err.message);
            } else {
                LastTimestampTel = twin.properties.reported.Telemetry.Timestamp;
                LastidVagone = twin.properties.reported.Telemetry.idVagone
                LastCurrent_Temperature = twin.properties.reported.Telemetry.Current_Temperature
                LastToilette = twin.properties.reported.Telemetry.Toilette
                LastDesired_Temperature = twin.properties.reported.Telemetry.Desired_Temperature
                LastEmergency_Status = twin.properties.reported.Telemetry.Emergency_Status
                LastBack_Door = twin.properties.reported.Telemetry.Back_Door
                LastFront_Door = twin.properties.reported.Telemetry.Front_Door
                LastHumidity = twin.properties.reported.Telemetry.Humidity
                console.log(twin.properties.reported.Telemetry)
                var jsonToInsert = {
                    "id_telemetry": 1,
                    "id_train": "IT12345",
                    "wagon_number": LastidVagone,
                    "current_temperature": LastCurrent_Temperature,
                    "desired_temperature": LastDesired_Temperature,
                    "humidity": LastHumidity,
                    "emergency_status": LastEmergency_Status,
                    "back_door": LastBack_Door,
                    "front_door": LastFront_Door,
                    "toilette_status": LastToilette,
                    "timestamp": LastTimestampTel
                }
            }
            model.insertTelemetry(jsonToInsert, (err, result) => {
                if (err) {
                    logger.error(err);
                } else if (result.affectedRows == 0) {
                    console.log("Data not found ");
                } else {
                    console.log("insertTelemetry request successful");
                }
            });

        }

        if (twin.properties.reported.Emergency.CreationDate != LastTimestampAlert) {
            if (err) {
                console.error('Could not query twins: ' + err.constructor.name + ': ' + err.message);
            } else {
                LastIdSender = twin.properties.reported.Emergency.IdSender
                LastTimestampAlert = twin.properties.reported.Emergency.CreationDate
                LastEmergencyMessage = twin.properties.reported.Emergency.EmergencyMessage
                console.log(twin.properties.reported.Emergency);
                var jsonToInsert = {
                    "id_alarm": 1,
                    "id_train": "IT12345",
                    "sender": LastIdSender,
                    "LastIdSender": LastEmergencyMessage,
                    "creation_date": creation_date
                }
                model.insertEmergency(jsonToInsert, (err, result) => {
                    if (err) {
                        logger.error(err);
                    } else if (result.affectedRows == 0) {
                        console.log("Data not found ");
                    } else {
                        console.log("insertEmergency request successful");
                    }
                });
            }
        }
    });
};
setInterval(getTwinData, 2000);