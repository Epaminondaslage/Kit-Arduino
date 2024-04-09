const int pinoSensorAlcool = 3; //PINO DIGITAL UTILIZADO PELO SENSOR DE ALCOOL

void setup(){  
    pinMode(pinoSensorAlcool,INPUT); //DEFINE A PORTA COMO ENTRADA
    Serial.begin(9600); //INICIALIZA A PORTA SERIAL
    Serial.println("Aquecendo sensor... por favor, aguarde..."); //ESCREVE O TEXTO NA JANELA SERIAL
    delay(300000); //INTERVALO DE 5 MINUTOS
    Serial.println("Sensor OK!"); //ESCREVE O TEXTO NA JANELA SERIAL
}
void loop(){

 if((digitalRead(pinoSensorAlcool) == 0){ //SE A LEITURA DO PINO FOR IGUAL A 0, FAZ
    Serial.println(" / ALCOOL DETECTADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }else{ //SENÃO
    Serial.println(" / ALCOOL NAO DETECTADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }
  delay(100); //DELAY DE 100ms
}
