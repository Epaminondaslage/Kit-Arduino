## Jogo Genius (ou Simon Says) 

O jogo Genius é uma aplicação de lógica e memória, onde o jogador precisa repetir sequências de luzes e sons que se tornam cada vez mais longas. O código é projetado para desafiar o jogador enquanto o Arduino gerencia a lógica do jogo e a detecção de erros.

### Componentes necessários:
- 4 LEDs de cores diferentes (vermelho, verde, azul, amarelo)
- 4 resistores de 220 ohms
- 4 botões
- Arduino UNO
- Jumpers e uma protoboard

### Esquema de ligações:
- LEDs:
  - LED 1 (vermelho): Anodo no pino 2, cátodo em GND com resistor de 220 ohms.
  - LED 2 (verde): Anodo no pino 3, cátodo em GND com resistor de 220 ohms.
  - LED 3 (azul): Anodo no pino 4, cátodo em GND com resistor de 220 ohms.
  - LED 4 (amarelo): Anodo no pino 5, cátodo em GND com resistor de 220 ohms.
  
- Botões:
  - Botão 1: Um lado no pino 8, outro lado no GND.
  - Botão 2: Um lado no pino 9, outro lado no GND.
  - Botão 3: Um lado no pino 10, outro lado no GND.
  - Botão 4: Um lado no pino 11, outro lado no GND.
 
 ### Descrição do Funcionamento: Jogo Genius com Arduino UNO

 #### 1. **Inicialização e Configuração**

 Quando o Arduino é ligado, ele executa a função `setup()`, que prepara os pinos para uso:

- **LEDs**: Configurados como saídas, permitindo que o Arduino controle quando acender ou apagar cada LED.
- **Botões**: Configurados como entradas, permitindo que o Arduino detecte quando um botão é pressionado.
- **Buzzer**: Configurado como saída, responsável por gerar os sons correspondentes às luzes dos LEDs.
  
O código também inicializa a comunicação serial para fins de debugging e gera o primeiro item da sequência aleatória que o jogador deverá repetir.

 #### 2. **Rodadas de Jogo**

O jogo segue um ciclo contínuo, controlado pela função `loop()`, que pode ser descrito em duas fases principais:

##### **Fase 1: Exibição da Sequência**

- O Arduino exibe a sequência de LEDs e sons até o nível atual (armazenada no array `sequence`).
- A sequência é reproduzida usando a função `playSequence()`, onde cada LED acende e emite um som através do buzzer por um tempo determinado. A função `lightUp()` cuida da operação combinada de acender o LED e tocar o som.

##### **Fase 2: Entrada do Jogador**

- Após a exibição da sequência, o jogo aguarda que o jogador repita a sequência pressionando os botões correspondentes aos LEDs.
- Para cada LED na sequência, o código verifica se o jogador pressionou o botão correto usando a função `checkButton()`.
  - Se o botão correto é pressionado, o Arduino acende o LED correspondente e emite o som, confirmando a escolha do jogador.
  - Se o jogador pressiona um botão incorreto, o jogo detecta o erro, exibe uma mensagem no monitor serial e reinicia o jogo para o nível inicial.

 #### 3. **Progressão no Jogo**

- Se o jogador repete corretamente a sequência, o jogo adiciona um novo LED à sequência e aumenta o nível do jogo.
- Este ciclo continua indefinidamente, com a sequência de LEDs aumentando de tamanho a cada rodada, tornando o jogo progressivamente mais desafiador.

 #### 4. **Reinício do Jogo**

- Sempre que o jogador comete um erro ao repetir a sequência, o jogo reinicia. O nível volta a ser 0, e uma nova sequência é gerada aleatoriamente.

  #### 5. Histórico de Pontuação

- O código  armazena e exibe a maior pontuação atingida pelo jogador. Se o jogador atingir uma nova maior pontuação, ela é exibida na comunicação serial.

  #### 6.  Timeout de 5 segundos

 - Implementado um timeout de 5 segundos para que o jogador pressione o botão correto, tornando o jogo mais desafiador.

  #### 7. Feedback de Avanço

 - O jogo indica o nível atual via comunicação serial sempre que o jogador avança para a próxima rodada.



### Descrição das Funções

#### 1. `lightUp(int led, int duration)`

Esta função acende o LED correspondente e toca o som associado por um tempo determinado.

- **Parâmetros**:
  - `led`: Índice do LED que será aceso.
  - `duration`: Duração em milissegundos para a luz e som.

- **Funcionamento**:
  - A função ativa o pino do LED e aciona o buzzer para emitir um som correspondente ao LED aceso. Após a duração especificada, o LED é apagado e o som é interrompido. Existe também uma pequena pausa entre os flashes para melhorar a visibilidade da sequência.

#### 2. `playSequence()`

Esta função toca a sequência de LEDs e sons armazenada na variável `sequence` até o nível atual.

- **Funcionamento**:
  - A função percorre o array `sequence` até o índice correspondente ao nível atual (`level`), acendendo cada LED e tocando o som correspondente na ordem correta.

#### 3. `checkButtonWithTimeout(int button, int timeout)`

Esta função verifica se o botão correto foi pressionado pelo jogador, com um tempo limite (timeout) para a espera.

- **Parâmetros**:
  - `button`: Índice do botão que está sendo verificado.
  - `timeout`: Tempo limite em milissegundos para o jogador pressionar o botão.

- **Retorno**:
  - `true` se o botão correto foi pressionado dentro do tempo limite; `false` caso contrário.

- **Funcionamento**:
  - A função verifica repetidamente o estado do botão durante o período do timeout. Se o botão correto for pressionado dentro do tempo limite, o LED correspondente acende, o som é tocado e a função retorna `true`. Caso contrário, a função retorna `false` após o timeout.

#### 4. `setup()`

Esta função é executada uma vez no início do programa e configura os pinos e inicializa variáveis.

- **Funcionamento**:
  - Configura os pinos dos LEDs como saídas, os pinos dos botões como entradas, e o pino do buzzer como saída.
  - Inicia a comunicação serial para debugging e exibição de informações.
  - Inicializa o gerador de números aleatórios e define o primeiro item da sequência.
  - Exibe a mensagem inicial e a maior pontuação armazenada até o momento.

#### 5. `loop()`

Esta função é executada continuamente e controla o fluxo principal do jogo.

- **Funcionamento**:
  - Reproduz a sequência atual de LEDs e sons usando a função `playSequence()`.
  - Espera que o jogador repita a sequência pressionando os botões na ordem correta. Se o jogador pressiona o botão incorreto, o jogo reinicia e a maior pontuação é atualizada, se necessário.
  - Se a sequência for repetida corretamente, um novo item é adicionado à sequência e o jogo avança para o próximo nível, indicando o progresso via comunicação serial.


