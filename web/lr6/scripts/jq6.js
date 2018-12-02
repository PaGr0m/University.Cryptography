$(document).ready(function(){
    $('#cursor').attr('src', '../images/cursor.png');
    $('#cursor').css(
        {
            left: 11,
            top: 11,
            position: 'absolute'
        });
    $(window).mousemove(function(even){
        var value_left = even.pageX;
        var value_top = even.pageY;
        $('#cursor').css({left: value_left, top: value_top});
    });
});
