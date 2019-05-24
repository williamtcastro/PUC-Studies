//ARQUIVO PARA LEITURA DE DADOS
//DATA 10/05/2019
//GRUPO - WILLIAM DE CASTRO | RODRIGO BRITEZ |WILLIAN AUGUSTO 

// function login(username, passwd) {
$('#loginForm').submit(function () {
    var username, passwd;
    username = $('#username_input').val();
    passwd = $('#passwd_input').val();
    getData(function(data){
        var users = data.users;
        var user_id;
        for(key in users){
            if((username == users[key].info.username) && (MD5(passwd) == users[key].info.passwd)){
                user_id = users[key].info.user_id;
                user_id= user_id.replace("U_", "");
                localStorage.setItem("logged", 1);
                changePage("main.html", user_id);
            }
        }
    });
    return false;
});

$('#logoff').click(function(){
    changePage("index.html", null);
});

function userData() {
    var user_d, user_id;
    user_d = window.localStorage.getItem("user");
    user_d = JSON.parse(user_d);
    user_id = user_d.id;
    user_id = parseInt(user_id, 10);
    getData(function(data){
        var user_d = data.users[user_id];
        var info = user_d.info;
        var name = info.name;
        // var username = info.username;
        $('#name').html(name);
    });
}

function patientListing() {
    var user_d, user_id;
    user_d = window.localStorage.getItem("user");
    user_d = JSON.parse(user_d);
    user_id = user_d.id;
    user_id = parseInt(user_id, 10);
    getData(function(data){
        var user_d, patients;
        user_d = data.users[user_id];
        patients = user_d.patients;
        Object.keys(patients).forEach(function(value){ // as weel as key
            var patient, patient_id, li, name, set_function, set_function2;
            patient_id = patients[value].id;
            patient_id = patient_id.replace("P_", "");
            getData(function(data){
                patient = data.patients[patient_id].info;
                name = patient.name;
            });
            li = document.createElement("li");
            if ( $('#listing-patients').length != 0) {    
                set_function = "changePage('patientprofile.html',"+patient_id+")";
                set_function2 = "changePage('patientprofile.html',"+patient_id+")";
                li.className = "list-group-item text-bold";
                li.innerHTML = name+'<button class="pull-right btn-sm" onclick="'+set_function2+'">Adicionar Visita</button><button class="pull-right btn-sm" onclick="'+set_function+'">Ver Visitas</button>';
                li.id = patient_id;
                document.getElementById('listing-patients').appendChild(li);
            }else{
                set_function = "changePage('patientprofile.html',"+patient_id+")";
                set_function2 = "changePage('patientprofile.html',"+patient_id+")";
                li.className = "list-group-item text-bold";
                li.innerHTML = name+'<button class="pull-right btn-sm" onclick="'+set_function2+'">Adicionar Visita</button><button class="pull-right btn-sm" onclick="'+set_function+'">Ver Paciente</button>';
                li.id = patient_id;
                document.getElementById('listing-patients-user').appendChild(li);
            }
        });
    });
}

function patientData(){
    var patient_id = window.localStorage.getItem("patient");
    patient_id = JSON.parse(patient_id);
    patient_id = patient_id.p;
    getData(function(data){
        var patient = data.patients[patient_id].info;
        $('#patient_name').html(patient.name);
        var p_id = patient.patient_id.replace("P_", "");
        $('#patient_id').val(p_id);
        $('#patient_gender').val(patient.gender);
        $('#patient_birth').val(patient.birth);
        $('#patient_email').val(patient.email);
        $('#patient_phone').val(patient.phone);
        $('#patient_address').val(patient.address);

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