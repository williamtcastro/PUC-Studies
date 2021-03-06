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
            if((username.toLowerCase() == users[key].info.username) && (MD5(passwd) == users[key].info.passwd)){
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

$('#newHistory').click(function(){
    var id = window.localStorage.getItem("patient");
    id = JSON.parse(id);
    changePage("newhistory.html", id.p);
})

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
        $('#user_id').val(user_id);
        $('#username').val(info.username);
        $('#user_birth').val(info.birth);
        $('#user_email').val(info.email);
        $('#user_phone').val(info.phone);
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
        if(patients.length != 0){
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
                    set_function = "changePage('history.html',"+patient_id+")";
                    set_function2 = "changePage('newhistory.html',"+patient_id+")";
                    set_function3 = "changePage('patientprofile.html',"+patient_id+")";
                    li.className = "list-group-item text-bold";
                    li.innerHTML = name+'<button class="pull-right btn-sm" onclick="'+set_function2+'">Adicionar Visita</button><button class="pull-right btn-sm" onclick="'+set_function+'">Ver Visitas</button><button class="pull-right btn-sm" onclick="'+set_function3+'">Ver Paciente</button>';
                    li.id = patient_id;
                    document.getElementById('listing-patients').appendChild(li);
                }else{
                    set_function = "changePage('patientprofile.html',"+patient_id+")";
                    set_function2 = "changePage('newhistory.html',"+patient_id+")";
                    set_function3 = "changePage('history.html',"+patient_id+")";
                    li.className = "list-group-item text-bold";
                    li.innerHTML = name+'<button class="pull-right btn-sm" onclick="'+set_function2+'">Adicionar Visita</button><button class="pull-right btn-sm" onclick="'+set_function+'">Ver Paciente</button><button class="pull-right btn-sm" onclick="'+set_function3+'">Ver Visitas</button>';
                    li.id = patient_id;
                    document.getElementById('listing-patients-user').appendChild(li);
                }
            });
        }else{
            if($('#listing-patients').length !=0){
                var li = document.createElement("li");
                li.className = "list-group-item text-bold";
                li.innerHTML = "Não possui pacientes cadastrados";
                document.getElementById('listing-patients').appendChild(li);
            }else{
                var li = document.createElement("li");
                li.className = "list-group-item text-bold";
                li.innerHTML = "Não possui pacientes cadastrados";
                document.getElementById('listing-patients-user').appendChild(li);
            }
        }
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
        $('#patient_document').val(patient.document);
        $('#patient_birth').val(patient.birth);
        $('#patient_email').val(patient.email);
        $('#patient_phone').val(patient.phone);
        $('#patient_address').val(patient.address);
        $('#seeHistory').val(p_id);


    });
}

function patientHistory() {
    var patient_id = window.localStorage.getItem("patient");
    patient_id = JSON.parse(patient_id);
    patient_id = patient_id.p;
    getData(function(data){
        console.log(data);
        var patient = data.patients[patient_id];
        console.log(patient);
        $('#name').html(patient.info.name);
        var history = patient.visit_history;
        if(history.length == 0){
            var li = document.createElement("li");
            li.className = "list-group-item text-bold";
            li.innerHTML = "Não possui visitas anteriores";
            document.getElementById('listing-history').appendChild(li);
            console.log(li);
        }else{
            Object.keys(history).forEach(function(value){
                console.log(value);
                var h_item, set_function, li;
                h_item = history[value].history_id;
                h_item = h_item.replace("H_", "");
                li = document.createElement("li");
                set_function = "changePage('historydetail.html',"+h_item+")";
                li.className = "list-group-item text-bold";
                li.innerHTML = "Visita: "+h_item+'<button class="pull-right btn-sm" onclick="'+set_function+'">Ver Visitas</button>';
                li.id = h_item;
                document.getElementById('listing-history').appendChild(li);
            });
        }
        
    });
}

function patientHistoryData() {
    var patient = localStorage.getItem("patient");
    patient = JSON.parse(patient);
    var history_id = window.localStorage.getItem("history");
    history_id = JSON.parse(history_id);
    history_id = history_id.h;
    getData(function(data){
        var history = data.patient_history[history_id];
        console.log(data)
        $('#history_id').val(history_id);
        $('#history_motif').val(history.motif);
        $('#history_date').val(history.date);
        $('#history_temp').val(history.temperature +" *C");
        $('#history_state').val(history.state);
        $('#history_inflamation').val(history.inflamation);
        $('#history_fever').val(history.fever);
        $('#history_obs').val(history.obs);
        $('#patient_name').html(data.patients[patient.p].info.name);
    });
}

function newPatientHistory() {
    var patient_id = window.localStorage.getItem("patient");
    patient_id = JSON.parse(patient_id);
    patient_id = patient_id.p;
    console.log(patient_id)
    getData(function(data){
        var name = data.patients[patient_id].info.name;
        $('#patient_name').html("Paciente: " +name);
    });
}