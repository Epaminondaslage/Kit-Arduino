# Projeto: Controle de LEDs via Bluetooth com Android e Arduino

## Introdução

Este projeto permite o controle de três LEDs conectados ao Arduino Uno através de comandos enviados via Bluetooth de um dispositivo Android. A comunicação é estabelecida entre o Arduino e o Android utilizando um módulo Bluetooth como o HC-05 ou HC-06. O usuário pode controlar os LEDs enviando caracteres específicos ('R', 'G', 'B') a partir de um aplicativo de terminal Bluetooth no Android.

## Componentes Necessários

- Arduino Uno
- Módulo Bluetooth (HC-05 ou HC-06)
- LEDs (3 unidades)
- Resistores (220Ω) para cada LED
- Jumpers para conexões
- Dispositivo Android com Bluetooth

## Módulo Bluetooth (HC-05 ou HC-06)

O módulo Bluetooth HC-05 e o HC-06 são módulos de comunicação sem fio amplamente utilizados em projetos de eletrônica e automação. Eles são ideais para estabelecer uma comunicação Bluetooth entre microcontroladores, como o Arduino, e dispositivos móveis, como smartphones e tablets.

### HC-05

- **Tipo**: Módulo Bluetooth Serial.
- **Modo**: Pode operar em modo mestre e escravo.
- **Comunicação**: Comunicação serial (UART).
- **Variação**: Pode ser configurado para comunicação Bluetooth padrão e Bluetooth Low Energy (BLE) com firmware apropriado.
- **Configuração**: Possui pinos para comunicação serial e configuração de parâmetros via comandos AT.
- **Alcance**: Aproximadamente 10 metros (variável dependendo do ambiente e obstáculos).

### HC-06

- **Tipo**: Módulo Bluetooth Serial.
- **Modo**: Operação apenas em modo escravo.
- **Comunicação**: Comunicação serial (UART).
- **Configuração**: Configuração básica via comandos AT.
- **Alcance**: Aproximadamente 10 metros (variável dependendo do ambiente e obstáculos).

### Características Comuns

- **Interface**: Conexão com microcontroladores via UART (TX/RX).
- **Alimentação**: Normalmente funciona com uma tensão de 3,3V a 5V.
- **Taxa de Transmissão**: Configurável via comandos AT, comumente 9600 bps.
- **Antena**: Interna, para comunicação Bluetooth.
- **Facilidade de Uso**: Ambos os módulos são fáceis de integrar com projetos baseados em Arduino e outros microcontroladores.

### Aplicações Típicas

- **Controle Remoto**: Permite controlar dispositivos remotamente via Bluetooth.
- **Monitoramento de Dados**: Transmite dados de sensores para dispositivos móveis.
- **Automação Residencial**: Integra dispositivos de automação com controle via smartphones.

### Conexão com Arduino

Para conectar o módulo Bluetooth HC-05 ou HC-06 ao Arduino:

1. **Pino TX do Módulo** ao **Pino RX do Arduino**.
2. **Pino RX do Módulo** ao **Pino TX do Arduino**.
3. **Pino GND do Módulo** ao **Pino GND do Arduino**.
4. **Pino VCC do Módulo** ao **Pino 5V do Arduino**.

Após a conexão, você pode usar a comunicação serial para enviar e receber dados entre o Arduino e um dispositivo móvel via Bluetooth.

## Esquema de Conexão

### Conexão do Módulo Bluetooth ao Arduino

- **VCC**: Conecte ao **5V** do Arduino.
- **GND**: Conecte ao **GND** do Arduino.
- **TXD (Transmitir)**: Conecte ao **RX** (pino 0) do Arduino.
- **RXD (Receber)**: Conecte ao **TX** (pino 1) do Arduino.

**Nota**: Desconecte os pinos RX e TX do módulo Bluetooth durante a programação do Arduino para evitar conflitos de comunicação.

### Conexão dos LEDs ao Arduino

- **LED 1**:
  - Anodo (perna longa): Conecte ao pino **3** do Arduino.
  - Catodo (perna curta): Conecte ao GND através de um resistor de **220Ω**.
  
- **LED 2**:
  - Anodo (perna longa): Conecte ao pino **4** do Arduino.
  - Catodo (perna curta): Conecte ao GND através de um resistor de **220Ω**.
  
- **LED 3**:
  - Anodo (perna longa): Conecte ao pino **5** do Arduino.
  - Catodo (perna curta): Conecte ao GND através de um resistor de **220Ω**.
## Integração com Android

### Passos para Configuração

#### Pareamento com o Módulo Bluetooth:
- Ative o Bluetooth no dispositivo Android.
- Procure por dispositivos Bluetooth e encontre o módulo HC-05 ou HC-06.
- Pareie o dispositivo Android com o módulo Bluetooth (o código PIN padrão é "1234" ou "0000").

#### Conexão com o Aplicativo Android:
- Baixe um aplicativo de terminal Bluetooth, como "Bluetooth Terminal" ou "Serial Bluetooth Terminal", da Google Play Store.
- Abra o aplicativo e conecte-se ao módulo Bluetooth pareado.

#### Envio de Comandos:
- Envie o caractere **'R'** para ligar ou desligar o LED 1.
- Envie o caractere **'G'** para ligar ou desligar o LED 2.
- Envie o caractere **'B'** para ligar ou desligar o LED 3.

### Teste de Funcionamento

**Observação**: Após enviar os comandos, os LEDs conectados ao Arduino devem ligar ou desligar conforme o comando enviado, e uma mensagem de confirmação será exibida no monitor serial do Arduino.

## Aplicativos de Terminal Bluetooth

Você pode baixar os aplicativos de terminal Bluetooth recomendados diretamente da Google Play Store. Aqui estão alguns links e nomes de aplicativos populares que você pode procurar:

- **Bluetooth Terminal**
  - [Bluetooth Terminal - Google Play Store](https://play.google.com/store/apps/details?id=kr.glomr.bluetooth_terminal)

- **Serial Bluetooth Terminal**
  - [Serial Bluetooth Terminal - Google Play Store](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal)

- **Bluetooth Serial Controller**
  - [Bluetooth Serial Controller - Google Play Store](https://play.google.com/store/apps/details?id=cc.arduino.bluetoothserial)

### Passos para Baixar e Instalar

1. Abra a Google Play Store no seu dispositivo Android.
2. Use a barra de pesquisa para procurar pelo nome do aplicativo.
3. Toque em "Instalar" para baixar e instalar o aplicativo em seu dispositivo.

Após a instalação, você pode seguir os passos de configuração para conectar-se ao módulo Bluetooth e enviar comandos para o Arduino.


## Conclusão

Este projeto demonstra como utilizar um dispositivo Android para controlar LEDs conectados ao Arduino via Bluetooth. A integração é simples e pode ser expandida para controlar outros dispositivos ou sensores, oferecendo uma base sólida para projetos mais avançados de automação e controle remoto.
