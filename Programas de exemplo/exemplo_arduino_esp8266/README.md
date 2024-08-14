# Web Server com ESP8266 e Arduino UNO

## Descrição do Projeto

Este projeto utiliza um Arduino UNO e um módulo ESP8266 para criar um servidor web que exibe a leitura de um pino analógico. O servidor web é acessado através de um navegador, e a página exibida é atualizada automaticamente a cada 5 segundos com a nova leitura do pino analógico A1. Este projeto é ideal para monitoramento remoto de sensores e controle de dispositivos via internet.

## Descrição do Módulo ESP8266

O **ESP8266** é um módulo Wi-Fi altamente integrado que pode ser utilizado para adicionar conectividade sem fio a projetos de eletrônica e IoT (Internet of Things). Ele possui um microcontrolador de 32 bits com arquitetura RISC, memória RAM, GPIOs e um módulo RF, tudo em um único chip. O ESP8266 é capaz de operar tanto como cliente quanto como ponto de acesso, tornando-o ideal para uma ampla gama de aplicações.

### Características principais do ESP8266:

- **Wi-Fi 802.11 b/g/n**: Suporte para redes Wi-Fi, incluindo modos de operação AP (Access Point) e STA (Station).
- **Baixo consumo de energia**: Ideal para aplicações que necessitam de eficiência energética.
- **GPIOs**: Vários pinos de entrada/saída para conectar sensores, atuadores e outros componentes.
- **Compatibilidade com AT Commands**: Pode ser controlado via comandos AT, o que facilita a integração com microcontroladores como o Arduino.
- **Capacidade de operar como servidor web**: Pode hospedar páginas web simples, como no projeto descrito.

## Conexões do ESP8266 ao Arduino

Para conectar o módulo ESP8266 ao Arduino, siga estas instruções:

- **TX do ESP8266**: Conecte ao pino **2** (RX) do Arduino.
- **RX do ESP8266**: Conecte ao pino **3** (TX) do Arduino.
- **VCC do ESP8266**: Conecte ao pino **3.3V** do Arduino.
- **GND do ESP8266**: Conecte ao pino **GND** do Arduino.
- **CH_PD do ESP8266**: Conecte ao pino **3.3V** do Arduino.

**Comandos AT** são um conjunto de comandos utilizados para controlar modems e módulos de comunicação, como o ESP8266, através de uma interface serial. "AT" é uma abreviação de "Attention," indicando que o dispositivo deve prestar atenção ao comando que segue.

Esses comandos foram originalmente desenvolvidos para controlar modems de telefone, mas se tornaram um padrão amplamente utilizado para controlar diversos dispositivos de comunicação. No contexto do ESP8266, os comandos AT permitem configurar e gerenciar diversas funções, tais como:

- **Configuração da rede Wi-Fi**: Conectar-se a uma rede, definir o modo de operação (AP, STA, ou ambos).
- **Envio e recepção de dados**: Estabelecer conexões TCP/UDP, enviar dados pela rede e receber respostas.
- **Controle de hardware**: Reiniciar o módulo, verificar o status, configurar GPIOs, entre outros.

### Exemplos de Comandos AT

- **`AT+RST`**: Reinicia o módulo ESP8266.
- **`AT+CWMODE=3`**: Configura o ESP8266 para operar no modo AP+STA.
- **`AT+CWJAP="SSID","PASSWORD"`**: Conecta o ESP8266 a uma rede Wi-Fi utilizando o SSID e a senha fornecidos.
- **`AT+CIFSR`**: Retorna o endereço IP atribuído ao ESP8266.
- **`AT+CIPMUX=1`**: Habilita múltiplas conexões TCP/IP.
- **`AT+CIPSERVER=1,80`**: Inicia um servidor na porta 80, permitindo que o ESP8266 receba conexões HTTP.

Os comandos AT são enviados ao ESP8266 através de uma interface serial (como a Serial do Arduino), e o módulo responde com o status da operação ou com os dados solicitados. Eles são fundamentais para configurar e utilizar o ESP8266 sem a necessidade de programar diretamente o firmware do módulo, tornando a configuração e o uso do ESP8266 acessível e flexível para uma ampla gama de aplicações.


## Configurações de Wi-Fi

Para configurar o módulo ESP8266 para conectar à sua rede Wi-Fi, você deve fornecer o nome da rede (SSID) e a senha (password). Essas informações são inseridas no código usando o comando `AT+CWJAP` da seguinte maneira:

```cpp
sendData("AT+CWJAP=\"NomeDaRede\",\"SenhaDaRede\"\r\n", 10000, DEBUG);
```
**NomeDaRede**: Substitua este valor pelo SSID da sua rede Wi-Fi.

