#include <SoftwareSerial.h>  

SoftwareSerial mySerial(6, 7); //PINOS DIGITAIS UTILIZADOS POR RX e TX  
String command = ""; //VARIÁVEL DO TIPO STRING
   
void setup(){  

  Serial.begin(115200); //INICIALIZA A SERIAL (VEJA QUE AQUI O BAUND ESTÁ EM 115200, LEMBRE-SE DE ALTERAR NO MONITOR SERIAL)
  Serial.println("Digite os comandos AT: ");  //ESCREVE O TEXTO NA SERIAL 
  mySerial.begin(9600);  //INICIALIZA A "mySerial"
}  
void loop(){  
 
  if (mySerial.available()){  //SE SERIAL HABILITADA, FAZ
     while(mySerial.available()){ //ENQUANTO A SERIAL ESTIVER HABILITADA, FAZ  
       command += (char)mySerial.read();  //FAZ A LEITURA DOS COMANDOS ENVIADOS VIA SERIAL
     }  
   Serial.println(command);  //ESCREVE O COMANDO NA SERIAL
   command = ""; //ELIMINA REPETIÇÕES
  } 
  if (Serial.available()){ //SE SERIAL HABILITADA, FAZ
    delay(10); //INTERVALO DE 10 MILISEGUNDOS 
    mySerial.write(Serial.read()); //FAZ A LEITURA DOS COMANDOS ENVIADOS VIA SERIAL
  }  
}
