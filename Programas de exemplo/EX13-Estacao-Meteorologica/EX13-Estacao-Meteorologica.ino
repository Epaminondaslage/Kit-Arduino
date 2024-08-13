/*
  Medição de Temperatura e Umidade com DHT11 e Display LCD
  Este exemplo demonstra como utilizar um sensor DHT11 para medir temperatura e umidade,
  exibindo os valores em um display LCD 16x2 via I2C.

  Elaborado/Adaptado por Epaminondas Lage
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definições do DHT11
#define DHTPIN 2     // Pino onde o sensor está conectado
#define DHTTYPE DHT11   // Tipo de sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

// Definições do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço I2C 0x27 para o LCD de 16 caracteres e 2 linhas

void setup() {
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  
  // Inicializa o sensor DHT11
  dht.begin();
  
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Aguarda alguns segundos entre as leituras dos dados do sensor
  delay(2000);

  // Leitura dos dados do sensor DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verifica se a leitura falhou e se sim, tenta novamente
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Falha ao ler");
    lcd.setCursor(0, 1);
    lcd.print("do sensor DHT11");
    return;
  }

  // Exibe os valores no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(h);
  lcd.print(" %");

  // Envia os dados para a porta serial
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");
}
