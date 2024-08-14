/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *                 Controle de LEDs via Bluetooth com Android             *
 * Elaborado/Adaptado por Epaminondas Lage                                *
 *                                                                        *
 * Este código permite o controle de três LEDs conectados aos pinos 3, 4, *
 * e 5 do Arduino Uno através de comandos enviados via Bluetooth. A       *
 * comunicação é feita entre Arduino e um dispositivo Android utilizando  *
 * um módulo Bluetooth (HC-05 ou HC-06).                                  *
 *                                                                        *
 * O usuário pode ligar ou desligar os LEDs enviando os caracteres 'R',   *
 * 'G', e 'B' através de um aplicativo de terminal Bluetooth no Android.  *
 *                                                                        *
 * Integração com Android:                                                *
 * - No dispositivo Android, utilize um aplicativo de terminal Bluetooth  *
 *   como "Bluetooth Terminal" ou "Serial Bluetooth Terminal" para se     *
 *   conectar ao módulo Bluetooth do Arduino.                             *
 * - Envie o caractere 'R' para controlar o LED 1, 'G' para o LED 2, e    *
 *   'B' para o LED 3. O estado dos LEDs será alternado entre ligado e    *
 *   desligado a cada comando recebido.                                   *
 **************************************************************************/

char buffer; // Variável do tipo char para armazenar o dado recebido via Bluetooth

const int LED1 = 3; // Pino digital utilizado pelo LED 1
const int LED2 = 4; // Pino digital utilizado pelo LED 2
const int LED3 = 5; // Pino digital utilizado pelo LED 3

int statusLED1 = 0; // Variável que armazena o estado do LED 1 (0 = desligado, 1 = ligado)
int statusLED2 = 0; // Variável que armazena o estado do LED 2 (0 = desligado, 1 = ligado)
int statusLED3 = 0; // Variável que armazena o estado do LED 3 (0 = desligado, 1 = ligado)

void setup(){
  pinMode(LED1, OUTPUT); // Configura o pino do LED 1 como saída
  pinMode(LED2, OUTPUT); // Configura o pino do LED 2 como saída
  pinMode(LED3, OUTPUT); // Configura o pino do LED 3 como saída
  Serial.begin(9600); // Inicializa a comunicação serial com velocidade de 9600 bps
}

void loop(){
  while(Serial.available() > 0){ // Verifica se há dados disponíveis na serial
    buffer = Serial.read(); // Lê o dado recebido via Bluetooth e armazena na variável buffer
    
    // Controle do LED 1 com o comando 'R'
    if ((buffer == 'R') && (statusLED1 == 0)){ // Se o comando recebido for 'R' e o LED 1 estiver desligado
      digitalWrite(LED1, HIGH); // Liga o LED 1
      Serial.println("LED 1 ligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 1 foi ligado
      statusLED1 = 1; // Atualiza o estado do LED 1 para ligado
    } else if ((buffer == 'R') && (statusLED1 == 1)){ // Se o comando recebido for 'R' e o LED 1 estiver ligado
      digitalWrite(LED1, LOW); // Desliga o LED 1
      Serial.println("LED 1 desligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 1 foi desligado
      statusLED1 = 0; // Atualiza o estado do LED 1 para desligado
    }
    
    // Controle do LED 2 com o comando 'G'
    if ((buffer == 'G') && (statusLED2 == 0)){ // Se o comando recebido for 'G' e o LED 2 estiver desligado
      digitalWrite(LED2, HIGH); // Liga o LED 2
      Serial.println("LED 2 ligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 2 foi ligado
      statusLED2 = 1; // Atualiza o estado do LED 2 para ligado
    } else if ((buffer == 'G') && (statusLED2 == 1)){ // Se o comando recebido for 'G' e o LED 2 estiver ligado
      digitalWrite(LED2, LOW); // Desliga o LED 2
      Serial.println("LED 2 desligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 2 foi desligado
      statusLED2 = 0; // Atualiza o estado do LED 2 para desligado
    }
    
    // Controle do LED 3 com o comando 'B'
    if ((buffer == 'B') && (statusLED3 == 0)){ // Se o comando recebido for 'B' e o LED 3 estiver desligado
      digitalWrite(LED3, HIGH); // Liga o LED 3
      Serial.println("LED 3 ligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 3 foi ligado
      statusLED3 = 1; // Atualiza o estado do LED 3 para ligado
    } else if ((buffer == 'B') && (statusLED3 == 1)){ // Se o comando recebido for 'B' e o LED 3 estiver ligado
      digitalWrite(LED3, LOW); // Desliga o LED 3
      Serial.println("LED 3 desligado!"); // Envia uma mensagem para o monitor serial indicando que o LED 3 foi desligado
      statusLED3 = 0; // Atualiza o estado do LED 3 para desligado
    }
  }
}
