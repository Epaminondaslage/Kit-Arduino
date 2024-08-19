# Controle de Brilho de LED com PWM - Arduino UNO

Este projeto demonstra como controlar o brilho de um LED usando PWM (Modulação por Largura de Pulso) com o Arduino UNO. O código utiliza a função seno para suavizar a transição do brilho, criando um efeito de pulsação.

## Componentes Necessários

- Arduino UNO
- LED
- Resistor de 220 ohms (para limitar a corrente do LED)
- Jumpers e Protoboard

## Conexões

- **LED**: Conecte o ânodo (perna longa) do LED ao pino 9 do Arduino através de um resistor de 220 ohms. Conecte o cátodo (perna curta) ao GND.

## Como Funciona

O código usa a função `sin()` para calcular um valor de PWM baseado em um ângulo, convertendo-o para um intervalo de 0 a 255. Esse valor é então aplicado ao LED usando a função `analogWrite()`, o que permite o controle suave do brilho do LED.

### Explicação do Código

- **Declarações e Variáveis**:
  - `ledPin`: Define o pino 9 do Arduino como o pino de controle do LED.
  - `sinVal`: Armazena o valor do seno para o ângulo dado.
  - `ledVal`: Armazena o valor de PWM calculado, que será aplicado ao LED.

- **Função `setup()`**:
  - Configura o pino do LED como saída.

- **Função `loop()`**:
  - Um loop `for` itera sobre valores de ângulo de 10 a 180 graus.
  - Para cada valor de ângulo, o código converte o ângulo para radianos, calcula o valor do seno e o mapeia para um valor de PWM (0 a 255).
  - O valor de PWM é aplicado ao LED, controlando seu brilho.
  - Um `delay(50)` é usado para criar uma transição suave no brilho do LED.

## Personalização

- **Velocidade da Pulsação**: Você pode alterar a velocidade da pulsação mudando o valor do `delay(50)` para um valor maior ou menor.
- **Intervalo do Ângulo**: Ajuste os valores de `x` no loop `for` para modificar a faixa de brilho do LED.

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
