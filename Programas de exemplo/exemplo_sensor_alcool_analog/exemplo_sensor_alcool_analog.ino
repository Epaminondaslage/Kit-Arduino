const int pinoSensorAlcool = A1; //PINO ANALÓGICO UTILIZADO PELO SENSOR DE ÁLCOOL
int leituraA1; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA

void setup(){  
    pinMode(pinoSensorAlcool,INPUT); //DEFINE A PORTA COMO ENTRADA
    Serial.begin(9600); //INICIALIZA A PORTA SERIAL
    Serial.println("Aquecendo sensor... por favor, aguarde..."); //ESCREVE O TEXTO NA JANELA SERIAL
    delay(300000); //INTERVALO DE 5 MINUTOS
    Serial.println("Sensor OK!"); //ESCREVE O TEXTO NA JANELA SERIAL
}
void loop(){

  leituraA1 = analogRead(pinoSensorAlcool); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  
 if(leituraA1 < 300){ //SE A LEITURA FOR MENOR QUE "300", FAZ / O VALOR 300 PODE SER AJUSTADO ENTRE 0 E 1023
    Serial.print(leituraA1); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / ALCOOL NAO DETECTADO"); //ESCREVE O TEXTO EM SEGUIDA
  }else{ //SENÃO
    Serial.print(leituraA1); //ESCREVE O VALOR LIDO NA PORTA ANALÓGICA
    Serial.println(" / ALCOOL DETECTADO"); //ESCREVE O TEXTO EM SEGUIDA
  }
  delay(100); //DELAY DE 100ms
}
