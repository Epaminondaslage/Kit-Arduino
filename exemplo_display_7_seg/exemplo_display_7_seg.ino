byte seven_seg_digits[16][7] = { { 1,1,1,1,1,1,0 },  //DIGITO 0
                                 { 0,1,1,0,0,0,0 },  //DIGITO 1
                                 { 1,1,0,1,1,0,1 },  //DIGITO 2
                                 { 1,1,1,1,0,0,1 },  //DIGITO 3
                                 { 0,1,1,0,0,1,1 },  //DIGITO 4
                                 { 1,0,1,1,0,1,1 },  //DIGITO 5
                                 { 1,0,1,1,1,1,1 },  //DIGITO 6
                                 { 1,1,1,0,0,0,0 },  //DIGITO 7
                                 { 1,1,1,1,1,1,1 },  //DIGITO 8
                                 { 1,1,1,0,0,1,1 },  //DIGITO 9
                                 { 1,1,1,0,1,1,1 },  //DIGITO A
                                 { 0,0,1,1,1,1,1 },  //DIGITO B
                                 { 1,0,0,1,1,1,0 },  //DIGITO C
                                 { 0,1,1,1,1,0,1 },  //DIGITO D
                                 { 1,0,0,1,1,1,1 },  //DIGITO E
                                 { 1,0,0,0,1,1,1 }   //DIGITO F
                                 };
void setup(){  
  pinMode(2, OUTPUT); //PINO 2 -> SEGMENTO A  
  pinMode(3, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(4, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(6, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(7, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(8, OUTPUT); //PINO 8 -> SEGMENTO G
  pinMode(9, OUTPUT); //PINO 9 -> SEGMENTO PONTO
  writePonto(0);
}
void writePonto(byte dot){  //FUNÇÃO QUE ACIONA O PONTO NO DISPLAY
  digitalWrite(9, dot);
}
void sevenSegWrite(byte digit){ //FUNCÇÃO QUE ACIONA O DISPLAY
  byte pin = 2;

  for (byte segCount = 0; segCount < 7; ++segCount){ //PARA "segCount" IGUAL A 0, ENQUANTO "segCount" MENOR QUE 7, INCREMENTA "segCount"
    digitalWrite(pin, seven_seg_digits[digit][segCount]); //PERCORRE O ARRAY E LIGA OS SEGMENTOS CORRESPONDENTES AO DIGITO
    ++pin; //INCREMENTA "pin"
  }
    writePonto(1); //LIGA O PONTO DO DISPLAY
    delay(100); //INTERVALO DE 100 MILISEGUNDOS
    writePonto(0); //DESLIGA O PONTO DO DISPLAY
}
//MÉTODO RESPONSÁVEL PELA CONTAGEM DE 0 A 9 E CONTAGEM DE "A" ATÉ "F" (NA CONTAGEM HEXADECIMAL "A"=10 / "B"=11 / "C"=12 / "D"=13 / "E"=14 / "F"=15)
void loop() {
  for (byte count = 0; count < 16; count++){ //PARA "count" IGUAL A 0, ENQUANTO "count" MENOR QUE 16, INCREMENTA "count"
     delay(500); //INTERVALO DE 500 MILISEGUNDOS
     sevenSegWrite(count); //FAZ A CONTAGEM
  }
  delay(4000); //INTERVALO DE 4 SEGUNDOS
}
