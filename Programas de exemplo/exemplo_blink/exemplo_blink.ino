/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *                    Exemplo Básico de Piscar um LED                     *
 * Elaborado/Adptado por  Epaminondas Lage                                *
 *                                                                        *
 * Este código pisca o LED embutido na placa Arduino UNO conectado ao     *
 * pino 13 em intervalos de 1 segundo. É um exemplo simples para iniciar  *
 * o aprendizado sobre controle de hardware com o Arduino.                *
 **************************************************************************/

void setup() {
    pinMode(13, OUTPUT); // Declara o pino 13 como sendo uma saída
}

void loop() {
    digitalWrite(13, HIGH); // Energiza o pino 13 e o LED da placa acende
    delay(1000); // Intervalo de 1 segundo (1000 milissegundos = 1 segundo)

    digitalWrite(13, LOW); // Desenergiza o pino 13 e o LED da placa apaga
    delay(1000); // Intervalo de 1 segundo
}
