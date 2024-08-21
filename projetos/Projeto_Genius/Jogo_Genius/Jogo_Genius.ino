/*
  Jogo Genius

  Arduino UNO, botões e LEDs. Esse código cria uma sequência de LEDs que o 
  jogador deve repetir. O jogo fica progressivamente mais difícil, adicionando
  mais LEDs à sequência a cada rodada.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Define pinos dos LEDs
const int ledPins[] = {2, 3, 4, 5};

// Define pinos dos botões
const int buttonPins[] = {8, 9, 10, 11};

// Define pino do buzzer
const int buzzerPin = 6;

// Frequências dos tons ajustadas para o som original do Genius
const int tones[] = {329, 261, 220, 164}; // E4, C4, A3, F3

// Sequência do jogo
int sequence[100];
int level = 0;
int maxScore = 0; // Armazena a maior pontuação atingida

// Função para acender os LEDs e tocar o som
void lightUp(int led, int duration) {
  digitalWrite(ledPins[led], HIGH);
  tone(buzzerPin, tones[led], duration);
  delay(duration);
  digitalWrite(ledPins[led], LOW);
  noTone(buzzerPin); // Para o som
  delay(200);  // Pequena pausa entre os flashes
}

// Função para tocar a sequência
void playSequence() {
  for (int i = 0; i <= level; i++) {
    lightUp(sequence[i], 500);
  }
}

// Função para verificar se o botão correto foi pressionado, com timeout
bool checkButtonWithTimeout(int button, int timeout) {
  unsigned long startTime = millis();
  while (millis() - startTime < timeout) {
    if (digitalRead(buttonPins[button]) == HIGH) {
      lightUp(button, 300);
      return true;
    }
  }
  return false;
}

// Função de setup
void setup() {
  // Configura pinos dos LEDs como saída
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Configura pinos dos botões como entrada
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  // Configura pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);

  // Inicia comunicação serial para debugging e pontuação
  Serial.begin(9600);

  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0));

  // Gera o primeiro item da sequência
  sequence[0] = random(0, 4);
  level = 0;

  // Mensagem inicial
  Serial.println("Bem-vindo ao Jogo Genius!");
  Serial.print("Maior Pontuação: ");
  Serial.println(maxScore);
}

// Função loop principal do jogo
void loop() {
  // Toca a sequência atual
  playSequence();

  // Espera o jogador repetir a sequência
  for (int i = 0; i <= level; i++) {
    bool correctButtonPressed = false;
    while (!correctButtonPressed) {
      for (int j = 0; j < 4; j++) {
        if (checkButtonWithTimeout(j, 5000)) { // 5 segundos para pressionar o botão correto
          if (sequence[i] == j) {
            correctButtonPressed = true;
          } else {
            // Se o jogador erra, o jogo reinicia
            Serial.println("Erro! Reiniciando o jogo...");
            delay(1000);

            // Atualiza a maior pontuação se necessário
            if (level > maxScore) {
              maxScore = level;
              Serial.print("Nova Maior Pontuação: ");
              Serial.println(maxScore);
            }

            // Reinicia o jogo
            level = 0;
            sequence[0] = random(0, 4);
            return;
          }
        }
      }
    }
  }

  // Se a sequência foi repetida corretamente, adiciona um novo LED à sequência
  level++;
  sequence[level] = random(0, 4);

  // Indica o avanço para o próximo nível
  Serial.print("Nível: ");
  Serial.println(level);

  // Pequena pausa antes de começar a próxima sequência
  delay(1000);
}
