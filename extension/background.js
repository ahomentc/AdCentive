chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {

	chrome.tabs.query({currentWindow: true, active: true}, function(tabs) {
        if (request.message == "Click") {
            alert("clicked");
        }
	});
});

