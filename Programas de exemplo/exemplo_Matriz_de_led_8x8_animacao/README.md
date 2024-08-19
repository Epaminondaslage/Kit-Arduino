# Animação com Matriz de LEDs e Arduino utilizando PROGMEM

Este projeto demonstra como criar uma animação em uma matriz de LEDs 8x8 controlada por um módulo Max7219, utilizando um Arduino UNO ou Nano. A animação é armazenada na memória flash do Arduino (PROGMEM), economizando RAM e permitindo a exibição de padrões animados na matriz de LEDs.

## Componentes Necessários

- Arduino UNO ou Nano
- Módulo de Matriz de LEDs 8x8 com Max7219
- Jumpers e Protoboard

## Conexões

- **DIN (Pino 1 do Max7219)**: Conectar ao pino digital 12 do Arduino
- **CS (Pino 12 do Max7219)**: Conectar ao pino digital 10 do Arduino
- **CLK (Pino 13 do Max7219)**: Conectar ao pino digital 11 do Arduino

## Como Funciona

O código armazena uma sequência de imagens na memória flash do Arduino utilizando o modificador `PROGMEM`. Essas imagens são então lidas e exibidas em sequência na matriz de LEDs, criando uma animação simples. O loop principal do código percorre cada imagem da sequência, a exibe, e depois avança para a próxima imagem, repetindo o ciclo indefinidamente.

### Explicação do Código

- **Armazenamento em PROGMEM**: As imagens são armazenadas em PROGMEM para economizar espaço na RAM do Arduino. 
- **Função `displayImage()`**: Esta função é responsável por extrair cada linha da imagem e exibi-la na matriz de LEDs.
- **Animação no `loop()`**: O loop principal copia a imagem da PROGMEM para a RAM e a exibe na matriz. A animação é controlada por um atraso de 500 ms entre as imagens.

## Personalização

- **Brilho do Display**: O brilho da matriz de LEDs pode ser ajustado modificando o valor na função `setIntensity()`.
- **Velocidade da Animação**: O tempo entre a exibição de cada imagem pode ser ajustado alterando o valor de `delay(500)`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO/Nano" e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte os componentes conforme as instruções.
2. A matriz de LEDs começará a exibir a animação assim que o Arduino for ligado.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