**SenhaDaRede**: Substitua este valor pela senha da sua rede Wi-Fi.

## Funcionamento do Código

### Declaração e Inicialização

- `#include <SoftwareSerial.h>`: Inclui a biblioteca para criar uma porta serial via software.
- `SoftwareSerial esp8266(2, 3);`: Define a comunicação serial com o ESP8266 nos pinos 2 (RX) e 3 (TX) do Arduino.
- `String leituraAnalog1 = "";`: Variável para armazenar a leitura do pino analógico A1.

### Função `setup()`

#### Inicialização das Comunicações Seriais:

- `Serial.begin(9600);`: Inicializa a comunicação serial do Arduino a 9600 bps.
- `esp8266.begin(9600);`: Inicializa a comunicação serial com o ESP8266 a 9600 bps.

#### Configuração do ESP8266:

- `sendData("AT+RST\r\n", 2000, DEBUG);`: Reinicia o módulo ESP8266.
- `sendData("AT+CWMODE=3\r\n", 1000, DEBUG);`: Configura o ESP8266 no modo AP+STA (ponto de acesso + estação).
- `sendData("AT+CWJAP=\"NomeDaRede\",\"SenhaDaRede\"\r\n", 10000, DEBUG);`: Conecta o ESP8266 à rede Wi-Fi.
- `sendData("AT+CIFSR\r\n", 1000, DEBUG);`: Retorna o endereço IP do ESP8266.
- `sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);`: Habilita múltiplas conexões.
- `sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);`: Inicia um servidor na porta 80.

### Função `loop()`

A função `loop()` aguarda requisições do navegador e, ao recebê-las, envia a leitura do pino analógico A1 ao cliente, fechando a conexão em seguida.

#### Limpeza da Variável:

- `leituraAnalog1 = "";`: Limpa o valor da variável `leituraAnalog1` antes de uma nova leitura.

#### Recepção e Processamento de Dados:

- `if(esp8266.available()){ ... }`: Verifica se há dados disponíveis na serial do ESP8266.
- `if(esp8266.find("+IPD,")){ ... }`: Verifica se há uma nova requisição de dados do navegador.
- `leituraAnalog1 = String(analogRead(1));`: Lê o valor do pino A1 e o armazena como uma string.

#### Criação e Envio da Página Web:

- **Criação da página**: A página HTML é criada dinamicamente com a leitura do pino analógico A1.
- **Envio da página**: O conteúdo da página é enviado ao cliente através de comandos AT do ESP8266.
- **Fechamento da Conexão**: A conexão é fechada após o envio da página, e o loop aguarda uma nova requisição.

### Função `sendData(String command, const int timeout, boolean debug)`

- **Envio de Comandos**: Envia comandos AT ao ESP8266 e retorna a resposta.
- **Depuração**: Se o modo de depuração estiver ativado, exibe a resposta do ESP8266 no monitor serial.

### Função `getDecimal(float val)`

- **Conversão de Float para Decimal**: Converte um valor float para seu valor decimal com precisão de duas casas decimais, retornando o valor como um long.

## Conclusão

Este projeto exemplifica a integração entre o Arduino UNO e o módulo ESP8266 para a criação de um servidor web, demonstrando a capacidade de monitoramento remoto em tempo real. Ao utilizar o protocolo HTTP, o ESP8266 serve uma página web dinâmica que exibe leituras do pino analógico A1, com atualizações automáticas a cada 5 segundos.

A implementação explora a comunicação serial via SoftwareSerial, permitindo que o Arduino UNO se comunique de maneira eficiente com o ESP8266, utilizando comandos AT para configurar o módulo e gerenciar conexões Wi-Fi e HTTP. A configuração do ESP8266 como um ponto de acesso e estação simultaneamente (AP+STA) permite uma flexibilidade maior, permitindo tanto a criação de uma rede própria quanto a conexão a uma rede existente.

Além disso, a lógica implementada no loop principal demonstra a capacidade de tratamento de múltiplas requisições HTTP, utilizando a funcionalidade de múltiplas conexões do ESP8266. A criação dinâmica de páginas web com dados de sensores possibilita uma aplicação prática em projetos de IoT, onde o monitoramento de dados remotos e o controle de dispositivos via web são essenciais.

O projeto pode ser facilmente expandido para incluir múltiplos sensores, controles adicionais, e até mesmo funcionalidades avançadas como autenticação de usuário e criptografia, dependendo das necessidades do sistema. Assim, este projeto serve como uma base robusta para o desenvolvimento de aplicações de IoT utilizando o ESP8266 e o Arduino UNO.

