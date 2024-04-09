#include <dht.h> //INCLUSÃO DE BIBLIOTECA

const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11

dht DHT; //VARIÁVEL DO TIPO DHT

void setup(){
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO ANTES DE INICIAR O CÓDIGO
}

void loop(){
  DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR
  Serial.print("Umidade = "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.print(DHT.humidity); //ESCREVE NA JANELA SERIAL O VALOR DA UMIDADE
  Serial.print(" %  "); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print("Temperatura = "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.print(DHT.temperature); //ESCREVE NA JANELA SERIAL O VALOR DE TEMPERATURA
  Serial.println("* Celsius  "); //ESCREVE O TEXTO NA JANELA SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}
