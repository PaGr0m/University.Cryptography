document.addEventListener("DOMContentLoaded", ready);

function ready() {
    var cs = document.getElementById('cursor');
    cs.src = "../images/cursor.png";
    cs.style.position = 'absolute';
    cs.style.left = 10 +'px';
    cs.style.top = 10 +'px';
    document.onmousemove = function (even){
        cs.style.left = (even.pageX) +'px';
        cs.style.top = (even.pageY) +'px';
    }
}
