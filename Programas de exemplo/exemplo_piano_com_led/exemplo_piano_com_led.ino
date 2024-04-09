/*******************************************************************************
*    CEFET-MG
*    Exercício 06 – Projeto Piano com Buzzer                                   *
*    Disciplina : Informática
*******************************************************************************/
const int ledpino1 = 13;
const int ledpino2 = 12;
const int ledpino3 = 11;
const int botaoA = 4;
const int botaoB = 3;
const int botaoC = 2;
const int som = 9;
 
int estado_botaoA = 0;
int estado_botaoB = 0;
int estado_botaoC = 0;
int tom = 0;
 
void setup() {
  // coloque seu código de setup aqui, para rodar uma vez: define saída e entrada do arduino
    pinMode(ledpino1, OUTPUT); //pino saida
    pinMode(ledpino2, OUTPUT); //pino saida
    pinMode(ledpino3, OUTPUT); //pino saida
    pinMode(som, OUTPUT); // pino de saída do arduino
    pinMode(botaoA, INPUT); //pino do botão é entrada
    pinMode(botaoB, INPUT); //pino do botão é entrada
    pinMode(botaoC, INPUT); //pino do botão é entrada
}
 
void loop() {
  // coloque seu código principal aqui, para rodar repetidamente:
 
    estado_botaoA = digitalRead(botaoA); //define estado bt A
    estado_botaoB = digitalRead(botaoB);
    estado_botaoC = digitalRead(botaoC);
 
    if(estado_botaoA && !estado_botaoB && !estado_botaoC) {
        tom = 100;
        digitalWrite(ledpino1, HIGH);
        }
    if(estado_botaoB && !estado_botaoA && !estado_botaoC) {
        tom = 200;
        digitalWrite(ledpino2, HIGH);
        }
    if (estado_botaoC && !estado_botaoA && !estado_botaoB) {
        tom = 500;
        digitalWrite(ledpino3, HIGH);
        }

 //teste de tom
    if(tom > 0) { //enquanto Tom for maior que zero faça o que esta descrit o baixo:
        digitalWrite(som, HIGH); // Liga buzzer
        delayMicroseconds(tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
        digitalWrite(som, LOW); // Desliga buzzer
        delayMicroseconds(tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
        tom = 0; // Reseta o Tom para zero, para sair do loop while e nao tocar o som constantemente
        digitalWrite(ledpino1, LOW);
        digitalWrite(ledpino2, LOW);
        digitalWrite(ledpino3, LOW);
        }
 
}
