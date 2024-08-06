// Definição das variáveis configuráveis
const int ledPin = 10;             // Pino onde o LED está conectado
int blinkCount = 3;                // Número de piscadas
int blinkDuration = 100;           // Duração de cada piscada em milissegundos (0.1 segundo)
int offDuration = 1500;            // Duração de apagar o LED em milissegundos (1.5 segundos)

void setup() {
  pinMode(ledPin, OUTPUT);         // Define o pino do LED como saída
}

void loop() {
  int count = 0;                   // Inicializa o contador para o número de piscadas

  // Loop para piscar o LED
  while (count < blinkCount) {
    digitalWrite(ledPin, HIGH);    // Acende o LED
    delay(blinkDuration);          // Mantém o LED aceso pelo tempo especificado
    digitalWrite(ledPin, LOW);     // Apaga o LED
    delay(blinkDuration);          // Pausa antes de piscar novamente
    count++;                       // Incrementa o contador
  }

  // Aguarda com o LED apagado
  delay(offDuration);              // Mantém o LED apagado pelo tempo de apagamento especificado
}
