const int sensorTensao = A2; //PINO ANALÓGICO UTILIZADO PELO SENSOR DE TENSÃO

String statusLamp = "DESLIGADA"; //VARIÁVEL QUE ARMAZENA O STATUS ATUAL DA LÂMPADA (LIGADA / DESLIGADA)

void setup(){
  pinMode(sensorTensao, INPUT); //DEFINE A PORTA COMO ENTRADA
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}    
void loop(){

  verificaStatusLamp();//CHAMA O MÉTDODO RESPONSÁVEL POR VERIFICAR SE A LÂMPADA ESTÁ ACESA OU APAGADA

  Serial.print("LAMPADA: "); //ESCREVE O TEXTO NA JANELA SERIAL
  Serial.println(statusLamp); //ESCREVE NA JANELA SERIAL O STATUS ATUAL DA LÂMPADA

}
//MÉTDODO RESPONSÁVEL POR VERIFICAR SE A LÂMPADA ESTÁ ACESA OU APAGADA
void verificaStatusLamp(){
  for (int i = 0; i < 50; i++){ //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 100, INCREMENTA "i"
    if(analogRead(sensorTensao) > 70){ //SE LEITURA FOR MAIOR QUE 70, FAZ
        statusLamp = "LIGADA"; //VARIÁVEL RECEBE O VALOR
    }else{ //SENÃO
      statusLamp = "DESLIGADA"; //VARIÁVEL RECEBE O VALOR
    }
  }
}

