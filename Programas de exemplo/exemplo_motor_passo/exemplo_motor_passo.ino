#include <Stepper.h> //INCLUSÃO DE BIBLIOTECA
 
const int stepsPerRevolution = 65; //NÚMERO DE PASSOS POR VOLTA
 
Stepper myStepper(stepsPerRevolution, 8,9,10,11); //INICIALIZA O MOTOR UTILIZANDO AS PORTAS DIGITAIS 8, 9, 10, 11
void setup(){
  myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
}
void loop(){
  //LAÇO "for" QUE LIMITA O TEMPO EM QUE O MOTOR GIRA NO SENTIDO ANTI-HORÁRIO      
  for(int i = 0; i < 50; i++){ //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 50 INCREMENTA "i"
          myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
  }
   //LAÇO "for" QUE LIMITA O TEMPO EM QUE O MOTOR GIRA NO SENTIDO HORÁRIO            
  for(int i = 0; i < 50; i++){//PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 50 INCREMENTA "i"
          myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
  }
}
