document.addEventListener("DOMContentLoaded", ready);

function ready() {
    document.getElementById('table').addEventListener("click", textColor);
    document.getElementById('table').addEventListener("contextmenu", backColor);
}

function textColor(e) {
    var s = '', s2 = 'text';
    s = e.target.id;
    document.body.style.color=s;
}
function backColor(e) {
    var s = '', s2 = 'text';
    s = e.target.id;
    document.body.style.backgroundColor=s;
}