/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                   Projeto Controle de Brilho de LED - PWM 
                    Elaborado/Adptado por Epaminondas Lage
 **************************************************************************/

int ledPin = 9; // Define o pino 9 do Arduino como o pino do LED
float sinVal;  // Variável para armazenar o valor do seno
int ledVal;    // Variável para armazenar o valor de PWM para o LED

void setup() 
{ 
  pinMode(ledPin, OUTPUT); // Configura o pino do LED como saída
} 

void loop() 
{ 
  for (int x = 10; x < 180; x++) 
  { 
    // Converte graus para radianos e então obtém o valor do seno
    sinVal = sin(x * (3.1412 / 180)); 
    // Converte o valor do seno para um valor de PWM entre 0 e 255
    ledVal = int(sinVal * 255); 
    // Aplica o valor de PWM ao LED
    analogWrite(ledPin, ledVal); 
    delay(50); // Aguarda 50 milissegundos antes de passar para o próximo valor
  } 
} 
