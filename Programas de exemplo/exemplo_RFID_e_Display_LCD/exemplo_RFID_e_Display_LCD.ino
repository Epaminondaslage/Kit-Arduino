/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
  RFID - Controle de Acesso leitor RFID com monitoramento por display 16x2 e acionamento de relé
                    Elaborado/Adptado por Epaminondas Lage
                            Autor : FILIPEFLOP 
 
   Pinagem Leitor RFID:
 
    Pino SDA  ligado na porta 10 do Arduino
    Pino SCK  ligado na porta 13 do Arduino
    Pino MOSI ligado na porta 11 do Arduino
    Pino MISO ligado na porta 12 do Arduino
    Pino NC   Não conectado
    Pino GND  ligado no pino GND do Arduino
    Pino RST  ligado na porta 9 do Arduino
    Pino 3.3  ligado ao pino 3.3 V do Arduino

    Display 16 x 2 
    
    Pino 4  (RS) ligado ao pino 6 do Arduino
    Pino 6   (E) ligado ao pino 7 do Arduino
    Pino 11 (D4) ligado ao pino 5 do Arduino
    Pino 12 (D5) ligado ao pino 4 do Arduino
    Pino 13 (D6) ligado ao pino 3 do Arduino
    Pino 14 (D7) ligado ao pino 2 do Arduino

**************************************************************************/
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#define SS_PIN 10
#define RST_PIN 9

// Cria Instância para MFRC522.
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Define os PINS liberados para abrir a fechadura 
int numpin=4;
char* pinliberados [] = {"14 A7 B1 7A", "D3 7F 94 79", "51 48 9B 2E", "24 C4 B3 7A"};
char* nomeliberados [] = {"Chave","Tag","Cartao", "Blandino"};
           

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 

//Define o pino que será utilizado para ligação do relé
const int saidarele=8;

char st[20];
 
void setup() 
{
  // Define Saída para ligar o rele
  pinMode(saidarele, OUTPUT); //PINO 8 Saída de Relé de porta 
  
  Serial.begin(9600); // Inicia a serial
  SPI.begin(); // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  //Define o número de colunas e linhas do LCD:  
  lcd.begin(16, 2);  
  mensageminicial();
}
 
void loop() 
{
  digitalWrite(saidarele, HIGH);    // Desliga Fechadura
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
   // return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  // testa os PINS Liberados
  for (int i=0;i<numpin;i++)
  {
    if(conteudo.substring(1) == pinliberados[i] ){
        Serial.print("Olá ");
        Serial.println(nomeliberados[i]);
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ola ");
        lcd.print(nomeliberados[i]);
        lcd.setCursor(0,1);
        lcd.print("Acesso liberado!");
        delay(1000);             // Aguarda um segundo 
        acionarele();                
        mensageminicial();
        return;
    }
  }
  Serial.println("Acesso Bloqueado");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Acesso Bloqueado !");
  delay(3000);
  mensageminicial();
} 

void acionarele()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    Fechadura");
    lcd.setCursor(0,1);
    lcd.print("     Acionada");
    digitalWrite(saidarele, LOW);       // Liga fechadura
    delay(2000);                       // Aguarda dois segundos
    digitalWrite(saidarele, HIGH);    // Desliga Fechadura     
}
void mensageminicial()
{
  while (! mfrc522.PICC_IsNewCardPresent()) 
  {
  lcd.clear();
  lcd.print("    Garagem");  
  lcd.setCursor(0,1);
  lcd.print("  Pe de Serra"); 
  delay(1000);
  if (mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  delay(1000);
  lcd.clear();
  lcd.print("    Aproxime");  
  lcd.setCursor(0,1);
  lcd.print("    Seu Tag");
  delay(1000);
  if (mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  delay(1000);
  }  
}
