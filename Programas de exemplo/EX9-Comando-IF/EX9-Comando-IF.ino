/*
  Controle de Piscar LED com Ciclos de 5 Segundos
  Este exemplo demonstra como fazer um LED piscar a cada segundo,
  e a cada 5 segundos, o LED pisca continuamente por 2 segundos.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Definição do pino do LED
const int ledPin = 13; // Pino do LED

void setup() {
  pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  // Pisca o LED a cada segundo
  digitalWrite(ledPin, HIGH); // Liga o LED
  delay(500); // Espera 500 ms
  digitalWrite(ledPin, LOW); // Desliga o LED
  delay(500); // Espera 500 ms

  // A cada 5 segundos, pisca por 2 segundos
  for (int i = 0; i < 4; i++) { // Executa o loop 4 vezes para totalizar 4 segundos
    digitalWrite(ledPin, HIGH); // Liga o LED
    delay(500); // Espera 500 ms
    digitalWrite(ledPin, LOW); // Desliga o LED
    delay(500); // Espera 500 ms
  }
  
  // Pisca por 2 segundos
  digitalWrite(ledPin, HIGH); // Liga o LED
  delay(2000); // Espera 2000 ms
  digitalWrite(ledPin, LOW); // Desliga o LED
  
  delay(1000); // Espera 1 segundo para completar o ciclo de 5 segundos
}
