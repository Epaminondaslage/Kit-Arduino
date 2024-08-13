# Controle de Brilho de LED com LDR e Modo Noturno no Arduino

Este projeto demonstra como utilizar um sensor LDR para ajustar o brilho de um LED em função da luminosidade ambiente, com a opção de ativar um modo noturno através de uma chave.

# PWM (Modulação por Largura de Pulso)

PWM, ou Modulação por Largura de Pulso (do inglês *Pulse Width Modulation*), é uma técnica usada para controlar a quantidade de energia fornecida a um dispositivo eletrônico, como um motor, um LED, ou um aquecedor. No contexto de eletrônica, PWM é frequentemente utilizado em situações onde se deseja ajustar a potência média fornecida a um dispositivo, como por exemplo, controlar o brilho de um LED ou a velocidade de um motor.

## Como Funciona o PWM

PWM funciona gerando uma onda quadrada com dois estados: **ALTO (HIGH)** e **BAIXO (LOW)**. A proporção entre o tempo em que o sinal permanece em estado ALTO e o tempo total do ciclo de onda é chamada de **ciclo de trabalho** (*duty cycle*). O ciclo de trabalho é normalmente expresso em porcentagem. Por exemplo:

- **Ciclo de trabalho de 0%**: o sinal está sempre em estado BAIXO (0V), e o dispositivo conectado não recebe energia.
- **Ciclo de trabalho de 50%**: o sinal passa 50% do tempo em estado ALTO (5V no caso do Arduino) e 50% do tempo em estado BAIXO (0V), fornecendo ao dispositivo uma energia média equivalente à metade da potência total.
- **Ciclo de trabalho de 100%**: o sinal está sempre em estado ALTO, fornecendo energia total ao dispositivo.

## Uso do PWM no Arduino

No Arduino, pinos específicos (marcados com "~" ao lado do número do pino na placa) podem gerar sinais PWM usando a função `analogWrite()`. Esta função permite definir o ciclo de trabalho em uma escala de 0 a 255:

- **0** corresponde a 0% de ciclo de trabalho (LED completamente apagado, por exemplo).
- **255** corresponde a 100% de ciclo de trabalho (LED completamente aceso).
- **Valores intermediários** ajustam a intensidade do sinal proporcionalmente.

## Aplicações Comuns do PWM

- **Controle de Brilho de LEDs**: Ajuste de intensidade luminosa com base em condições ambientais ou interações do usuário.
- **Controle de Velocidade de Motores**: Em robótica e automação, PWM é amplamente utilizado para controlar a velocidade de motores de corrente contínua (DC).
- **Gerenciamento de Potência**: PWM pode ser usado para controlar a quantidade de energia fornecida a aquecedores, ventiladores e outros dispositivos, permitindo um uso mais eficiente da energia.

## Vantagens do PWM

- **Eficiência**: PWM permite um controle eficiente da potência com mínima perda de energia, uma vez que o dispositivo de controle (como um transistor) alterna entre estados de condução completa e corte, minimizando o tempo em estados de transição onde a dissipação de energia é maior.
- **Simplicidade**: Implementação fácil com microcontroladores como o Arduino.
- **Flexibilidade**: Pode ser utilizado para uma ampla gama de aplicações, desde controle de motores até ajuste de luminosidade de LEDs.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- Sensor LDR (Light Dependent Resistor)
- 1 LED
- 1 Resistor (220Ω a 1kΩ) para o LED
- 1 Resistor (10kΩ) para o LDR
- 1 Chave (push button ou switch)
- Jumpers e Protoboard

## Como Funciona

O código utiliza um sensor LDR conectado ao pino analógico A0 do Arduino para medir a luminosidade do ambiente. Um LED conectado ao pino 9 do Arduino tem seu brilho ajustado com base na leitura do LDR. Se o ambiente estiver mais claro, o LED brilhará menos, e vice-versa. Além disso, há um modo noturno que, quando ativado por uma chave conectada ao pino 2, faz o LED brilhar na intensidade máxima, independentemente da leitura do LDR.

### Explicação do Código

- **Função `setup()`**:
  - Configura os pinos do LED, LDR, chave e LED indicador.
  - Inicializa a comunicação serial para depuração (opcional).

- **Função `loop()`**:
  - Lê o estado da chave para determinar se o modo noturno está ativo.
  - Ajusta o brilho do LED com base no modo selecionado:
    - **Modo Noturno**: O LED acende com intensidade máxima.
    - **Modo Automático**: O brilho do LED é ajustado conforme a luminosidade captada pelo LDR.
  - Exibe informações de depuração no monitor serial (opcional).

## Personalização

- **Limiar de Escuridão**: O valor de `LIMIAR` pode ser ajustado para definir o ponto em que o LED deve acender com maior intensidade.
- **Intervalo de Tempo**: O valor de `INTERVALO` define o tempo de espera entre cada leitura do LDR e pode ser ajustado conforme necessário.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LDR, a chave, o LED e o LED indicador ao Arduino conforme as instruções.
2. Após carregar o código, o LED terá seu brilho ajustado conforme a luminosidade do ambiente, com a possibilidade de ativar o modo noturno para brilho máximo.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
