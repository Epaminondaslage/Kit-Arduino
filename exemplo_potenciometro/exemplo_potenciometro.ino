const int pinoPot = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
int leituraA5; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA
  
void setup(){  
  pinMode(pinoPot, INPUT); //DEFINE A PORTA COMO ENTRADA
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}    
void loop(){  
  leituraA5 = analogRead(pinoPot); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  Serial.print(leituraA5); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
  Serial.println(" bits"); //ESCREVE O TEXTO EM SEGUIDA
  delay(100); //DELAY DE 100ms
}
