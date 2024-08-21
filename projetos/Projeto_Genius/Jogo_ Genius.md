## Jogo Genius (ou Simon Says) 

Utilizar  um Arduino UNO, botões e LEDs. Esse código básico cria uma sequência de LEDs que o jogador deve repetir. O jogo fica progressivamente mais difícil, adicionando mais LEDs à sequência a cada rodada.

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
