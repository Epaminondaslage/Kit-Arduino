# Controle de RTC DS3231 com Arduino UNO

Este projeto demonstra como utilizar o módulo de Relógio em Tempo Real (RTC) DS3231 com um Arduino UNO. O código permite configurar o relógio com a data e hora da compilação do código, monitorar o horário atual e obter a temperatura medida pelo RTC.

## Componentes Necessários

- Arduino UNO
- Módulo RTC DS3231
- Jumpers e Protoboard

## Conexões

### Conexões do RTC DS3231

- **SDA (Pino 4 do DS3231)**: Conectar ao pino A4 do Arduino (linha de dados I2C)
- **SCL (Pino 5 do DS3231)**: Conectar ao pino A5 do Arduino (linha de clock I2C)
- **GND (Pino 6 do DS3231)**: Conectar ao GND do Arduino
- **VCC (Pino 8 do DS3231)**: Conectar ao pino 5V do Arduino

## Como Funciona

O código inicializa o módulo RTC DS3231 e verifica se o relógio está atualizado. Se o relógio não estiver funcionando corretamente ou se a bateria estiver descarregada, o código ajusta o RTC com a data e hora da compilação do código. O loop principal do código exibe a data, a hora e a temperatura medida pelo RTC a cada 5 segundos.

### Explicação do Código

- **Verificação do RTC**: O código verifica se o RTC está funcionando e se a data/hora estão atualizadas. Se necessário, ajusta o relógio com a data/hora da compilação.
- **Funções de Formatação**: Duas funções (`formatDate()` e `formatTime()`) são usadas para formatar a data e a hora como strings legíveis antes de exibi-las no monitor serial.
- **Monitoramento de Temperatura**: O RTC DS3231 possui um sensor de temperatura integrado, que pode ser monitorado e exibido no monitor serial.

## Personalização

- **Formato de Data e Hora**: O formato da data e da hora pode ser ajustado modificando as strings de formato nas funções `formatDate()` e `formatTime()`.
- **Intervalo de Atualização**: O tempo entre as atualizações pode ser ajustado modificando o valor de `delay(5000)`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte o módulo RTC DS3231 ao Arduino conforme as instruções.
2. Abra o Monitor Serial na IDE do Arduino para visualizar a data, hora e temperatura em tempo real.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
