# Exibição de Dígitos em um Display de 7 Segmentos com Arduino

Este projeto demonstra como exibir os dígitos de 0 a 9 em um display de 7 segmentos utilizando um Arduino UNO. O código aciona cada segmento do display para formar os números de 0 a 9, um por vez, com um intervalo de 1 segundo entre cada exibição.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- Display de 7 segmentos (com cátodo comum)
- Resistores (220Ω a 1kΩ) para cada segmento do display
- Jumpers e Protoboard

## Como Funciona

O código utiliza sete pinos digitais (2 a 8) do Arduino para controlar os segmentos do display de 7 segmentos. O mapeamento dos números de 0 a 9 é feito por meio de um array que define quais segmentos devem ser acesos para formar cada número. No `loop()`, os números são exibidos sequencialmente, de 0 a 9, com um intervalo de 1 segundo entre cada número.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura os pinos dos segmentos como saídas.
- **Função `loop()`**: Executada repetidamente, exibe os números de 0 a 9 no display com um intervalo de 1 segundo entre cada número.
- **Função `displayDigit()`**: Recebe um número como argumento e aciona os segmentos correspondentes para formar o número no display.

## Personalização

- **Intervalo de Tempo**: O tempo de exibição de cada número pode ser ajustado modificando o valor de `delay(1000)` no `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o display de 7 segmentos ao Arduino conforme as instruções.
2. Após carregar o código, o display começará a exibir os números de 0 a 9, com um intervalo de 1 segundo entre cada número.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
