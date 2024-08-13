# Controle de Lâmpada com LDR e Relé no Arduino

Este projeto demonstra como utilizar um sensor LDR para controlar uma lâmpada através de um relé conectado a um Arduino UNO. A lâmpada será ligada automaticamente quando o ambiente estiver escuro e desligada durante o dia.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- Sensor LDR (Light Dependent Resistor)
- Relé
- 1 Resistor (10kΩ) para o LDR
- Lâmpada ou outro dispositivo de carga controlado pelo relé
- Jumpers e Protoboard

## Como Funciona

O código utiliza um sensor LDR conectado ao pino analógico A2 para medir a luminosidade do ambiente. Quando o valor lido pelo LDR for inferior ao limiar definido (`LIMIAR`), o relé conectado ao pino 10 é acionado, ligando a lâmpada. Se o valor lido for superior ao limiar, o relé é desligado, apagando a lâmpada.

### Explicação do Código

- **Função `setup()`**: Configura os pinos do relé e do LDR. Também inicializa a comunicação serial para fins de depuração.
- **Função `loop()`**: Lê continuamente o valor do LDR. Dependendo da luminosidade, o relé é ligado ou desligado, controlando a lâmpada.

## Personalização

- **Limiar de Escuridão**: O valor de `LIMIAR` pode ser ajustado para definir o ponto em que o relé deve ser acionado ou desligado.
- **Intervalo de Tempo**: O valor de `INTERVALO` define o tempo de espera entre cada leitura do LDR e pode ser ajustado conforme necessário.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o LDR e o relé ao Arduino conforme as instruções.
2. Após carregar o código, a lâmpada será automaticamente ligada quando o ambiente estiver escuro e desligada quando estiver claro.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
