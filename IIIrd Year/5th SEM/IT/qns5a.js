const a1=document.querySelector('#color1');
const a2=document.querySelector('#color2');
const a3=document.querySelector('#color3');
const a4=document.querySelector('#num1');
const a5=document.querySelector('#num2');
const a6=document.querySelector('#num3');
const a7=document.querySelector('#font1');
const a8=document.querySelector('#font2');
const a9=document.querySelector('#font3');

a1.addEventListener('click',function(){
    document.querySelector('p').style.color='red';
})

a2.addEventListener('click',function(){
    document.querySelector('p').style.color='green';
})

a3.addEventListener('click',function(){
    document.querySelector('p').style.color='blue';
})


a4.addEventListener('click',function(){
    document.querySelector('p').style.fontSize='10px';
})

a5.addEventListener('click',function(){
    document.querySelector('p').style.fontSize='20px';
})

a6.addEventListener('click',function(){
    document.querySelector('p').style.fontSize='30px';
})

a7.addEventListener('click',function(){
    document.querySelector('p').style.fontFamily='arial' ;
})

a8.addEventListener('click',function(){
    document.querySelector('p').style.fontFamily='cursive';
})

a9.addEventListener('click',function(){
    document.querySelector('p').style.fontFamily='italics'
    ;
})