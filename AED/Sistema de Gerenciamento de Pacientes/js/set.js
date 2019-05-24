function changePage(direction, id) {
    switch (direction) {

        case "main.html":
            var p_data = undefined;
            window.localStorage.setItem("patient", JSON.stringify(p_data));
            var u_data = { "id" : id};
            window.localStorage.setItem("user", JSON.stringify(u_data));
            window.location.href = direction; 
            break;
    
        case "index.html":
            var p_data = undefined;
            window.localStorage.setItem("patient", p_data);
            window.localStorage.setItem("logged", 0);
            window.location.replace(direction); 
            break;
        
        case "newpatients.html":
            var p_data = undefined;
            window.localStorage.setItem("patient", p_data);
            window.location.href = direction; 
            break;

        case "patients.html":
            var p_data = undefined;
            window.localStorage.setItem("patient", p_data);
            window.location.href = direction; 
            break;
        
        case "patientprofile.html":
            var p_data = { "p" : id};
            window.localStorage.setItem("patient", JSON.stringify(p_data));
            window.location.href = direction;
            break;

        case "history.html":
            var p_data = { "p" : id};
            window.localStorage.setItem("patient", JSON.stringify(p_data));
            window.location.href = direction;
            break;

        case "newhistory.html":
            var p_data = { "p" : id};
            window.localStorage.setItem("patient", JSON.stringify(p_data));
            window.location.href = direction;
            break;
    
        default:
        alert("NOP");
            break;
    }
}

function mainPage(){
    var logged = window.localStorage.getItem("logged");
    if(logged == 1){
        userData();
        patientListing();
    }else{
        changePage("index.html", null);
    }
}

function patientProfile(){
    var logged = window.localStorage.getItem("logged");
    if(logged == 1){
        patientData();
    }else{
        changePage("index.html", null);
    }
}

function userProfile(){
    var logged = window.localStorage.getItem("logged");
    if(logged == 1){
        userData();
    }else{
        changePage("index.html", null);
    }
}

function verify(){
    var logged = window.localStorage.getItem("logged");
    if(logged != 1){
        changePage("index.html", null);
    }
}

function patientHistory(){
    var logged = window.localStorage.getItem("logged");
    if(logged == 1){
        patientHistory();
    }else{
        changePage("index.html", null);
    }
}