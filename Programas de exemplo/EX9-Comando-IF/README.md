# Controle de Piscar LED com Ciclos de 5 Segundos no Arduino

Este projeto demonstra como controlar um LED conectado ao pino 13 de um Arduino, fazendo-o piscar a cada segundo. A cada 5 segundos, o LED pisca continuamente por 2 segundos antes de retomar o ciclo.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 1 LED (opcional, caso a placa não tenha um LED embutido)
- 1 Resistor (220Ω a 1kΩ) (opcional, caso utilize um LED externo)
- Jumpers e Protoboard (se estiver utilizando um LED externo)

## Como Funciona

O código faz o LED piscar a cada segundo. A cada ciclo de 5 segundos, o LED pisca continuamente por 2 segundos, completando o ciclo. Este ciclo é repetido indefinidamente. O pino utilizado é o 13, que é o pino padrão do LED embutido na maioria das placas Arduino.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura o pino 13 como uma saída para controlar o LED.
- **Função `loop()`**: Executada repetidamente, controla o ciclo de piscadas do LED, alternando entre um piscar simples e um piscar contínuo de 2 segundos a cada 5 segundos.

## Personalização

- **Intervalo de Piscar**: O tempo que o LED permanece aceso ou apagado pode ser ajustado modificando o valor de `delay(500)` nas partes relevantes do código.
- **Duração de Piscar Contínuo**: O tempo de 2 segundos durante o ciclo de 5 segundos pode ser ajustado modificando o valor de `delay(2000)`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LED ao Arduino, caso esteja utilizando um LED externo.
2. Após carregar o código, o LED começará a piscar conforme o ciclo descrito.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
