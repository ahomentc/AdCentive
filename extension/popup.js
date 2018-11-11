function refresh() {
    var val = localStorage["total_elements"];
    console.log("current token value: ", val);
    document.getElementById("tokens").value = val;
}

window.addEventListener('load', function load(event){
    var createButton = document.getElementById('refresh');
    createButton.addEventListener('click', function() { refresh(); });

    var backButton = document.getElementById('preferences');
    backButton.addEventListener('click', function() {
        console.log("test");
        window.open('preferences.html');
    });
    return true;
});