function TrianglePS(a, setting) {
    setting.Perimeter = 3*a;
    setting.Square = Math.pow(a, 2) * Math.sqrt(3) / 4;
}

function main(obj) {
    var val = obj.val.value;
    var settings = {
        Perimeter : 0,
        Square : 0
    };

    TrianglePS(val, settings);
    alert("Perimeter = " + settings.Perimeter);
    alert("Square = " + settings.Square);
}