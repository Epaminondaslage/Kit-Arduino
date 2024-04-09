int ledPin = 13; //PINO EM QUE O LED ESTÁ CONECTADO
int ledStatus = LOW; //DEFINE QUE O ESTADO INICIAL DO LED É DESLIGADO

long previousMillis = 0; //VARIÁVEL QUE CONTROLA O TEMPO
long redLedInterval = 1000; //VARIÁVEL QUE REGISTRA O INTERVALO (1000ms = 1 SEGUNDO)

void setup() {
pinMode(ledPin, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
}

void loop(){
  unsigned long currentMillis = millis(); //VARIÁVEL RECEBE O TEMPO ATUAL EM MILISEGUNDOS

  if (currentMillis - previousMillis > redLedInterval) { //SE O TEMPO ATUAL MENOS O TEMPO ANTERIOR FOR MENOR QUE O INTERVALO, FAZ
    previousMillis = currentMillis; //TEMPO ANTERIOR GUARDA O TEMPO ATUAL

    if (ledStatus == LOW) { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM LOW MUDA PARA HIGH
      ledStatus = HIGH; //VARIÁVEL RECEBE ESTADO HIGH(LIGA A PORTA)
    } else { //VERIFICA O ESTADO ATUAL DO LED E SE ESTIVER EM HIGH MUDA PARA LOW
      ledStatus = LOW; //VARIÁVEL RECEBE ESTADO LOW(DESLIGA A PORTA)
    }
    digitalWrite(ledPin, ledStatus); //ESCREVE NA PORTA DIGITAL 13 O ESTADO DO LED (HIGH OU LOW)
  }
}
