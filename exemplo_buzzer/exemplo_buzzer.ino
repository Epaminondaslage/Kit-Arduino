const int pinoBuzzer = 2; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO

void setup() {
pinMode(pinoBuzzer, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
}
void loop() {
 tone(pinoBuzzer,1500,800); //ACIONA O BUZZER
}


