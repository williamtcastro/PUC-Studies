int led1 = 10;
int led2 = 11;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {

  if (Serial.available()) {

    int a = Serial.read();

    if (a == '1') {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      Serial.println("LED 1 LIGADO | LED 2 DESLIGADO!\n");
    }

    if (a == '0') {
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
      Serial.println("LED 1 DESLIGADO | LED 2 LIGADO!\n");
    }
  }
  
  // put your main code here, to run repeatedly:

}
