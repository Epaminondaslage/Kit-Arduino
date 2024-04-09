void setup(){
  pinMode(3, OUTPUT); //CORRESPONDE A LIGAÇÃO NO PINO 1 DO TECLADO (LINHA)
  pinMode(4, OUTPUT); //CORRESPONDE A LIGAÇÃO NO PINO 2 DO TECLADO (LINHA)
  pinMode(5, OUTPUT); //CORRESPONDE A LIGAÇÃO NO PINO 3 DO TECLADO (LINHA)
  pinMode(6, OUTPUT); //CORRESPONDE A LIGAÇÃO NO PINO 4 DO TECLADO (LINHA)
  
  pinMode(8, INPUT); //CORRESPONDE A LIGAÇÃO NO PINO 5 DO TECLADO (COLUNA)
  pinMode(9, INPUT); //CORRESPONDE A LIGAÇÃO NO PINO 6 DO TECLADO (COLUNA)
  pinMode(10, INPUT); //CORRESPONDE A LIGAÇÃO NO PINO 7 DO TECLADO (COLUNA)
  pinMode(11, INPUT); //CORRESPONDE A LIGAÇÃO NO PINO 8 DO TECLADO (COLUNA)
   
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aguardando acionamento das teclas..."); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
}
 
void loop(){
    for (int ti = 3; ti<7; ti++){ //PARA "ti" IGUAL A 3, ENQUANTO "ti" MENOR QUE 7, INCREMENTA "ti"
    digitalWrite(3, LOW); //ALTERNA O ESTADO DO PINO PARA LOW
    digitalWrite(4, LOW); //ALTERNA O ESTADO DO PINO PARA LOW
    digitalWrite(5, LOW); //ALTERNA O ESTADO DO PINO PARA LOW
    digitalWrite(6, LOW); //ALTERNA O ESTADO DO PINO PARA LOW
    digitalWrite(ti, HIGH); //ALTERNA O ESTADO DO PINO PARA HIGH

    if (digitalRead(8) == HIGH){ //SE A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
      imprime_linha_coluna(ti-2, 1); //CHAMA O MÉTODO "imprime_linha_coluna()" E PASSA OS PARÂMETROS
      while(digitalRead(8) == HIGH){} //ENQUANTO A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
    }  
    if (digitalRead(9) == HIGH){ //SE A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
      imprime_linha_coluna(ti-2, 2); //CHAMA O MÉTODO "imprime_linha_coluna()" E PASSA OS PARÂMETROS
      while(digitalRead(9) == HIGH){}; //ENQUANTO A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
    }
    if (digitalRead(10) == HIGH){ //SE A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
      imprime_linha_coluna(ti-2, 3); //CHAMA O MÉTODO "imprime_linha_coluna()" E PASSA OS PARÂMETROS
      while(digitalRead(10) == HIGH){} //ENQUANTO A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
    }
    if (digitalRead(11) == HIGH){ //SE A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
      imprime_linha_coluna(ti-2, 4); //CHAMA O MÉTODO "imprime_linha_coluna()" E PASSA OS PARÂMETROS
      while(digitalRead(11) == HIGH){} //ENQUANTO A LEITURA DO PINO DIGITAL FOR IGUAL A HIGH, FAZ
    }
   }
   delay(10); //INTERVALO DE 10 MILISEGUNDOS
}
//MÉTODO PARA IMPRIMIR AS INFORMAÇÕES NA JANELA SERIAL
void imprime_linha_coluna(int x, int y){
       Serial.print("Linha : "); //ESCREVE O TEXTO NA JANELA SERIAL
       Serial.print(x); //ESCREVE NA JANELA SERIAL O VALOR DA LINHA
       Serial.print(" x Coluna : "); //ESCREVE O TEXTO NA JANELA SERIAL
       Serial.print(y); //ESCREVE NA JANELA SERIAL O VALOR DA COLUNA
       delay(10); //INTERVALO DE 10 MILISEGUNDOS
       Serial.println(); //SALTA UMA LINHA NA JANELA SERIAL
}
