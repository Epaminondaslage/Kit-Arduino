const int pinoSensorGas = A2; //PINO ANALÓGICO UTILIZADO PELO SENSOR DE GÁS
int leituraA2; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA

void setup(){  
    pinMode(pinoSensorGas,INPUT); //DEFINE A PORTA COMO ENTRADA
    Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
void loop(){

  leituraA2 = analogRead(pinoSensorGas); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  
 if(leituraA2 < 300){ //SE A LEITURA FOR MENOR QUE "300", FAZ / O VALOR 300 PODE SER AJUSTADO ENTRE 0 E 1023
    Serial.print(leituraA2); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / NIVEL DE GAS ACIMA DO NORMAL"); //ESCREVE O TEXTO EM SEGUIDA
  }else{ //SENÃO
    Serial.print(leituraA2); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / NIVEL DE GAS NORMAL"); //ESCREVE O TEXTO EM SEGUIDA
  }
  delay(100); //DELAY DE 100ms
}
