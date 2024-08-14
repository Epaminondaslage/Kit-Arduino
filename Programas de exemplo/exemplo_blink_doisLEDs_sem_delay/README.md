## Descrição da Funcionalidade

Este projeto demonstra como controlar dois LEDs conectados aos pinos digitais 13 e 12 do Arduino de forma independente, utilizando a função `millis()` para gerenciar os intervalos de tempo sem bloquear o loop principal.

### Funcionalidade Geral

- **LED Vermelho (Pino 13)**: O LED vermelho é configurado para piscar com um intervalo de 2 segundos. O estado do LED (ligado ou desligado) é alternado a cada 2 segundos.
- **LED Verde (Pino 12)**: O LED verde também é configurado para piscar com um intervalo de 2 segundos, independente do LED vermelho.

### Como Funciona

1. **Inicialização**: No `setup()`, os pinos 13 e 12 são configurados como saídas digitais, prontos para controlar os LEDs.

2. **Controle de Tempo com `millis()`**:
   - A função `millis()` retorna o tempo em milissegundos desde que o Arduino começou a executar o programa. Essa função é usada para medir intervalos de tempo sem parar a execução do programa, ao contrário da função `delay()`.
   - O valor retornado por `millis()` é armazenado em uma variável a cada ciclo do loop. Em seguida, o programa compara o tempo atual com o tempo armazenado anteriormente para determinar se o intervalo necessário já passou.
   - Para cada LED, o código verifica se o tempo decorrido desde a última mudança de estado é maior que o intervalo definido (2 segundos para ambos).
   - Se o tempo decorrido for maior, o estado do LED é alternado (ligado ou desligado), e o tempo anterior é atualizado para o tempo atual.

3. **Piscar Independente**:
   - Os LEDs são controlados de forma independente. Mesmo que os intervalos sejam os mesmos, o controle separado permite que os LEDs possam ter diferentes tempos de piscar se os intervalos forem ajustados posteriormente.

### Vantagens do Uso de `millis()`

- **Execução Não Bloqueante**: Diferente da função `delay()`, que interrompe completamente o código por um período de tempo, `millis()` permite que o Arduino continue executando outras tarefas enquanto monitora o tempo.
- **Precisão e Flexibilidade**: O uso de `millis()` permite maior controle sobre o tempo e facilita a implementação de várias operações temporizadas simultaneamente, como o controle de múltiplos LEDs ou outros dispositivos.

Este método de controle usando `millis()` é vantajoso em relação ao uso da função `delay()` porque não bloqueia o loop principal, permitindo que o Arduino execute outras tarefas simultaneamente enquanto controla o tempo dos LEDs.
