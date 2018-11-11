document.addEventListener('click', (event) => {
	console.log("ola2");
	//chrome.runtime.sendMessage({"message" : "Click"});
	chrome.runtime.sendMessage({message : "Click"}, function(response) {
		console.log("resp: ", response.farewell);
		chrome.runtime.sendMessage({message2 : "Click2"});
	  });
});

chrome.runtime.onMessage.addListener(
	function(request, sender, sendResponse) {
		if( request.message === "music" ) {
			console.log("music");
		} else if ( request.message === "events" ) {
			console.log("events");
		} else if ( request.message === "food" ) {
			console.log("food");
		} else if ( request.message === "electronics" ) {
			console.log("electronics");
		}
	}
  );

/*var document = document.getElementById("iframe");
document.getElementById("iframe").addEventListener("click", function(){
	console.log("ola");
    chrome.runtime.sendMessage({"message" : "Click"});
});*/