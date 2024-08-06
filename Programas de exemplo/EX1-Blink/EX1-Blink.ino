/*
Blink (Piscar)
*/
// A função setup() é executada uma vez quando você pressiona reset ou liga a placa
void setup() {
// inicializa o pino digital LED_BUILTIN como uma saída.
pinMode(LED_BUILTIN, OUTPUT);
}
// A função loop() é executada continuamente
void loop() {
digitalWrite(LED_BUILTIN, HIGH); // acende o LED (HIGH é o nível de tensão)
delay(1000); // espera por um segundo
digitalWrite(LED_BUILTIN, LOW); // apaga o LED (LOW é o nível de tensão)
delay(1000); // espera por um segundo
}