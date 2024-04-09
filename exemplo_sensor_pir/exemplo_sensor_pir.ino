const int pinoPIR = 3; //PINO DIGITAL UTILIZADO PELO SENSOR DE PRESENÇA
const int pinoLED = 7; //PINO DIGITAL UTILIZADO PELO LED

void setup(){
  pinMode(pinoLED, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(pinoPIR, INPUT); //DEFINE A PORTA COMO ENTRADA
}
void loop(){
 if(digitalRead(pinoPIR) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
    digitalWrite(pinoLED, HIGH); //ACENDE O LED
 }else{
  digitalWrite(pinoLED, LOW); //APAGA O LED
 }
}
