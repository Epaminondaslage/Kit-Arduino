# Controle de Três LEDs com Arduino

Este projeto demonstra como controlar três LEDs conectados aos pinos 4, 5 e 6 de um Arduino. O código acende cada LED sequencialmente, com um intervalo de um segundo entre cada ação.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 3 LEDs
- 3 Resistores (220Ω a 1kΩ)
- Jumpers e Protoboard

## Como Funciona

O código utiliza três pinos digitais (4, 5 e 6) para controlar três LEDs. No `setup()`, esses pinos são configurados como saídas. No `loop()`, cada LED é aceso em sequência, permanecendo aceso por um segundo antes de ser apagado e passar para o próximo LED. Esse ciclo se repete indefinidamente.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura os pinos 4, 5 e 6 como saídas para controlar os LEDs.
- **Função `loop()`**: Executada repetidamente, controla o ciclo de acender e apagar cada LED com um intervalo de um segundo entre cada ação.

## Personalização

- **Intervalo de Tempo**: O tempo que cada LED permanece aceso pode ser ajustado modificando o valor de `delay(1000)` no `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte os LEDs e os resistores ao Arduino conforme as instruções.
2. Após carregar o código, os LEDs começarão a acender em sequência, com um intervalo de um segundo.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
