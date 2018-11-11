var token_value = 10;
function refresh() {
    var val =  ++token_value;
    localStorage["total_elements"] = val;
    console.log("Current token value: ", val);
    document.getElementById("tokens").value = val;
}

window.addEventListener('load', function load(event){
    var createButton = document.getElementById('refresh');
    createButton.addEventListener('click', function() { refresh(); return false;});

    var backButton = document.getElementById('preferences');
    backButton.addEventListener('click', function() {
        console.log("Clicked!");
    });
    return true;
});