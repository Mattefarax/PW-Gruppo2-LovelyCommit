const { MongoClient } = require("mongodb");
var config = require('./config.json');
let model = require('../IotSender');
const fs = require('fs');


const uri = config.connectionString;
const client = new MongoClient(uri);
// Json examples for inserts
var JsonUsers = {
  "username": "ddd",
  "password": "12345",
  "train_management_permission": ["IT23345"],
  "creation_date": "2022-06-17 03:14:07",
  "last_access": "2022-07-04 00:14:07"
};
var JsonTrains = {
  "id_train": "IT23345",
  "number_of_wagons": 1,
  "date_creation": "2022-06-17 03:14:07",
  "date_last_update": "2022-07-04 00:14:07"
};
var JsonTelemetries = {
  "id_telemetry": 5,
  "id_train": "IT23345",
  "wagon_number": 1,
  "current_temperature": 25.5,
  "desired_temperature": 27.5,
  "humidity": 4.7,
  "emergency_status": 0,
  "back_door": 0,
  "front_door": 0,
  "toilette_status": 0,
  "timestamp": "2022-06-18 03:14:07"
};
var JsonAlarms = {
  "id_alarm": "0",
  "id_train": "IT23345",
  "sender": 0,
  "emergency_message": "allarme generico",
  "creation_date": "2022-06-17 03:14:07",
  "closing_date": "2022-06-17 03:14:07"
};
async function Insertvalues() {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const users = database.collection('Users');
    const trains = database.collection('Trains');
    const telemetries = database.collection('Telemetries');
    const alarms = database.collection('Alarms');

    userData = JSON.parse(JSON.stringify(JsonUsers));
    trainData = JSON.parse(JSON.stringify(JsonTrains));
    telemetryData = JSON.parse(JSON.stringify(JsonTelemetries));
    alarmData = JSON.parse(JSON.stringify(JsonAlarms));

    const resultUsers = await users.insertOne(userData);
    console.log(`A document was inserted with the _id: ${resultUsers.insertedId}`);

    const resultTrains = await trains.insertOne(trainData);
    console.log(`A document was inserted with the _id: ${resultTrains.insertedId}`);

    const resultTelemetries = await telemetries.insertOne(telemetryData);
    console.log(`A document was inserted with the _id: ${resultTelemetries.insertedId}`);

    const resultAlarms = await alarms.insertOne(alarmData);
    console.log(`A document was inserted with the _id: ${resultAlarms.insertedId}`);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function getTelemetry(id_trains, callback) {

  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const telemetries = database.collection('Telemetries');
    const alarms = database.collection('Alarms');

    var alarmIndexNumber = 0;
    var availableTrains = ["IT12345", "IT23456"];
    //var availableTrains = id_trains;
    var trainInfos = [];
    var trainAlarms = [];
    for (let i = 0; i < availableTrains.length; i++) {
      trainInfos[i] = await telemetries.find({
        id_train: availableTrains[i]
      }).limit(1).toArray();
      var alarm = trainInfos[i][0].emergency_status;
      if (alarm == 1) {
        trainAlarms[alarmIndexNumber] = await alarms.find({
          id_train: availableTrains[i]
        }).limit(1).toArray();
        console.log(trainAlarms[alarmIndexNumber]);
        alarmIndexNumber = alarmIndexNumber + 1;
      }
    }
    const obj1 = JSON.parse(JSON.stringify(trainAlarms));
    const obj2 = JSON.parse(JSON.stringify(trainInfos));
    const trainTelAlarm = {
      obj1,
      obj2
    };
    return [null, trainTelAlarm];
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return (err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function getLoginConfirmation(mail, psw, callback) {
  try {
    await client.connect();

    const database = client.db('LovelyCommitTrainSystem');
    const users = database.collection('Users');

    var trainString = "";
    //var varUser = "aaa";
    //var varPsw = "12345";
    var varUser = mail;
    var varPsw = psw;
    var query = {
      username: varUser,
      password: varPsw
    };
    var loginStatus = await (users.find(query)).toArray();

    if (loginStatus[0] != null) {
      trainString = (loginStatus[0].train_management_permission).toString();
    } else {
    }

    return callback(null, trainString);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function insertTelemetry(TelemetriesJson, callback) {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const telemetries = database.collection('Telemetries');

    trainInfos[i].id_telemetry = trainInfos[i].id_telemetry + 1;
    telemetryData.id_telemetry = trainInfos[i].id_telemetry
    telemetryData = JSON.parse(TelemetriesJson);

    const resultTelemetries = await telemetries.insertOne(telemetryData);
    var resultstring = `A document was inserted with the _id: ${resultTelemetries.insertedId}`
    console.log(resultstring);

    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}
async function insertEmergency(EmergencyJson, callback) {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const alarms = database.collection('Alarms');

    emergencyData = JSON.parse(EmergencyJson);

    const resultEmergency = await alarms.insertOne(emergencyData);
    var resultstring = `A document was inserted with the _id: ${resultEmergency.insertedId}`
    console.log(resultstring);

    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function updateEmergency(timestamp, ObjID, callback) {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const alarms = database.collection('Alarms');
    
    await alarms.updateOne(
      { "_id": ObjID },
      { $set: { "closing_date": timestamp } }
    );
    var resultstring = `A document was inserted with the _id: ${resultEmergency.insertedId}`
    console.log(resultstring);

    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function sendEmergency(id_train_eme, timestamp, msg, sender, callback) {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const telemetries = database.collection('Telemetries');
    const alarms = database.collection('Alarms');

    telemetryData = JSON.parse(JSON.stringify(JsonTelemetries));
    alarmData = JSON.parse(JSON.stringify(JsonAlarms));

    trainInfos[i] = await telemetries.find({
      id_train_eme: availableTrains[i]
    }).limit(1).toArray();
    trainInfos[i].emergency_status = 1;
    trainInfos[i].timestamp = timestamp;
    const resultTelemetries = await telemetries.insertOne(telemetryData);
    console.log(`A document was inserted with the _id: ${resultTelemetries.insertedId}`);
    var JsonAlarmsNew = {
      "id_alarm": 56,
      "id_train": id_train_eme,
      "sender": 0,
      "emergency_message": msg,
      "creation_date": timestamp
    };
    alarmData = JSON.parse(JSON.stringify(JsonAlarmsNew));
    const resultAlarms = await alarms.insertOne(alarmData);
    console.log(`A document was inserted with the _id: ${resultAlarms.insertedId}`);
    if (sender == 1) {
      model.sendDesired(1, JsonAlarmsNew);
    }
    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}

async function sendMessage(id_trains, wagon_Number, msg, callback) {
  try {
    var NewTimestamp = new Date();
    var jsonToSend = {
      "idVagone": wagon_Number,
      "Desired_Temperature": 25,
      "Timestamp": NewTimestamp,
      "Toggle_Back_Door": 0,
      "Toggle_Front_Door": 0,
      "Text_Message": msg
    }
    await model.sendDesired(1, jsonToSend);
    var resultstring = `message sent`
    console.log(resultstring);
    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  }
}

async function modifyDesired(operation, valueToChange, wagon_Number, id_trains, callback) {
  try {

    var NewTimestamp = new Date();
    var jsonToSend = {
      "idVagone": wagon_Number,
      "Desired_Temperature": 25,
      "Timestamp": NewTimestamp,
      "Toggle_Back_Door": 0,
      "Toggle_Front_Door": 0,
      "Text_Message": ""
    }

    switch (operation) {
      case 0:
        jsonToSend.Desired_Temperature = valueToChange;
        break;
      case 1:
        jsonToSend.Toggle_Back_Door = valueToChange;
        break;
      case 2:
        jsonToSend.Toggle_Front_Door = valueToChange;
        break;
    }
    await model.sendDesired(0, jsonToSend);
    var resultstring = `Desired setted`
    console.log(resultstring);
    return callback(null, resultstring);
  } catch (err) {
    console.log("An error has occurred");
    console.log(err)
    return callback(err);
  }
}
getTelemetry(1);
module.exports = {
  getLoginConfirmation,
  getTelemetry,
  insertTelemetry,
  sendEmergency,
  sendMessage,
  modifyDesired,
  insertEmergency,
  updateEmergency
};