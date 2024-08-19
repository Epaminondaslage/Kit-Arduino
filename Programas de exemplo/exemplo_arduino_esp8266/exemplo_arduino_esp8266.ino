/**************************************************************************
 *          Servidor Web com ESP8266 e Leitura de Pino Analógico          *
 *                Elaborado/Adptado por Epaminondas Lage                  *
 *                                                                        *
 * Este código utiliza um módulo ESP8266 para criar um servidor web que   *
 * exibe a leitura do pino analógico A1 em uma página web. O servidor é   *
 * acessível através de um navegador web, e a página é atualizada         *
 * automaticamente a cada 5 segundos.                                     *
 **************************************************************************/

#include <SoftwareSerial.h> // Inclusão da biblioteca para comunicação serial via software

#define DEBUG true // Define uma constante para habilitar o modo de depuração

// O TX do ESP-01 deve ser ligado no pino 2 (RX) do Arduino
// O RX do ESP-01 deve ser ligado no pino 3 (TX) do Arduino

SoftwareSerial esp8266(2, 3); // Cria um objeto do tipo SoftwareSerial (pino 2 = RX / pino 3 = TX)

String leituraAnalog1 = ""; // Variável do tipo String para armazenar a leitura analógica

void setup(){
  delay(500); // Aguarda 500 milissegundos para inicialização
  Serial.begin(9600); // Inicializa a comunicação serial do Arduino
  esp8266.begin(9600); // Inicializa a comunicação serial com o ESP-01
  
  sendData("AT+RST\r\n", 2000, DEBUG); // Reinicia o ESP-01
  sendData("AT+CWMODE=3\r\n", 1000, DEBUG); // Configura o ESP-01 no modo de operação 3 (AP + STA)
  sendData("AT+CWJAP=\"OliveiraRocha\",\"2015ano2015\"\r\n", 10000, DEBUG); // Conecta à rede Wi-Fi com SSID e senha especificados
  sendData("AT+CIFSR\r\n", 1000, DEBUG); // Retorna o IP alocado ao ESP-01 (modo STA)
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG); // Habilita múltiplas conexões
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); // Inicia um servidor na porta 80
}

void loop(){
  leituraAnalog1 = ""; // Limpa o valor da variável leituraAnalog1
  
  if(esp8266.available()){ // Verifica se o ESP8266 está enviando dados
    
    if(esp8266.find("+IPD,")){ // Verifica se há dados recebidos pelo ESP8266
    
      leituraAnalog1 = String(analogRead(1)); // Lê o valor analógico do pino A1 e converte para String
     
      int connectionId = esp8266.read() - 48; // Lê o ID da conexão, ajustando o valor ASCII para decimal
     
      // Cria a página web que será exibida quando o servidor receber uma requisição
      String webpage = "<head><meta http-equiv=\"refresh\" content=\"5\"></head>";
      webpage += "<body style=background-color:#ADD8E6>";
      webpage += "<center><h1>CEFET-MG</h1><h2> ESP8266</h2><h3>";
      webpage += "Leitura no pino analógico A1: ";
      webpage += leituraAnalog1 + " </h3></center>";
      
      String cipSend = "AT+CIPSEND="; // Cria a string para enviar os comandos ao ESP-01
         
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";
     
      // Envia os comandos para o módulo ESP-01
      sendData(cipSend, 1000, DEBUG);
      sendData(webpage, 1000, DEBUG);
     
      // Encerra a conexão
      String closeCommand = "AT+CIPCLOSE="; 
      closeCommand += connectionId;
      closeCommand += "\r\n";
     
      sendData(closeCommand, 2000, DEBUG); // Envia o comando para fechar a conexão
     
      delay(5000); // Aguarda 5 segundos antes de processar a próxima requisição
    }
  }
}

String sendData(String command, const int timeout, boolean debug){ // Método que envia comandos ao ESP-01

    String response = ""; // Variável que armazena a resposta do ESP-01
    
    esp8266.println(command); // Envia o comando para o ESP-01
    
    long int time = millis(); // Armazena o tempo atual
    
    while((time + timeout) > millis()){ // Aguarda até que o tempo limite seja atingido
      while(esp8266.available()){
        char c = esp8266.read(); // Lê caractere por caractere da resposta do ESP-01
        response += c; // Armazena a resposta completa
      }  
    }
    
    if(debug){ // Se o modo de depuração estiver ativado
      Serial.println("Arduino: " + response); // Exibe a resposta do ESP-01 no monitor serial
    }
    
    return response; // Retorna a resposta obtida
}

long getDecimal(float val){ // Função que converte um valor float para decimal
  int intPart = int(val); // Converte a parte inteira do valor
  
  long decPart = 100 * (val - intPart); // Calcula a parte decimal com precisão de 2 casas decimais
  
  if(decPart > 0) // Se a parte decimal for maior que 0
    return decPart; // Retorna a parte decimal
  
  return 00; // Se não, retorna 0
}
