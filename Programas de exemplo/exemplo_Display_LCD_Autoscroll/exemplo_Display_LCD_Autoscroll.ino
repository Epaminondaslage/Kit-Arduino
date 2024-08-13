/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                Demonstração do Uso de um Display LCD 16x2 - Autoscroll
                    Elaborado/Adaptado por Epaminondas Lage
 **************************************************************************

 Biblioteca LiquidCrystal - Autoscroll

  Demonstra o uso de um display LCD 16x2. A biblioteca LiquidCrystal
  funciona com todos os displays LCD compatíveis com o driver
  Hitachi HD44780. Existem muitos desses displays disponíveis, e
  geralmente é possível identificá-los pela interface de 16 pinos.

  Este sketch demonstra o uso das funções autoscroll()
  e noAutoscroll() para fazer o texto novo rolar automaticamente ou não.

  O circuito:
  * Pino RS do LCD no pino digital 6 do Arduino
  * Pino Enable do LCD no pino digital 7 do Arduino
  * Pino D4 do LCD no pino digital 5 do Arduino
  * Pino D5 do LCD no pino digital 4 do Arduino
  * Pino D6 do LCD no pino digital 3 do Arduino
  * Pino D7 do LCD no pino digital 2 do Arduino
  * Pino R/W do LCD ao GND
  * Resistor de 10K:
  * extremidades conectadas ao +5V e ao GND
  * terminal central conectado ao pino VO do LCD (pino 3)

  Código original da biblioteca adicionado em 18 de abril de 2008
  por David A. Mellis
  Biblioteca modificada em 5 de julho de 2009
  por Limor Fried (http://www.ladyada.net)
  Exemplo adicionado em 9 de julho de 2009
  por Tom Igoe
  Modificado em 22 de novembro de 2010
  por Tom Igoe
  Modificado em 7 de novembro de 2016
  por Arturo Guadalupi

  Este código de exemplo é de domínio público.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll
*/

// Inclui o código da biblioteca:
#include <LiquidCrystal.h>

// Inicializa a biblioteca associando os pinos da interface LCD aos pinos do Arduino
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Configura o número de colunas e linhas do LCD:
  lcd.begin(16, 2);
}

void loop() {
  // Define o cursor para a posição (0,0):
  lcd.setCursor(0, 0);
  // Imprime de 0 a 9 na primeira linha:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }

  // Define o cursor para a posição (16,1), fora da tela visível na segunda linha:
  lcd.setCursor(16, 1);
  // Configura o display para rolagem automática:
  lcd.autoscroll();
  // Imprime de 0 a 9 na segunda linha com rolagem:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // Desativa a rolagem automática
  lcd.noAutoscroll();

  // Limpa a tela para o próximo loop:
  lcd.clear();
}
