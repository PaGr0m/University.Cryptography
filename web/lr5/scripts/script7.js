function getRandomInRange(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function myFunc(obj){
    var count = document.getElementById('val').value;
    var arr = [];
    var min = 1000;

    for (var i = 0; i < count; i++)
    {
        arr[i] = getRandomInRange(0, 99);
        if (min > arr[i])
            min = arr[i];
    }

    alert(arr + "  |  " + min);
}