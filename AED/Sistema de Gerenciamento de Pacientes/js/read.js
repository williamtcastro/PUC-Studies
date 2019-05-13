//ARQUIVO PARA LEITURA DE DADOS
//DATA 10/05/2019
//GRUPO - WILLIAM DE CASTRO | RODRIGO BRITEZ |WILLIAN AUGUSTO 

function login(username, passwd) {
    getData(function(data){
        var users = data.users;
        var user_id;
        for(key in users){
            if((username == users[key].info.username) && (MD5(passwd) == users[key].info.passwd)){
                user_id = users[key].info.user_id;
                user_id= user_id.replace("U_", "");
                console.log("LOGADO");
                userData(user_id);
            }
        }
    });
}

function logoff(){
}

function userData(user_id) { 
    user_id = parseInt(user_id, 10);
    getData(function(data){
        var user = data.users[user_id];
        var info = user.info;
        var name = info.name;
        var birth = info.birth;
        var username = info.username;
        // window.location.href="http://java67.blogspot.com"; 
    });
}

function patientListing(user_id) {
    user_id = parseInt(user_id, 10);
    getData(function(data){
        var user = data.users[user_id];
        var patients = user.patients;
        patients.forEach(function(value){ // as weel as key
            var patient = value.id;
            patient = patient.replace("P_", "");
            console.log(patient);
        });
    });
}

function patientData(patient_id){
    patient_id = parseInt(patient_id, 10);
    getData(function(data){
        var patient = data.patients[patient_id].info;
        var name = patient.name;
        var birth = patient.birth;
        console.log(name);
    });
}

function patientHistory(patient_id) {
    patient_id = parseInt(patient_id, 10);
    getData(function(data){
        var patient = data.patients[patient_id];
        var history = patient.visit_history;
        history.forEach(function(value){
            var h_item = value.history_id;
            h_item = h_item.replace("H_", " ");
            console.log(h_item);
            //HANDLE THE INTEMS IN PATIENTS
        });
    });
}

function patientHistoryData(history_id) {
    history_id = parseInt(history_id, 10);
    getData(function(data){
        var history = data.patient_history[history_id];
        var patient_id = history.patient_id;
        var patient_temp = history.patient_temperature;
    });
}

//FUNCAO IDENTICA A PATIENT LISTING
// function userPatients(user_id) {
//     user_id = parseInt(user_id, 10);
//     getData(function(data){
//         var user = data.users[user_id];
//         var patients = user.patients;
//        patients.forEach(function(value){
//             var p_item = value.id;
//             p_item = p_item.replace("P_", "");
//             console.log(p_item);
//             //HANDLE THE INTEMS IN PATIENTS
//         });
//     });
// }