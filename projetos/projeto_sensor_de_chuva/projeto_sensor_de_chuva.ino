#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Carrega a biblioteca LiquidCrystal_I2C de Frank Brabender

int pino_d = 7; // Pino digital conectado ao D0 do sensor de chuva
int pino_a = A5; // Pino analógico conectado ao A0 do sensor de chuva
int val_d = 0; // Variável para armazenar o valor lido do pino digital
int val_a = 0; // Variável para armazenar o valor lido do pino analógico

// Define o display LCD I2C com endereço 0x27 (alterar se necessário)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); // Inicializa o display
  lcd.backlight(); // Liga a luz de fundo do display
  
  pinMode(pino_d, INPUT); // Configura o pino digital como entrada
  pinMode(pino_a, INPUT); // Configura o pino analógico como entrada
  Serial.begin(9600); // Inicia a comunicação serial a 9600 bps
  
  // Exibe as labels "Chuva" e "Intens." no display
  lcd.setCursor(0, 0); // Posiciona o cursor na primeira linha, primeira coluna
  lcd.print("Chuva  : "); // Exibe o texto "Chuva  : " na primeira linha
  lcd.setCursor(0, 1); // Posiciona o cursor na segunda linha, primeira coluna
  lcd.print("Intens.: "); // Exibe o texto "Intens.: " na segunda linha
}

void loop() {
  // Lê o estado do pino digital (D0 do sensor de chuva)
  val_d = digitalRead(pino_d);
  // Lê o valor analógico do pino A0 (sensor de chuva)
  val_a = analogRead(pino_a);
  
  // Envia os valores lidos para o monitor serial
  Serial.print("Valor digital : ");
  Serial.print(val_d); // Exibe o valor do pino digital
  Serial.print(" - Valor analogico : ");
  Serial.println(val_a); // Exibe o valor do pino analógico

  // Verifica se há chuva (val_d = 0) ou não (val_d = 1) e exibe no display
  if (val_d == 1) {
    lcd.setCursor(10, 0); // Posiciona o cursor na primeira linha, coluna 10
    lcd.print("Nao "); // Exibe "Nao" se não houver chuva
  } else {
    lcd.setCursor(10, 0); // Posiciona o cursor na primeira linha, coluna 10
    lcd.print("Sim "); // Exibe "Sim" se houver chuva
  }

  // Determina o nível de intensidade da chuva com base no valor analógico
  lcd.setCursor(10, 1); // Posiciona o cursor na segunda linha, coluna 10
  if (val_a > 900 && val_a <= 1023) {
    lcd.print("---- "); // Exibe "----" para indicar chuva muito fraca
  } else if (val_a > 600 && val_a <= 900) {
    lcd.print("Fraca"); // Exibe "Fraca" para chuva leve
  } else if (val_a > 400 && val_a <= 600) {
    lcd.print("Moder"); // Exibe "Moder" para chuva moderada
  } else if (val_a <= 400) {
    lcd.print("Forte"); // Exibe "Forte" para chuva intensa
  } else {
    lcd.print("     "); // Limpa o display se nenhum valor for correspondente
  }
  
  delay(1000); // Aguarda 1 segundo antes de repetir o loop
}
