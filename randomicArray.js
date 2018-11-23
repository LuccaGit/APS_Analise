const randomArray = (qtde) => {
	var array = []
	for (i = 0; i < qtde; i++) {
		array.push((Math.floor( Math.random() * 2)) ?
			(Math.floor(Math.random() * qtde) + 1) :
			(Math.floor(Math.random() * qtde) * (-1))
		);
	}
	return array;
}

const getArrayString = (array, ind) => {
	var arrayString = '';
	var len = array.length;
	for (i = 0; i < len; i++) {
		arrayString = ( i + 1 < len) ?
			arrayString.concat(parseInt(array[i]) + ' ') :
			arrayString.concat(parseInt(array[i]));
	}
	return arrayString;
}

if (process.argv.length > 2)
	var array = randomArray(parseInt(process.argv[2]))
	console.log(getArrayString(array, 0))
