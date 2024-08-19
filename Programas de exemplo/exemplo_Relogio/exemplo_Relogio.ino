/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                    Relógio com o integrado DS3231 (RTC)
                    Elaborado/Adptado por Epaminondas Lage
                    Clube de Robótica da ESGC – 2017
                    Prof. Ramiro Martins
                    Modificado em 17/06/19
 **************************************************************************/ 

#include <DS3231.h> // Inclui a biblioteca para controlar o RTC DS3231

DS3231 rtc(SDA, SCL); // Inicializa o RTC utilizando os pinos SDA e SCL

void setup()
{
  // Inicialização da comunicação serial
  Serial.begin(9600);
  // Inicialização do RTC
  rtc.begin();

  // Configuração inicial da data e hora no RTC
  rtc.setDOW(MONDAY);        // Define o dia da semana (em inglês)
  rtc.setTime(15, 29, 0);    // Define a hora no formato 24 horas (HH:MM:SS)
  rtc.setDate(20, 3, 2017);  // Define a data (DD, MM, AAAA)

  // As configurações acima só precisam ser feitas uma vez, no upload inicial.
  // Após a configuração inicial, o RTC manterá a data e hora atualizadas.
}

void loop()
{
  // Leitura e exibição do dia da semana
  Serial.print("Dia da semana: ");
  Serial.println(rtc.getDOWStr()); // Obtém e exibe o dia da semana

  // Leitura e exibição da data
  Serial.print("Data: ");
  Serial.println(rtc.getDateStr()); // Obtém e exibe a data

  // Leitura e exibição da hora
  Serial.print("Horas: ");
  Serial.println(rtc.getTimeStr()); // Obtém e exibe a hora

  // Espera de 1 segundo antes de realizar a próxima leitura
  delay(1000);
}

