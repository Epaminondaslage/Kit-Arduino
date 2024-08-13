/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                 Utilizado para descobrir endereço de I2C
                    Elaborado/Adaptado por Epaminondas Lage
 **************************************************************************/

#include <Wire.h>  // Inclui a biblioteca Wire para comunicação I2C

// Definições de tempo
#define TEMPOLEITURA 100  // Tempo de espera entre cada leitura em milissegundos
#define TEMPOESPERA 3000  // Tempo de espera após detectar um dispositivo em milissegundos

// Variáveis globais
byte endereco;              // Armazena o endereço I2C
byte codigoResultado = 0;   // Armazena o código de resultado da transmissão I2C
byte dispositivosEncontrados = 0;  // Contador de dispositivos encontrados no barramento I2C
 
void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  Wire.begin();        // Inicializa o barramento I2C
  while (!Serial);     // Aguarda a inicialização da serial
  scanI2c();           // Chama a função para escanear os endereços I2C
}
 
// Função para escanear o barramento I2C em busca de dispositivos conectados
void scanI2c() {
  for (endereco = 0; endereco < 128; endereco++) {  // Loop através de todos os endereços I2C possíveis
    Wire.beginTransmission(endereco);  // Inicia a transmissão para o endereço especificado
    codigoResultado = Wire.endTransmission();  // Finaliza a transmissão e captura o resultado

    if (codigoResultado == 0) {  // Se a transmissão foi bem-sucedida, um dispositivo foi encontrado
      Serial.print("Dispositivo I2C detectado no endereço: ");
      Serial.println(endereco, HEX);  // Imprime o endereço do dispositivo em formato hexadecimal
      dispositivosEncontrados++;  // Incrementa o contador de dispositivos encontrados
      delay(TEMPOESPERA);  // Espera antes de continuar o escaneamento
    }
    delay(TEMPOLEITURA);  // Espera entre cada tentativa de endereço
  }

  // Verifica se algum dispositivo foi encontrado
  if (dispositivosEncontrados > 0) {
    Serial.print("Foi encontrado um total de: ");
    Serial.print(dispositivosEncontrados);
    Serial.println(" dispositivos");
  } else {
    Serial.println("Nenhum dispositivo foi encontrado !!!");
  }
}
 
void loop() {
  // O loop principal não faz nada; o escaneamento é realizado apenas no setup
}
