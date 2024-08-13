/*
  Controle de Três LEDs
  Este exemplo demonstra como controlar três LEDs conectados aos pinos 4, 5 e 6 de um Arduino,
  acendendo cada um deles sequencialmente com um intervalo de um segundo.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Definição dos pinos dos LEDs
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

void setup() {
  // Define os pinos dos LEDs como saídas
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Acende o primeiro LED e espera 1 segundo
  digitalWrite(ledPin1, HIGH);
  delay(1000);
  digitalWrite(ledPin1, LOW);
  
  // Acende o segundo LED e espera 1 segundo
  digitalWrite(ledPin2, HIGH);
  delay(1000);
  digitalWrite(ledPin2, LOW);
  
  // Acende o terceiro LED e espera 1 segundo
  digitalWrite(ledPin3, HIGH);
  delay(1000);
  digitalWrite(ledPin3, LOW);
}
