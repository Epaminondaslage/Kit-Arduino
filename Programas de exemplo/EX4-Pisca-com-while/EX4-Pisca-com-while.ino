const int ledPin = 13; // Pino de saída onde o LED está conectado
const int blinkCount = 3; // Número de piscadas
const int blinkInterval = 1000; // Intervalo de piscar em milissegundos (1 segundo)
const int offDuration = 5000; // Duração de apagar o LED em milissegundos (5 segundos)

void setup() {
  pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  int count = 0; // Contador de piscadas

  // Piscar o LED 3 vezes
  while (count < blinkCount) {
    digitalWrite(ledPin, HIGH); // Acende o LED
    delay(blinkInterval / (2 * blinkCount)); // Aguarda metade do intervalo
    digitalWrite(ledPin, LOW); // Apaga o LED
    delay(blinkInterval / (2 * blinkCount)); // Aguarda metade do intervalo
    count++; // Incrementa o contador
  }

  // Aguarda 5 segundos com o LED apagado
  unsigned long startTime = millis(); // Armazena o tempo de início
  while (millis() - startTime < offDuration) {
    // Aguarda até que o tempo de apagamento tenha passado
  }
}
