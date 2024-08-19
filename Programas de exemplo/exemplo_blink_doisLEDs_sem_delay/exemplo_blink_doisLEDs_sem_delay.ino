/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *               Controle Independente de Dois LEDs com Intervalos        *
 * Elaborado/Adaptado  Epaminondas Lage                                   *
 *                                                                        *
 * Este código controla dois LEDs conectados aos pinos digitais 13 e 12   *
 * de forma independente. Cada LED é configurado para piscar com um       *
 * intervalo específico, utilizando a função millis() para controlar o    *
 * tempo sem bloquear o loop principal.                                   *
 **************************************************************************/

int redLedPin = 13; // Variável que define o pino digital onde o LED vermelho está conectado
int greenLedPin = 12; // Variável que define o pino digital onde o LED verde está conectado

int redLedState = LOW; // Define que o estado inicial do LED vermelho é desligado
int greenLedState = LOW; // Define que o estado inicial do LED verde é desligado

long previousMillisRed = 0; // Variável que armazena o tempo anterior para o LED vermelho
long previousMillisGreen = 0; // Variável que armazena o tempo anterior para o LED verde

long redLedInterval = 2000; // Intervalo de tempo em milissegundos para o LED vermelho (2000 ms = 2 segundos)
long greenLedInterval = 2000; // Intervalo de tempo em milissegundos para o LED verde (2000 ms = 2 segundos)

void setup(){  
  pinMode(redLedPin, OUTPUT); // Configura o pino do LED vermelho como saída
  pinMode(greenLedPin, OUTPUT); // Configura o pino do LED verde como saída
}

void loop() {
  // Controle do LED vermelho
  unsigned long currentMillisRed = millis(); // Armazena o tempo atual em milissegundos para o LED vermelho

  if (currentMillisRed - previousMillisRed > redLedInterval) { // Verifica se o tempo decorrido é maior que o intervalo definido
    previousMillisRed = currentMillisRed; // Atualiza o tempo anterior para o tempo atual

    // Alterna o estado do LED vermelho
    if (redLedState == LOW) { 
      redLedState = HIGH; // Liga o LED vermelho
    } else { 
      redLedState = LOW; // Desliga o LED vermelho
    }

    digitalWrite(redLedPin, redLedState); // Atualiza o estado do LED vermelho no pino 13
  }

  // Controle do LED verde
  unsigned long currentMillisGreen = millis(); // Armazena o tempo atual em milissegundos para o LED verde

  if (currentMillisGreen - previousMillisGreen > greenLedInterval) { // Verifica se o tempo decorrido é maior que o intervalo definido
    previousMillisGreen = currentMillisGreen; // Atualiza o tempo anterior para o tempo atual

    // Alterna o estado do LED verde
    if (greenLedState == LOW) { 
      greenLedState = HIGH; // Liga o LED verde
    } else { 
      greenLedState = LOW; // Desliga o LED verde
    }

    digitalWrite(greenLedPin, greenLedState); // Atualiza o estado do LED verde no pino 12
  }
}
