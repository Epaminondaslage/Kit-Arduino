/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                   Pisca aleatoreamente um dos quatro LEDs
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/
long a; 
int Pinos[] = {9,10,11,12}; // Array que armazena os pinos dos LEDs
int timer = 500; // Tempo de espera entre os piscas (em milissegundos)
int contador = 0; // Variável de contagem para o loop de configuração

// Configura os pinos como saídas
void setup() {
  for (contador = 0; contador < 4; contador++) {
   pinMode(Pinos[contador], OUTPUT); // Define os pinos 9, 10, 11, 12 como saídas
 }  
}

void loop() {
  // Sorteia um número aleatório entre 0 e 3
  a = random(0, 4); 
  digitalWrite(Pinos[a], HIGH); // Liga o LED correspondente ao número sorteado
  delay(timer); // Aguarda o tempo definido em 'timer'
  digitalWrite(Pinos[a], LOW); // Desliga o LED
  delay(timer); // Aguarda o tempo definido em 'timer'
}
