/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                           Animação com PROGMEM
                        Roda no Arduino Uno e Nano
           Fonte: xantorohara.guithub.io/led_matrix-editor
                  Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/

 #include <LedControl.h>

const int DIN_PIN = 12;
const int CS_PIN = 10;
const int CLK_PIN = 11;

const uint64_t IMAGES[] PROGMEM = {
  0xff000001010000ff, 0xff000003030000ff, 0xff000006060000ff,
  0xff00000c0c0000ff, 0xff000018180000ff, 0xff000030300000ff,
  0xff000060600000ff, 0xff0000c0c00000ff, 0xff000080800000ff,
  0xff0000c0c00000ff, 0xff000060600000ff, 0xff000018180000ff,
  0xff00000c0c0000ff, 0xff000006060000ff, 0xff000003030000ff,
  0xff000001010000ff
};
const int IMAGES_LEN = sizeof(IMAGES)/8;


LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);


void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
  uint64_t image;
  memcpy_P(&image, &IMAGES[i], 8);
  
  displayImage(image);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(500);
}
