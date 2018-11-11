document.addEventListener('click', (event) => {
	console.log("ola2");
	chrome.runtime.sendMessage({"message" : "Click"});
});

/*var document = document.getElementById("iframe");
document.getElementById("iframe").addEventListener("click", function(){
	console.log("ola");
    chrome.runtime.sendMessage({"message" : "Click"});
});*/