#include <SPI.h> //INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS PARA FUNCIONAMENTO DO CÓDIGO
#include <Ethernet.h> //INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS PARA FUNCIONAMENTO DO CÓDIGO

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //ATRIBUIÇÃO DE ENDEREÇO MAC AO W5100
byte ip[] = { 192, 168, 0, 175 }; //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110  **** ISSO VARIA, NO MEU CASO É: 192.168.0.175
EthernetServer server(80); //CASO OCORRA PROBLEMAS COM A PORTA 80, UTILIZE OUTRA (EX:8082,8089) E A CHAMADA DA URL FICARÁ IP:PORTA(EX: 192.168.0.15:8082)

int ledPin = 5; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(VARIÁVEL CORRESPONDENTE AO PINO DIGITAL 5 DO ARDUINO)
String readString = String(30); //VARIÁVEL PARA BUSCAR DADOS NO ENDEREÇO(URL)
int status = 0; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(SERÁ RESPONSÁVEL POR VERIFICAR O STATUS ATUAL DO LED)

void setup(){
  Ethernet.begin(mac, ip); //INICIA O ETHERNET ENC28J60
  server.begin(); //INICIA O SERVIDOR PARA RECEBER DADOS NA PORTA DEFINIDA EM "EthernetServer server(porta);"
  pinMode(ledPin, OUTPUT); //DEFINE QUE A VARIÁVEL SERÁ UMA SAÍDA
  }
void loop(){
EthernetClient client = server.available(); //CRIA UMA CONEXÃO COM O CLIENTE
  if (client) { // SE EXISTE CLIENTE FAZ
    while (client.connected()) {//ENQUANTO EXISTIR CLIENTE CONECTADO FAZ
   if (client.available()) { //SE O CLIENTE ESTÁ HABILITADO FAZ
    char c = client.read(); //LÊ CARACTER A CARACTER DA REQUISIÇÃO HTTP
    if (readString.length() < 100) //SE O ARRAY FOR MENOR QUE 100
      {
        readString += c; // "readstring" VAI RECEBER OS CARACTERES LIDO
      }  
        if (c == '\n') { //SE ENCONTRAR "\n" É O FINAL DO CABEÇALHO DA REQUISIÇÃO HTTP
          if (readString.indexOf("?") <0){ //SE ENCONTRAR O CARACTER "?"
          }
          else //SENÃO
        if(readString.indexOf("ledParam=1") >0) //SE ENCONTRAR O PARÂMETRO "ledParam=1"
           {
             digitalWrite(ledPin, HIGH); //ENERGIZA A PORTA "ledPin" E O LED ACENDE
             status = 1; //VARIÁVEL RECEBE VALOR 1(SIGNIFICA QUE O LED ESTÁ ACESO)
           }else{ //SENÃO
             digitalWrite(ledPin, LOW); //DESENERGIZA A PORTA "ledPin" E O LED APAGA
             status = 0; //VARIÁVEL RECEBE VALOR 0(SIGNIFICA QUE O LED ESTÁ APAGADO)             
           }
          client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
          client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
          client.println();
          //AS LINHAS ABAIXO CRIAM A PÁGINA HTML
          client.println("<body style=background-color:#ADD8E6>"); //DEFINE A COR DE FUNDO DA PÁGINA
          client.println("<center><font color='blue'><h1>MASTERWALKER SHOP</font></center></h1>"); //ESCREVE "MASTERWALKER SHOP" NA PÁGINA
          client.println("<h1><center>CONTROLE DE LED</center></h1>"); //ESCREVE "CONTROLE DE LED" NA PÁGINA
          if (status == 1){ //SE VARIÁVEL FOR IGUAL A 1 FAZ
          //A LINHA ABAIXO CRIA UM FORMULÁRIO CONTENDO UMA ENTRADA INVISÍVEL(hidden) COM O PARÂMETRO DA URL E CRIA UM BOTÃO(APAGAR SE O LED ETSIVER ACESO).
          client.println("<center><form method=get name=LED><input type=hidden name=ledParam value=0 /><input type=submit value=APAGAR></form></center>");
          }else{ //SENÃO
          //A LINHA ABAIXO CRIA UM FORMULÁRIO CONTENDO UMA ENTRADA INVISÍVEL(hidden) COM O PARÂMETRO DA URL E CRIA UM BOTÃO(ACENDER SE O LED ETSIVER APAGADO).
          client.println("<center><form method=get name=LED><input type=hidden name=ledParam value=1 /><input type=submit value=ACENDER></form></center>");
          }    
          client.println("<hr />"); //TAG HTML QUE CRIA UMA LINHA NA PÁGINA
          client.println("<hr />"); //TAG HTML QUE CRIA UMA LINHA NA PÁGINA
          client.println("</body></html>"); //FINALIZA A TAG "body" E TAG "html"
          readString=""; //A VARIÁVEL É REINICIALIZADA
          client.stop(); //FINALIZA A REQUISIÇÃO HTTP
            }
          }
        }
      }
 }
