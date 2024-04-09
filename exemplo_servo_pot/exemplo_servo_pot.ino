#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 
Servo servo; //OBJETO DO TIPO SERVO
 
const int pinoPOT = A0; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
const int pinoServo = 3; //PINO DIGITAL UTILIZADO PELO SERVO  
 
int leituraA0; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA           
  
void setup(){
  servo.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  pinMode(pinoPOT, INPUT); //DEFINE A PORTA COMO ENTRADA 
} 
void loop(){ 
  leituraA0 = analogRead(pinoPOT); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS) 
  leituraA0 = map(leituraA0, 0, 1023, 0, 180); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS 
  servo.write(leituraA0); //APLICA AO SERVO O VALOR / POSIÇÃO GERADO PELA FUNÇÃO "map"
  delay(15); //INTERVALO DE 15ms  
}
