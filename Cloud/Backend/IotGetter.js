'use strict';

var config = require('./config.json');
var Registry = require('azure-iothub').Registry;

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
            }
        }
        if (twin.properties.reported.Emergency.CreationDate != LastTimestampAlert) {
            if (err) {
                console.error('Could not query twins: ' + err.constructor.name + ': ' + err.message);
            } else {
            LastIdSender = twin.properties.reported.Emergency.IdSender
            LastTimestampAlert = twin.properties.reported.Emergency.CreationDate
            LastEmergencyMessage = twin.properties.reported.Emergency.EmergencyMessage
            console.log(twin.properties.reported.Emergency);
            }
        }
    });
};
setInterval(getTwinData, 2000);