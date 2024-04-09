char buffer; //VARIÁVEL DO TIPO CHAR

const int LED1 = 3; //PINO DIGITAL UTILIZADO PELO LED
const int LED2 = 4; //PINO DIGITAL UTILIZADO PELO LED
const int LED3 = 5; //PINO DIGITAL UTILIZADO PELO LED

int statusLED1 = 0; //VARIÁVEL QUE ARMAZENA O ESTADO DO LED 1
int statusLED2 = 0; //VARIÁVEL QUE ARMAZENA O ESTADO DO LED 2
int statusLED3 = 0; //VARIÁVEL QUE ARMAZENA O ESTADO DO LED 3
 
void setup(){
  pinMode(LED1, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(LED2, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(LED3, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  Serial.begin(9600); //INICIALIZA A SERIAL
}
void loop(){
  while(Serial.available() > 0){ //ENQUANTO A SERIAL ESTIVER HABILITADA, FAZ
    buffer = Serial.read(); //VARIÁVEL ARMAZENA A LEITURA FEITA
    if ((buffer == 'R') && (statusLED1 == 0)){ //SE LEITURA FOR IGUAL A "R" E O STATUS DO LED FOR IGUAL A 0, FAZ
      digitalWrite(LED1, HIGH); //LIGA O LED1
      Serial.println("LED 1 ligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED1 = 1; //VARIÁVEL RECEBE VALOR 1
    }else{ //SENÃO
      if((buffer == 'R') && (statusLED1 == 1)){ //SE LEITURA FOR IGUAL A "R" E O STATUS DO LED FOR IGUAL A 1, FAZ
        digitalWrite(LED1, LOW); //DESLIGA O LED1
      Serial.println("LED 1 desligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED1 = 0; //VARIÁVEL RECEBE VALOR 0
      }
    }
    if ((buffer == 'G') && (statusLED2 == 0)){ //SE LEITURA FOR IGUAL A "G" E O STATUS DO LED FOR IGUAL A 0, FAZ
      digitalWrite(LED2, HIGH); //LIGA O LED2
      Serial.println("LED 2 ligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED2 = 1; //VARIÁVEL RECEBE VALOR 1
    }else{ //SENÃO
      if((buffer == 'G') && (statusLED2 == 1)){ //SE LEITURA FOR IGUAL A "G" E O STATUS DO LED FOR IGUAL A 1, FAZ
        digitalWrite(LED2, LOW); //DESLIGA O LED2
      Serial.println("LED 2 desligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED2 = 0; //VARIÁVEL RECEBE VALOR 0
      }
    }
    if ((buffer == 'B') && (statusLED3 == 0)){ //SE LEITURA FOR IGUAL A "B" E O STATUS DO LED FOR IGUAL A 0, FAZ
      digitalWrite(LED3, HIGH); //LIGA O LED3
      Serial.println("LED 3 ligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED3 = 1; //VARIÁVEL RECEBE VALOR 1
    }else{ //SENÃO
      if((buffer == 'B') && (statusLED3 == 1)){ //SE LEITURA FOR IGUAL A "B" E O STATUS DO LED FOR IGUAL A 1, FAZ
      digitalWrite(LED3, LOW); //DESLIGA O LED3
      Serial.println("LED 3 desligado!"); //ESCREVE O TEXTO NA SERIAL (RETORNO DE INFORMAÇÃO PARA O APP)
      statusLED3 = 0; //VARIÁVEL RECEBE VALOR 0
      }
    }
  }
}
