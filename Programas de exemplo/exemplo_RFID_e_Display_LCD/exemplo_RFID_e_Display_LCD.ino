/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
  RFID - Controle de Acesso com Leitor RFID, Monitoramento por Display 16x2 e Acionamento de Relé
                    Elaborado/Adaptado por Epaminondas Lage
                            Autor: FILIPEFLOP 
 
   Pinagem do Leitor RFID:
 
    Pino SDA  ligado na porta 10 do Arduino
    Pino SCK  ligado na porta 13 do Arduino
    Pino MOSI ligado na porta 11 do Arduino
    Pino MISO ligado na porta 12 do Arduino
    Pino NC   Não conectado
    Pino GND  ligado no pino GND do Arduino
    Pino RST  ligado na porta 9 do Arduino
    Pino 3.3V ligado ao pino 3.3V do Arduino

    Pinagem do Display 16x2:
    
    Pino 4  (RS) ligado ao pino 6 do Arduino
    Pino 6  (E)  ligado ao pino 7 do Arduino
    Pino 11 (D4) ligado ao pino 5 do Arduino
    Pino 12 (D5) ligado ao pino 4 do Arduino
    Pino 13 (D6) ligado ao pino 3 do Arduino
    Pino 14 (D7) ligado ao pino 2 do Arduino

**************************************************************************/
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10  // Pino SS para o leitor RFID
#define RST_PIN 9  // Pino RST para o leitor RFID

// Cria uma instância do MFRC522 para o leitor RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Define os PINs autorizados para abrir a fechadura
int numpin = 4;
char* pinliberados[] = {"14 A7 B1 7A", "D3 7F 94 79", "51 48 9B 2E", "24 C4 B3 7A"};
char* nomeliberados[] = {"Chave", "Tag", "Cartao", "Blandino"};

// Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 

// Define o pino que será utilizado para ligação do relé
const int saidarele = 8;

char st[20]; // Variável auxiliar para armazenar strings
 
void setup() 
{
  pinMode(saidarele, OUTPUT); // Configura o pino do relé como saída
  Serial.begin(9600);         // Inicia a comunicação serial
  SPI.begin();                // Inicia o barramento SPI
  mfrc522.PCD_Init();         // Inicializa o leitor RFID
  Serial.println("Aproxime o seu cartão do leitor...");
  Serial.println();

  // Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);  
  mensageminicial(); // Exibe a mensagem inicial no display
}
 
void loop() 
{
  digitalWrite(saidarele, HIGH); // Desliga a fechadura

  // Verifica se há um novo cartão presente
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  // Tenta ler o cartão
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  // Mostra o UID na serial
  Serial.print("UID da tag: ");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem: ");
  conteudo.toUpperCase();

  // Verifica se o cartão está na lista de autorizados
  for (int i = 0; i < numpin; i++)
  {
    if(conteudo.substring(1) == pinliberados[i]) 
    {
        Serial.print("Olá ");
        Serial.println(nomeliberados[i]);
        Serial.println();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ola ");
        lcd.print(nomeliberados[i]);
        lcd.setCursor(0, 1);
        lcd.print("Acesso liberado!");
        delay(1000);           // Aguarda um segundo 
        acionarele();          // Aciona o relé para abrir a fechadura             
        mensageminicial();     // Retorna à mensagem inicial no display
        return;
    }
  }

  // Se o cartão não for autorizado, bloqueia o acesso
  Serial.println("Acesso Bloqueado");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Acesso Bloqueado !");
  delay(3000);
  mensageminicial(); // Retorna à mensagem inicial no display
} 

// Função para acionar o relé e abrir a fechadura
void acionarele()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Fechadura");
    lcd.setCursor(0, 1);
    lcd.print("     Acionada");
    digitalWrite(saidarele, LOW);   // Liga a fechadura
    delay(2000);                    // Aguarda dois segundos
    digitalWrite(saidarele, HIGH);  // Desliga a fechadura     
}

// Função para exibir a mensagem inicial no display
void mensageminicial()
{
  while (!mfrc522.PICC_IsNewCardPresent()) 
  {
    lcd.clear();
    lcd.print("    Garagem");  
    lcd.setCursor(0, 1);
    lcd.print("  Pe de Serra"); 
    delay(1000);
    if (mfrc522.PICC_IsNewCardPresent()) {
      return;
    }
    delay(1000);
    lcd.clear();
    lcd.print("    Aproxime");  
    lcd.setCursor(0, 1);
    lcd.print("    Seu Tag");
    delay(1000);
    if (mfrc522.PICC_IsNewCardPresent()) {
      return;
    }
    delay(1000);
  }  
}
