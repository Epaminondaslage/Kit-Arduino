/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *             Controle Sequencial de Três LEDs com Intervalos            *
 * Elaborado/Adaptado por [Seu Nome ou Epaminondas Lage]                  *
 *                                                                        *
 * Este código controla três LEDs conectados aos pinos digitais 13, 12 e  *
 * 11 de forma sequencial. Cada LED é aceso por 1 segundo enquanto os     *
 * outros permanecem apagados. O ciclo se repete indefinidamente.         *
 **************************************************************************/

const int ledPins[] = {13, 12, 11}; // Array que define os pinos dos LEDs
const int numLeds = 3; // Número de LEDs controlados
const int interval = 1000; // Intervalo de tempo em milissegundos para cada LED

void setup() {
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT); // Declara cada pino de LED como saída
    }
}

void loop() {
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], HIGH); // Acende o LED no pino atual
        delay(interval); // Espera pelo intervalo definido
        digitalWrite(ledPins[i], LOW); // Apaga o LED no pino atual
    }
}
