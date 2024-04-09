/**************************************************************************
 * Programa: Placar Eletronico com Arduino e Max7219
 * Autor: Arduino e Cia 
 * Adaptado por Epaminondas Lage
 * https://www.arduinoecia.com.br/2017/11/placar-eletronico-arduino-modulo-max-7219.html?src=Filipeflop
 * Utiliza duas matriz de LED 8x8 com Max 7219
 * Programa para Arduino UNO/Nano
 * http://xantorohara.github.io/led-matrix-editor/# Editor de caracter
*/


#include "LedControl.h" // Incluir a bilbioteca LedControl.h

/*Conexoes do modulo Max7219
 *  
 * Create a new LedControl variable.
 * We use pins 12,11 and 10 on the Arduino Nano for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221
 * There will only be a single MAX7221 attached to the arduino 
 * LedControl lc1=LedControl(12,11,10,1);
*/

//DataIn = Pino 12
//CLK = Pino 11
//CS = Pino 10

LedControl lc = LedControl(12, 11, 10, 2);

//Armazenam o valor dos botoes
int v_but1, v_but2, v_but3;

//Brilho dos displays
int brilho = 15;

//Numero do display selecionado
int j = 0;

//Array do placar atual
int placar[2] = {0, 0};

//Array do placar anterior
int placar_ant[2] = {0, 0};

unsigned long delaytime = 200;

void setup()
{
  Serial.begin(9600);
  //Inicializa pinos botoes
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  //Inicializa pinos leds
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(3, HIGH);

  //Inicializa os displays
  lc.shutdown(0, false);
  lc.shutdown(1, false);

  //Ajusta o brilho de cada display
  lc.setIntensity(0, brilho);
  lc.setIntensity(1, brilho);

  //Apaga os displays
  lc.clearDisplay(0);
  lc.clearDisplay(1);

  //Mostra 0 (zero) nos dois displays
  writeOnMatrix(0, 0);
  writeOnMatrix(0, 1);
}

void loop()
{
  //Verifica se o botao de alternar
  //displays foi acionado
  v_but1 = digitalRead(6);
  if (v_but1 == 0)
  {
    j = !j;
    //Acende o led correspondente
    if (j == 0)
    {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    }
    else
    {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
    }
    while (digitalRead(6) == 0)
    {delay(50);}
  }

  //Verifica se o botao de aumentar
  //contador foi acionado
  v_but2 = digitalRead(7);
  if (v_but2 == 0)
  {
    placar[j] = placar[j] + 1;
    if (placar[j] <= 0 || placar[j] >= 10)
    {
      placar[j] = 0;
    }
    if (placar_ant[j] != placar[j])
    {
      //Chama a rotina que atualiza o display
      writeOnMatrix(placar[j], j);
      v_but3 = digitalRead(8);
      placar_ant[j] = placar [j];
    }
    while (digitalRead(7) == 0)
    {delay(50);}
  }

  //Verifica se o botao de diminuir
  //contador foi acionado
  v_but3 = digitalRead(8);
  if (v_but3 == 0)
  {
    placar[j] = placar[j] - 1;
    if (placar[j] <= 0 || placar[j] >= 10)
    {
      placar[j] = 0;
    }
    if (placar_ant[j] != placar[j])
    {
      //Chama a rotina que atualiza o display
      writeOnMatrix(placar[j], j);
      v_but3 = digitalRead(8);
      placar_ant[j] = placar [j];
    }
    while (digitalRead(8) == 0)
    {delay(50);}
  }
}

