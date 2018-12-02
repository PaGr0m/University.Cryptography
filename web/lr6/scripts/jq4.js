$(document).ready(function(){
    $('#menu-item').mouseover(function(){
        $('#submenu').show();
    });

    $('#menu-item').mouseout(function(){
        $('#submenu').hide();
    });

    $('#menu-item2').mouseover(function(){
        $('#submenu2').show();
    });

    $('#menu-item2').mouseout(function(){
        $('#submenu2').hide();
    });
});
