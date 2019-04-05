#define verde 2
#define amarelo 3
#define vermelho 4

int number[]={0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1};

void setup() {
  Serial.begin(9600);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);

}

void loop() {
  for(int i=0; i<=7; i++){
    count(i);
  }
  delay(1000);
}

void count(int i){
  int valor = i;
  int valVer = i;
  int valAma = i*2;
  int valVerm = i*3;
  bool valorFinalVer = valor[valVer];
  bool valorFinalAma = valor[valAma];
  bool valorFinalVerm = valor[valVerm];


  if(i == 0){
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
  }else{
    digitalWrite(verde, valorFinalVer);
    digitalWrite(verde, valorFinalAma);
    digitalWrite(verde, valorFinalVerm);
  }
}