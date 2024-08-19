# Projeto: Sinalizador de Garagem

## Descrição

Este projeto utiliza um Arduino para controlar dois LEDs que piscam alternadamente. O código faz com que o LED 1 acenda enquanto o LED 2 fica apagado, e vice-versa, em um intervalo de 500 ms. A informação sobre o estado atual dos LEDs é exibida na porta serial.

## Componentes Necessários

- 1 Arduino (UNO, Nano, etc.)
- 2 LEDs
- 2 resistores de 220Ω
- Fios de conexão
- Protoboard

## Esquema de Ligação

1. Conecte o LED 1 ao pino 8 do Arduino com um resistor de 220Ω.
2. Conecte o LED 2 ao pino 9 do Arduino com um resistor de 220Ω.
3. Conecte os catodos dos LEDs ao GND do Arduino.
## Explicação do Código

- **Pinos dos LEDs**: O `ledPin1` é configurado para o pino 8 e o `ledPin2` para o pino 9.
- **Intervalo de Tempo**: Foi definido um intervalo de 500 ms (`interval = 500`) para alternar o estado dos LEDs.
- **Função `setup()`**:
  - A comunicação serial é inicializada com `Serial.begin(9600)`.
  - Os pinos dos LEDs são configurados como saídas utilizando `pinMode()`.
  - Informações sobre os pinos dos LEDs são exibidas no monitor serial.
- **Função `loop()`**:
  - O `digitalWrite()` é utilizado para alternar o estado dos LEDs.
  - Mensagens sobre o estado dos LEDs são enviadas ao monitor serial com `Serial.println()`.
  - O `delay(interval)` cria uma pausa de 500 ms entre as mudanças de estado dos LEDs.

## Funcionamento

O programa alterna continuamente entre ligar o LED 1 e desligar o LED 2, e vice-versa, a cada 500 ms. O estado atual dos LEDs é exibido no monitor serial, permitindo acompanhar o comportamento do circuito em tempo real.

## Considerações

- Certifique-se de usar resistores adequados para proteger os LEDs.
- Você pode alterar o intervalo de tempo ajustando o valor da variável `interval` para experimentar diferentes frequências de piscada.


## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
