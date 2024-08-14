/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *               Controle de LED com Temporização Usando millis()         *
 * Elaborado/Adaptado por Epaminondas Lage                                *
 *                                                                        *
 * Este código controla um LED conectado ao pino 13 do Arduino, fazendo-o *
 * piscar em intervalos regulares de 1 segundo. O código utiliza a função *
 * millis() para controlar o tempo sem bloquear a execução do programa,   *
 * permitindo uma operação mais eficiente.                                *
 **************************************************************************/

int ledPin = 13; // Pino em que o LED está conectado
int ledStatus = LOW; // Define que o estado inicial do LED é desligado

long previousMillis = 0; // Variável que armazena o tempo anterior em milissegundos
long redLedInterval = 1000; // Intervalo de tempo (1000ms = 1 segundo) entre mudanças de estado do LED

void setup() {
    pinMode(ledPin, OUTPUT); // Configura o pino 13 como saída para controlar o LED
}

void loop(){
    unsigned long currentMillis = millis(); // Armazena o tempo atual em milissegundos

    if (currentMillis - previousMillis > redLedInterval) { // Verifica se o tempo decorrido é maior que o intervalo definido
        previousMillis = currentMillis; // Atualiza o tempo anterior para o tempo atual

        if (ledStatus == LOW) { // Verifica o estado atual do LED; se estiver desligado, muda para ligado
            ledStatus = HIGH; // Muda o estado do LED para ligado
        } else { // Se o LED estiver ligado, muda para desligado
            ledStatus = LOW; // Muda o estado do LED para desligado
        }
        digitalWrite(ledPin, ledStatus); // Escreve o estado do LED (ligado ou desligado) no pino 13
    }
}
