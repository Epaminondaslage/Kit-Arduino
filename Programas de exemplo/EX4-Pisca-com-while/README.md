# Piscar LED Três Vezes com Intervalo de 5 Segundos

Este projeto demonstra como fazer um LED piscar três vezes com um intervalo de 1 segundo entre piscadas, seguido de um período de 5 segundos em que o LED permanece apagado, antes de repetir o ciclo.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 1 LED
- 1 Resistor (220Ω a 1kΩ)
- Jumpers e Protoboard

## Como Funciona

O código faz o LED piscar três vezes em intervalos de 1 segundo, depois permanece apagado por 5 segundos antes de repetir o ciclo. O pino utilizado é o 13, que é o pino padrão do LED embutido na maioria das placas Arduino.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura o pino 13 como uma saída para controlar o LED.
- **Função `loop()`**: Executada repetidamente, controla o ciclo de três piscadas do LED seguidas por 5 segundos de inatividade.

## Personalização

- **Número de Piscadas**: O número de piscadas pode ser ajustado modificando o valor de `blinkCount`.
- **Intervalo de Piscadas**: O tempo de intervalo entre as piscadas pode ser ajustado modificando o valor de `blinkInterval`.
- **Duração de Apagamento**: O tempo em que o LED permanece apagado pode ser ajustado modificando o valor de `offDuration`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LED e o resistor ao Arduino conforme as instruções.
2. Após carregar o código, o LED piscará três vezes, com um intervalo de 1 segundo entre cada piscada, e depois permanecerá apagado por 5 segundos.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
