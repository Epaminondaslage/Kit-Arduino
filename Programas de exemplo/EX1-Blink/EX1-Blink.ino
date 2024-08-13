/*
  Blink (Piscar)
  Este exemplo faz o LED embutido na placa Arduino piscar continuamente.
  O LED embutido geralmente está conectado ao pino digital 13.

  Elaborado/Adaptado por Epaminondas Lage
*/

// A função setup() é executada uma vez quando você pressiona reset ou liga a placa
void setup() {
  // Inicializa o pino digital LED_BUILTIN como uma saída
  pinMode(LED_BUILTIN, OUTPUT);
}

// A função loop() é executada continuamente
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Acende o LED (HIGH é o nível de tensão)
  delay(1000);                     // Espera por um segundo
  digitalWrite(LED_BUILTIN, LOW);  // Apaga o LED (LOW é o nível de tensão)
  delay(1000);                     // Espera por um segundo
}
