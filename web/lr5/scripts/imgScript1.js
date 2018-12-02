window.onload = function() {

    var drawingCanvas = document.getElementById('img1');
    if(drawingCanvas && drawingCanvas.getContext) {
        var ctx = drawingCanvas.getContext('2d');
        var offset = 100;

        ctx.beginPath();
        ctx.moveTo(0 + offset, 0);
        ctx.lineTo(40 + offset, 40);
        ctx.lineTo(-40 + offset, 40);
        ctx.lineTo(0 + offset, 0);

        ctx.moveTo(0 + offset, 40);
        ctx.lineTo(40 + offset, 80);
        ctx.lineTo(-40 + offset, 80);
        ctx.lineTo(0 + offset, 40);

        ctx.moveTo(0 + offset, 80);
        ctx.lineTo(40 + offset, 120);
        ctx.lineTo(-40 + offset, 120);
        ctx.lineTo(0 + offset, 80);

        ctx.moveTo(10 + offset, 120);
        ctx.lineTo(10 + offset, 140);
        ctx.lineTo(-10 + offset, 140);
        ctx.lineTo(-10 + offset, 120);

        ctx.closePath();
        ctx.stroke();
    }
}