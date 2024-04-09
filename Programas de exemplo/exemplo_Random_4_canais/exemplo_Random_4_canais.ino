/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                   Pisca aleatoreamente um dos quatro leds
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/
long a; 
int Pinos[] = {9,10,11,12};
int timer =500;
int contador=0;

// Configura porta de saída
void setup() {
  for (contador = 0; contador < 4; contador++) {
   pinMode(Pinos[contador], OUTPUT);
 }  
}
void loop() {
  //sorteia um numero aleatório entre 0 3
  a=random(0,4);
  digitalWrite(Pinos[a],HIGH);
  delay(timer);
  digitalWrite(Pinos[a], LOW);
  delay(timer);
  }

  
