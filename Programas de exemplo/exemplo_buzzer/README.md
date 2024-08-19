# Programa para Tocar uma Melodia com Buzzer

Este código toca uma melodia simples usando um buzzer conectado ao Arduino. A melodia utilizada é "Ode to Joy" de Ludwig van Beethoven.

## Conexões

- **Pino positivo do buzzer**: Conecte ao pino digital 8 do Arduino.
- **Pino negativo do buzzer**: Conecte ao pino GND do Arduino.

## Notas

As notas são representadas em Hertz (Hz), e as pausas entre as notas são representadas por `0 Hz`.

## Definições das Notas

- **NOTE_C4**: 261 Hz (Dó central)
- **NOTE_D4**: 293 Hz (Ré)
- **NOTE_E4**: 329 Hz (Mi)
- **NOTE_F4**: 349 Hz (Fá)
- **NOTE_G4**: 392 Hz (Sol)
- **NOTE_A4**: 440 Hz (Lá)
- **NOTE_B4**: 493 Hz (Si)
- **NOTE_C5**: 523 Hz (Dó, uma oitava acima)
- **REST**: Pausa (0 Hz)

## Como Funciona

- **Definições das Notas**: O código define as frequências das notas e pausas.
- **Arrays de Notas e Durações**: O array `melody` contém as notas a serem tocadas, e `noteDurations` define a duração de cada nota.
- **Função `setup()`**: Configura o pino do buzzer como saída.
- **Função `loop()`**: Toca a melodia, onde cada nota é tocada por sua duração e depois uma pequena pausa é adicionada.

## Testando o Código

1. Conecte o buzzer ao pino digital 8 e ao GND do Arduino.
2. Faça o upload do código para o Arduino.
3. O buzzer deve tocar a melodia "Ode to Joy" repetidamente.

