function condition( obj ) {
    var a = obj.valA.value;
    var b = obj.valB.value;
    var c = obj.valC.value;
    var count = 0;

    if ( a > 0 )
        count++;
    if ( b > 0 )
        count++;
    if ( c > 0 )
        count++;

    obj.result.value = count;
}