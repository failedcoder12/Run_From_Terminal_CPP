var socket = io();

socket.on('connect',function() {
	console.log('Connected to server');
});

// socket.on('answer', function(ans){
// 	console.log('Answer',ans);
// });

// socket.emit('DNA',{
// 	stringA : "ACACGT",
// 	stringB : "ACCCG"
// });
