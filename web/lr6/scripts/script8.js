document.addEventListener("DOMContentLoaded", ready);


function ready(){
    document.getElementById('left_img').addEventListener("click", backImg);
    document.getElementById('right_img').addEventListener("click", nextImg);
    document.getElementById('center_img').addEventListener("click", showImg);

    const IMAGES_COUNT = 5;
    const images = [];

    for (let i = 0; i < IMAGES_COUNT; i++)
        images[i] = ("../images/" + i.toString() + ".jpg");

    var center_image = document.getElementById('center_img'), even = false;
    var left_image = document.getElementById('left_img');
    var right_image = document.getElementById('right_img');

    var center_index = 0;
    var left_index = images.length-1;
    var right_index = center_index+1;

    viewImages();

    function viewImages() {
        left_image.src = images[left_index];
        right_image.src = images[right_index];
        center_image.src = images[center_index];
    }

    function backImg(){
        center_index--;
        left_index = center_index-1;
        right_index = center_index+1;

        if (left_index == -1){
            left_index = IMAGES_COUNT;
        }
        if (center_index < 0){
            right_index = 0;
            center_index = IMAGES_COUNT;
            left_index = IMAGES_COUNT-1;
        }

        viewImages();
    }

    function nextImg(){
        center_index++;
        left_index = center_index-1;
        right_index = center_index+1;

        if (right_index == IMAGES_COUNT){
            right_index = 0;
        }
        if (center_index == IMAGES_COUNT){
            right_index = 1;
            center_index = 0;
            left_index = IMAGES_COUNT;
        }

        viewImages();
    }

    function showImg() {
        if(even){
            center_image.style.zoom = "1";
            left_image.style.display = 'inline';
            right_image.style.display = 'inline';
            even = false;
        }
        else {
            center_image.style.zoom = "2";
            left_image.style.display = 'none';
            right_image.style.display = 'none';
            even = true;
        }
    }
}
