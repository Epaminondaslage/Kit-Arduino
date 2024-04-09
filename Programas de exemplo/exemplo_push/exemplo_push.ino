const int pushButton = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON 

int leitura = 0; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA DIGITAL

void setup() {
pinMode(pushButton, INPUT); //DEFINE A PORTA COMO ENTRADA
Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
void loop(){
  leitura = digitalRead(pushButton); //LÊ O VALOR NA PORTA DIGITAL

  if(leitura == 0){ //SE O VALOR LIDO FOR IGUAL A 0, FAZ
  Serial.println("BOTAO PRESSIONADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }else{ //SENÃO, FAZ
    Serial.println("BOTAO NAO PRESSIONADO"); //ESCREVE O TEXTO NA JANELA SERIAL
  }
}
