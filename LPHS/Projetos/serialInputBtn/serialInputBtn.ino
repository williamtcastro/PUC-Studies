int led1 = 10;
int led2 = 11;
int btn = 9;

void setup() {

  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  if(digitalRead(btn) == HIGH){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }

  if(digitalRead(btn) == LOW){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  } 
}
