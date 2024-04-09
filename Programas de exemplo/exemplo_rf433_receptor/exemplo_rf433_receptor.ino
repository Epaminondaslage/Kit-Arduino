#include <VirtualWire.h> //INCLUSÃO DE BIBLIOTECA

int ledPin = 5; //PINO DIGITAL UTILIZADO PELO LED

int valor_recebido_RF; //VARIÁVEL DO TIPO INTEIRA
char recebido_RF_char[4]; //VARIÁVEL DO TIPO CHAR

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  pinMode(ledPin, OUTPUT); //DECLARA O PINO COMO SAÍDA
  vw_set_rx_pin(7); //PINO LIGADO AO PINO DATA DO RECEPTOR RF
  vw_setup(5000); //VELOCIDADE DE COMUNICAÇÃO (BITS/SEGUNDO)
  vw_rx_start(); //INICIA A RECEPÇÃO DE DADOS
  Serial.println("Recepcao modulo RF - Aguardando..."); //ESCREVE O TEXTO NA SERIAL
}
void loop(){
  //TRATAMENTO DE MENSSAGEM RECEBIDA
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)){
    int i; //VARIÁVEL DO TIPO INTEIRA
        for (i = 0; i < buflen; i++){ //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE "buflen", INCREMENTA "i"
          recebido_RF_char[i] = char(buf[i]); //ARMAZENA OS CARACTERES RECEBIDOS
       }
       recebido_RF_char[buflen] = '\0';
       
       valor_recebido_RF = atoi(recebido_RF_char); //CONVERTE O VALOR RECEBIDO PARA UM INTEIRO
         
       Serial.print("Recebido: "); //ESCREVE O TEXTO NA SERIAL
       Serial.print(valor_recebido_RF); //ESCREVE VALOR NA SERIAL
       if (valor_recebido_RF == 1){ //SE LEITURA FOR IGUAL A 1, FAZ
         digitalWrite(ledPin, HIGH); //ESCREVE HIGH NO PINO
         Serial.println(" - Led aceso !"); //ESCREVE O TEXTO NA SERIAL
       }
       if (valor_recebido_RF == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
         digitalWrite(ledPin, LOW); //ESCREVE LOW NO PINO
         Serial.println(" - Led apagado !"); //ESCREVE O TEXTO NA SERIAL
       }
    }
}
