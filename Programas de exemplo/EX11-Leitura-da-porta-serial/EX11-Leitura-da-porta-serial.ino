/*
  Controle de LED via Porta Serial
  Este exemplo demonstra como controlar um LED conectado ao pino 13 de um Arduino através de comandos recebidos pela porta serial.
  O LED liga ou desliga quando o caractere 'a' é digitado na interface serial.

  Elaborado/Adaptado por Epaminondas Lage
*/

int status = 0; // VARIÁVEL QUE CONTROLA O STATUS (LIGADO / DESLIGADO)

void setup(){
  pinMode(13, OUTPUT); // DECLARA O PINO 13 COMO SENDO SAÍDA
  digitalWrite(13, LOW); // LED INICIA DESLIGADO
  Serial.begin(9600); // INICIALIZA A PORTA SERIAL
}    

void loop(){
  char c = Serial.read(); // VARIÁVEL RESPONSÁVEL POR RECEBER O CARACTERE DIGITADO NA JANELA SERIAL

  if (c == 'a'){ // SE CARACTERE DIGITADO FOR IGUAL A "a", FAZ
    if (status == 0){ // SE VARIÁVEL FOR IGUAL A 0, FAZ
      digitalWrite(13, HIGH); // LIGA O LED DO PINO 13
      status = 1; // VARIÁVEL RECEBE O VALOR 1 (LIGADO)
      Serial.println("LED 13 LIGADO"); // ESCREVE O TEXTO NA JANELA SERIAL
    } else { // SENÃO, FAZ
      digitalWrite(13, LOW); // DESLIGA O LED DO PINO 13
      status = 0; // VARIÁVEL RECEBE O VALOR 0 (DESLIGADO)
      Serial.println("LED 13 DESLIGADO"); // ESCREVE O TEXTO NA JANELA SERIAL
    }
  }
}
