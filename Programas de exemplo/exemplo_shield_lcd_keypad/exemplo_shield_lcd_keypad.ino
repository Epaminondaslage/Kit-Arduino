#include <LiquidCrystal.h>  //INCLUSÃO DE BIBLIOTECA
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //PORTAS DO ARDUINO QUE SÃO UTILIZADAS PELO SHIELD KEYPAD DISPLAY LCD
  
void setup(){  
 lcd.begin(16, 2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
 lcd.setCursor(0,0); //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1) 
 lcd.print("MASTERWALKERSHOP"); //ESCREVE A PALAVRA "MASTERWALKERSHOP" NA PRIMEIRA LINHA DO DISPLAY LCD  
 lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
 lcd.print("TECLA :"); //ESCREVE A PALAVRA "TECLA" NA SEGUNDA LINHA DISPLAY LCD
}  
  
void loop(){  
 int botao; //VARIÁVEL DO TIPO INTEIRA
 botao = analogRead (0);  //Leitura do valor da porta analógica A0
 lcd.setCursor(8,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
 if (botao < 100) { //SE VALOR DA VARIÁVEL "botao" FOR MENOR QUE 100, FAZ 
  lcd.print ("DIREITA "); //ESCREVE NO LCD O TEXTO 
 }  
 else if (botao < 200) { //SE VALOR DA VARIÁVEL "botao" FOR MENOR QUE 200, FAZ
  lcd.print ("CIMA    ");  //ESCREVE NO LCD O TEXTO
 }  
 else if (botao < 400){ //SE VALOR DA VARIÁVEL "botao" FOR MENOR QUE 400, FAZ  
  lcd.print ("BAIXO   "); //ESCREVE NO LCD O TEXTO 
 }  
 else if (botao < 600){ //SE VALOR DA VARIÁVEL "botao" FOR MENOR QUE 600, FAZ  
  lcd.print ("ESQUERDA"); //ESCREVE NO LCD O TEXTO 
 }  
 else if (botao < 800){ //SE VALOR DA VARIÁVEL "botao" FOR MENOR QUE 800, FAZ 
  lcd.print ("SELECT  "); //ESCREVE NO LCD O TEXTO 
 }  
}
