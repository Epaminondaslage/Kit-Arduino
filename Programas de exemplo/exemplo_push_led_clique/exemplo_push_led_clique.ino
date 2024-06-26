const int pushButton = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int led = 2; //PINO DIGITAL UTILIZADO PELO LED

int leitura = 0; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA DIGITAL
int estado = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO LED (ACESO / APAGADO)

void setup() {
pinMode(pushButton, INPUT); //DEFINE A PORTA COMO ENTRADA
pinMode(led, OUTPUT); //DEFINE A PORTA COMO SAÍDA
}
void loop(){
  leitura = digitalRead(pushButton); //LÊ O VALOR NA PORTA DIGITAL

  if((leitura == 0) && (estado == 0)){ //SE O VALOR LIDO FOR IGUAL A 0 "E" O ESTADO DO LED FOR IGUAL A 0, FAZ
  digitalWrite(led, HIGH); // LED ACESO
  estado = 1; //VARIÁVEL RECEBE VALOR 1 (LIGADO)
  delay(200); //INTERVALO DE 200ms
  }else{ //SENÃO, FAZ
    if((leitura == 0) && (estado == 1)){ //SE O VALOR LIDO FOR IGUAL A 0 "E" O ESTADO DO LED FOR IGUAL A 1, FAZ
      digitalWrite(led, LOW); // LED APAGADO
      estado = 0; //VARIÁVEL RECEBE VALOR 0 (DESLIGADO)
      delay(200); //INTERVALO DE 200ms
    }
  }
}



