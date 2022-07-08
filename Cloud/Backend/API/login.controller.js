let model = require('../MongoDb/mongoClient');
let logger = require('./settings/utilities/logger');

function getLoginConfirmation(req, res) {
    let mail = req.body.mail;
    let psw = req.body.psw;
    model.getLoginConfirmation(mail, psw, (err, result) => {
        if (err) {
            logger.error(err);
            res.status(500).send({ success: false, message: 'Internal server error' });
        } else if (!result.length) {
            res.status(404).send({ success: false, message: 'Invalid credentials' });
        } else {
            console.log("User " + mail + " logged in");
            res.status(200).send({ success: true, user: result });
            //res.redirect(200, 'http://127.0.0.1:5501/interface.html');
        }
    });
}

module.exports = {
    getLoginConfirmation
};