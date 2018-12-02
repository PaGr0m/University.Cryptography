function myFunc() {
    var N = document.getElementById("N").value;
    var A = document.getElementById("A").value;
    var D = document.getElementById("D").value;

    var arr = [];
    arr[0] = A;
    for (var i = 1; i < N; i++)
    {
        arr[i] = (A + Math.pow(D, i));
    }

    alert(arr);
}