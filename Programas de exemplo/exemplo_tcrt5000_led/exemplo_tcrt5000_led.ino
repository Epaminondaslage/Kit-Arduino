int pinoLED = 8; //PINO DIGITAL UTILIZADO PELO LED  
int pinoSR = 7; //PINO DIGITAL UTILIZADO PELO SENSOR REFLEXIVO  
int leituraD7; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA DIGITAL 
int estadoLED = 0; //VARIÁVEL QUE ARMAZENA O ESTADO ATUAL DO LED  
   
void setup(){  
  pinMode(pinoLED, OUTPUT); //DEFINE A PORTA COMO SAÍDA   
  pinMode(pinoSR, INPUT); //DEFINE A PORTA COMO ENTRADA
}  
   
void loop(){
  leituraD7 = digitalRead(pinoSR); //LÊ AS INFORMAÇÕES DO SENSOR REFLEXIVO
  if (leituraD7 != 1){ //SE LEITURA FOR DIFERENTE DE 1, FAZ  
    while(digitalRead(pinoSR) != 1){ //ENQUANTO O SINAL NO PINO FOR DIFERENTE DE 1  
     delay(100); //INTERVALO DE 100ms
    }  
    estadoLED = !estadoLED; //ALTERA O ESTADO DO LED (LIGADO/DESLIGADO)
    digitalWrite(pinoLED, estadoLED); //LIGA OU DESLIGA O LED DE ACORDO COM O estadoLED
  }   
}
