# Controle de Piscar LED com Intervalos Configuráveis no Arduino

Este projeto demonstra como fazer um LED piscar três vezes, com duração de 100 ms por piscada, seguido de um período de 1,5 segundos em que o LED permanece apagado, antes de repetir o ciclo.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 1 LED
- 1 Resistor (220Ω a 1kΩ)
- Jumpers e Protoboard

## Como Funciona

O código faz o LED piscar três vezes, com cada piscada durando 100 ms, seguido de 1,5 segundos de apagamento antes de repetir o ciclo. O pino utilizado é o 10, onde o LED está conectado. A quantidade de piscadas, a duração de cada piscada, e o tempo de apagamento são configuráveis através das variáveis `blinkCount`, `blinkDuration` e `offDuration`, respectivamente.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura o pino 10 como uma saída para controlar o LED.
- **Função `loop()`**: Executada repetidamente, controla o ciclo de três piscadas do LED seguidas por 1,5 segundos de inatividade.

## Personalização

- **Número de Piscadas**: O número de piscadas pode ser ajustado modificando o valor de `blinkCount`.
- **Duração das Piscadas**: O tempo que cada piscada dura pode ser ajustado modificando o valor de `blinkDuration`.
- **Duração do Apagamento**: O tempo em que o LED permanece apagado pode ser ajustado modificando o valor de `offDuration`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LED e o resistor ao Arduino conforme as instruções.
2. Após carregar o código, o LED piscará três vezes, com um intervalo de 100 ms entre cada piscada, e depois permanecerá apagado por 1,5 segundos.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
