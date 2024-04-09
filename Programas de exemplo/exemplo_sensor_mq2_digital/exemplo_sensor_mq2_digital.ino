const int pinoSensorGas = 3; //PINO DIGITAL UTILIZADO PELO SENSOR DE GÁS

void setup(){  
    pinMode(pinoSensorGas,INPUT); //DEFINE A PORTA COMO ENTRADA
    Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
void loop(){

 if((digitalRead(pinoSensorGas) == 0){ //SE A LEITURA DO PINO FOR IGUAL A 0, FAZ
    Serial.println(" / NIVEL DE GAS ACIMA DO NORMAL"); //ESCREVE O TEXTO NA JANELA SERIAL
  }else{ //SENÃO
    Serial.println(" / NIVEL DE GAS NORMAL"); //ESCREVE O TEXTO NA JANELA SERIAL
  }
  delay(100); //DELAY DE 100ms
}
