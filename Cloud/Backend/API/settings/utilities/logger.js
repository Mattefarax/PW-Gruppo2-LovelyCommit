let moment = require('moment');

function log(message) {
    console.log("\x1b[36m[LOG]\x1b[0m " + moment().format("DD/MM/YY HH:mm:ss.SSS[ms]") + " ### " + message);
}

function info(message) {
    console.log("\x1b[32m[INFO]\x1b[0m " + moment().format("DD/MM/YY HH:mm:ss.SSS[ms]") + " ### " + message);
}

function debug(message) {
    console.log("\x1b[34m[DEBUG]\x1b[0m " + moment().format("DD/MM/YY HH:mm:ss.SSS[ms]") + " ### " + message);
}

function warn(message) {
    console.log("\x1b[33m[WARN]\x1b[0m " + moment().format("DD/MM/YY HH:mm:ss.SSS[ms]") + " ### " + message);
}

function error(message) {
    console.log("\x1b[31m[ERROR]\x1b[0m " + moment().format("DD/MM/YY HH:mm:ss.SSS[ms]") + " ### " + message);
}
module.exports = {
    log,
    info,
    debug,
    warn,
    error,
};