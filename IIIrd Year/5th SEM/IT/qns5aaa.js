//var red=document.getElementById("red").id;
var colour=$(".colour")
colour.on('click',changeColor);

var fontSize=$(".fSize");
fontSize.on("click",changeFont);

var fontStyle=$(".fStyle");
fontStyle.on("click",changeFontStyle);

function changeColor(e){
    var col=e.target.id;
    if(col=="red")
    document.getElementById("para").style.color="red";
    else if(col=="green")
    document.getElementById("para").style.color="green";
    else if(col=="blue")
    document.getElementById("para").style.color="blue";
}

function changeFont(e){
    
    var fontS=e.target.id;
    if(fontS=="10")
    document.getElementById("para").style.fontSize=10+"px";
    else if(fontS=="20")
    document.getElementById("para").style.fontSize=20+"px";
    else if(fontS=="30")
    document.getElementById("para").style.fontSize=30+"px";
}

function changeFontStyle(e){
    var fontStyle=e.target.id;
    
    if(fontStyle=="arial")
    document.getElementById("para").style.fontFamily="arial";
    else if(fontStyle=="helvetica")
    document.getElementById("para").style.fontFamily="helvetica";
    else if(fontStyle=="cursive")
    document.getElementById("para").style.fontFamily="cursive";
}
