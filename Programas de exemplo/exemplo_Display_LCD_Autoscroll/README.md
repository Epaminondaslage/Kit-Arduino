# Demonstrando o Uso de Autoscroll com Display LCD 16x2 no Arduino UNO

Este projeto demonstra como utilizar um display LCD 16x2 com a biblioteca LiquidCrystal no Arduino UNO. O código mostra como usar as funções `autoscroll()` e `noAutoscroll()` para controlar a rolagem automática do texto no display.

## Componentes Necessários

- Arduino UNO
- Display LCD 16x2 compatível com HD44780
- Potenciômetro de 10K ohms (para ajuste de contraste do display)
- Resistores (opcional)
- Jumpers e Protoboard

## Conexões

- **Pino RS do LCD**: Conectar ao pino digital 6 do Arduino
- **Pino Enable do LCD**: Conectar ao pino digital 7 do Arduino
- **Pino D4 do LCD**: Conectar ao pino digital 5 do Arduino
- **Pino D5 do LCD**: Conectar ao pino digital 4 do Arduino
- **Pino D6 do LCD**: Conectar ao pino digital 3 do Arduino
- **Pino D7 do LCD**: Conectar ao pino digital 2 do Arduino
- **Pino R/W do LCD**: Conectar ao GND
- **Potenciômetro de 10K**:
  - Conectar as extremidades ao +5V e ao GND
  - Conectar o terminal central ao pino VO do LCD (pino 3)

## Como Funciona

O código inicializa o display LCD com 16 colunas e 2 linhas. Em seguida, o loop principal realiza as seguintes operações:

1. **Exibição sem Rolagem**: Os números de 0 a 9 são exibidos na primeira linha do display, sem rolagem.
2. **Exibição com Rolagem Automática**: Na segunda linha, o cursor é posicionado fora da tela visível, e os números de 0 a 9 são exibidos com rolagem automática, fazendo o texto "deslizar" pela tela.
3. **Limpeza da Tela**: Após a exibição, a tela é limpa e o processo é reiniciado.

### Explicação do Código

- **Função `lcd.setCursor()`**: Define a posição do cursor no display, onde o próximo texto será exibido.
- **Função `lcd.autoscroll()`**: Ativa a rolagem automática, fazendo com que o texto exibido se mova para a esquerda.
- **Função `lcd.noAutoscroll()`**: Desativa a rolagem automática.
- **Função `lcd.clear()`**: Limpa o display, removendo qualquer texto que estava sendo exibido.

## Personalização

- **Tempo de Exibição**: O tempo entre a exibição de cada número pode ser ajustado alterando o valor de `delay(500)`.
- **Quantidade de Dígitos**: O código atualmente exibe os dígitos de 0 a 9. Este intervalo pode ser alterado modificando o loop `for`.

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

Projeto Elaborado/Adaptado por Epaminondas Lage
