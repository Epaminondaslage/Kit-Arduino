<<<<<<< HEAD
// Define os pinos dos LEDs
const int ledPin1 = 8;
const int ledPin2 = 9;
// Intervalo de tempo (em milissegundos) para piscar os LEDs
const int interval = 500;
void setup() {
// Inicializa a comunicação serial
Serial.begin(9600);
// Define os pinos dos LEDs como saída
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
// Exibe os pinos dos LEDs na porta serial
Serial.print("LED 1 está conectado ao pino ");
Serial.println(ledPin1);
Serial.print("LED 2 está conectado ao pino ");
Serial.println(ledPin2);
=======
/*
  Controle de Três LEDs
  Este exemplo demonstra como controlar três LEDs conectados aos pinos 4, 5 e 6 de um Arduino,
  acendendo cada um deles sequencialmente com um intervalo de um segundo.

  Elaborado/Adaptado por Epaminondas Lage
*/

// Definição dos pinos dos LEDs
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

void setup() {
  // Define os pinos dos LEDs como saídas
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
>>>>>>> 62596efe297f8a502af1c4051dc3acd7076af92e
}

void loop() {
<<<<<<< HEAD
    // Acende o LED 1 e apaga o LED 2
       digitalWrite(ledPin1, HIGH); 
       digitalWrite(ledPin2, LOW);
        Serial.println("LED 1 aceso, LED 2 apagado");
    // Espera pelo intervalo
       delay(interval);    // Apaga o LED 1 e acende o LED 2
       digitalWrite(ledPin1, LOW);
       digitalWrite(ledPin2, HIGH);
       Serial.println("LED 1 apagado, LED 2 aceso");
    // Espera pelo intervalo
       delay(interval);
  }
=======
  // Acende o primeiro LED e espera 1 segundo
  digitalWrite(ledPin1, HIGH);
  delay(1000);
  digitalWrite(ledPin1, LOW);
  
  // Acende o segundo LED e espera 1 segundo
  digitalWrite(ledPin2, HIGH);
  delay(1000);
  digitalWrite(ledPin2, LOW);
  
  // Acende o terceiro LED e espera 1 segundo
  digitalWrite(ledPin3, HIGH);
  delay(1000);
  digitalWrite(ledPin3, LOW);
}
>>>>>>> 62596efe297f8a502af1c4051dc3acd7076af92e
