// Definição dos pinos dos LEDs
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
// Definição do pino do botão
const int buttonPin = 3;

// Variável para armazenar o valor aleatório
long a;

void setup() {
  // Inicializa os pinos dos LEDs como saídas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  // Inicializa o pino do botão como entrada
  pinMode(buttonPin, INPUT);

  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  // Usando um loop for para repetir indefinidamente
  for (; digitalRead(buttonPin) == LOW;) {
    // Gera um número aleatório entre 8 e 11 (pinos dos LEDs)
    a = random(8, 12);

    // Acende o LED correspondente
    digitalWrite(a, HIGH);

    // Aguarda por um período de tempo
    delay(500);

    // Apaga o LED
    digitalWrite(a, LOW);

    // Aguarda por um período de tempo antes de repetir
    delay(500);
  }

  // Apaga todos os LEDs quando o botão é pressionado
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
