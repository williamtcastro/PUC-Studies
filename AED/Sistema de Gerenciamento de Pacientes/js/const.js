function getData(handleData){
    $.getJSON('/data/data.json', function(data){
        handleData(data);
    }); 
}

getData(function(data){    
});