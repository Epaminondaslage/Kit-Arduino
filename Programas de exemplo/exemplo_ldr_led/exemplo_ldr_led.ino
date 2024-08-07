// Definição dos pinos
const int PINO_RELE = 10; // PINO DIGITAL UTILIZADO PELO RELÉ
const int PINO_LDR = A2;  // PINO ANALÓGICO UTILIZADO PELO LDR

// Variável para armazenar o valor lido na porta analógica
int leituraLDR; 

void setup() {
  // Configuração dos pinos
  pinMode(PINO_RELE, OUTPUT); // DEFINE A PORTA COMO SAÍDA
  pinMode(PINO_LDR, INPUT);   // DEFINE A PORTA COMO ENTRADA
  
  // Inicialização da comunicação serial para depuração (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê o valor na porta analógica (valor lido em bits que vai de 0 a 1023)
  leituraLDR = analogRead(PINO_LDR);
  
  // Imprime o valor lido para depuração (opcional)
  Serial.print("Valor lido no LDR: ");
  Serial.println(leituraLDR);

  // Ajuste do valor limite conforme necessário
  const int LIMIAR = 600;
  
  // Liga o relé no escuro e desliga durante o dia
  if (leituraLDR < LIMIAR) {
    digitalWrite(PINO_RELE, HIGH); // LIGA O RELÉ (ESCURO)
  } else {
    digitalWrite(PINO_RELE, LOW);  // DESLIGA O RELÉ (CLARO)
  }

  // Pequena pausa para estabilidade (opcional)
  delay(100);
}

