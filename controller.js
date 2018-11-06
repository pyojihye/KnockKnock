(document).ready(function() {
	var tempsArray = [];
	var tArray = [];
	var sessionArray = [];
	var currTemp = '';

	var dataRef = new Firebase('https://smartfrontdoor-50046.firebaseio.com/');
	dataRef.on('value', function(snapshot) {
		var t = snapshot.val();
		var count = 0;

		for (var key in t) {
		  if (t.hasOwnProperty(key)) {		    
		    var dt = [];	    
		    dt[0] = count;
		    dt[1] = parseFloat(t[key]);
		    tempsArray = [];
		    tempsArray.push(dt);
		    tArray = [];
		    tArray.push(dt[1]);
		    count++;
		  }
		}
		sessionArray.push(tempsArray[0])
		//console.log(tempsArray)
		$.plot($("#chart1"), [ sessionArray ]);
		currTemp = tempsArray[0][1].toString();
		$('#tempMsg').show();
		$("#currTemp").text(currTemp);
	});			
});