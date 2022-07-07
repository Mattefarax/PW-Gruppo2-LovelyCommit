let express = require('express');
let controller = require('./login.controller');
let route = express.Router();
route.post('/', controller.getLoginConfirmation);

module.exports = route;