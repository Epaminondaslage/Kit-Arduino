/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                   Utiliza para descobrir endereço de I2C
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/

#include <Wire.h>
#define TEMPOLEITURA 100
#define TEMPOESPERA 3000
byte endereco;
byte codigoResultado=0;
byte dispositivosEncontrados=0;
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  while (!Serial); 
  scanI2c();           
}
 
void scanI2c(){
    for (endereco=0; endereco<128; endereco++){
    Wire.beginTransmission(endereco);
    codigoResultado = Wire.endTransmission();
    if (codigoResultado==0){
      Serial.print ("Dispositivo I2c detectado no endereço: ");
      Serial.println(endereco,HEX);
      dispositivosEncontrados++;
      delay(TEMPOESPERA);
 
    }
    delay(TEMPOLEITURA);
  }
  if (dispositivosEncontrados>0){
    Serial.print("Foi encontrado um total de: ");
    Serial.print(dispositivosEncontrados);
    Serial.println(" dispositivos");
  }
  else{
    Serial.println("Nenhum dispositivo foi encontrado !!!");
  }
}
 
 
void loop() {
 
}
