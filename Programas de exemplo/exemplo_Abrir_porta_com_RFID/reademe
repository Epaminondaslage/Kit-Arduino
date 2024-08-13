/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                  Programa para Abrir Uma porta através do RFID
                            Autor : Felipe Gbur
                    Elaborado/Adptado por Epaminondas Lage
 **************************************************************************/
#include <SPI.h> // Inclui a biblioteca para comunicação SPI
#include <MFRC522.h> // Inclui a biblioteca para o leitor RFID MFRC522

// Definições dos pinos
#define SS_PIN 10  // Pino de seleção do periférico (SS) para o MFRC522
#define RST_PIN 9  // Pino de reset para o MFRC522
#define LED_R 5    // Pino do LED vermelho
#define LED_G 3    // Pino do LED verde
char st[20]; // Declara um array de caracteres para armazenar strings

// Instancia o objeto MFRC522 usando os pinos definidos
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup()
{
  // Inicia a comunicação serial
  Serial.begin(9600);

  // Inicia o barramento SPI
  SPI.begin();

  // Inicia o módulo MFRC522
  mfrc522.PCD_Init();

  // Mensagem inicial na serial
  Serial.println("Aproxime o seu cartao/TAG do leitor");
  Serial.println();

  // Define os pinos dos LEDs como saída
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
}
 
void loop()
{
  // Inicializa os LEDs: verde apagado, vermelho aceso
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, HIGH);
 
  // Verifica se há um novo cartão presente
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return; // Sai do loop se nenhum novo cartão for detectado
  }

  // Tenta ler o cartão
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return; // Sai do loop se a leitura do cartão falhar
  }

  // Mostra o ID do cartão/tag na serial
  Serial.print("ID do Cartao/tag:");
  String conteudo = ""; // String para armazenar o conteúdo do ID
  byte letra; // Variável auxiliar para armazenar o byte lido
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); // Formata a saída em hexadecimal
    Serial.print(mfrc522.uid.uidByte[i], HEX); // Imprime o byte em hexadecimal
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); // Adiciona o byte à string conteúdo
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX)); // Concatena o byte em formato hexadecimal à string
  }
  Serial.println(); // Nova linha após mostrar o ID
  Serial.print("Mensagem : ");
  conteudo.toUpperCase(); // Converte a string para maiúsculas
 
  // Verifica se o ID lido corresponde a um dos IDs autorizados
  if (conteudo.substring(1) == "51 48 9B 2E" || 
      conteudo.substring(1) == "D3 7F 94 79" || 
      conteudo.substring(1) == "14 A7 B1 7A" || 
      conteudo.substring(1) == "94 43 BB 7A") // IDs dos cartões autorizados
  {
    // Se o ID for autorizado, acende o LED verde e apaga o vermelho
    Serial.println("Acesso autorizado !");
    Serial.println();
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_R, LOW);
    delay(5000); // Mantém o LED verde aceso por 5 segundos
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH); // Restaura o estado inicial dos LEDs
  }
}
