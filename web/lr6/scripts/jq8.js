const IMAGES_COUNT = 5;
const images = [];

for (let i = 0; i < IMAGES_COUNT; i++)
    images[i] = ("../images/" + i.toString() + ".jpg");

var center_index = 0;
var left_index = images.length - 1;
var right_index = center_index + 1;

$(document).ready(function(){
    $('#left_img').click(function(){
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
    });

    $('#right_img').click(function(){
        center_index++;
        left_index = center_index-1;
        right_index = center_index+1;

        if (right_index == IMAGES_COUNT){
            right_index = 0;
        }
        if (center_index == IMAGES_COUNT){
            right_index = 1;
            center_index = 0;
            left_index = 10;
        }
        viewImages();
    });

    viewImages();
});


function viewImages() {
    $('#left_img').attr('src', images[left_index]);
    $('#center_img').attr('src', images[center_index]);
    $('#right_img').attr('src', images[right_index]);
}
