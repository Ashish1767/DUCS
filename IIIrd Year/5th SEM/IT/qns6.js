 function petfunc(){
    
 var pet={
    name:document.getElementById('petname').value,
    age:document.getElementById('petage').value,
    weight:document.getElementById('petweight').value,
    type:document.getElementById('pettype').value,
    breed:document.getElementById('petbreed').value,
    likes:document.getElementById('petlikes').value,
   

        };
        console.log(pet);
        console.log(JSON.stringify(pet));
         }
        