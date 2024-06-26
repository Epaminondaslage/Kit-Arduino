int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; // PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; // //PINO REFERNETE A LIGAÇÃO NO PINO KEY / SW

void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  Serial.begin (9600); //INICIALIZA A PORTA SERIAL
}
void loop(){  
  Serial.print("EIXO X: "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println(analogRead(eixo_X), DEC); //ECREVE NA JANELA SERIAL O VALOR NO EIXO X
  Serial.print("EIXO Y: "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println (analogRead(eixo_Y), DEC); //ECREVE NA JANELA SERIAL O VALOR NO EIXO Y
  
  Serial.print("BOTAO"); //ESCREVE O TEXTO NA JANELA SERIAL
  if (digitalRead(botao) == HIGH){ //SE LEITURA DO PINO FOR IGUAL A HIGH, FAZ
    Serial.println(" NAO ESTA PRESSIONADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }
  else{ //SENÃO
    Serial.println (" ESTA PRESSIONADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }
  delay(500); //INTERVALO DE 500 MILISEGUNDOS
}
