void setup(){  
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}    
void loop(){
  Serial.println("MENSAGEM DE TESTE"); //ESCREVE O TEXTO NA JANELA SERIAL
  delay(1000); //DELAY DE 1 SEGUNDO
}
