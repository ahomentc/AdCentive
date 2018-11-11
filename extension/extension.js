document.addEventListener('click', (event) => {
	console.log("ola2");
	//chrome.runtime.sendMessage({"message" : "Click"});
	chrome.runtime.sendMessage({message : "Click"}, function(response) {
		console.log("resp: ", response.farewell);
		chrome.runtime.sendMessage({message2 : "Click2"});
	  });
});

/*var document = document.getElementById("iframe");
document.getElementById("iframe").addEventListener("click", function(){
	console.log("ola");
    chrome.runtime.sendMessage({"message" : "Click"});
});*/