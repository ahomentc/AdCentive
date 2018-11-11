/*chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {

	chrome.tabs.query({currentWindow: true, active: true}, function(tabs) {
        if (request.message == "Click") {
            //alert("clicked");
        }
	});
});*/

/*****************************************************************
 * onMessage from the extension or tab (a content script)
 *****************************************************************/
chrome.runtime.onMessage.addListener(
    function(request, sender, sendResponse) {
      if (request.message == "Click") {
        if (localStorage.getItem("total_elements") === null) {
            console.log("first");
            localStorage["total_elements"] = 1; // Get from EOS backend
            window.val = localStorage["total_elements"];
          }
        else {
            console.log("second");
            localStorage["total_elements"] =  Number(localStorage["total_elements"]) + Number(1);
            window.val = localStorage["total_elements"];
        }
        sendResponse({ farewell: "any response from background" });
      } else {
        sendResponse({ result: "error", message: `Invalid 'cmd'` });
      }
      // Note: Returning true is required here!
      //  ref: http://stackoverflow.com/questions/20077487/chrome-extension-message-passing-response-not-sent
      return true; 
    });