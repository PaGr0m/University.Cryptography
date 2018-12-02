document.addEventListener("DOMContentLoaded", ready);

function ready() {
    document.getElementById('head1').addEventListener("click", show);
    document.getElementById('head2').addEventListener("click", show);
}

function show(e) {
    var s = '';
    var s2 = 'text';

    s = e.target.id;
    s2 += s[4];

    if (document.getElementById(s2).style.display == 'none') {
        document.getElementById(s2).style.display = 'block';
    }
    else {
        document.getElementById(s2).style.display = 'none';
    }
}