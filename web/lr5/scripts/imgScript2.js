window.onload = function() {

    var drawingCanvas = document.getElementById('img2');
    if(drawingCanvas && drawingCanvas.getContext) {
        var ctx = drawingCanvas.getContext('2d');

        ctx.fillStyle = "rgb(255, 0, 0)";
        ctx.beginPath();
        ctx.fillRect(0, 0, 350, 160);
        ctx.closePath();
        ctx.stroke();
        ctx.fill();


        ctx.fillStyle = "rgb(255, 255, 255)";
        ctx.beginPath();
        ctx.fillRect(50, 0, 60, 160);
        ctx.closePath();
        ctx.stroke();
        ctx.fill();

        ctx.fillStyle = "rgb(255, 255, 255)";
        ctx.beginPath();
        ctx.fillRect(0, 54, 350, 55);
        ctx.closePath();
        ctx.stroke();
        ctx.fill();
    }

}