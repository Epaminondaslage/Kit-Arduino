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
