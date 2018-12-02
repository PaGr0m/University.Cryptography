function getRandomInRange(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function myFunc() {
    var N = document.getElementById("N").value;
    var K = document.getElementById("K").value;
    var L = document.getElementById("L").value;

    var arr = [];
    var res = 0;
    for (var i = 0; i < N; i++)
        arr[i] = getRandomInRange(0, 50);

    for (var i = K; i <= L; i++)
        res = res + arr[i];

    res = res / (L-K+1);

    alert(arr + "   |   " + res);
}