const int pushButton = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int ledPin = 2; //PINO DIGITAL UTILIZADO PELO LED

int leitura = 0; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA DIGITAL

void setup() {
pinMode(pushButton, INPUT); //DEFINE A PORTA COMO ENTRADA
pinMode(ledPin, OUTPUT); //DEFINE A PORTA COMO SAÍDA
}
void loop(){
  leitura = digitalRead(pushButton); //LÊ O VALOR NA PORTA DIGITAL

  if(leitura == 0){ //SE O VALOR LIDO FOR IGUAL A 0, FAZ
  digitalWrite(ledPin, HIGH); // LED ACESO
  }else{ //SENÃO, FAZ
    digitalWrite(ledPin, LOW); // LED APAGADO
  }
}



