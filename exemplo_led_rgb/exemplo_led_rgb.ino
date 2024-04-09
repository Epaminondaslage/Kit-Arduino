const int ledVermelho = 8; //PINO 8 CORRESPONDE A COR VERMELHA(RED)
const int ledVerde = 9; //PINO 9 CORRESPONDE A COR VERDE(GREEN)
const int ledAzul = 10; //PINO 10 CORRESPONDE A COR AZUL(BLUE)
 
void setup() {
  pinMode(ledAzul,OUTPUT); //DECLARA A VARIÁVEL COMO SENDO SAÍDA
  pinMode(ledVerde,OUTPUT); //DECLARA A VARIÁVEL COMO SENDO SAÍDA  
  pinMode(ledVermelho,OUTPUT); //DECLARA A VARIÁVEL COMO SENDO SAÍDA 
}
void loop() {
  digitalWrite(ledVermelho,HIGH); //COLOCA A SAÍDA EM HIGH(LIGADA) E O LED ACENDE NA COR VERMELHO
  delay(500);//INTERVALO DE 500ms
  digitalWrite(ledVermelho,LOW); //COLOCA A SAÍDA EM LOW(DESLIGADA)

  digitalWrite(ledVerde,HIGH); //COLOCA A SAÍDA EM HIGH(LIGADA) E O LED ACENDE NA COR VERDE
  delay(500);//INTERVALO DE 500ms
  digitalWrite(ledVerde,LOW); //COLOCA A SAÍDA EM LOW(DESLIGADA)

  digitalWrite(ledAzul,HIGH); //COLOCA A SAÍDA EM HIGH(LIGADA) E O LED ACENDE NA COR AZUL
  delay(500); //INTERVALO DE 500ms
  digitalWrite(ledAzul,LOW); //COLOCA A SAÍDA EM LOW(DESLIGADA)
   
  //MISTURANDO AS CORES DO LED PARA OBTER CORES DIFERENTES
  digitalWrite(ledAzul,HIGH); //ACENDE
  digitalWrite(ledVerde,HIGH);//ACENDE
  digitalWrite(ledVermelho,HIGH);//ACENDE
  delay(1500); //INTERVALO DE 1500ms    
  digitalWrite(ledAzul,HIGH);//ACENDE
  digitalWrite(ledVerde,HIGH);//ACENDE
  digitalWrite(ledVermelho,LOW); //APAGA  
  delay(1500); //INTERVALO DE 1500ms      
  digitalWrite(ledAzul,LOW);//APAGA
  digitalWrite(ledVerde,HIGH); //ACENDE
  digitalWrite(ledVermelho,HIGH); //ACENDE
  delay(1500); //INTERVALO DE 1500ms      
  digitalWrite(ledAzul,HIGH); //ACENDE
  digitalWrite(ledVerde,LOW);//APAGA
  digitalWrite(ledVermelho,HIGH); //ACENDE
  delay(1500); //INTERVALO DE 1500ms
}
