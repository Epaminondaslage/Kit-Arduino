#include <SPI.h>//INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS PARA FUNCIONAMENTO DO CÓDIGO
#include <Ethernet.h>//INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS PARA FUNCIONAMENTO DO CÓDIGO
 
const int pino_Canal1 = 2; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(VARIÁVEL CORRESPONDENTE AO PINO DIGITAL 2 DO ARDUINO)
const int pino_Canal2 = 3; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(VARIÁVEL CORRESPONDENTE AO PINO DIGITAL 3 DO ARDUINO)
const int pino_Canal3 = 4; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(VARIÁVEL CORRESPONDENTE AO PINO DIGITAL 4 DO ARDUINO)
const int pino_Canal4 = 5; //DECLARAÇÃO DE VARIÁVEL DO TIPO INTEIRA(VARIÁVEL CORRESPONDENTE AO PINO DIGITAL 5 DO ARDUINO)

boolean ligado = true; //DECLARAÇÃO DE VARIÁVEL DO TIPO BOOLEANA (CONTROLA O ESTADO ATUAL DO CANAL 1 DO MÓDULO RELÉ)
boolean ligado_2 = true; //DECLARAÇÃO DE VARIÁVEL DO TIPO BOOLEANA (CONTROLA O ESTADO ATUAL DO CANAL 2 DO MÓDULO RELÉ)
boolean ligado_3 = true; //DECLARAÇÃO DE VARIÁVEL DO TIPO BOOLEANA (CONTROLA O ESTADO ATUAL DO CANAL 3 DO MÓDULO RELÉ)
boolean ligado_4 = true; //DECLARAÇÃO DE VARIÁVEL DO TIPO BOOLEANA (CONTROLA O ESTADO ATUAL DO CANAL 4 DO MÓDULO RELÉ)

String readString; //VARIÁVEL PARA BUSCAR DADOS NO ENDEREÇO(URL)

byte mac[] = { 0xA4, 0x28, 0x72, 0xCA, 0x55, 0x2F }; //ATRIBUIÇÃO DE ENDEREÇO MAC AO W5100
byte ip[] = { 192, 168, 0, 175 }; //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110  **** ISSO VARIA, NO MEU CASO É: 192.168.0.175
byte gateway[] = { 192, 168, 0, 1 }; //MUDE PARA O GATEWAY PADRÃO DO SEU ROTEADOR **** NO MEU CASO É O 192.168.0.1
byte subnet[] = { 255, 255, 255, 0 }; //NÃO PRECISA MEXER (MASCARA DE REDE)
 
