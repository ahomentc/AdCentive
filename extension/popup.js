/*chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {

	chrome.tabs.query({currentWindow: true, active: true}, function(tabs) {
        if (request.message == "Click") {
            console.log("tests");
            alert("clickedd");
        }
	});
});
*/

function refresh() {
console.log("test: ", localStorage["total_elements"]);
document.getElementById("tokens").innerHTML = localStorage["total_elements"];
}