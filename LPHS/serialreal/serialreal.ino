int decisao = 0;
int led1 = 2;
int led2 = 3;
int led3 = 10;
int delaytime = 1000;

void setup() {
  Serial.begin(9600);
  Serial.print("BEM VINDO AO PROGRAMA\n1- Ligar leds individuais\n2- Modificar o tempo de delay");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available()) {
    decisao = Serial.read();
    Serial.print(decisao);
    if (decisao == 0) {
      Serial.print("Change Led");
      changeLED();
    }else if(decisao == 5010) {
      Serial.print("Change delay");
      changeDelay();
    }
  }
}

void changeLED(){
  Serial.print("FOI");
  if (Serial.available()) {
    int comando = Serial.read();
    if (comando == 0) {
      Serial.print("\nNenhum Led Acionado");
    }else if (comando ==  1) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }else if (comando ==  2) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }else if (comando ==  3) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
  } 
}

void changeDelay(){
  if (Serial.available()) {
    int comando = Serial.read();
    if (comando == 1) {
      delaytime = delaytime + 500;
    }else if (comando ==  2) {
      delaytime = delaytime - 500;
    }else if (comando == 0){
      Serial.print("\nTempo resetado!!!");
      delaytime = 1000;
      }
   }
}