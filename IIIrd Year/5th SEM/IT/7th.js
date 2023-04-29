 var x = new XMLHttpRequest();

x.onload = function () {
    if (x.status === 200) {
        t = 1
        responseObject = JSON.parse(x.responseText);
        console.log(responseObject)
        var newContent = '';
        for (var i = 0; i < responseObject.Pets.length; i++) {
            varC = "p" + t
            newContent = '<p style:"display:inline">' + '<img style ="width:80px;height:70px;border-radius:20px;margin-top:20px" src=' + responseObject.Pets[i].Image + '</img>' + '&nbsp&nbsp&nbsp&nbsp' + responseObject.Pets[i].name + '&nbsp:&nbsp' + responseObject.Pets[i].type + '<p>';
            document.getElementById(varC).innerHTML = newContent;
            // console.log(varC)
            t++;
        }


    }
}

x.open('GET', '7th.JSON', true);
x.send(null);




function printData(passed) {
    var x = new XMLHttpRequest();

    x.onload = function () {
        if (x.status === 200) {
            rObj = JSON.parse(x.responseText);

            var nstr = '';

            nstr += '<img style ="width:90px;height:90px;border-radius:20px;margin-top:20px;display:block;margin-left:auto;margin-right:auto" src=' + responseObject.Pets[passed].Image + '</img>' + '<p>' + "Name : " + responseObject.Pets[passed].name + '</p>' + '<p>' + "Age : " + responseObject.Pets[passed].age + '</p>' + '<p>' + "Weight : " + responseObject.Pets[passed].weight + '</p>' + '<p>' + "Type : " + responseObject.Pets[passed].type + '</p>' + '<p>' + "Likes : " + responseObject.Pets[passed].likes + '</p>';

            document.getElementById('right').innerHTML = nstr;
        }
    };

    x.open('GET', '7th.json', true);
    x.send(null);

}



$("#btn").on('click', function () {

    $("#right").css("border", "2px solid black")
    $("#right").css("padding", "30px")
    $("#right").css("background-color", "darkgrey")
    $(".data").css("visibility", "hidden")
    $("#right").css("width", "250px")
    $("#right").css("text-align", "center")
    $("#right").css("border-radius", "20px")
})
$(".btn1").on('click', function () {

    $(".btn1").html("Clicked")
    $(".btn2").html("Click to show full information")
    $(".btn3").html("Click to show full information")

    printData(0)
    const audio1 = new Audio("dog.mp3");
    const audio2 = new Audio("cat.mp3");
    const audio3 = new Audio("rabbit.mp3");
    audio2.pause();
    audio3.pause();
    audio1.play();


});

$(".btn2").on('click', function () {
    
    $(".btn2").html("Clicked")
    $(".btn1").html("Click to show full information")
    $(".btn3").html("Click to show full information")

    printData(1)
    const audio1 = new Audio("dog.mp3");
    const audio2 = new Audio("cat.mp3");
    const audio3 = new Audio("rabbit.mp3");
    audio1.pause();
    audio3.pause();
    audio2.play();
});
$(".btn3").on('click', function () {

    $(".btn3").html("Clicked")
    $(".btn1").html("Click to show full information")
    $(".btn2").html("Click to show full information")

    printData(2)
    const audio1 = new Audio("dog.mp3");
    const audio2 = new Audio("cat.mp3");
    const audio3 = new Audio("rabbit.mp3");
    audio2.pause();
    audio1.pause();
    audio3.play();
});