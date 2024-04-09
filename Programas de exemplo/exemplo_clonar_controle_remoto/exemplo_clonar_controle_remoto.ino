#include <IRremote.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 2; //PINO DIGITAL EM QUE O RECEPTOR VS1838B ESTÁ CONECTADO

IRrecv irrecv(RECV_PIN); //VARIÁVEL DO TIPO IRrecv

decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  irrecv.enableIRIn(); //INICIALIZA O RECEPTOR
}
//MÉTODO RESPONSÁVEL POR FAZER A DECODIFICAÇÃO DO SINAL IR RECEBIDO
//OS DADOS SÃO PASSADOS PARA A BIBLIOTECA IRREMOTE QUE FAZ TODO O
//TRATAMENTO E RETORNA AS INFORMAÇÕES DE ACORDO COM O PROTOCOLO RECONHECIDO
void dump(decode_results *results){
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  } 
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");
  } 
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  } 
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  } 
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {  
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->panasonicAddress,HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
     Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
     Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == SAMSUNG) {
     Serial.print("Decoded SAMSUNG: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}
void loop() {
  //RETORNA NA SERIAL AS INFORMAÇÕES FINAIS SOBRE O COMANDO IR QUE FOI IDENTIFICADO
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume();
  }
}
