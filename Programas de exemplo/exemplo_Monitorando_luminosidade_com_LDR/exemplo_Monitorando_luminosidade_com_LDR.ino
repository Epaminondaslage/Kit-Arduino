/**************************************************************************
                    Placa de Desenvolvimento Arduino UNO 
                                 Uso de LDR
                    Elaborado/Adptado por Epaminondas Lage
            
 **************************************************************************/

#define LAMP 8 //Define o LAMP como 8
int LDR;   //Variável para a leitura do LDR
int cont;  //Variável utilizada para armazenar os valores lidos pelo sensor
int i;    //Variável para contagem



void setup()
{
  pinMode(LAMP,OUTPUT); //Define o pino D8 como saída
  Serial.begin(19200);   //Inicia a serial
}
void loop()
{
  LDR=0; //Zera a variável LDR
  for(i=0;i<=50;i++) //Faz 50 vezes a leitura do sensor
    {
      cont=analogRead(A0); //Lê o valor do sensor (LDR ligado ao pino A0) e guarda na variável LDR
      LDR = LDR+cont; //Armazenamento na varíavel LDR o valor lido + o valor anterior
      delay(100); //Delay se 100 milissegundos
     }
  
      LDR=LDR/50; //Divide o valor armazenado por 50
     Serial.println(LDR); //Imprime o valor do LDR

      (LDR >= 400) ? (digitalWrite(LAMP,HIGH)) : (digitalWrite(LAMP,LOW));
  
     //Se o valor lido (luminosidade) for maior ou igual a 400, liga a lâmpada, senão desliga a lâmpada
}

 
