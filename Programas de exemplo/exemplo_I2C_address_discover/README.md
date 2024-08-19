# Scanner de Endereços I2C com Arduino UNO

Este projeto é utilizado para descobrir os endereços de dispositivos conectados ao barramento I2C utilizando um Arduino UNO. É útil para identificar os endereços I2C de sensores, displays, ou outros dispositivos que utilizam esse protocolo de comunicação.

## Componentes Necessários

- Arduino UNO
- Dispositivos I2C (sensores, displays, etc.)
- Jumpers e Protoboard

## Conexões

- **SDA**: Conectar ao pino A4 do Arduino (linha de dados I2C)
- **SCL**: Conectar ao pino A5 do Arduino (linha de clock I2C)
- **GND**: Conectar ao GND do Arduino
- **VCC**: Conectar ao +5V ou +3.3V, dependendo dos requisitos do dispositivo I2C

## Como Funciona

O código percorre todos os endereços I2C possíveis (de 0 a 127) e tenta se comunicar com cada um. Se um dispositivo responde a um determinado endereço, o código imprime esse endereço na porta serial, permitindo que você identifique os dispositivos conectados e seus respectivos endereços.

### Explicação do Código

- **Função `Wire.beginTransmission(endereco)`**: Inicia uma transmissão I2C para o endereço especificado.
- **Função `Wire.endTransmission()`**: Finaliza a transmissão e retorna um código de status. Um código de 0 indica que um dispositivo respondeu no endereço especificado.
- **Variáveis `TEMPOLEITURA` e `TEMPOESPERA`**: Controlam os intervalos de tempo entre as tentativas de comunicação e a espera após a detecção de um dispositivo.

## Personalização

- **Intervalo entre Leituras**: O tempo entre cada leitura pode ser ajustado alterando o valor de `TEMPOLEITURA`.
- **Tempo de Espera após Detecção**: O tempo de espera após encontrar um dispositivo pode ser ajustado modificando `TEMPOESPERA`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte seus dispositivos I2C ao Arduino conforme as instruções.
2. Abra o Monitor Serial na IDE do Arduino para visualizar os endereços I2C detectados.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto Elaborado/Adaptado por Epaminondas Lage
