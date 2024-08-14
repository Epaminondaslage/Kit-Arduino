## Introdução ao Projeto

Este projeto é um exemplo básico de como controlar um LED utilizando a placa de desenvolvimento Arduino Uno. Ele foi projetado para introduzir conceitos fundamentais de programação de microcontroladores, como a configuração de pinos digitais como entrada ou saída e o uso de funções básicas para manipular o hardware conectado ao Arduino.

No código, um LED embutido na placa Arduino, conectado ao pino 13, é configurado para piscar em intervalos regulares de 1 segundo. Este exemplo, conhecido como "Blink", é frequentemente utilizado como o primeiro passo para aprender a programar no ambiente Arduino, proporcionando uma base sólida para projetos mais avançados.

## Explicação do Código

Este código é um exemplo básico de como controlar um LED usando o Arduino. O LED está conectado ao pino 13, que é configurado como saída. O código alterna o LED entre ligado e desligado em intervalos de 1 segundo.

### Função `setup()`

A função `setup()` é executada uma vez quando o Arduino é ligado ou resetado. Neste exemplo, a função configura o pino 13 como uma saída digital.

```cpp
void setup() {
    pinMode(13, OUTPUT); // Declara o pino 13 como sendo uma saída
}
```
### Função `loop()`

A função `loop()` é executada repetidamente após a função `setup()`. Neste exemplo, ela alterna o estado do pino 13 entre alto (HIGH) e baixo (LOW), ligando e desligando o LED em intervalos de 1 segundo.

- **`digitalWrite(13, HIGH);`**: Define o pino 13 como alto (5V), ligando o LED conectado a esse pino.
- **`delay(1000);`**: Pausa a execução do programa por 1 segundo (1000 milissegundos).
- **`digitalWrite(13, LOW);`**: Define o pino 13 como baixo (0V), desligando o LED.
- **`delay(1000);`**: Pausa a execução do programa por mais 1 segundo.

## Funcionamento Geral

Quando o Arduino é ligado, o LED conectado ao pino 13 começará a piscar com um intervalo de 1 segundo. Isso acontece porque o `loop()` continua executando indefinidamente, alternando o estado do LED entre ligado e desligado.

Este exemplo é frequentemente utilizado como um primeiro passo para aprender a programar o Arduino e compreender o funcionamento básico de controle de hardware através do código.
