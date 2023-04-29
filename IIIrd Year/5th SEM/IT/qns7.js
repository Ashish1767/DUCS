var xhr= new XMLHttpRequest();
xhr.onload=function()
{
   if(xhr.status===200)
   {
   var responseObject=JSON.parse(xhr.responseText);
   var newContent = ''; 
   t=1;
for (var i = 0; i < responseObject.pets.length; i++)
 { 
   varc="p"+t;
    newContent= '<p style:"display:inline">';
    newContent += '<img src=" ' + responseObject.pets[i] .img +' "'; 
    newContent += 'alt="' + responseObject.pets[i] .type + '"/>' ; 
    newContent+= '<p><b>' + responseObject .pets[i] .type+ '</b><br>'; 
    newContent += '</div>'; 
    document.getElementById(varc).innerHTML=newContent ; 
    t++;


  }

    }
}

xhr.open('GET','qns7.json',true);
xhr.send(null);



function printData(Passed){
    var xhr= new XMLHttpRequest();
       xhr.onload=function(){
         if(xhr.status===200){
            var responseObject=JSON.parse(xhr.responseText);
            var newCont = ''; 
            newCont += '<p style:"display:inline">'; 
            newCont+='<p><b>'+ responseObject .pets[Passed] .img+ '</b><br>'; 
            newCont+='<p><b>'+"name:"+ responseObject .pets[Passed] .name+ '</b><br>'; 
            newCont+= '<p><b>'+"age:" + responseObject .pets[Passed] .age+ '</b><br>';
            newCont+= '<p><b>'+"breed:" + responseObject .pets[Passed] .breed+ '</b><br>';
            newCont+= '<p><b>' +"weight:"+ responseObject .pets[Passed] .weight+ '</b><br>';
            newCont+= '<p><b>' +"things liked:"+ responseObject .pets[Passed] .likes+ '</b><br>';
            newCont += '</div>'; 

  document.getElementById('right').innerHTML=newCont ;
   
   } 
}

   xhr.open('GET','qns7.json',true);
   xhr.send(null);
}

  
  $(".btn1").on('click', function () {
   $(".btn").css;
   $(".btn1").html("showing")
   $(".btn2").html("show details")
   $(".btn3").html("show details")
   $(".btn4").html("show details")
   printData(0)
})


$(".btn2").on('click', function () {

   $(".btn2").html("showing")
   $(".btn1").html("show details")
   $(".btn3").html("show details")
   $(".btn4").html("show details")
   printData(1)
});
$(".btn3").on('click', function () {

   $(".btn3").html("showing")
   $(".btn1").html("show details")
   $(".btn2").html("show details")
   $(".btn4").html("show details")

   printData(2)
   });

   $(".btn4").on('click', function () {

      $(".btn4").html("showing")
      $(".btn1").html("show details")
      $(".btn2").html("show details")
      $(".btn3").html("show details")
      
   
      printData(3)
      });
      

   
