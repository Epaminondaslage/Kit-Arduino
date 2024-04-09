int redLedPin = 13; //VARIÁVEL RECEBE O PINO DIGITAL EM QUE O LED VERMELHO ESTÁ CONECTADO
int greenLedPin = 12; //VARIÁVEL RECEBE O PINO DIGITAL EM QUE O LED VERDE ESTÁ CONECTADO

int redLedState = LOW; //DEFINE QUE O ESTADO INICIAL DO LED VERMELHO É DESLIGADO
int greenLedState = LOW; //DEFINE QUE O ESTADO INICIAL DO LED VERDE É DESLIGADO

long previousMillisRed = 0; //VARIÁVEL QUE CONTROLA O TEMPO DO LED VERMELHO
long previousMillisGreen = 0; //VARIÁVEL QUE CONTROLA O TEMPO DO LED VERDE

long redLedInterval = 2000; //VARIÁVEL QUE REGISTRA O INTERVALO (2000ms = 2 SEGUNDOS)
long greenLedInterval = 2000; //VARIÁVEL QUE REGISTRA O INTERVALO (500ms = 500 MILISEGUNDOS)

void setup(){  
  pinMode(redLedPin, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(greenLedPin, OUTPUT); //DEFINE A PORTA COMO SAÍDA 
}
void loop()
{
  //INICIO DO CONTROLE DO LED VERMELHO
  unsigned long currentMillisRed = millis(); //VARIÁVEL RECEBE O TEMPO ATUAL EM MILISEGUNDOS

  if (currentMillisRed - previousMillisRed > redLedInterval) { //SE O TEMPO ATUAL MENOS O TEMPO ANTERIOR FOR MENOR QUE O INTERVALO, FAZ
    previousMillisRed = currentMillisRed; //TEMPO ANTERIOR GUARDA O TEMPO ATUAL

    if (redLedState == LOW) { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM LOW MUDA PARA HIGH
      redLedState = HIGH; //VARIÁVEL RECEBE ESTADO HIGH(LIGA A PORTA)
    } else { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM HIGH MUDA PARA LOW
      redLedState = LOW; //VARIÁVEL RECEBE ESTADO LOW(DESLIGA A PORTA)
    }

    digitalWrite(redLedPin, redLedState); //ESCREVE NA PORTA DIGITAL 8 O ESTADO DO LED VERMELHO (HIGH OU LOW)
  }
  //FIM DO CONTROLE DO LED VERMELHO
  //-----------------------------------------------------------------------------------------------------------------------------------------
  //INICIO DO CONTROLE DO LED VERDE
  unsigned long currentMillisGreen = millis(); //VARIÁVEL RECEBE O TEMPO ATUAL EM MILISEGUNDOS

  if (currentMillisGreen - previousMillisGreen > greenLedInterval) { //SE O TEMPO ATUAL MENOS O TEMPO ANTERIOR FOR MENOR QUE O INTERVALO, FAZ
    previousMillisGreen = currentMillisGreen; //TEMPO ANTERIOR GUARDA O TEMPO ATUAL

    if (greenLedState == LOW) { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM LOW MUDA PARA HIGH
      greenLedState = HIGH; //VARIÁVEL RECEBE ESTADO HIGH(LIGA A PORTA)
    } else { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM HIGH MUDA PARA LOW
      greenLedState = LOW; //VARIÁVEL RECEBE ESTADO LOW(DESLIGA A PORTA)
    }

    digitalWrite(greenLedPin, greenLedState); //ESCREVE NA PORTA DIGITAL 9 O ESTADO DO LED VERDE (HIGH OU LOW)
  }
  //FIM DO CONTROLE DO LED VERDE
}
