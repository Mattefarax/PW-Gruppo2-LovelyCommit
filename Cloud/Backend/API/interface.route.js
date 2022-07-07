let express = require('express');
let controller = require('../interface.controller');
let route = express.Router();
route.get('/gtelemetry', controller.getTelemetry);

route.post('/uptelemetry', controller.insertTelemetry);
route.post('/upmessage', controller.sendMessage);
route.post('/upemergency', controller.sendEmergency);
route.post('/moddesired', controller.modifyDesired);
module.exports = route;