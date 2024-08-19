# Controle de Acesso com RFID, Display 16x2 e Relé usando Arduino UNO

Este projeto implementa um sistema de controle de acesso utilizando um leitor RFID, um display LCD 16x2 para monitoramento e um relé para acionar a fechadura. O sistema permite o acesso de cartões RFID autorizados e exibe mensagens de status no display.

## Componentes Necessários

- Arduino UNO
- Leitor RFID RC522
- Display LCD 16x2
- Módulo Relé
- Jumpers e Protoboard

## Conexões

### Conexões do Leitor RFID RC522

- **SDA (Pino 1 do RFID)**: Conectar ao pino digital 10 do Arduino
- **SCK (Pino 2 do RFID)**: Conectar ao pino digital 13 do Arduino
- **MOSI (Pino 3 do RFID)**: Conectar ao pino digital 11 do Arduino
- **MISO (Pino 4 do RFID)**: Conectar ao pino digital 12 do Arduino
- **RST (Pino 5 do RFID)**: Conectar ao pino digital 9 do Arduino
- **GND (Pino 6 do RFID)**: Conectar ao GND do Arduino
- **3.3V (Pino 7 do RFID)**: Conectar ao pino 3.3V do Arduino

### Conexões do Display LCD 16x2

- **RS (Pino 4 do LCD)**: Conectar ao pino digital 6 do Arduino
- **E (Pino 6 do LCD)**: Conectar ao pino digital 7 do Arduino
- **D4 (Pino 11 do LCD)**: Conectar ao pino digital 5 do Arduino
- **D5 (Pino 12 do LCD)**: Conectar ao pino digital 4 do Arduino
- **D6 (Pino 13 do LCD)**: Conectar ao pino digital 3 do Arduino
- **D7 (Pino 14 do LCD)**: Conectar ao pino digital 2 do Arduino

### Conexões do Módulo Relé

- **Sinal**: Conectar ao pino digital 8 do Arduino
- **GND**: Conectar ao GND do Arduino
- **VCC**: Conectar ao pino 5V do Arduino

## Como Funciona

O código utiliza um leitor RFID para detectar a aproximação de cartões. Se o UID do cartão corresponder a um dos cartões autorizados, o relé é acionado para abrir a fechadura e uma mensagem de "Acesso Liberado
