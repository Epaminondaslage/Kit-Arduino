int leds[] = {8,9,10,11}; //DECLARA OS PINOS QUE SERÃO USADOS PELOS LED'S
int contador = 0; //VARIÁVEL RESPONSÁVEL PELA CONTAGEM FEITA NO LAÇO "for"
int timer  = 150; //INTERVALO DE 150ms

void setup(){
  for(contador = 0; contador < 4; contador ++){ //PARA "contador" IGUAL A 0,ENQUANTO "contador" MENOR QUE 4, INCREMENTA "contador"
    pinMode(leds[contador], OUTPUT); //DEFINE AS PORTAS COMO SAÍDA
  }
}
void loop(){
  for(contador = 0; contador < 4; contador ++){ //PARA "contador" IGUAL A 0,ENQUANTO "contador" MENOR QUE 4, INCREMENTA "contador"
    digitalWrite(leds[contador], HIGH); //ACENDE O LED
    delay(timer); //INTERVALO DE 150ms
    digitalWrite(leds[contador], LOW); //APAGA O LED
    delay(timer); //INTERVALO DE 150ms
  }
}

