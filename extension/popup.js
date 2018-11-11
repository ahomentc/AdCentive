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
    console.log("current token value: ", localStorage["total_elements"]);
    document.getElementById("tokens").value = localStorage["total_elements"];
}

window.addEventListener('load', function load(event){
    var createButton = document.getElementById('refresh');
    createButton.addEventListener('click', function() { refresh(); });
});