# Controle Aleatório de LEDs com Botão no Arduino

Este projeto demonstra como controlar quatro LEDs conectados aos pinos 8, 9, 10 e 11 de um Arduino, usando um botão para gerar um número aleatório e acender o LED correspondente. O código repete o processo de forma indefinida até que o botão seja pressionado.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 4 LEDs
- 4 Resistores (220Ω a 1kΩ)
- 1 Botão
- Jumpers e Protoboard

## Como Funciona

O código utiliza um botão conectado ao pino 3 para acionar o processo de geração de números aleatórios. Quando o botão não está pressionado, o Arduino gera um número aleatório entre 8 e 11, que corresponde aos pinos onde os LEDs estão conectados, e acende o LED correspondente. O ciclo se repete a cada 500 ms. Quando o botão é pressionado, todos os LEDs são apagados.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura os pinos dos LEDs como saídas e o pino do botão como entrada. Também inicializa o gerador de números aleatórios.
- **Função `loop()`**: Executada repetidamente, gera um número aleatório entre 8 e 11 para acender o LED correspondente enquanto o botão não for pressionado. Quando o botão é pressionado, todos os LEDs são apagados.

## Personalização

- **Intervalo de Tempo**: O tempo que cada LED permanece aceso pode ser ajustado modificando o valor de `delay(500)` no `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte os LEDs, resistores e o botão ao Arduino conforme as instruções.
2. Após carregar o código, os LEDs começarão a acender aleatoriamente enquanto o botão não for pressionado. Quando o botão for pressionado, todos os LEDs serão apagados.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
