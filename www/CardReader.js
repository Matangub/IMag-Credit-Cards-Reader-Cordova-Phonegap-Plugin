var exec = require('cordova/exec');
function CardReader() { 
	console.log("CardReader.js: is created");
}

CardReader.prototype.Read = function(success, fail){
	console.log("CardReader Started");
	exec(function(data){
		console.log(data);
		var result = data.split("/");
		success(result[0], result[1], result[2]);
	}, fail, "CardReader", "readCreditCard", []);
	//exec(success, fail, "CardPlugin", "readCreditCard", []);
}

var cardReader = new CardReader(); 

module.exports = cardReader;