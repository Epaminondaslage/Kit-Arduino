#include <DS1307.h> //INCLUSÃO DA BIBLIOTECA

DS1307 rtc(A4, A5); //SDA(PINO A4) E SCL(PINO A5)
 
void setup(){

  rtc.halt(false); //ACIONA O DS1307
   
  //AS 3 LINHAS ABAIXO PODEM SER COMENTADAS APÓS A PRIMEIRA INICIALIZAÇÃO
  rtc.setDOW(MONDAY); //SETA O DIA DA SEMANA
  rtc.setTime(17, 10, 0); //SETA A HORA
  rtc.setDate(1, 2, 2016); //SETA O DIA / MÊS / ANO
   
  rtc.setSQWRate(SQW_RATE_1); //DEFINIÇÃO DO PINO SQW/OUT
  rtc.enableSQW(true); //HABILITA O SQW
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
 
void loop(){
  Serial.print("Hora : "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.print(rtc.getTimeStr()); //ESCREVE NA JANELA SERIAL A HORA
  Serial.print(" "); //INSERE ESPAÇO
  Serial.print("Data : "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.print(rtc.getDateStr(FORMAT_SHORT)); //ESCREVE NA JANELA SERIAL A DATA
  Serial.print(" "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println(rtc.getDOWStr(FORMAT_SHORT)); //ESCREVE NA JANELA SERIAL O DIA DA SEMANA
  delay (1000); //INTERVALO DE 1 SEGUNDO
}
