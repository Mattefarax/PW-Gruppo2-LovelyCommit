const { MongoClient } = require("mongodb");
  var config = require('./config.json');

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
async function run() {
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const users = database.collection('Users');
    const trains = database.collection('Trains');
    const telemetries = database.collection('Telemetries');
    const alarms = database.collection('Alarms');

    userData=JSON.parse(JSON.stringify(JsonUsers));
    trainData=JSON.parse(JSON.stringify(JsonTrains));
    telemetryData=JSON.parse(JSON.stringify(JsonTelemetries));
    alarmData=JSON.parse(JSON.stringify(JsonAlarms));


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
async function runQuery(){
  try {
    await client.connect();
    const database = client.db('LovelyCommitTrainSystem');
    const users = database.collection('Users');
    const trains = database.collection('Trains');
    const telemetries = database.collection('Telemetries');
    const alarms = database.collection('Alarms');
    var varUser = "bbb";
    var varPsw = "12345";
    var query = {
      username: varUser,
      password: varPsw
    };
   // const loginStatus = await users.find(query);

    users.find().toString(function(err, result) {
      if (err) throw err;
      console.log(result);
    });


    
  } finally {
    // Ensures that the client will close when you finish/error
    await client.close();
  }
}
//run().catch(console.dir);
runQuery().catch(console.dir);

