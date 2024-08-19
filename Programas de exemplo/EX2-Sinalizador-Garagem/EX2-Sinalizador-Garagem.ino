/*
  Projeto: Sinalizador de Garagem
  Descrição: Este código faz com que dois LEDs conectados ao Arduino pisquem alternadamente
  em um intervalo de tempo definido. O estado dos LEDs é exibido no monitor serial.
  
  Autor: [Epaminondas Lage]
  Data: [julho 2024]
*/

// Define os pinos dos LEDs
const int ledPin1 = 8;  // LED 1 conectado ao pino digital 8
const int ledPin2 = 9;  // LED 2 conectado ao pino digital 9

// Intervalo de tempo (em milissegundos) para alternar o estado dos LEDs
const int interval = 500;

void setup() {
  // Inicializa a comunicação serial com a taxa de 9600 bps
  Serial.begin(9600);
  
  // Define os pinos dos LEDs como saídas
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  // Exibe no monitor serial a que pino cada LED está conectado
  Serial.print("LED 1 está conectado ao pino ");
  Serial.println(ledPin1);
  Serial.print("LED 2 está conectado ao pino ");
  Serial.println(ledPin2);
}

void loop() {
  // Acende o LED 1 e apaga o LED 2
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin2, LOW);
  Serial.println("LED 1 aceso, LED 2 apagado");
  
  // Aguarda pelo intervalo definido antes de mudar o estado dos LEDs
  delay(interval);
  
  // Apaga o LED 1 e acende o LED 2
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  Serial.println("LED 1 apagado, LED 2 aceso");
  
  // Aguarda pelo intervalo definido antes de repetir o ciclo
  delay(interval);
}
