'use strict';

var config = require('./config.json');
var Registry = require('azure-iothub').Registry;
var Client = require('azure-iothub').Client;

var connectionString = config.connectionString;
var registry = Registry.fromConnectionString(connectionString);
var client = Client.fromConnectionString(connectionString);
var deviceToReboot = 'Rpi-train1';

var isAlert = 0;

var NewTimestamp = new Date();
var NewIdVagone = 0;
var NewDesired_Temperature = "0,00";
var NewToggle_Back_Door ="\u0000";
var NewToggle_Front_Door ="\u0000";
var NewText_Message ="";

function sendDesired() {

    registry.getTwin(deviceToReboot, function(err, twin){
        if (err) {
            console.error(err.constructor.name + ': ' + err.message);
        } else {
            NewTimestamp = new Date().getTime();
            if (isAlert==0){
            var patch = {
                properties: {
                    desired: {
                        Comands: {
                            idVagone: NewIdVagone,
                            Desired_Temperature: NewDesired_Temperature,
                            Timestamp: NewTimestamp,
                            Toggle_Back_Door: NewToggle_Back_Door,
                            Toggle_Front_Door: NewToggle_Front_Door,
                            Text_Message: NewText_Message
                        }
                }
                }
            };
        } else{
            var patch = {
                properties: {
                    desired: {
                        Comands: {
                            Timestamp: NewTimestamp,
                            EmergencyMessage: NewText_Message
                        }
                    }
                    }
                };x

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

setInterval(sendDesired, 2000);