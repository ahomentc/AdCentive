window.addEventListener('load', function load(event){
    var backButton = document.getElementById('back');
    backButton.addEventListener('click', function() {
        window.location.href='popup.html';
    });
});

function popup(action) {
    console.log(action);
    chrome.tabs.query({currentWindow: true, active: true}, function (tabs){
    var activeTab = tabs[0];
    chrome.tabs.sendMessage(activeTab.id, {"message": action});
   });
}

document.addEventListener("DOMContentLoaded", function (event) {
    var _musicselector = document.querySelector('input[name=music]');
    _musicselector.addEventListener('change', function (event) {
        if (_musicselector.checked) {
            popup("music");
        }
    });

    var _eventsselector = document.querySelector('input[name=events]');
    _eventsselector.addEventListener('change', function (event) {
        if (_eventsselector.checked) {
            popup("events");
        }
    });

    var _foodselector = document.querySelector('input[name=food]');
    _foodselector.addEventListener('change', function (event) {
        if (_foodselector.checked) {
            popup("food");
        }
    });

    var _electronicsselector = document.querySelector('input[name=electronics]');
    _electronicsselector.addEventListener('change', function (event) {
        if (_electronicsselector.checked) {
            popup("electronics");
        }
    });
});