/* PACKAGE REQUIRES */
let express = require("express");
let cors = require('cors');
let bodyParser = require('body-parser');
/* CUSTOM REQUIRES */
let config = require('./settings/configs/process.config');
let logger = require('./settings/utilities/logger');
/* APP USE CASES */
let app = express();

app.use(bodyParser.urlencoded({
    extended: true

}));
app.use(bodyParser.json());
// app.use(cors());
app.use(cors({ exposedHeaders: ['Content-Disposition'] }));


/* APP ROUTES */
let login = require('./login.route');
let interface = require('./interface.route');


let router = express.Router();
app.use('/', router);
app.use('/login', login);
app.use('/interface', interface);

//app.use('/public', express.static("public"));
let server = app.listen(config.serverPort);

logger.info("Server listening on port " + config.serverPort);
