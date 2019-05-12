int modulos;
int a = 6;
int count = 1;
int b = 9;
int c = 10;
int d = 11;
int divisor = 4;
int speed = 500;
char cmd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < count; i++){
    count++;
    if (Serial.available()) {
      cmd = Serial.read();

      if (cmd == '+') {
        speed = speed - 10;
      }
      if (cmd == '-') {
        speed = speed + 10;
      }
      if (cmd == '=') {
        speed = 500;
      }
      if (cmd == 'F') {
        speed = 50;
      }
      if (cmd == 'L') {
        speed = 1000;
      }
      Serial.println(speed);
    }

    modulos = i % divisor;
//    Serial.println(modulos);

    switch (modulos){
      case 0:
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        delay(speed);
        break;
    
      case 1:
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        delay(speed);
        break;

      case 2:
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, HIGH);
        digitalWrite(d, LOW);
        delay(speed);
        break;

      case 3:
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, HIGH);
        delay(speed);
        break;
    }

  }
  
}
