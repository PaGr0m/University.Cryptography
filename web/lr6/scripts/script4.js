document.addEventListener("DOMContentLoaded", ready);

function ready() {
    document.getElementById("nav").addEventListener("click", show);
}

function show(e) {
    var target = e.target;
    var targetParent = target.closest('.menu-item');
    if (targetParent) {
        var subm = targetParent.getElementsByClassName('submenu')[0];
        close();
        if (subm) {
            subm.style.display = 'block';
        }
    }
}

function close() {
    var s = document.getElementsByClassName('submenu');
    for (var i = 0; i < s.length; i++) {
        s[i].style.display = 'none';
    }
}