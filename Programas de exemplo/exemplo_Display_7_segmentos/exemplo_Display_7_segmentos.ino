/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
            Programa para apresentar em um display de 7 segmentos de 0 a 9
                             Display catodo comum
                    Elaborado/Adptado por Epaminondas Lage
 **************************************************************************/

//                             G F A B E D C
byte sete_digitos[10][7] = { { 0,1,1,1,1,1,1 },  //DIGITO 0
                             { 0,0,0,1,0,0,1 },  //DIGITO 1
                             { 1,0,1,1,1,1,0 },  //DIGITO 2
                             { 1,0,1,1,0,1,1 },  //DIGITO 3
                             { 1,1,0,1,0,0,1 },  //DIGITO 4
                             { 1,1,1,0,0,1,1 },  //DIGITO 5
                             { 1,1,1,0,1,1,1 },  //DIGITO 6
                             { 0,0,1,1,0,0,1 },  //DIGITO 7
                             { 1,1,1,1,1,1,1 },  //DIGITO 8
                             { 1,1,1,1,0,1,1 },  //DIGITO 9
                            };
void setup(){  
  pinMode(2, OUTPUT); //PINO 2 -> SEGMENTO A  
  pinMode(3, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(4, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(6, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(7, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(8, OUTPUT); //PINO 8 -> SEGMENTO G
  }
//FUNÇÃO QUE ACIONA O DISPLAY
void ligadisplay(byte digit){ 
  byte pino = 2;
  for (byte Segmento = 0; Segmento < 7; ++Segmento){     //PARA "Segmento" IGUAL A 0, ENQUANTO "Segmento" MENOR QUE 7, INCREMENTA "Segmento"
    //PERCORRE O ARRAY E LIGA OS SEGMENTOS CORRESPONDENTES AO DIGITO
    digitalWrite(pino, sete_digitos[digit][Segmento]); 
    //INCREMENTA "pino"
    ++pino; 
  }
}


//MÉTODO RESPONSÁVEL PELA CONTAGEM DE 0 A 9

void loop() {
  /*PARA "conta" IGUAL A 0, ENQUANTO "conta" MENOR QUE 10, INCREMENTA "conta"*/
  for (byte conta = 0; conta < 10; conta++){ 
     delay(1000); //INTERVALO DE 1000 MILISEGUNDOS
     ligadisplay(conta); //FAZ A CONTAGEM
  }
  delay(4000); //INTERVALO DE 4 SEGUNDOS
}
