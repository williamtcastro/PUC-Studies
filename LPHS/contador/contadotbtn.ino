#define verde 4
#define amarelo 3
#define vermelho 2
#define btn 8

void setup() {
    const int now;
    Serial.begin(9600);
    pinMode(verde, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(vermelho, OUTPUT);
    pinMode(btn, INPUT);
}

void loop() {
    int valor = digitalRead(btn);
    contagem(valor);
}

void contagemAdd(int valor){
    if(valor == HIGH){
        now++;
    }
}

void contagem(int valor){
    if(valor == HIGH){
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, LOW);
        delay(1000);
        Serial.print(2);
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, HIGH);
        delay(1000);
        Serial.print(3);
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, HIGH);
        digitalWrite(vermelho, LOW);
        delay(1000);
        Serial.print(4);
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, HIGH);
        digitalWrite(vermelho, HIGH);
        delay(1000);
        Serial.print(5);
        digitalWrite(verde, HIGH);
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, LOW);
        delay(1000);
        digitalWrite(verde, HIGH);
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, HIGH);
        delay(1000);
        digitalWrite(verde, HIGH);
        digitalWrite(amarelo, HIGH);
        digitalWrite(vermelho, LOW);
        delay(1000);
        digitalWrite(verde, HIGH);
        digitalWrite(amarelo, HIGH);
        digitalWrite(vermelho, HIGH);
        delay(1000);
    }
}