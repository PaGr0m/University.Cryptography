function fields(form)
{
    var labels = form.getElementsByTagName('label');
    var resBlock = document.createElement('label');
    resBlock.className = "results";

    for (var i = 0; i < labels.length; i++)
        resBlock.innerHTML += '<br>' + labels[i].firstElementChild.value ;
    document.body.appendChild(resBlock);
    event.preventDefault();
}