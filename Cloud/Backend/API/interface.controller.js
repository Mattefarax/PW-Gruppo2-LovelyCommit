let model = require('../MongoDb/mongoClient');
let logger = require('../../settings/utilities/logger');

function getTelemetry(req, res) {
    console.log("Sending getTelemetry request");
    let id_trains = req.query.id_trains;
    let err = null;
    if (err) {
        logger.error(err);
        res.status(401).send({ success: false, message: 'Invalid authentication token' });
    } else {
        model.getTelemetry(id_trains, (err, result) => {
            if (err) {
                logger.error(err);
                res.status(500).send({ success: false, message: 'Internal server error' });
            } else if (!result.length) {
                res.status(404).send({ success: false, message: 'Not found' });
            } else {
                console.log("getTelemetry request successful");
                res.status(200).send({ success: true, telemetries: result });
            }
        });
    }
}

function insertTelemetry(req, res) {
    console.log("Sending insertTelemetry request");
    let id_trains = req.query.id_trains;
    let telemetryData = req.query.telemetryData
    let err = null;
    if (err) {
        logger.error(err);
        res.status(401).send({ success: false, message: 'Invalid authentication token' });
    } else {
        model.insertTelemetry(id_trains, telemetryData, (err, result) => {
            if (err) {
                logger.error(err);
                res.status(500).send({ success: false, message: 'Internal server error' });
            } else if (result.affectedRows == 0) {
                console.log("Data not found ");
                res.status(404).send({ success: false, message: 'Data not found' });
            } else {
                console.log("insertTelemetry request successful");
                res.status(200).send({ success: true, message: 'Telemetries Updated YAY!' });
            }
        });
    }
}
function sendMessage(req, res) {
    console.log("Sending sendMessage request");
    let id_trains = req.query.id_trains;
    let msg = req.query.msg;
    let err = null;
    if (err) {
        logger.error(err);
        res.status(401).send({ success: false, message: 'Invalid authentication token' });
    } else {
        model.sendMessage(id_trains, msg, (err, result) => {
            if (err) {
                logger.error(err);
                res.status(500).send({ success: false, message: 'Internal server error' });
            } else if (result.affectedRows == 0) {
                console.log("Data not found ");
                res.status(404).send({ success: false, message: 'Data not found' });
            } else {
                console.log("sendMessage request successful");
                res.status(200).send({ success: true, message: 'Message sent YAY!' });
            }
        });
    }
}

function sendEmergency(req, res) {
    console.log("Sending sendEmergency request");
    let id_trains = req.query.id_trains;
    let timestamp = req.query.timestamp;
    let msg = req.query.timestamp;
    let sender = -1;
    let err = null;
    if (err) {
        logger.error(err);
        res.status(401).send({ success: false, message: 'Invalid authentication token' });
    } else {
        model.sendEmergency(id_trains, timestamp, msg, sender, (err, result) => {
            if (err) {
                logger.error(err);
                res.status(500).send({ success: false, message: 'Internal server error' });
            } else if (result.affectedRows == 0) {
                console.log("Data not found ");
                res.status(404).send({ success: false, message: 'Data not found' });
            } else {
                console.log("sendEmergency request successful");
                res.status(200).send({ success: true, message: 'Emergency sent' });
            }
        });
    }
}

module.exports = {
    getTelemetry,
    insertTelemetry,
    sendMessage,
    sendEmergency
};