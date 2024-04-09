
/**************************************************************************
 *                 Placa de desenvolvimento Arduino Uno                   *
 *                           Teclado maticial 4x4                         *
 * Fonte: http://blogmasterwalkershop.com.br/wp-content/uploads/2018/06/img01_como_usar_com_arduino_teclado_matricial_de_membrana_4x4_uno_mega_2560_leonardo_nano.jpg                                                               *
 **************************************************************************/
#include <Password.h>

Password password = Password( "1234" );

byte currentLength = 0;

void setup(){
 Serial.begin(9600);
 Serial.println("Try to guess the password!");
 Serial.println("Reset with ! evaluate with ?");
 Serial.print("Enter password: ");
}

void loop(){
 if (Serial.available()){
   char input = Serial.read();
   switch (input){
     case '!': //reset password
       password.reset();
       currentLength = 0;
       Serial.println("\tPassword is reset!");
     break;
     case '?': //evaluate password
       if (password.evaluate()){
         Serial.println("\tYou guessed the correct password!");
       }else{
         Serial.println("\tYou did not guess the correct password!");
       }
     break;
     default: //append any keypress that is not a '!' nor a '?' to the currently guessed password.
       password.append(input);
       currentLength++;
       
       //Print some feedback.
       Serial.print("Enter password: ");
       for (byte i=0; i<currentLength; i++){
         Serial.print('*');
       }
       Serial.println();
    }
 }
}
