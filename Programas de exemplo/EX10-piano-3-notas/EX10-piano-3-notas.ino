/*
  Controle de LEDs e Buzzer com Botões
  Este exemplo demonstra como controlar três LEDs e um buzzer utilizando três botões conectados a um Arduino.
  Quando um botão é pressionado, o LED correspondente acende e o buzzer toca uma nota específica.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Definição dos pinos dos LEDs
const int ledPins[] = {11, 12, 13}; // Pinos dos LEDs
// Definição dos pinos dos botões
const int buttonPins[] = {2, 3, 4}; // Pinos dos botões
// Definição do pino do buzzer
const int buzzerPin = 9; // Pino do buzzer
// Definição das notas musicais para o buzzer (C4, E4, G4)
const int notes[] = {261, 329, 392}; // Notas (C4, E4, G4)

void setup() {
  // Configura os pinos dos LEDs como saídas
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura os pinos dos botões como entradas com pull-up interno
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  // Verifica o estado de cada botão e aciona o LED e o buzzer correspondentes
  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Se o botão for pressionado
      digitalWrite(ledPins[i], HIGH); // Liga o LED correspondente
      tone(buzzerPin, notes[i]); // Toca a nota correspondente no buzzer
    } else {
      digitalWrite(ledPins[i], LOW); // Desliga o LED correspondente
      noTone(buzzerPin); // Para de tocar o buzzer
    }
  }
}
