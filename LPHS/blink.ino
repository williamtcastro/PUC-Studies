// A definicao da funcao deve ter tipo_retorno nome_funcao(argumentos){conteudo}
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

//funcao que fica em loop eterno
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}