/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                                 Uso de LDR
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/

#define LAMP 8 // Define o pino da lâmpada como 8
int LDR;   // Variável para armazenar a leitura média do LDR
int cont;  // Variável utilizada para armazenar os valores lidos pelo sensor em cada iteração
int i;    // Variável para contagem das iterações



void setup()
{
  pinMode(LAMP,OUTPUT); // Define o pino D8 como saída (onde a lâmpada está conectada)
  Serial.begin(19200);   // Inicia a comunicação serial com uma taxa de 19200 bps
}

void loop()
{
  LDR = 0; // Zera a variável LDR antes de iniciar as leituras
  for(i = 0; i < 50; i++) // Executa 50 leituras do sensor
    {
      cont = analogRead(A0); // Lê o valor do sensor (LDR conectado ao pino A0) e armazena na variável cont
      LDR = LDR + cont; // Soma o valor lido ao valor acumulado em LDR
      delay(100); // Atraso de 100 milissegundos entre as leituras
     }
  
  LDR = LDR / 50; // Calcula a média dos valores lidos dividindo por 50
  Serial.println(LDR); // Exibe o valor médio do LDR no monitor serial

  // Se o valor lido (luminosidade) for maior ou igual a 400, liga a lâmpada, senão desliga a lâmpada
  (LDR >= 400) ? (digitalWrite(LAMP,HIGH)) : (digitalWrite(LAMP,LOW));
}
