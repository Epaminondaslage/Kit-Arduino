# Placar Eletrônico com Arduino e Módulo Max7219

Este projeto implementa um placar eletrônico utilizando um Arduino UNO ou Nano e duas matrizes de LEDs 8x8 controladas por um módulo Max7219. Ele permite aumentar ou diminuir a contagem exibida em cada uma das matrizes utilizando botões, com a exibição de números de 0 a 9.

## Componentes Necessários

- Arduino UNO ou Nano
- 2 Módulos de Matriz de LEDs 8x8 com Max7219
- 3 Botões (para controle de contagem e alternância de display)
- 2 LEDs (para indicar qual display está selecionado)
- Resistores (opcional, para LEDs)
- Jumpers e Protoboard

## Conexões

### Conexões do Max7219

- **DATA IN (Pino 1 do Max7219)**: Conectar ao pino digital 12 do Arduino
- **CLK (Pino 13 do Max7219)**: Conectar ao pino digital 11 do Arduino
- **LOAD/CS (Pino 12 do Max7219)**: Conectar ao pino digital 10 do Arduino

### Conexões dos Botões

- **Botão 1 (Alternar Displays)**: Conectar ao pino digital 6 do Arduino com resistor pull-up interno
- **Botão 2 (Aumentar Contagem)**: Conectar ao pino digital 7 do Arduino com resistor pull-up interno
- **Botão 3 (Diminuir Contagem)**: Conectar ao pino digital 8 do Arduino com resistor pull-up interno

### Conexões dos LEDs Indicadores

- **LED 1 (Display 1 Selecionado)**: Conectar ao pino digital 3 do Arduino
- **LED 2 (Display 2 Selecionado)**: Conectar ao pino digital 4 do Arduino

## Como Funciona

O código inicializa duas matrizes de LEDs 8x8, que são controladas individualmente através de botões. O primeiro botão alterna entre as matrizes, enquanto os outros dois botões incrementam ou decrementam a contagem exibida. Cada matriz de LEDs exibe números de 0 a 9 utilizando caracteres pré-definidos no código.

### Explicação do Código

- **Controle das Matrizes**: A biblioteca `LedControl.h` é utilizada para controlar as matrizes de LEDs através do módulo Max7219.
- **Botões de Controle**: Três botões permitem alternar entre os displays e ajustar a contagem em cada um.
- **LEDs Indicadores**: Dois LEDs indicam qual display está selecionado para ajustes.
- **Função `writeOnMatrix()`**: Exibe o número correspondente na matriz de LEDs, utilizando arrays que definem o formato de cada dígito.

## Personalização

- **Brilho do Display**: O brilho das matrizes pode ser ajustado modificando o valor da variável `brilho` no código.
- **Delay entre Operações**: O tempo de espera entre as operações pode ser ajustado modificando o valor da variável `delaytime`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO/Nano" e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte os componentes conforme as instruções.
2. Utilize os botões para alternar entre os displays e ajustar a contagem.
3. O LED acenderá para indicar qual display está selecionado.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto Elaborado por Arduino e Cia, Adaptado por Epaminondas Lage
