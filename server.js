// -------------------This is the standard server for three.js
var servi = require('servi');
var app = new servi(true);

port(8080);

app.serveFiles("public"); // name of new folder
app.route('/', sendData);      // route requests for /data to sendData() function


//
// ----------------This is the serialport server
var serialport = require('serialport'),// include the library
   SerialPort = serialport.SerialPort, // make a local instance of it
   // get port name from the command line:
   portName = process.argv[2]; 
   
var latestData = 0;  				// latest data saved from the serial port

var myPort = new SerialPort(portName, { 
   baudRate: 9600,
   // look for return and newline at the end of each data packet:
   parser: serialport.parsers.readline("\r\n") 
 });   

// these are the definitions for the serial events:
myPort.on('open', showPortOpen);  
myPort.on('data', saveLatestData); 
myPort.on('close', showPortClose);
myPort.on('error', showError);

// these are the functions called when the serial events occur:
function showPortOpen() {
   console.log('port open. Data rate: ' + myPort.options.baudRate);
}

function saveLatestData(data) {
   console.log(data);
   latestData = data;
}

function showPortClose() {
   console.log('port closed.');
}

function showError(error) {
   console.log('Serial port error: ' + error);
}

// ------------------------ Server function
function sendData(request) {	
	// respond to the client request with the latest serial string:
   request.respond(latestData);
}

//

app.start();