# Sistema de Controle de Acesso com Arduino e RFID

Este projeto implementa um sistema de controle de acesso utilizando um Arduino UNO e um leitor RFID MFRC522. O sistema lê o ID de um cartão RFID e verifica se ele está autorizado para conceder acesso. Se o cartão for autorizado, um LED verde acende, indicando que o acesso foi permitido.

## Componentes Necessários

- Arduino UNO
- Leitor RFID MFRC522
- Cartões ou tags RFID compatíveis com o MFRC522
- LED verde
- LED vermelho
- Resistores de 220 ohms (para os LEDs)
- Jumpers e Protoboard

## Conexões

- **SS_PIN (Pino 10)**: Conectar ao pino SDA do MFRC522
- **RST_PIN (Pino 9)**: Conectar ao pino RST do MFRC522
- **MOSI (Pino 11)**: Conectar ao pino MOSI do MFRC522
- **MISO (Pino 12)**: Conectar ao pino MISO do MFRC522
- **SCK (Pino 13)**: Conectar ao pino SCK do MFRC522
- **GND**: Conectar ao GND do MFRC522
- **3.3V**: Conectar ao 3.3V do MFRC522
- **LED Vermelho (Pino 5)**: Conectar ao ânodo do LED vermelho (usar resistor de 220 ohms)
- **LED Verde (Pino 3)**: Conectar ao ânodo do LED verde (usar resistor de 220 ohms)
- Os cátodos dos LEDs devem ser conectados ao GND.

## Bibliotecas Necessárias

Este projeto requer a instalação das seguintes bibliotecas:

- [SPI](https://www.arduino.cc/en/Reference/SPI)
- [MFRC522](https://github.com/miguelbalboa/rfid)

Para instalar as bibliotecas, você pode usar o Gerenciador de Bibliotecas da IDE do Arduino.

## Código

O código completo está disponível no arquivo `rfid_access_control.ino`. Ele é composto pelas seguintes seções:

1. **Inclusão de Bibliotecas**: As bibliotecas SPI e MFRC522 são incluídas para comunicação com o leitor RFID.
2. **Definição de Pinos**: Os pinos do Arduino para conexão com o leitor RFID e LEDs são definidos.
3. **Setup**: Inicializa a comunicação serial, o barramento SPI e o módulo MFRC522. Também configura os pinos dos LEDs como saídas.
4. **Loop Principal**: No loop principal, o sistema verifica continuamente se um novo cartão RFID é aproximado do leitor. Se um cartão autorizado for detectado, o LED verde acende para indicar que o acesso foi concedido.

## IDs Autorizados

No código, os seguintes IDs de cartões/tag são autorizados:

- `51 48 9B 2E`
- `D3 7F 94 79`
- `14 A7 B1 7A`
- `94 43 BB 7A`

Você pode adicionar ou remover IDs autorizados conforme necessário, modificando a comparação na seção do loop principal do código.

## Como Funciona

1. Quando o sistema está ligado, ele espera que um cartão RFID seja aproximado do leitor.
2. Se um cartão é detectado, o sistema verifica se o ID do cartão está na lista de IDs autorizados.
3. Se o ID for autorizado, o LED verde acende por 5 segundos, indicando que o acesso foi concedido.
4. Se o ID não for autorizado, o LED vermelho permanece aceso.

## Personalização

- **Tempo do LED Verde**: Você pode ajustar o tempo em que o LED verde permanece aceso, modificando o valor do `delay(5000)` para o tempo desejado em milissegundos.
- **IDs Autorizados**: Para adicionar novos cartões, obtenha o ID através do monitor serial e adicione-o à lista de IDs autorizados no código.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

- Autor Original: Felipe Gbur
- Adaptação: Epaminondas Lage
