# Controle de LED via Porta Serial no Arduino

Este projeto demonstra como controlar um LED conectado ao pino 13 de um Arduino utilizando a comunicação serial. Quando o caractere 'a' é digitado na interface serial, o LED alterna entre ligado e desligado.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 1 LED (opcional, caso a placa não tenha um LED embutido)
- 1 Resistor (220Ω a 1kΩ) (opcional, caso utilize um LED externo)
- Jumpers e Protoboard (se estiver utilizando um LED externo)

## Como Funciona

O código permite que você controle o LED conectado ao pino 13 de um Arduino digitando o caractere 'a' na interface serial. O LED liga ou desliga alternadamente a cada vez que o caractere é digitado.

### Explicação do Código

- **Função `setup()`**: Configura o pino 13 como uma saída para controlar o LED e inicializa a comunicação serial a 9600 bps.
- **Função `loop()`**: Lê os dados da porta serial. Se o caractere 'a' for recebido, o código alterna o estado do LED (liga ou desliga) e imprime o estado atual na interface serial.

## Personalização

- **Caractere de Controle**: O caractere utilizado para alternar o LED pode ser modificado alterando o valor `'a'` no código.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LED ao Arduino, caso esteja utilizando um LED externo.
2. Abra o Monitor Serial na IDE do Arduino.
3. Digite 'a' e pressione Enter para alternar o estado do LED.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
