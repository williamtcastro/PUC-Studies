int int1 = 10;
int int2 = 11;
int int2 = 12;
int int3 = 13;
int btn = 9;
int count = 0;

void setup() {

  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  if(digitalRead(btn) == HIGH){
    count++;
  }
  int modulos = count % 2;
  
  if(modulos == 0){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }else if(modulos == 1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  } else if(modulos == 2){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  } else if(modulos == 3){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  } 
}
