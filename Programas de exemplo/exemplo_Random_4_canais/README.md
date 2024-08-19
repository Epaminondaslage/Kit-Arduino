# Pisca Aleatoriamente um dos Quatro LEDs - Arduino UNO

## Descrição do Projeto

Este projeto faz com que um dos quatro LEDs conectados aos pinos 9, 10, 11 e 12 do Arduino UNO pisque aleatoriamente. A cada ciclo, um LED diferente é selecionado para acender, criando um efeito de pisca-pisca aleatório.

## Funcionamento do Código

### Declaração de Variáveis

- **`long a;`**: Esta variável armazena o número aleatório sorteado, que determina qual LED será aceso.
- **`int Pinos[] = {9,10,11,12};`**: Um array que armazena os números dos pinos aos quais os LEDs estão conectados.
- **`int timer = 500;`**: Define o tempo de espera (em milissegundos) entre acender e apagar o LED.
- **`int contador = 0;`**: Variável usada para a configuração inicial dos pinos.

### Função `setup()`

- **`for (contador = 0; contador < 4; contador++) { pinMode(Pinos[contador], OUTPUT); }`**: O loop `for` é usado para configurar os pinos 9, 10, 11 e 12 como saídas, que são os pinos aos quais os LEDs estão conectados.

### Função `loop()`

A função `loop()` é responsável por sortear aleatoriamente um LED e acendê-lo, depois apagá-lo após um intervalo de tempo definido. O processo é repetido indefinidamente.

1. **Sorteio de LED**:
   - **`a = random(0, 4);`**: Sorteia um número aleatório entre 0 e 3, que corresponde a um dos índices do array `Pinos`.

2. **Acendimento e Apagamento do LED**:
   - **`digitalWrite(Pinos[a], HIGH);`**: Liga o LED correspondente ao número sorteado.
   - **`delay(timer);`**: Aguarda pelo tempo definido em `timer` antes de apagar o LED.
   - **`digitalWrite(Pinos[a], LOW);`**: Desliga o LED.
   - **`delay(timer);`**: Aguarda novamente pelo tempo definido em `timer` antes de repetir o processo.

