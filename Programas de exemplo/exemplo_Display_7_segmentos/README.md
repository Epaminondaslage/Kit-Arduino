# Controle de Display de 7 Segmentos com Arduino UNO

Este projeto demonstra como controlar um display de 7 segmentos com cátodo comum usando um Arduino UNO. O código faz com que o display conte de 0 a 9, com cada dígito sendo exibido por um segundo antes de passar para o próximo.

## Componentes Necessários

- Arduino UNO
- Display de 7 segmentos (cátodo comum)
- Resistores (220 ohms para cada segmento)
- Jumpers e Protoboard

## Conexões

Os segmentos do display de 7 segmentos devem ser conectados aos seguintes pinos do Arduino:

- **Segmento A**: Pino 2
- **Segmento B**: Pino 3
- **Segmento C**: Pino 4
- **Segmento D**: Pino 5
- **Segmento E**: Pino 6
- **Segmento F**: Pino 7
- **Segmento G**: Pino 8

Cada segmento deve ter um resistor de 220 ohms em série para limitar a corrente.

## Como Funciona

O código define uma matriz que mapeia quais segmentos devem estar acesos para representar cada dígito de 0 a 9. A função `ligadisplay()` é usada para acionar os segmentos corretos de acordo com o dígito atual. No loop principal, o código faz uma contagem de 0 a 9, exibindo cada número por um segundo antes de passar para o próximo.

### Explicação do Código

- **Matriz `sete_digitos[10][7]`**:
  - Define quais segmentos (A-G) devem ser acesos para representar os dígitos de 0 a 9. Cada linha da matriz corresponde a um dígito e cada coluna corresponde a um segmento do display.

- **Função `setup()`**:
  - Configura os pinos 2 a 8 como saídas, que correspondem aos segmentos do display de 7 segmentos.

- **Função `ligadisplay()`**:
  - Recebe um dígito (0 a 9) como parâmetro e aciona os segmentos apropriados para exibir o dígito no display.

- **Função `loop()`**:
  - Faz a contagem de 0 a 9, com cada número sendo exibido por 1 segundo. Após a contagem de 0 a 9, há uma pausa de 4 segundos antes de reiniciar a contagem.

## Personalização

- **Tempo de Exibição**: O tempo que cada dígito é exibido pode ser ajustado alterando o valor do `delay(1000)` na função `loop()`.
- **Intervalo entre Contagens**: O tempo entre o fim de uma contagem e o início de outra pode ser ajustado alterando o valor do `delay(4000)` na função `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" e a porta correta.
4. Carregue o código na placa Arduino.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto Elaborado/Adptado por Epaminondas Lage
