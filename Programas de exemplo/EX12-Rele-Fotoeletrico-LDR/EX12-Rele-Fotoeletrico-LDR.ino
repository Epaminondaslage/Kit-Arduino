// Definição dos pinos
const int PINO_RELE = 10; // PINO DIGITAL UTILIZADO PELO RELÉ
const int PINO_LDR = A2;  // PINO ANALÓGICO UTILIZADO PELO LDR

// Constantes para o limiar e o intervalo de tempo
const int LIMIAR = 600;   // Valor de limiar para determinar escuridão
const int INTERVALO = 100; // Intervalo de tempo para o delay em milissegundos

void setup() {
  // Configuração dos pinos
  pinMode(PINO_RELE, OUTPUT); // Define a porta como saída
  pinMode(PINO_LDR, INPUT);   // Define a porta como entrada
  
  // Inicialização da comunicação serial para depuração (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lê o valor na porta analógica (valor lido em bits que vai de 0 a 1023)
  int leituraLDR = analogRead(PINO_LDR);
  
  // Imprime o valor lido para depuração (opcional)
  Serial.print("Valor lido no LDR: ");
  Serial.println(leituraLDR);
  
  // Liga o relé no escuro e desliga durante o dia
  digitalWrite(PINO_RELE, leituraLDR < LIMIAR ? HIGH : LOW);

  // Pequena pausa para estabilidade
  delay(INTERVALO);
}
