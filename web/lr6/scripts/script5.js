document.addEventListener("DOMContentLoaded", notUpperLatin);

function notUpperLatin(e) {
    document.getElementById('qwe').addEventListener("keyup", notUpperLatin);
    var s2;
    s2 = document.getElementById('qwe').value;
    if (s2[s2.length-1]>='A' && s2[s2.length-1]<='Z'){
        document.getElementById('qwe').value = document.getElementById('qwe').value.slice(0,-1);
    }
}