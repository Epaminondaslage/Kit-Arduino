#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <MFRC522.h> //INCLUSÃO DE BIBLIOTECA

const int SS_PIN = 10 //PINO DIGITAL UTILIZADO PELO MÓDULO RFID
const int RST_PIN = 9 //PINO DIGITAL UTILIZADO PELO MÓDULO RFID

MFRC522 mfrc522(SS_PIN, RST_PIN); //DEFINIÇÕES DOS PINOS DO MÓDULO RC522

const int pino_led_liberado = 5; //PINO DIGITAL UTILIZADO PELO LED
const int pino_led_negado = 6; //PINO DIGITAL UTILIZADO PELO LED

char st[20]; //ARRAY DE 20 POSIÇÕES

void setup(){
  pinMode(pino_led_liberado, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  pinMode(pino_led_negado, OUTPUT); //DEFINE A PORTA COMO SAÍDA
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
  SPI.begin(); //INICIALIZA A SPI BUS
  mfrc522.PCD_Init(); // INICIA O MÓDULO RFID MFRC522
  Serial.println("Aproxime o seu cartao do leitor..."); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
}
void loop(){
  // Aguarda a aproximacao do cartao
  if ( ! mfrc522.PICC_IsNewCardPresent()){ //AGUARDA A APROXIMAÇÃO DO CARTÃO (CHAVEIRO OU CARTÃO PLÁSTICO)
    return;
  }
  // Seleciona um dos cartoes
  if ( ! mfrc522.PICC_ReadCardSerial()){ //SELECIONA UM DOS CARTÕES
    return;
  }
  Serial.print("UID da tag :"); //MOSTRA NA SERIAL O UID DO CARTÃO LIDO / ANOTE OS UID's DO SEU CARTÃO PLÁSTICO E DO CHAVEIRO
  String conteudo= ""; //VARIÁVEL DO TIPO STRING QUE GUARDA O CONTEÚDO LIDO
  byte letra; //VARIÁVEL DO TIPO BYTE
  for (byte i = 0; i < mfrc522.uid.size; i++){ //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE "mfrc522.uid.size", INCREMENTA "i"
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); //ESCREVE O TEXTO NA JANELA SERIAL
     Serial.print(mfrc522.uid.uidByte[i], HEX); //ESCREVE O TEXTO NA JANELA SERIAL
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); //CONCATENA O CONTEÚDO LIDO
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX)); //CONCATENA O CONTEÚDO LIDO
  }
  Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
  Serial.print("Mensagem : "); //ESCREVE O TEXTO NA JANELA SERIAL
  conteudo.toUpperCase(); //TRANSFORMA TODO CONTEÚDO LIDO EM LETRAS MAIÚSCULAS
  
  if(conteudo.substring(1) == "83 8E 58 02"){ //TESTA SE O CARTÃO LIDO POSSUI CÓDIGO IGUAL AO DA SEQUÊNCIA "83 8E 58 02" / "83 8E 58 02" DEVE SER ALTERADO PARA O UID DO SEU CARTÃO PLÁSTICO
    digitalWrite(pino_led_liberado, HIGH); //ACENDE O LED REFERENTE A LIBERAÇÃO
    Serial.println("Cartao1 - Acesso liberado !"); //ESCREVE O TEXTO NA JANELA SERIAL
    Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
    delay(3000); //INTERVALO DE 3 SEGUNDOS
    digitalWrite(pino_led_liberado, LOW); //APAGA O LED REFERENTE A NEGAÇÃO
    }
  if(conteudo.substring(1) == "A3 37 1D 00"){ //TESTA SE O CARTÃO LIDO POSSUI CÓDIGO IGUAL AO DA SEQUÊNCIA "A3 37 1D 00" / "A3 37 1D 00" DEVE SER ALTERADO PARA O UID DO SEU CHAVEIRO
    Serial.println("Cartao2 - Acesso negado !!"); //ESCREVE O TEXTO NA JANELA SERIAL
    Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
    // Pisca o led vermelho
    for (int i= 1; i<5 ; i++){ //PARA "i" IGUAL A 1, ENQUANTO "i" MENOR QUE 5, INCREMENTA "i"
      digitalWrite(pino_led_negado, HIGH); //ACENDE O LED REFERENTE A NEGAÇÃO
      delay(200); //INTERVALO DE 200ms
      digitalWrite(pino_led_negado, LOW); //APAGA O LED REFERENTE A NEGAÇÃO
      delay(200); //INTERVALO DE 200ms
    }
  }
  delay(1000); //INTERVALO DE 1 SEGUNDO
}
