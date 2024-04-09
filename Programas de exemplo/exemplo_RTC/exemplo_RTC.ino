/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                                 RTC DSC3231
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/
//Incluir as libraries
#include <Wire.h> //Built-in
#include <RtcDS3231.h> //Library Manager
RtcDS3231<TwoWire> Rtc(Wire); 

void setup ()
{
  Serial.begin(9600);
  Rtc.Begin();
  // Obtém a data da compilação
  RtcDateTime data_compilacao = RtcDateTime(__DATE__, __TIME__);
  if (!Rtc.IsDateTimeValid()) //Se relogio está desatualizado
  {
    Serial.println("Relógio está desatualizado!!!");
    Rtc.SetDateTime(data_compilacao); // acerta o relógio com a data da compilação
  }
  if (!Rtc.GetIsRunning()) // Ativa o RTC
  {
    Rtc.SetIsRunning(true);
  }
  RtcDateTime now = Rtc.GetDateTime(); 
  if (now < data_compilacao) // Verifica se a data está consistente
  {
    Rtc.SetDateTime(data_compilacao);
  }
  // Reset
  Rtc.Enable32kHzPin(false);
  Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
  Serial.println("Relógio ativado\n");
}

void loop ()
{
  if (!Rtc.IsDateTimeValid()) //Bateria arriou?
  {
    Serial.println("Relógio está desatualizado!!!");
  }
  RtcDateTime now = Rtc.GetDateTime(); // Obtém o horário atual
  Serial.println(formatDate(now,"d/m/y"));
  Serial.println();
  Serial.println(formatTime(now,"h:m:s"));
  Serial.println();
  RtcTemperature temp = Rtc.GetTemperature(); // Obtém temperatura
  Serial.print(temp.AsFloat());
  Serial.println("C");
  delay(5000); 
}

// Funções para formatação dos dados
String formatDate(const RtcDateTime& dt, String format) 
{
  String d = dt.Day() < 10 ? "0" + String(dt.Day()) : String(dt.Day()) ; 
  String m = dt.Month() < 10 ? "0" + String(dt.Month()) : String(dt.Month()) ;
  String y = String(dt.Year()) ;
  format.replace("d",d);
  format.replace("m",m);
  format.replace("y",y);
  return format;
}

String formatTime(const RtcDateTime& dt, String format)
{
  String h = dt.Hour() < 10 ? "0" + String(dt.Hour()) : String(dt.Hour()) ;
  String m = dt.Minute() < 10 ? "0" + String(dt.Minute()) : String(dt.Minute()) ;
  String s = dt.Second() < 10 ? "0" + String(dt.Second()) : String(dt.Second()) ;
  format.replace("h",h);
  format.replace("m",m);
  format.replace("s",s);
  return format;
}


// Funções para formatação dos dados
String formatDate(const RtcDateTime& dt, String format) 
{
  String d = dt.Day() < 10 ? "0" + String(dt.Day()) : String(dt.Day()) ; 
  String m = dt.Month() < 10 ? "0" + String(dt.Month()) : String(dt.Month()) ;
  String y = String(dt.Year()) ;
  format.replace("d",d);
  format.replace("m",m);
  format.replace("y",y);
  return format;
}

String formatTime(const RtcDateTime& dt, String format)
{
  String h = dt.Hour() < 10 ? "0" + String(dt.Hour()) : String(dt.Hour()) ;
  String m = dt.Minute() < 10 ? "0" + String(dt.Minute()) : String(dt.Minute()) ;
  String s = dt.Second() < 10 ? "0" + String(dt.Second()) : String(dt.Second()) ;
  format.replace("h",h);
  format.replace("m",m);
  format.replace("s",s);
  return format;
}
