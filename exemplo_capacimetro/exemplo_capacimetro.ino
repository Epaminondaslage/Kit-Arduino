const int OUT_PIN = A2; //PINO ANALÓGICO DE SAÍDA
const int IN_PIN = A0; //PINO ANALÓGICO DE ENTRADA
const float IN_STRAY_CAP_TO_GND = 24.48; //VARIÁVEL PARA TESTE PARASITA DO CAPACITOR
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND; //VARIÁVEL RECEBE VALOR DE "IN_STRAY_CAP_TO_GND"
const float R_PULLUP = 34.8; //VALOR DO RESISTOR PULL_UP
const int MAX_ADC_VALUE = 1023; //VALOR MÁXIMO NA CONVERSÃO ANALÓGICO DIGITAL

void setup(){
  pinMode(OUT_PIN, OUTPUT);  //DEFINE A PORTA COMO SAÍDA
  pinMode(IN_PIN, OUTPUT); //DEFINE A PORTA COMO ENTRADA
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}

void loop(){
    pinMode(IN_PIN, INPUT); //DEFINE A PORTA COMO ENTRADA
    digitalWrite(OUT_PIN, HIGH); //ESCREVE VALOR ALTO NA PORTA DE SAÍDA
    int val = analogRead(IN_PIN); //VARIÁVEL DO TIPO INTEIRA RECEBE LEITURA DO PINO ANALÓGICO DE ENTRADA
    digitalWrite(OUT_PIN, LOW); //ESCREVE VALOR BAIXO NA PORTA DE SAÍDA

    if (val < 1000){ //SE VARIÁVEL FOR MENOR QUE 1000, FAZ
      pinMode(IN_PIN, OUTPUT); //DEFINE A PORTA COMO ENTRADA

      float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val); //VARIÁVEL RECEBE O RESULTADO OBTIDO NA FÓRMULA

    }
    else //senão
    {
      pinMode(IN_PIN, OUTPUT); //DEFINE A PORTA COMO SAÍDA
      delay(1); //DELAY DE 1 MILISEGUNDO
      pinMode(OUT_PIN, INPUT_PULLUP); //ATIVA RESISTOR PULL UP
      unsigned long u1 = micros(); //VARIÁVEL RECEBE TEMPO (MICROSEGUNDOS)
      unsigned long t; //DECLARAÇÃO DE VARIÁVEL
      int digVal; //DECLARAÇÃO DE VARIÁVEL

      do{//FAÇA
        digVal = digitalRead(OUT_PIN); //VARIÁVEL RECEBE LEITURA FEITA EM "OUT_PIN"
        unsigned long u2 = micros(); //VARIÁVEL RECEBE TEMPO (MICROSEGUNDOS)
        t = u2 > u1 ? u2 - u1 : u1 - u2; //EXECUTA A FÓRMULA
      } while ((digVal < 1) && (t < 400000L)); //ENQUANTO "digVal" MENOR QUE 1 E "t" MENOR QUE 400000L, faz

      pinMode(OUT_PIN, INPUT); //DEFINE A PORTA COMO ENTRADA
      val = analogRead(OUT_PIN); //VARIÁVEL RECEBE LEITURA FEITA EM "OUT_PIN"
      digitalWrite(IN_PIN, HIGH); //ESCREVE VALOR ALTO NA PORTA
      int dischargeTime = (int)(t / 1000L) * 5; //VARIÁVEL RECEBE O RESULTADO DA FÓRMULA
      delay(dischargeTime);    //DELAY BASEADO NO RESULTADO ARMAZENADO NA VARIÁVEL "dischargeTime"
      pinMode(OUT_PIN, OUTPUT); //DEFINE A PORTA COMO SAÍDA
      digitalWrite(OUT_PIN, LOW); //ESCREVE VALOR BAIXO NA PORTA
      digitalWrite(IN_PIN, LOW); //ESCREVE VALOR BAIXO NA PORTA

      //CALCULA A CAPACITÂNCIA
      float capacitance = -(float)t / R_PULLUP
                              / log(1.0 - (float)val / (float)MAX_ADC_VALUE);

      Serial.print(F("Capacitancia: ")); //ESCREVE O TEXTO NA JANELA SERIAL
      if (capacitance > 1000.0){ //SE CAPACITÂNCIA FOR MAIOR QUE 1000, FAZ
        Serial.print(capacitance / 1000.0, 2); //MOSTRA NA JANELA SERIAL A CAPACITÂNCIA COM 2 CASAS DECIMAIS
        Serial.println(F(" uF (microFarads)")); //ESCREVE O TEXTO NA JANELA SERIAL
      }
      else{ //SENÃO
        Serial.print(capacitance, 2); //MOSTRA NA JANELA SERIAL A CAPACITÂNCIA COM 2 CASAS DECIMAIS
        Serial.println(F(" nF (nanoFarads)")); //ESCREVE O TEXTO NA JANELA SERIAL
      }
    }
    while (millis() % 1000 != 0) //ENQUANTO "millis()" TIVER MÓDULO DIFERNETE DE 0
      ;    
}
