/**************************************************************************
 * Programa: Placar Eletrônico com Arduino e Max7219
 * Autor: Arduino e Cia 
 * Adaptado por Epaminondas Lage
 * https://www.arduinoecia.com.br/2017/11/placar-eletronico-arduino-modulo-max-7219.html?src=Filipeflop
 * Utiliza duas matrizes de LED 8x8 com Max7219
 * Programa para Arduino UNO/Nano
 * http://xantorohara.github.io/led-matrix-editor/# Editor de caracteres
 **************************************************************************/

#include "LedControl.h" // Inclui a biblioteca LedControl.h para controlar o Max7219

/* Conexões do módulo Max7219:
 * 
 * DATA IN do Max7219 -> Pino 12 do Arduino
 * CLK do Max7219 -> Pino 11 do Arduino
 * LOAD(/CS) do Max7219 -> Pino 10 do Arduino
 * LedControl lc = LedControl(12, 11, 10, 2); // Inicializa o controle para 2 displays
*/

// Definições dos pinos do Arduino para a conexão com o Max7219
LedControl lc = LedControl(12, 11, 10, 2); // Configura para 2 matrizes de LED 8x8

// Variáveis para armazenar o estado dos botões
int v_but1, v_but2, v_but3;

// Brilho dos displays
int brilho = 15;

// Número do display selecionado
int j = 0;

// Arrays para armazenar o placar atual e o placar anterior
int placar[2] = {0, 0};
int placar_ant[2] = {0, 0};

unsigned long delaytime = 200; // Tempo de atraso entre as operações

void setup()
{
  Serial.begin(9600); // Inicializa a comunicação serial para depuração

  // Inicializa os pinos dos botões como entradas com pull-up interno
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  // Inicializa os pinos dos LEDs como saídas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(3, HIGH); // Acende o LED conectado ao pino 3 inicialmente

  // Inicializa os displays de LED
  lc.shutdown(0, false); // Ativa o primeiro display
  lc.shutdown(1, false); // Ativa o segundo display

  // Configura o brilho dos displays
  lc.setIntensity(0, brilho);
  lc.setIntensity(1, brilho);

  // Limpa os displays
  lc.clearDisplay(0);
  lc.clearDisplay(1);

  // Mostra o número 0 em ambos os displays
  writeOnMatrix(0, 0);
  writeOnMatrix(0, 1);
}

void loop()
{
  // Verifica se o botão de alternar displays foi pressionado
  v_but1 = digitalRead(6);
  if (v_but1 == 0)
  {
    j = !j; // Alterna entre o display 0 e 1

    // Acende o LED correspondente ao display selecionado
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

    // Aguarda até que o botão seja liberado
    while (digitalRead(6) == 0)
    {
      delay(50);
    }
  }

  // Verifica se o botão de aumentar o contador foi pressionado
  v_but2 = digitalRead(7);
  if (v_but2 == 0)
  {
    placar[j] = placar[j] + 1; // Incrementa o placar do display selecionado
    if (placar[j] <= 0 || placar[j] >= 10)
    {
      placar[j] = 0; // Reseta o placar se for maior que 9 ou menor que 0
    }
    if (placar_ant[j] != placar[j])
    {
      // Atualiza o display com o novo valor do placar
      writeOnMatrix(placar[j], j);
      placar_ant[j] = placar[j]; // Atualiza o placar anterior
    }

    // Aguarda até que o botão seja liberado
    while (digitalRead(7) == 0)
    {
      delay(50);
    }
  }

  // Verifica se o botão de diminuir o contador foi pressionado
  v_but3 = digitalRead(8);
  if (v_but3 == 0)
  {
    placar[j] = placar[j] - 1; // Decrementa o placar do display selecionado
    if (placar[j] <= 0 || placar[j] >= 10)
    {
      placar[j] = 0; // Reseta o placar se for menor que 0 ou maior que 9
    }
    if (placar_ant[j] != placar[j])
    {
      // Atualiza o display com o novo valor do placar
      writeOnMatrix(placar[j], j);
      placar_ant[j] = placar[j]; // Atualiza o placar anterior
    }

    // Aguarda até que o botão seja liberado
    while (digitalRead(8) == 0)
    {
      delay(50);
    }
  }
}

// Função para exibir um número na matriz de LEDs
void writeOnMatrix(int numero, int tela)
{
  // Arrays que definem a forma de cada número de 0 a 9
  byte N0[8] = {B00000000, B00000000, B00111110, B01000001,
                B01000001, B00111110, B00000000, B00000000};
  byte N1[8] = {B00000000, B00000000, B00000000, B01000010,
                B01111111, B01000000, B00000000, B00000000};
  byte N2[8] = {B00000000, B00000000, B01100010, B01010001,
                B01001001, B01000110, B00000000, B00000000};
  byte N3[8] = {B00000000, B00000000, B00100010, B01000001,
                B01001001, B00110110, B00000000, B00000000};
  byte N4[8] = {B00000000, B00000000, B00001100, B00001010,
                B00001001, B01111111, B00000000, B00000000};
  byte N5[8] = {B00000000, B00000000, B00100111, B01000101,
                B01000101, B00111001, B00000000, B00000000};
  byte N6[8] = {B00000000, B00000000, B00111110, B01001001,
                B01001001, B00110000, B00000000, B00000000};
  byte N7[8] = {B00000000, B00000000, B01100001, B00010001,
                B00001001, B00000111, B00000000, B00000000};
  byte N8[8] = {B00000000, B00000000, B00110110, B01001001,
                B01001001, B00110110, B00000000, B00000000};
  byte N9[8] = {B00000000, B00000000, B00001110, B01001001,
                B01001001, B00111110, B00000000, B00000000};

  // Mostra no display selecionado o número correspondente
  switch (numero)
  {
    case 0:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N0[i]);
      break;
    case 1:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N1[i]);
      break;
    case 2:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N2[i]);
      break;
    case 3:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N3[i]);
      break;
    case 4:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N4[i]);
      break;
    case 5:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N5[i]);
      break;
    case 6:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N6[i]);
      break;
    case 7:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N7[i]);
      break;
    case 8:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N8[i]);
      break;
    case 9:
      for (int i = 0; i < 8; i++) lc.setRow(tela, i, N9[i]);
      break;
  }
}
