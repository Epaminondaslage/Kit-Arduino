# Medição de Temperatura e Umidade com DHT11 e Display LCD no Arduino

Este projeto demonstra como utilizar um sensor DHT11 para medir a temperatura e a umidade do ambiente, exibindo os valores em um display LCD 16x2 via comunicação I2C.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- Sensor DHT11 (ou similar)
- Display LCD 16x2 com interface I2C
- Jumpers e Protoboard

## Como Funciona

O código utiliza um sensor DHT11 conectado ao pino digital 2 do Arduino para medir a temperatura e a umidade do ambiente. Esses valores são exibidos em um display LCD 16x2, conectado via interface I2C. O código também envia os dados para o monitor serial, permitindo monitoramento via computador.

### Explicação do Código

- **Bibliotecas Utilizadas**:
  - `Wire.h`: Biblioteca padrão do Arduino para comunicação I2C.
  - `LiquidCrystal_I2C.h`: Biblioteca para controlar displays LCD via I2C.
  - `DHT.h`: Biblioteca para sensores de temperatura e umidade DHT.

- **Função `setup()`**:
  - Inicializa o display LCD e o sensor DHT11.
  - Configura a comunicação serial para monitoramento via computador.

- **Função `loop()`**:
  - Lê os valores de temperatura e umidade do sensor DHT11.
  - Exibe os valores no display LCD.
  - Envia os dados para o monitor serial.
  - Verifica se houve erro na leitura e, caso positivo, exibe uma mensagem de erro no LCD.

## Personalização

- **Intervalo de Leitura**: O tempo de espera entre as leituras pode ser ajustado modificando o valor de `delay(2000)` no `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o sensor DHT11 e o display LCD ao Arduino conforme as instruções.
2. Após carregar o código, os valores de temperatura e umidade serão exibidos no LCD e enviados para o monitor serial.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
