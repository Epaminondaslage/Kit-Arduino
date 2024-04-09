const int pinoSensorChuva = A2; //PINO ANALÓGICO UTILIZADO PELO SENSOR DE CHUVA
int leituraA2; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA

void setup(){  
    pinMode(pinoSensorChuva,INPUT); //DEFINE A PORTA COMO ENTRADA
    Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
void loop(){

  leituraA2 = analogRead(pinoSensorChuva); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  
 if(leituraA2 < 511){ //SE A LEITURA FOR MENOR QUE "511", FAZ / O VALOR 511 PODE SER AJUSTADO ENTRE 0 E 1023
    Serial.print(leituraA2); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / CHOVENDO"); //ESCREVE O TEXTO EM SEGUIDA
  }else{ //SENÃO
    Serial.print(leituraA2); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / SEM CHUVA"); //ESCREVE O TEXTO EM SEGUIDA
  }
  delay(100); //DELAY DE 100ms
}
