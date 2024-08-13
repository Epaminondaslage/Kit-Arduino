/**************************************************************************
                Medição de Temperatura com Sensor LM35 e Arduino
             Elaborado/Adptado por [Epaminondas Lage]
              
  Este código utiliza um sensor LM35 conectado ao pino A0 do Arduino para
  medir a temperatura ambiente e exibi-la no monitor serial a cada segundo.
  
  - A leitura analógica do pino A0 é convertida em uma tensão correspondente.
  - A tensão é então convertida para uma leitura de temperatura em graus Celsius.
  
 **************************************************************************/

float temp; // Variável que armazena a temperatura medida
const int sensorPin = A0; // Pino em que o sensor está conectado (pino analógico A0)

void setup(){
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps
}

void loop(){
  temp = analogRead(sensorPin); // Lê o valor do pino analógico A0 e armazena em 'temp'
  
  // O valor lido é multiplicado por uma constante para converter a leitura
  // em temperatura em graus Celsius. Para o LM35, cada unidade lida equivale a 0,48828125 °C.
  temp = temp * 0.48828125; 
  
  // Exibe a temperatura medida no monitor serial
  Serial.print("Temperatura: "); // Exibe o texto "Temperatura: "
  Serial.print(temp); // Exibe a temperatura medida
  Serial.print("°C"); // Exibe o texto "°C"
  Serial.println(); // Quebra de linha no monitor serial
  
  delay(1000); // Aguarda 1 segundo antes de realizar uma nova leitura
}
