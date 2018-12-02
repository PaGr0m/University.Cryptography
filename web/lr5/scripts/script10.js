function getRandomInRange(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function myFunc() {
    var N = document.getElementById("N").value;

    var arr = [];
    var min = 1000;
    var max = -1;
    var tmp = 0;
    var minIdx = 0;
    var maxIdx = 0;


    for (var i = 0; i < N; i++)
    {
        arr[i] = getRandomInRange(0, 50);

        if (min > arr[i])
        {
            min = arr[i];
            minIdx = i;
        }


        if (max < arr[i])
        {
            max = arr[i];
            maxIdx = i;
        }

    }
    alert(arr);

    tmp = arr[minIdx];
    arr[minIdx] = max;
    arr[maxIdx] = tmp;

    alert(arr);
}