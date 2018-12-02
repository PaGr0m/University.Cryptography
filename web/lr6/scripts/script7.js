document.addEventListener("DOMContentLoaded", showImages);
let idx = 0;
const IMAGES_COUNT = 5;
const images = [];

for (let i = 0; i < IMAGES_COUNT; i++)
    images[i] = ("../images/" + i.toString() + ".jpg");

function showImages()
{
    let image = document.getElementById("my_img");
    image.src = images[idx];
    image.style.width = 400 + "px";
    image.style.height = 400 + "px";

    if (idx === IMAGES_COUNT-1)
        idx = 0;
    else
        idx++;

    setTimeout("showImages()", 500);
}