void writeOnMatrix(int numero, int tela)
{
  //O array abaixo forma o numero 0
  byte N0[8] = {B00000000, B00000000, B00111110, B01000001,
                B01000001, B00111110, B00000000, B00000000
               };
  //numero 1
  byte N1[8] = {B00000000, B00000000, B00000000, B01000010,
                B01111111, B01000000, B00000000, B00000000
               };
  //numero 2
  byte N2[8] = {B00000000, B00000000, B01100010, B01010001,
                B01001001, B01000110, B00000000, B00000000
               };
  //numero 3
  byte N3[8] = {B00000000, B00000000, B00100010, B01000001,
                B01001001, B00110110, B00000000, B00000000
               };
  //numero 4
  byte N4[8] = {B00000000, B00000000, B00001100, B00001010,
                B00001001, B01111111, B00000000, B00000000
               };
  //numero 5
  byte N5[8] = {B00000000, B00000000, B00100111, B01000101,
                B01000101, B00111001, B00000000, B00000000
               };
  //numero 6
  byte N6[8] = {B00000000, B00000000, B00111110, B01001001,
                B01001001, B00110000, B00000000, B00000000
               };
  //numero 7
  byte N7[8] = {B00000000, B00000000, B01100001, B00010001,
                B00001001, B00000111, B00000000, B00000000
               };
  //numero 8
  byte N8[8] = {B00000000, B00000000, B00110110, B01001001,
                B01001001, B00110110, B00000000, B00000000
               };
  //numero 9
  byte N9[8] = {B00000000, B00000000, B00001110, B01001001,
                B01001001, B00111110, B00000000, B00000000
               };

  //Mostra no display selecionado o numero correspondente
  switch (numero)
  {
    case 0:
      lc.setRow(tela, 1, N0[0]);
      lc.setRow(tela, 1, N0[1]);
      lc.setRow(tela, 2, N0[2]);
      lc.setRow(tela, 3, N0[3]);
      lc.setRow(tela, 4, N0[4]);
      lc.setRow(tela, 5, N0[5]);
      lc.setRow(tela, 6, N0[6]);
      lc.setRow(tela, 7, N0[7]);
      break;
    case 1:
      lc.setRow(tela, 1, N1[0]);
      lc.setRow(tela, 1, N1[1]);
      lc.setRow(tela, 2, N1[2]);
      lc.setRow(tela, 3, N1[3]);
      lc.setRow(tela, 4, N1[4]);
      lc.setRow(tela, 5, N1[5]);
      lc.setRow(tela, 6, N1[6]);
      lc.setRow(tela, 7, N1[7]);
      break;
    case 2:
      lc.setRow(tela, 1, N2[0]);
      lc.setRow(tela, 1, N2[1]);
      lc.setRow(tela, 2, N2[2]);
      lc.setRow(tela, 3, N2[3]);
      lc.setRow(tela, 4, N2[4]);
      lc.setRow(tela, 5, N2[5]);
      lc.setRow(tela, 6, N2[6]);
      lc.setRow(tela, 7, N2[7]);
      break;
    case 3:
      lc.setRow(tela, 1, N3[0]);
      lc.setRow(tela, 1, N3[1]);
      lc.setRow(tela, 2, N3[2]);
      lc.setRow(tela, 3, N3[3]);
      lc.setRow(tela, 4, N3[4]);
      lc.setRow(tela, 5, N3[5]);
      lc.setRow(tela, 6, N3[6]);
      lc.setRow(tela, 7, N3[7]);
      break;
    case 4:
      lc.setRow(tela, 1, N4[0]);
      lc.setRow(tela, 1, N4[1]);
      lc.setRow(tela, 2, N4[2]);
      lc.setRow(tela, 3, N4[3]);
      lc.setRow(tela, 4, N4[4]);
      lc.setRow(tela, 5, N4[5]);
      lc.setRow(tela, 6, N4[6]);
      lc.setRow(tela, 7, N4[7]);
      break;
    case 5:
      lc.setRow(tela, 1, N5[0]);
      lc.setRow(tela, 1, N5[1]);
      lc.setRow(tela, 2, N5[2]);
      lc.setRow(tela, 3, N5[3]);
      lc.setRow(tela, 4, N5[4]);
      lc.setRow(tela, 5, N5[5]);
      lc.setRow(tela, 6, N5[6]);
      lc.setRow(tela, 7, N5[7]);
      break;
    case 6:
      lc.setRow(tela, 1, N6[0]);
      lc.setRow(tela, 1, N6[1]);
      lc.setRow(tela, 2, N6[2]);
      lc.setRow(tela, 3, N6[3]);
      lc.setRow(tela, 4, N6[4]);
      lc.setRow(tela, 5, N6[5]);
      lc.setRow(tela, 6, N6[6]);
      lc.setRow(tela, 7, N6[7]);
      break;
    case 7:
      lc.setRow(tela, 1, N7[0]);
      lc.setRow(tela, 1, N7[1]);
      lc.setRow(tela, 2, N7[2]);
      lc.setRow(tela, 3, N7[3]);
      lc.setRow(tela, 4, N7[4]);
      lc.setRow(tela, 5, N7[5]);
      lc.setRow(tela, 6, N7[6]);
      lc.setRow(tela, 7, N7[7]);
      break;
    case 8:
      lc.setRow(tela, 1, N8[0]);
      lc.setRow(tela, 1, N8[1]);
      lc.setRow(tela, 2, N8[2]);
      lc.setRow(tela, 3, N8[3]);
      lc.setRow(tela, 4, N8[4]);
      lc.setRow(tela, 5, N8[5]);
      lc.setRow(tela, 6, N8[6]);
      lc.setRow(tela, 7, N8[7]);
      break;
    case 9:
      lc.setRow(tela, 1, N9[0]);
      lc.setRow(tela, 1, N9[1]);
      lc.setRow(tela, 2, N9[2]);
      lc.setRow(tela, 3, N9[3]);
      lc.setRow(tela, 4, N9[4]);
      lc.setRow(tela, 5, N9[5]);
      lc.setRow(tela, 6, N9[6]);
      lc.setRow(tela, 7, N9[7]);
      break;
  }
}
