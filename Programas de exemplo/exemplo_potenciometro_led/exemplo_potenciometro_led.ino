const int pinoLED = 10; //PINO DIGITAL UTILIZADO PELO LED
const int pinoPOT = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
int leituraA5 = 0; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA

float luminosidadeLED = 0; //VARIÁVEL QUE ARMAZENA O VALOR DA LUMINOSIDADE QUE SERÁ APLICADA AO LED

void setup(){
   pinMode(pinoLED, OUTPUT); //DEFINE A PORTA COMO SAÍDA
   pinMode(pinoPOT, INPUT); //DEFINE A PORTA COMO ENTRADA
}

void loop(){
  leituraA5 = analogRead(pinoPOT); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  luminosidadeLED = map(leituraA5, 0, 1023, 0, 255); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  analogWrite(pinoLED, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
}