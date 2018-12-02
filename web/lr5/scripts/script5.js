function power( obj ) {
    var val = obj.val.value;
    var count = 1;

    while (count < val)
    {
        count *= 3;
        if (count == val)
        {
            alert("True");
            return;
        }
    }
    alert("False")
}