# Projeto: Piscar LED com Controle de Tempo Usando Arduino seum usar a função Delay()

## Introdução

Este projeto demonstra como controlar um LED conectado ao Arduino, fazendo-o piscar em intervalos regulares de 1 segundo. O código utiliza a função `millis()` para controlar o tempo sem bloquear a execução do programa, permitindo uma operação não-bloqueante, ao contrário do uso da função `delay()`. Isso torna o código mais eficiente e flexível para ser expandido e adaptado a outras aplicações.

## Explicação do Código

Este código controla um LED conectado ao pino 13 do Arduino, alternando seu estado (ligado/desligado) a cada 1 segundo.

### Declaração de Variáveis

- **`ledPin`**: Define o pino digital ao qual o LED está conectado. Neste caso, o LED está conectado ao pino 13.
- **`ledStatus`**: Armazena o estado atual do LED, inicialmente definido como `LOW` (desligado).
- **`previousMillis`**: Armazena o tempo anterior em milissegundos, utilizado para calcular o intervalo entre os estados do LED.
- **`redLedInterval`**: Define o intervalo de tempo em milissegundos (1 segundo = 1000 ms) entre as mudanças de estado do LED.

### Função `setup()`

A função `setup()` é executada uma vez quando o Arduino é ligado ou resetado. Nesta função, o pino definido em `ledPin` é configurado como uma saída digital, permitindo o controle do LED.

### Função `loop()`

A função `loop()` é executada repetidamente enquanto o Arduino está ligado. Esta função monitora o tempo decorrido utilizando `millis()` e altera o estado do LED a cada 1 segundo, sem bloquear a execução do código.

### Funcionamento Geral

O código controla um LED conectado ao pino 13 do Arduino, fazendo-o piscar com um intervalo de 1 segundo. O uso da função `millis()` permite que o código verifique o tempo decorrido sem pausar a execução, ao contrário da função `delay()`. Isso torna o código mais eficiente e permite que outras tarefas sejam realizadas em paralelo.

### Benefícios do Código

- **Eficiência**: O uso de `millis()` evita a pausa completa do código, permitindo que outras operações possam ser realizadas enquanto o tempo é monitorado.
- **Flexibilidade**: Este código pode ser facilmente adaptado para controlar outros dispositivos ou para realizar múltiplas tarefas simultâneas.
- **Expansibilidade**: O projeto pode ser expandido para incluir múltiplos LEDs ou outros componentes que precisem ser controlados em intervalos específicos.

Este exemplo é ideal para iniciantes que desejam aprender sobre controle de tempo em projetos Arduino sem utilizar a função `delay()`. Ele fornece uma base sólida para projetos mais complexos, onde a sincronização de múltiplos componentes é essencial.
