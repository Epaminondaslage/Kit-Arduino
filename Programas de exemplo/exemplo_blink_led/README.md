# Projeto: Controle Sequencial de LEDs com Arduino

## Introdução

Este projeto demonstra como controlar três LEDs conectados a um Arduino de forma sequencial. O código acende e apaga os LEDs em intervalos definidos, criando um padrão de piscar que se repete indefinidamente. A implementação faz uso eficiente de arrays e loops para simplificar o controle dos LEDs, tornando o código mais conciso, fácil de manter e escalável.

Este projeto é ideal para iniciantes que desejam aprender sobre controle de hardware com o Arduino, especificamente no que diz respeito ao controle de múltiplos LEDs. Além de proporcionar um entendimento básico sobre a configuração de pinos digitais como saídas, o projeto também introduz o conceito de ciclos de controle repetitivos, essenciais em muitos projetos de automação e eletrônica.

## Explicação do Código

Este código controla três LEDs conectados aos pinos digitais 13, 12 e 11 do Arduino de forma sequencial, acendendo cada LED por 1 segundo enquanto os outros permanecem apagados. O ciclo se repete indefinidamente. A principal melhoria neste código em comparação com a versão anterior é a eficiência, conseguida através do uso de arrays e loops.

### Declaração de Variáveis e Configurações

```cpp
const int ledPins[] = {13, 12, 11}; // Array que define os pinos dos LEDs
const int numLeds = 3; // Número de LEDs controlados
const int interval = 1000; // Intervalo de tempo em milissegundos para cada LED
```
### Função `setup()`

A função `setup()` é executada uma vez quando o Arduino é ligado ou resetado. Nesta função, todos os pinos definidos no array `ledPins[]` são configurados como saídas, para que possam controlar os LEDs.

```cpp
void setup() {
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT); // Declara cada pino de LED como saída
    }
}
```
### `setup()`

- **Esta função** é executada uma vez quando o Arduino é ligado ou resetado. Aqui, ela configura todos os pinos definidos no array `ledPins[]` como saídas, para que possam controlar os LEDs.
- **`for` loop**: Itera sobre cada pino no array `ledPins[]` e configura cada um como uma saída usando `pinMode()`.

### Função `loop()`

```cpp
void loop() {
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], HIGH); // Acende o LED no pino atual
        delay(interval); // Espera pelo intervalo definido
        digitalWrite(ledPins[i], LOW); // Apaga o LED no pino atual
    }
}
```

- **`loop()`**: Esta função é executada repetidamente e continuamente enquanto o Arduino está ligado. É onde o ciclo de acender e apagar LEDs ocorre.
- **`for` loop**: Itera através de cada pino no array `ledPins[]`.
    - **`digitalWrite(ledPins[i], HIGH);`**: Liga o LED conectado ao pino correspondente (acende o LED).
    - **`delay(interval);`**: Pausa a execução do programa por 1 segundo (ou o valor definido em `interval`), mantendo o LED aceso por esse tempo.
    - **`digitalWrite(ledPins[i], LOW);`**: Desliga o LED após o intervalo de tempo.

## Funcionamento Geral

O código controla três LEDs em sequência:

- **Primeiro LED (Pino 13)**: O LED conectado ao pino 13 acende, enquanto os LEDs nos pinos 12 e 11 permanecem apagados. Após 1 segundo, o LED no pino 13 é apagado.
- **Segundo LED (Pino 12)**: O LED no pino 12 acende, enquanto os LEDs nos pinos 13 e 11 permanecem apagados. Após 1 segundo, o LED no pino 12 é apagado.
- **Terceiro LED (Pino 11)**: O LED no pino 11 acende, enquanto os LEDs nos pinos 13 e 12 permanecem apagados. Após 1 segundo, o LED no pino 11 é apagado.

Este ciclo se repete indefinidamente, com os LEDs piscando um de cada vez em sequência.

## Benefícios do Código

- **Eficiência**: O uso de arrays e loops reduz a repetição de código, tornando-o mais conciso e fácil de modificar.
- **Escalabilidade**: É fácil adicionar mais LEDs ao circuito, bastando aumentar o tamanho do array `ledPins[]` e ajustar a variável `numLeds`.
- **Manutenção**: A estrutura do código facilita a manutenção e a atualização do código para incluir novos comportamentos ou componentes.

## Conclusão

Este código é um exemplo prático de como controlar múltiplos LEDs de maneira eficiente e pode ser facilmente expandido para incluir mais LEDs ou outras funcionalidades.


