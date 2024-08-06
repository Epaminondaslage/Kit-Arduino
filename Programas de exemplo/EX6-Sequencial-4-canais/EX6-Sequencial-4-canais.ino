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

