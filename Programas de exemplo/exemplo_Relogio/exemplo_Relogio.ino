/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                    Relógio com o integrado DS3231 (RTC)
                    Elaborado/Adptado por Epaminondas Lage
                    Clube de Robótica da ESGC – 2017
                    Prof. Ramiro Martins
                    Modificado em 17/06/19
 **************************************************************************/ 
#include <DS3231.h>
DS3231 rtc(SDA, SCL);

void setup()
{
  // Inicialização da comunicação
  Serial.begin(9600);
  // Initialização do rtc
  rtc.begin();

  // As linhas seguintes têm de ser atualizadas com a Data e Hora de envio do programa para o Arduíno
  rtc.setDOW(MONDAY);     // Deve ser alterado o dia da semana para o dia em que estás em inglês
  rtc.setTime(15, 29, 0);     // Escreve as horas no formato 12:00:00 (formato 24 horas)
  rtc.setDate(20, 3, 2017);   // Escreve a data de acordo com o sistema que utilizas DD, MM, AAAA
  // Este programa escreve a data e hora no RTC e o relógio fica a trabalhar
}
// As linhas seguintes são para fazer a leitura da data e hora
void loop()
{
  // Le o dia de semana
  Serial.print("Dia da semana: ");
  Serial.println(rtc.getDOWStr());
  // Le a data
  Serial.print("Data: ");
  Serial.println(rtc.getDateStr());
  // Envia as horas
  Serial.print("Horas: ");
  Serial.println(rtc.getTimeStr());
  // Tempo de espera antes de uma nova leitura 1 segundo
  delay (1000);
}