EthernetServer server(80); //CASO OCORRA PROBLEMAS COM A PORTA 80, UTILIZE OUTRA (EX:8082,8089) E A CHAMADA DA URL FICARÁ IP:PORTA(EX: 192.168.0.15:8082)
void setup(){
  pinMode(pino_Canal1, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pino_Canal2, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pino_Canal3, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pino_Canal4, OUTPUT); //DEFINE O PINO COMO SAÍDA
  
  digitalWrite(pino_Canal1, HIGH); //INICIA O PINO COM SINAL ALTO
  digitalWrite(pino_Canal2, HIGH); //INICIA O PINO COM SINAL ALTO
  digitalWrite(pino_Canal3, HIGH); //INICIA O PINO COM SINAL ALTO
  digitalWrite(pino_Canal4, HIGH); //INICIA O PINO COM SINAL ALTO
  Ethernet.begin(mac, ip, gateway, subnet); //INICIALIZA A CONEXÃO ETHERNET
  server.begin(); //INICIA O SERVIDOR PARA RECEBER DADOS NA PORTA DEFINIDA EM "EthernetServer server(porta);"
}
void loop(){
  EthernetClient client = server.available(); //CRIA UMA VARIÁVEL CHAMADA client
  if (client){ //SE EXISTE CLIENTE
    while (client.connected()){ //ENQUANTO EXISTIR CLIENTE CONECTADO FAZ
      if (client.available()){ //SE O CLIENTE ESTÁ HABILITADO FAZ
        char c = client.read(); //LÊ CARACTER A CARACTER DA REQUISIÇÃO HTTP
        if (readString.length() < 100){ //SE O ARRAY FOR MENOR QUE 100
          readString += c; //"readstring" VAI RECEBER OS CARACTERES LIDO
        }
        if (c == '\n'){ //SE ENCONTRAR "\n" É O FINAL DO CABEÇALHO DA REQUISIÇÃO HTTP
          if (readString.indexOf("?ligLamp1") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
            digitalWrite(pino_Canal1, LOW); //ACIONA O PINO E ENERGIZA A SAÍDA DO RELÉ
            ligado = false; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A FALSO
          }else{ //SENÃO
            if (readString.indexOf("?desligLamp1") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
              digitalWrite(pino_Canal1, HIGH); //ACIONA O PINO E DESENERGIZA A SAÍDA DO RELÉ
              ligado = true; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A VERDADEIRO
            }
          }
          if (readString.indexOf("?ligLamp2") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
            digitalWrite(pino_Canal2, LOW); //ACIONA O PINO E ENERGIZA A SAÍDA DO RELÉ
            ligado_2 = false; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A FALSO
          }else{ //SENÃO
            if (readString.indexOf("?desligLamp2") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
              digitalWrite(pino_Canal2, HIGH); //ACIONA O PINO E DESENERGIZA A SAÍDA DO RELÉ
              ligado_2 = true; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A VERDADEIRO
            }
          }
          if (readString.indexOf("?ligLamp3") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
            digitalWrite(pino_Canal3, LOW); //ACIONA O PINO E ENERGIZA A SAÍDA DO RELÉ
            ligado_3 = false; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A FALSO
          }else{ //SENÃO
            if (readString.indexOf("?desligLamp3") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
              digitalWrite(pino_Canal3, HIGH); //ACIONA O PINO E DESENERGIZA A SAÍDA DO RELÉ
              ligado_3 = true; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A VERDADEIRO
            }
          }
          if (readString.indexOf("?ligLamp4") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
            digitalWrite(pino_Canal4, LOW); //ACIONA O PINO E ENERGIZA A SAÍDA DO RELÉ
            ligado_4 = false; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A FALSO
          }else{ //SENÃO
            if (readString.indexOf("?desligLamp4") > 0){ //SE ENCONTRAR O PARÂMETRO, FAZ
              digitalWrite(pino_Canal4, HIGH); //ACIONA O PINO E DESENERGIZA A SAÍDA DO RELÉ
              ligado_4 = true; //VARIÁVEL BOOLEANA RECEBE ESTADO IGUAL A VERDADEIRO
            }
          }
          readString = ""; //A VARIÁVEL É REINICIALIZADA
 
          client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
          client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
          client.println();
          client.println("<html>"); //INICIO DA PÁGINA HTML
          client.println("<head>"); //INICIO  DO CABEÇÁRIO
          client.println("<link rel='icon' type='image/png' href='http://masterwshop.com.br/cursoArduino/webLamp/logo.png'/>"); //DEFINIÇÃO DO ICONE DE TITULO DA PÁGINA
          client.println("<title>MASTERWALKER SHOP</title>"); //DEFINE O TITULO DA PÁGINA
          client.println("<meta http-equiv='Content-Type' content='text/html; charset=ISO-8859-1'>"); //DEFINE ALGUMAS CONFIGURAÇÕES DA PÁGINA
          client.println("<meta name='viewport' content='width=720, initial-scale=0.5' />"); //DEFINE ALGUMAS CONFIGURAÇÕES DA PÁGINA
          client.println("<link rel='stylesheet' type='text/css' href='http://masterwshop.com.br/cursoArduino/webLamp/css_file.css' />"); //REFERENCIA O ARQUIVO CSS (FOLHAS DE ESTILO)
          client.println("<script type='text/javascript' src='http://masterwshop.com.br/cursoArduino/webLamp/javascript_file.js'></script>"); //REFERENCIA O ARQUIVO JAVASCRIPT
          client.println("</head>"); //FINALIZA O CABEÇÁRIO
          client.println("<body>"); //INICIO DA TAG BODY
          client.println("<div id='wrapper'><img alt='MSHOP' src='http://masterwshop.com.br/cursoArduino/webLamp/logo.png'/><br/>"); //DIV CONTENDO O LOGO DA MASTERWALKER SHOP
          client.println("<div id='div1'>Lampada 1</div>"); //DIV REFERENTE A LÂMPADA 1
          client.println("<div id='div2'>Lampada 2</div>"); //DIV REFERENTE A LÂMPADA 2
          client.println("<div id='div3'>Lampada 3</div>"); //DIV REFERENTE A LÂMPADA 3
          client.println("<div id='div4'>Lampada 4</div>"); //DIV REFERENTE A LÂMPADA 4
          client.print("<div id='rele'></div><div id='estado' style='visibility: hidden;'>"); //ABERTURA DE DIV
          client.print(ligado); //RETORNA PARA O CLIENTE O ESTADO DO CANAL 1 DO MÓDULO RELÉ
          client.println("</div>"); //FECHAMENTO DE DIV
          client.println("<div id='botao'></div>"); //DIV REFERENTE AO BOTÃO 1
          client.println("<div id='botao_2'></div>"); //DIV REFERENTE AO BOTÃO 2
          client.println("<div id='botao_3'></div>"); //DIV REFERENTE AO BOTÃO 3
          client.println("<div id='botao_4'></div>"); //DIV REFERENTE AO BOTÃO 4
          client.print("<div id='rele_2'></div><div id='estado_2' style='visibility: hidden;'>"); //ABERTURA DE DIV
          client.print(ligado_2); //RETORNA PARA O CLIENTE O ESTADO DO CANAL 2 DO MÓDULO RELÉ
          client.println("</div>"); //FECHAMENTO DE DIV
          client.print("<div id='rele_3'></div><div id='estado_3' style='visibility: hidden;'>"); //ABERTURA DE DIV
          client.print(ligado_3); //RETORNA PARA O CLIENTE O ESTADO DO CANAL 3 DO MÓDULO RELÉ
          client.println("</div>"); //FECHAMENTO DE DIV
          client.print("<div id='rele_4'></div><div id='estado_4' style='visibility: hidden;'>"); //ABERTURA DE DIV
          client.print(ligado_4); //RETORNA PARA O CLIENTE O ESTADO DO CANAL 4 DO MÓDULO RELÉ
          client.println("</div>"); //FECHAMENTO DE DIV
          client.println("</div>"); //FECHAMENTO DE DIV
          client.println("<script>AlteraRele1()</script>"); //CHAMA A FUNÇÃO QUE ESTÁ CONTIDA NO ARQUIVO DE JAVASCRIPT
          client.println("<script>AlteraRele2()</script>"); //CHAMA A FUNÇÃO QUE ESTÁ CONTIDA NO ARQUIVO DE JAVASCRIPT
          client.println("<script>AlteraRele3()</script>"); //CHAMA A FUNÇÃO QUE ESTÁ CONTIDA NO ARQUIVO DE JAVASCRIPT
          client.println("<script>AlteraRele4()</script>"); //CHAMA A FUNÇÃO QUE ESTÁ CONTIDA NO ARQUIVO DE JAVASCRIPT
          client.println("</div>"); //FECHAMENTO DE DIV
          client.println("</body>"); //FINALIZA A TAG "body"
          client.println("</html>"); //FINALIZA A TAG "html"
          delay(1); //INTERVALO DE 1 MILISEGUNDO
          client.stop(); //FINALIZA A REQUISIÇÃO HTTP
        }
      }
    }
  }
}
