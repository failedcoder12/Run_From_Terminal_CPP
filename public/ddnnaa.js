var socket = io();
var A,B,C;
socket.on('connect',()=>{
		console.log('Connected to server');
		var params = jQuery.deparam(window.location.search);
		A = params.name;
		B = params.room;
		socket.emit('solving',params, function(error){
			if(error){
				alert(error);
				window.location.href='/';
			}else {
				console.log('No error');
			}
		});

socket.on('answer', function(ans){
	console.log('Answer',ans);
	C=ans.answer;
	var template = jQuery('#message-template').html();
	var html = Mustache.render(template,{
		AA: A,
		BB: B,
		CC: C
	});
	jQuery('#messages').append(html);

});

});
