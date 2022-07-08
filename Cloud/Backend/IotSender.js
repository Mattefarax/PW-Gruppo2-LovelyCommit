'use strict';

var config = require('./config.json');
var Registry = require('azure-iothub').Registry;

var connectionString = config.connectionString;
var registry = Registry.fromConnectionString(connectionString);
var deviceToReboot = 'Rpi-train1';

var NewTimestamp = new Date();
var NewIdVagone = 0;
var NewDesired_Temperature = "0,00";
var NewToggle_Back_Door ="\u0000";
var NewToggle_Front_Door ="\u0000";
var NewText_Message ="";

function sendDesired(isAlert, jsonModifiers) {

    registry.getTwin(deviceToReboot, function(err, twin){
        if (err) {
            console.error(err.constructor.name + ': ' + err.message);
        } else {
            if (isAlert==0){
            var patch = {
                properties: {
                    desired: {
                        Comands: {
                            idVagone: jsonModifiers.idVagone,
                            Desired_Temperature: jsonModifiers.Desired_Temperature,
                            Timestamp: jsonModifiers.Timestamp,
                            Toggle_Back_Door: jsonModifiers.Toggle_Back_Door,
                            Toggle_Front_Door: jsonModifiers.Toggle_Front_Door,
                            Text_Message: jsonModifiers.Text_Message
                        }
                }
                }
            };
        } else{
            var patch = {
                properties: {
                    desired: {
                        Comands: {
                            Timestamp: jsonModifiers.creation_date,
                            EmergencyMessage: jsonModifiers.emergency_message
                        }
                    }
                    }
                };
        }
            twin.update(patch, function(err) {
            if (err) {
                console.error('Could not update twin: ' + err.constructor.name + ': ' + err.message);
            } else {
                console.log(twin.deviceId + ' twin updated successfully');
            }
            });
        }
    });
}