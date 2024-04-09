const int pinoRele = 8; //PINO DIGITAL UTILIZADO PELO MÓDULO RELÉ
int status = 0; //VARIÁVEL QUE CONTROLA O STATUS DO MÓDULO RELÉ (LIGADO / DESLIGADO)

void setup(){
  pinMode(pinoRele, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  digitalWrite(pinoRele, HIGH); //MÓDULO RELÉ INICIA DESLIGADO
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}    
void loop(){

  char c = Serial.read(); //VARIÁVEL RESPONSÁVEL POR RECEBER O CARACTER DIGITADO NA JANELA SERIAL

  if (c == 'a'){ //SE CARACTER DIGITADO FOR IGUAL A "a", FAZ
    if (status == 0){ //SE VARIÁVEL FOR IGUAL A 0, FAZ
      digitalWrite(pinoRele, LOW); //ENERGIZA O PINO 8 E O RELÉ ATIVA
      status = 1; //VARIÁVEL RECEBE O VALOR 1
      Serial.println("RELE LIGADO"); //ESCREVE O TEXTO NA JANELA SERIAL
    }else{ //SENÃO, FAZ
      digitalWrite(pinoRele, HIGH); //ENERGIZA O PINO 8 E O RELÉ DESATIVA
      status = 0; //VARIÁVEL RECEBE O VALOR 0
      Serial.println("RELE DESLIGADO"); //ESCREVE O TEXTO NA JANELA SERIAL
    }
  }
}
