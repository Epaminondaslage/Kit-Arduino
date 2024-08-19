/**************************************************************************
 *                 Placa de Desenvolvimento Arduino Uno                   *
 *                Medição de Corrente e Potência com Sensor ACS712        *
 *                  Elaborado/Adptado por Epaminondas Lage                *
 *                                                                        *
 * Este código utiliza o sensor de corrente ACS712 para medir a corrente  *
 * consumida e calcular a potência aproximada, exibindo os valores no     *
 * monitor serial do Arduino.                                             *
 **************************************************************************/

const int scAnalog = A0; // Porta analógica (A0) utilizada pelo sensor de corrente
float sensorValue_aux = 0; // Variável auxiliar do tipo float para leituras
float sensorValue = 0; // Variável que armazena o valor médio da leitura
float currentValue = 0; // Variável que armazena o valor da corrente calculada
float voltsporUnidade = 0.0048828125; // Fator de conversão de volts por unidade (5V/1023)
int tensaoRede = 127; // Tensão da rede elétrica (127V ou 220V)
float potenciaAprox = 0; // Variável que armazena a potência calculada

void setup(){
  Serial.begin(9600); // Inicializa a porta serial
}
 
void loop(){
  currentValue = 0; // Reinicia o valor atual da corrente
  sensorValue = 0; // Reinicia o valor atual da leitura do sensor

  // Realiza 500 leituras do sensor para maior precisão
  for(int i = 500; i > 0; i--){
    sensorValue_aux = (analogRead(scAnalog) - 510); // Lê o pino analógico A0 e ajusta o valor para corrente zero
    sensorValue += pow(sensorValue_aux, 2); // Soma os quadrados das leituras
  }
  
  // Calcula o valor médio quadrático e converte para volts
  sensorValue = (sqrt(sensorValue / 500)) * voltsporUnidade;
  currentValue = (sensorValue / 0.066); // Calcula a corrente em amperes (66 mV por ampere)

  // Tratamento de ruído: ignora valores abaixo de 0,200A
  if(currentValue <= 0.200){
    currentValue = 0;
  }

  // Calcula a potência aproximada
  potenciaAprox = tensaoRede * currentValue;

  // Exibe as informações no monitor serial
  Serial.print("Corrente medida: ");
  Serial.print(currentValue, 3);
  Serial.print("A / Potencia (Consumo): ");
  Serial.print(potenciaAprox, 3);
  Serial.println("W");

  delay(150); // Intervalo de 150 milissegundos antes de nova leitura
}
