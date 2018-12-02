document.addEventListener("DOMContentLoaded", ready);

function ready() {
    var text = document.getElementById('my_text');
    text.style.position = 'absolute';
    var pos = 100;

    window.onkeydown = function (even) {
        if (even.keyCode == 37){ //left
            pos -= 100;
        }
        else if(even.keyCode == 39){ //right
            pos += 100;
        }
        text.style.left = pos +'px';
    }
}
