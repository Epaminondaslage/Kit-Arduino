const int ledPins[] = {11, 12, 13}; // Pinos dos LEDs
const int buttonPins[] = {2, 3, 4}; // Pinos dos botões
const int buzzerPin = 9; // Pino do buzzer
const int notes[] = {261, 329, 392}; // Notas (C4, E4, G4)

void setup() {
  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura os pinos dos botões como entrada com pull-up interno
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Se o botão for pressionado
      digitalWrite(ledPins[i], HIGH); // Liga o LED correspondente
      tone(buzzerPin, notes[i]); // Toca a nota correspondente
    } else {
      digitalWrite(ledPins[i], LOW); // Desliga o LED correspondente
      noTone(buzzerPin); // Para de tocar o buzzer
    }
  }
}
