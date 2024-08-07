// Definição dos pinos
const int PINO_LED = 9;           // Pino PWM conectado ao LED
const int PINO_LDR = A0;          // Pino analógico conectado ao LDR
const int PINO_CHAVE = 2;         // Pino digital conectado à chave
const int PINO_LED_INDICADOR = 8; // Pino digital conectado ao LED indicador

// Constantes para o limiar e o intervalo de tempo
const int LIMIAR = 600;   // Valor de limiar para determinar escuridão
const int INTERVALO = 100; // Intervalo de tempo para o delay em milissegundos

void setup() {
  // Configuração dos pinos
  pinMode(PINO_LED, OUTPUT);          // Define a porta como saída
  pinMode(PINO_LDR, INPUT);            // Define a porta como entrada
  pinMode(PINO_CHAVE, INPUT_PULLUP);   // Define a porta da chave como entrada com pull-up interno
  pinMode(PINO_LED_INDICADOR, OUTPUT); // Define a porta do LED indicador como saída
  
  // Inicialização da comunicação serial para depuração (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê o estado da chave
  bool modoNoturno = !digitalRead(PINO_CHAVE); // Chave ativada retorna LOW
  
  // Atualiza o LED indicador baseado no modo
  digitalWrite(PINO_LED_INDICADOR, modoNoturno ? HIGH : LOW);

  // Lê o valor na porta analógica (valor lido em bits que vai de 0 a 1023)
  int leituraLDR = analogRead(PINO_LDR);
  
  // Imprime o valor lido e o estado do modo para depuração (opcional)
  Serial.print("Valor lido no LDR: ");
  Serial.print(leituraLDR);
  Serial.print(" -> Modo Noturno: ");
  Serial.println(modoNoturno ? "Ativo" : "Desativado");

  if (modoNoturno) {
    // Modo noturno: LED com intensidade máxima
    analogWrite(PINO_LED, 255); // Intensidade máxima
  } else {
    // Modo automático: ajusta a intensidade do LED baseado no LDR
    int valorPWM = map(leituraLDR, 0, 1023, 0, 255);
    analogWrite(PINO_LED, valorPWM);
  }

  // Pequena pausa para estabilidade
  delay(INTERVALO);
}
