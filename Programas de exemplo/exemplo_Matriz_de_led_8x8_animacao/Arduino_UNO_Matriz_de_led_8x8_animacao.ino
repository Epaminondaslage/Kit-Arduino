/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                           Animação com PROGMEM
                        Roda no Arduino Uno e Nano
           Fonte: xantorohara.github.io/led_matrix-editor
                  Elaborado/Adaptado por Epaminondas Lage
 **************************************************************************/

#include <LedControl.h> // Inclui a biblioteca LedControl para controlar a matriz de LEDs

// Definições dos pinos para conexão com o módulo Max7219
const int DIN_PIN = 12;  // Pino de dados
const int CS_PIN = 10;   // Pino de chip select
const int CLK_PIN = 11;  // Pino de clock

// Animação armazenada na memória flash (PROGMEM) para economizar RAM
const uint64_t IMAGES[] PROGMEM = {
  0xff000001010000ff, 0xff000003030000ff, 0xff000006060000ff,
  0xff00000c0c0000ff, 0xff000018180000ff, 0xff000030300000ff,
  0xff000060600000ff, 0xff0000c0c00000ff, 0xff000080800000ff,
  0xff0000c0c00000ff, 0xff000060600000ff, 0xff000018180000ff,
  0xff00000c0c0000ff, 0xff000006060000ff, 0xff000003030000ff,
  0xff000001010000ff
};
const int IMAGES_LEN = sizeof(IMAGES) / 8; // Calcula o número de imagens na animação

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN); // Inicializa o controle do display LED

void setup() {
  display.clearDisplay(0);          // Limpa o display
  display.shutdown(0, false);       // Ativa o display
  display.setIntensity(0, 10);      // Define o brilho do display
}

// Função para exibir uma imagem na matriz de LEDs
void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) { // Percorre as linhas da matriz
    byte row = (image >> i * 8) & 0xFF; // Extrai os bits de cada linha da imagem
    for (int j = 0; j < 8; j++) { // Percorre as colunas da matriz
      display.setLed(0, i, j, bitRead(row, j)); // Define o estado de cada LED
    }
  }
}

int i = 0; // Índice para a animação

void loop() {
  uint64_t image;
  memcpy_P(&image, &IMAGES[i], 8); // Copia a imagem da memória flash (PROGMEM) para a RAM
  
  displayImage(image); // Exibe a imagem na matriz de LEDs
  if (++i >= IMAGES_LEN) { // Incrementa o índice e reinicia se atingir o final
    i = 0;
  }
  delay(500); // Aguarda 500 ms antes de exibir a próxima imagem
}
