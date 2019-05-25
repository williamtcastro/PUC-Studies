//ARQUIVO PARA INSERCAO DE DADOS
//DATA 10/05/2019
//GRUPO - WILLIAM DE CASTRO | RODRIGO BRITEZ |WILLIAN AUGUSTO 

$('#seeHistory').click(function(){
    var id = $('#seeHistory').val();
    changePage("history.html", id);
});


$('#registerForm').submit(function () {
    var username, passwd, name, birth, passwd_confirm;
    username = $('#username_input').val();
    passwd = $('#passwd_input').val();
    email = $('#email_input').val();
    name = $('#name_input').val();
    birth = $('#birth_date').val();
    passwd_confirm = $('#passwd_input_confirm').val();
    if(MD5(passwd) === MD5(passwd_confirm)){
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
                  "email" : email,
                  "birth" : birth,
                  "user_id" : "U_"+n_id
                },
                "patients": []
            }}
            n_data = idfyString(n_data, n_id);
            f_data = Object.assign(n_data, data.users);
            users = {"users": f_data};
            f_users = $.extend(data, users);
            // ENCRYPTED VERSION
            f_users = encryptToSave(f_users);
            localStorage.setItem("sistem", f_users);
            localStorage.setItem("logged", 1);
            // localStorage.setItem("sistem", JSON.stringify(f_users));
            // localStorage.setItem("logged", 1);
            changePage("main.html", n_id);
        });
    }else{
        alert("Senhas não correspondem");
    }
    return false;
});

$('#newPatientForm').submit(function(){
    var patient_name, patient_phone, patient_email, patient_birth, patient_address, patient_gender;
    patient_name = $('#patient_name').val();
    patient_phone = $('#patient_phone').val();
    patient_email = $('#patient_email').val();
    patient_birth = $('#patient_birth').val();
    patient_address = $('#patient_address').val();
    patient_gender = $('#patient_gender').val();
    var user, user_id;
    user = window.localStorage.getItem("user");
    user = JSON.parse(user);
    user_id = user.id;
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
              "phone" : patient_phone,
              "address" : patient_address,
              "email" : patient_email,
              "patient_id" : "P_"+ n_id
            },
            "visit_history": []
          }}
        n_data = idfyString(n_data, n_id);
        f_data = Object.assign(n_data, data.patients);
        patients = {"patients": f_data};
        f_patients = $.extend(data, patients);
        // ENCRYPTED VERSION
        f_patients = encryptToSave(f_patients);
        localStorage.setItem("sistem", f_patients);
        // localStorage.setItem("sistem", JSON.stringify(f_patients));
        addPatientToUser(user_id, n_id);
    });
    return false;
});

$('#newPatient').click(function(){
    var user;
    user = window.localStorage.getItem("user");
    user = JSON.parse(user);
    user = user.id;
    changePage("newpatients.html", user);
});

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
        // ENCRYPTED VERSION
        f_data = encryptToSave(f_data);
        localStorage.setItem("sistem", f_data);
        // localStorage.setItem("sistem", JSON.stringify(f_data));
        changePage("patients.html", user_id);
    });
}

$('#newHistoryForm').submit(function(){
// function createPatientHistory() {
    var patient_id = window.localStorage.getItem("patient");
    patient_id = JSON.parse(patient_id);
    patient_id = patient_id.p;
    var patient_temperature, patient_state, patient_inflamation, patient_fever, patient_visit_date, patient_visit_obs, patient_motif;
    patient_motif = $('#patient_motif').val();
    patient_temperature = $('#patient_temp').val();
    patient_state = $('#patient_state').val();
    patient_inflamation = $('#patient_inflamation').val();
    patient_fever = $('#patient_fever').val();
    patient_visit_date = $('#patient_visit_date').val();
    patient_visit_obs = $('#patient_visit_obs').val();

    var f_data, patients_history, f_patients_history, n_data, n_id = 0;
    getData(function(data){
        for(let i=0; data.patient_history[i] != undefined; i++){
            n_id++;
        }
        n_data = {
            n_id : {
                "patient_id" : "P_" + patient_id,
                "motif" : patient_motif,
                "temperature" : patient_temperature,
                "state" : patient_state,
                "inflamation" : patient_inflamation,
                "fever" : patient_fever,
                "date" : patient_visit_date,
                "obs" : patient_visit_obs
            }
        }
        n_data = idfyString(n_data, n_id);
        f_data = Object.assign(n_data, data.patient_history);
        patients_history = {"patient_history": f_data};
        f_patients_history = $.extend(data, patients_history);
        // ENCRYPTED VERSION
        f_patients_history = encryptToSave(f_patients_history);
        localStorage.setItem("sistem", f_patients_history);
        // localStorage.setItem("sistem", JSON.stringify(f_patients_history));
        addHistoryToPatient(patient_id, n_id);
    }); 
    return false;
});

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
        // ENCRYPTED VERSION
        f_patients_history = encryptToSave(f_patients_history);
        localStorage.setItem("sistem", f_patients_history);
        // localStorage.setItem("sistem", JSON.stringify(f_patients_history));
    });
    changePage("historydetail.html", patient_history_id);
}