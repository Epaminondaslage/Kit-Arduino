/*
  Controle Sequencial de Quatro LEDs
  Este exemplo demonstra como controlar quatro LEDs conectados aos pinos 8, 9, 10 e 11 de um Arduino,
  acendendo cada um deles sequencialmente com um intervalo de 0,5 segundos.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Definição dos pinos dos LEDs
const int ledPins[] = {8, 9, 10, 11}; // Pinos onde os LEDs estão conectados

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); // Define os pinos dos LEDs como saída
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH); // Acende o LED
    delay(500); // Espera 0,5 segundos
    digitalWrite(ledPins[i], LOW); // Apaga o LED
    delay(500); // Espera 0,5 segundos
  }
}
