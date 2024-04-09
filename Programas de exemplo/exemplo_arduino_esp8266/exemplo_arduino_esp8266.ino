#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
 
#define DEBUG true

//O TX DO ESP-01 DEVE SER LIGADO NO PINO 2 (RX) DO ARDUINO
//O RX DO ESP-01 DEVE SER LIGADO NO PINO 3 (TX) DO ARDUINO

SoftwareSerial esp8266(2,3); ///OBJETO DO TIPO SoftwareSerial ( 2 = RX / 3 = TX)

String leituraAnalog1 = ""; //VARIÁVEL DO TIPO STRING

void setup(){
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS
  Serial.begin(9600); //INICIALIA A SERIAL DO ARDUINO
  esp8266.begin(9600); //INICIALIA A SERIAL DO ESP-01
  
  sendData("AT+RST\r\n",2000,DEBUG); //REINICIA O ESP-01
  sendData("AT+CWMODE=3\r\n",1000,DEBUG); //CONFIGURA O ESP-01 NO MODO DE OPERAÇÃO 3 (AP + STA)
  sendData("AT+CWJAP=\"OliveiraRocha\",\"2015ano2015\"r\n",10000,DEBUG); //COLOQUE OS DADOS DA SUA REDE SEM FIO (NOME DA REDE EM SUA_REDE_WIFI E A SENHA EM SENHA_REDE_WIFI)
  sendData("AT+CIFSR\r\n",1000,DEBUG); //RETORNA O IP EM QUE O ESP-01 FOI ALOCADO (MODO STA OU STATION)
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); //HABILITA MULTIPLAS CONEXÕES
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); //HABILITA A PORTA 80
}
 
void loop(){
  leituraAnalog1 = ""; //LIMPA O VALOR DA VARIÁVEL
  
  if(esp8266.available()){ //VERIFICA SE O ESP8266 ESTÁ ENVIANDO DADOS E SE ESTÁ DISPONÍVEL
    
    if(esp8266.find("+IPD,")){
    
    leituraAnalog1 = String(analogRead(1)); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO (VALOR É CONVERTIDO EM STRING ANTES DE SER ARMAZENADO)
     
     int connectionId = esp8266.read()-48; //SUBTRAI 48, POIS O MÉTODO read() RETORNA OS VALORES ASCII E O PRIMEIRO NÚMERO DECIMAL COMEÇA EM 48
     
     //CONSTRUÇÃO DA PÁGINA WEB QUE SERÁ EXIBIDA QUANDO O WEBSERVER RECEBER UMA REQUISIÇÃO
     String webpage = "<head><meta http-equiv=""refresh"" content=""5""></head>";
     webpage+="<body style=background-color:#ADD8E6>";
     webpage+="<center><h1>MasterWalker Shop</h1><h2> ESP8266</h2><h3>";
     webpage+="Leitura no pino analogico A1: ";
      webpage+=leituraAnalog1 + " </h3></center>";
      
     String cipSend = "AT+CIPSEND="; //CRIA UMA VARIÁVEL PARA ENVIAR OS COMANDOS AO ESP-01
         
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     
     //ENVIA OS COMANDOS PARA O MODULO
     sendData(cipSend,1000,DEBUG);
     sendData(webpage,1000,DEBUG);
     
     //ENCERRA OS COMANDOS
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId;
     closeCommand+="\r\n";
     
     sendData(closeCommand,2000,DEBUG); //ENVIA OS COMANDOS DE ENCERRAMENTO
     
     delay(5000); //INTERVALO DE DE 5 SEGUNDOS
    }
  }
}

String sendData(String command, const int timeout, boolean debug){ //MÉTODO QUE ENVIA OS COMANDOS PARA O ESP-01

    String response = ""; //VARIÁVEL QUE ARMAZENA A RESPOSTA DO ESP-01
    
    esp8266.println(command); //IMPRIME OS COMANDOS DO ESP-01
    
    long int time = millis(); //VARIÁVEL DO TIPO long int
    
    while( (time+timeout) > millis()){
      while(esp8266.available()){
        
        char c = esp8266.read(); //CONCATENA CARACTERE POR CARACTERE RECEBIDO DO ESP-01
        response+=c;
      }  
    }
    if(debug){//DEBUG DE RESPOSTA DO ESP8266
      
      Serial.println("Arduino : " + response); //IMPRIME NA SERIAL OS DADOS QUE O ESP-01 ENVIOU PARA O ARDUINO
    }
    return response;
}

long getDecimal(float val){ //CONVERSÃO DE FLOAT EM STRING
  int intPart = int(val); //CONVERSÃO DE FLOAT EM INTEIRO
  
  //multiplica por 100
  //precisão de 2 casas decimais
  long decPart = 100*(val-intPart); //MULTIPLICA POR 100 COM PRECISÃO DE 2 CASAS DECIMAIS
  
  if(decPart>0) //SE decPart VALOR FOR MAIOR QUE 0, FAZ
  return(decPart);           
  
  //SENÃO, FAZ
  else if(decPart=0)
     return(00);           
}
