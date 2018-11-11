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
		console.log("Req:", request);
		if( request.message === "music" ) {
			console.log("music");
			document.getElementById('adimg').src='Music_ad.jpg';
		} else if ( request.message === "events" ) {
			console.log("events");
			document.getElementById('adimg').src='Event_ad.jpg';
		} else if ( request.message === "food" ) {
			console.log("food");
			document.getElementById('adimg').src='Food_ad.jpg';
		} else if ( request.message === "electronics" ) {
			console.log("electronics");
			document.getElementById('adimg').src='amazon_ad.jpg';
		}
	}
  );

/*var document = document.getElementById("iframe");
document.getElementById("iframe").addEventListener("click", function(){
	console.log("ola");
    chrome.runtime.sendMessage({"message" : "Click"});
});*/