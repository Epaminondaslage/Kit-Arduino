#include <VirtualWire.h> //INCLUSÃO DE BIBLIOTECA

const int ledPin = 13; //PINO DIGITAL 13 (LED DO PINO 13)
const int pino_botao = A0; //PINO ANALÓGICO UTILIZADO PELO PUSH BUTTON

int valor_botao; //VARIÁVEL DO TIPO INTEIRA 
char Valor_CharMsg[4]; //VARIÁVEL DO TIPO CHAR 
int estado = 0; //VARIÁVEL DE CONTROLE DO ESTADO DO LED

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  pinMode(ledPin,OUTPUT); //DECLARA O PINO COMO SAÍDA
  pinMode(pino_botao,INPUT); //DECLARA O PINO COMO ENTRADA
  vw_set_tx_pin(4); //PINO LIGADO AO PINO DATA DO TRANSMISSOR RF
  vw_setup(5000); //VELOCIDADE DE COMUNICAÇÃO (BITS/SEGUNDOS)
  Serial.println("TRANSMISSAO DE MODULO RF - PRESSIONE O BOTÃO..."); //ESCREVE O TEXTO NA SERIAL
}
void loop(){
  valor_botao = digitalRead(pino_botao); //VERIFICA O ESTADO DO PUSH BUTTON (PRESSIONADO / NÃO PRESSIONADO)
  if (valor_botao == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
    estado = !estado; //ALTERA O ESTADO DO LED (LIGADO / DESLIGADO)
    itoa(estado,Valor_CharMsg,10); //FAZ A CONVERSÃO DO VALOR PARA SER ENVIADO
    digitalWrite(13, true); //LIGA O LED DO PINO 13 QUE INDICA O ENVIO DE DADOS
    vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg)); //EFETUA O ENVIO DOS DADOS
    vw_wait_tx(); //AGUARDA O ENVIO DOS DADOS
    digitalWrite(13, false); //DESLIGA O LED DO PINO 13 E ENCERRA A TRANSMISSÃO
    Serial.print("Valor enviado: "); //ESCREVE TEXTO NA SERIAL
    Serial.println(Valor_CharMsg); //ESCREVE O VALOR NA SERIAL
    delay(500); //INTERVALO DE 500 MILISEGUNDOS
  }
}
