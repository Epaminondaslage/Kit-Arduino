/*
 * Programa para tocar uma melodia simples com um buzzer usando Arduino.
 * Melodia: "Ode to Joy" de Ludwig van Beethoven.
 *
 * Conexões:
 * - Pino positivo do buzzer no pino digital 8 do Arduino.
 * - Pino negativo do buzzer no pino GND do Arduino.
 *
 * Notas:
 * - As notas são representadas em Hertz (Hz).
 * - Pausas entre as notas são representadas por 0 Hz.
 *
 * Código adptado por: Epaminondas Lage
 */

// Definindo o pino onde o buzzer está conectado
const int buzzerPin = 8;

// Frequências das notas em Hertz
const int NOTE_C4 = 261; // Dó central
const int NOTE_D4 = 293; // Ré
const int NOTE_E4 = 329; // Mi
const int NOTE_F4 = 349; // Fá
const int NOTE_G4 = 392; // Sol
const int NOTE_A4 = 440; // Lá
const int NOTE_B4 = 493; // Si
const int NOTE_C5 = 523; // Dó (uma oitava acima)
const int REST = 0; // Pausa entre as notas

// Notas da música "Ode to Joy"
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,  // Primeira frase
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,  // Segunda frase
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,  // Terceira frase
  NOTE_E4, NOTE_D4, NOTE_D4, REST,      // Quarta frase

  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,  // Quinta frase
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,  // Sexta frase
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,  // Sétima frase
  NOTE_D4, NOTE_C4, REST, REST         // Oitava frase
};

// Durações das notas em milissegundos
int noteDurations[] = {
  400, 400, 400, 400,  // Primeira frase
  400, 400, 400, 400,  // Segunda frase
  400, 400, 400, 400,  // Terceira frase
  800, 800, 800, 800,  // Quarta frase
  
  400, 400, 400, 400,  // Quinta frase
  400, 400, 400, 400,  // Sexta frase
  400, 400, 400, 400,  // Sétima frase
  800, 800, 800, 800   // Oitava frase
};

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  // Toca a melodia
  for (int i = 0; i < 32; i++) {
    int note = melody[i];          // Obtém a nota atual
    int duration = noteDurations[i]; // Obtém a duração da nota atual

    if (note > 0) {
      tone(buzzerPin, note, duration); // Toca a nota
    } else {
      noTone(buzzerPin); // Pausa (desativa o buzzer)
    }

    delay(duration * 1.30); // Adiciona um pequeno atraso entre as notas
  }
  
  delay(2000); // Atraso entre repetições da música
}
