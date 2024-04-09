int pinoLed = 10; //PINO DIGITAL UTILIZADO PELO LED
int pinoLDR = A2; //PINO ANALÓGICO UTILIZADO PELO LDR
int leituraA2; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA
  
void setup(){  
  pinMode(pinoLed, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(pinoLDR, INPUT); //DEFINE A PORTA COMO ENTRADA 
}    
void loop(){  
  leituraA2 = analogRead(pinoLDR); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)

  //O VALOR 600 PODE SER AJUSTADO
  if(leituraA2 > 600){ //SE O VALOR LIDO FOR MAIOR QUE 600, FAZ
    digitalWrite(pinoLed, HIGH); //ACENDE O LED
  }  
  else{ //SENÃO, FAZ
    digitalWrite(pinoLed, LOW); //APAGA O LED
  }  
}
