const path = require('path');
const http = require('http');
const express = require('express');
const {isRealString} = require('./validation.js');
const socketIO = require('socket.io');
const publicPath = path.join(__dirname,'../public');
var app = express();
const port = process.env.PORT || 3000;
var server = http.createServer(app);
var io = socketIO(server);

app.use(express.static(publicPath));

server.listen(port, ()=>{
	console.log('Server is up on port 3000');
});

var cmd = require('node-cmd');

var st = "";
function myFunction(stringA, stringB,fun) {

// cmd.get(
// 	`g++ DNA.cpp`,
// 	function(err,data,stderr){
// 		console.log('WOOOO',data);
		cmd.get(
			`a.exe ${stringA} ${stringB}`,
			function(err,data,stderr){
				console.log('WO',data);
				st = data;
				fun();
			}
		);
// 	}
// );

}
io.on('connection',(socket)=>{
	console.log('New User Connected');
	// socket.emit('answer',{
	// 	answer: st
	// });

	socket.on('solving',(params,callback)=>{
		if(!isRealString(params.name) || !isRealString(params.room)){
			callback('DNA string and Infected string is required');
		}else {
			function fun(){
				socket.emit('answer',{
					answer: st
				});
				console.log('hjgkjhg');
			}
			myFunction(params.name,params.room,fun);
			console.log(st);
			callback();
		}
	});
	// socket.on('DNA',(strin)=>{
	// 	console.log(strin.stringA,strin.stringB);
	// });

});

// var form = document.querySelector('#signupForm')
 
// var data = getFormData(form, {trim: true})
 
// console.log(JSON.stringify(data))

