function p() 
{
	n = document.getElementById('name').value;
	a = document.getElementById('age').value;
	w = document.getElementById('weight').value;
	t = document.getElementById('type').value;
	wil = document.getElementById('wil').value;

	var Pet = {
		name : n,
		age : a,
		type : t,
		weight : w,
		likes : wil
	};

	console.log(Pet);
	console.log(JSON.stringify(Pet));
}