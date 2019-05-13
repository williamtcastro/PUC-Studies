//ARQUIVO PARA INSERCAO DE DADOS
//DATA 10/05/2019
//GRUPO - WILLIAM DE CASTRO | RODRIGO BRITEZ |WILLIAN AUGUSTO 

$('#registerForm').submit(function () {
// function registerUser(username, passwd, name) {
    var username, passwd, name;
    username = $('#username_input').val();
    passwd = $('#passwd_input').val();
    name = $('#name_input').val();
    getData(function(data){
        var f_data, users, f_users, n_data, n_id=0;
        for(let i=0; data.users[i] != undefined; i++){
            n_id++;
        }
        n_data = { n_id :{
            "info": {
              "username" : username,
              "passwd" : MD5(passwd),
              "name" : name,
              "birth" : "",
              "user_id" : "U_"+n_id
            },
            "patients": []
        }}
        n_data = idfyString(n_data, n_id);
        f_data = Object.assign(n_data, data.users);
        users = {"users": f_data};
        f_users = $.extend(data, users);
        localStorage.setItem("sistem", JSON.stringify(f_users));
    });
// }
    return false;
});

function createPatient(user_id,  patient_name, patient_gender, patient_birth) {
    user_id = parseInt(user_id, 10);
    getData(function(data){
        var f_data, patients, f_patients, n_data, n_id=0;
        for(let i=0; data.patients[i] != undefined; i++){
            n_id++;
        }
        n_data = { n_id : {
            "info": {
              "name" : patient_name,
              "birth" : patient_birth,
              "gender" : patient_gender,
              "patient_id" : "P_"+ n_id
            },
            "visit_history": []
          }}
        n_data = idfyString(n_data, n_id);
        f_data = Object.assign(n_data, data.patients);
        patients = {"patients": f_data};
        f_patients = $.extend(data, patients);
        localStorage.setItem("sistem", JSON.stringify(f_patients));
        addPatientToUser(user_id, n_id);
    });
}

function addPatientToUser(user_id, patient_id) {
    var f_data, patients, f_patients, n_data, user, f_user, users;
    user_id = parseInt(user_id, 10);
    patient_id = parseInt(patient_id, 10);
    getData(function(data){
        user = data.users[user_id];
        users = data.users;
        n_data = { n_id : {"id" : "P_"+patient_id}};
        n_data = idfyString(n_data, patient_id);
        f_data = Object.assign(n_data, data.users[user_id].patients);
        patients = {"patients": f_data};
        f_patients = $.extend(user, patients);
        f_user = { n_id : f_patients}
        f_user = idfyString(f_user, user_id);
        f_users = $.extend(users, f_user);
        f_data = {"users": f_users};
        f_data = $.extend(data, f_data);
        localStorage.setItem("sistem", JSON.stringify(f_data));
    });
}

function createPatientHistory(patient_id) {
    var f_data, patients_history, f_patients_history, n_data, n_id = 0;
    getData(function(data){
        for(let i=0; data.patient_history[i] != undefined; i++){
            n_id++;
        }
        n_data = {
            n_id : {
                "patient_id" : "P_" + patient_id,
                "patient_temperature" : "12",
                "patient_status" : "STATUS",
            }
        }
        n_data = idfyString(n_data, n_id);
        f_data = Object.assign(n_data, data.patient_history);
        patients_history = {"patient_history": f_data};
        f_patients_history = $.extend(data, patients_history);
        localStorage.setItem("sistem", JSON.stringify(f_patients_history));
        addHistoryToPatient(patient_id, n_id);
    });
}

function addHistoryToPatient(patient_id, patient_history_id){
    var f_data, patient, f_patient, n_data;
    getData(function(data){
        n_data = { n_id : {"history_id" : "H_"+patient_history_id}};
        n_data = idfyString(n_data, patient_history_id);
        f_data = Object.assign(n_data, data.patients[patient_id].visit_history);
        patients_history = {"visit_history": f_data};
        patient = data.patients[patient_id];
        // f_patient = { n_id : { }}
        f_patients_history = $.extend(patient, patients_history);
        f_patient = { n_id : f_patients_history };
        f_patient = idfyString(f_patient, patient_id);
        f_patients_history = $.extend(data.patients, f_patient);
        f_patients_history = {"patients": f_patients_history};
        f_patients_history = $.extend(data, f_patients_history);
        localStorage.setItem("sistem", JSON.stringify(f_patients_history));
    });
}