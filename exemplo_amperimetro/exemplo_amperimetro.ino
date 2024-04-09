const int scAnalog = A0; //PORTA ANALÓGICA(A0) UTILIZADA PELO SENSOR DE CORRENTE
float sensorValue_aux = 0; //VARIÁVEL DO TIPO FLOAT
float sensorValue = 0; //VARIÁVEL DO TIPO FLOAT
float currentValue = 0; //VARIÁVEL DO TIPO FLOAT
float voltsporUnidade = 0.0048828125; //VARIÁVEL RECEBE 5/1023 = 0.0048828125
int tensaoRede = 127; //VARIÁVEL RECEBE O VALOR DA REDE AC(127V OU 220V)
float potenciaAprox = 0; //VARIÁVEL RECEBE O VALOR DA POTÊNCIA CALCULADA
 
void setup(){
 
Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}
 
void loop(){

 currentValue = 0; //REINICIA O VALOR ATUAL E ATUALIZA NA PRÓXIMA LEITURA
 sensorValue = 0; //REINICIA O VALOR ATUAL E ATUALIZA NA PRÓXIMA LEITURA
 
 for(int i=500; i>0; i--){
 sensorValue_aux = (analogRead(scAnalog) -510); //LÊ O PINO ANALOGICO A0 E AJUSTA O VALOR LIDO, VISTO QUE A SAÍDA DO SENSOR É VCC/2 PARA CORRENTE IGUAL A 0
 sensorValue += pow(sensorValue_aux,2); //SOMA OS QUADARDOS DAS LEITURAS NO LAÇO
 }
 sensorValue = (sqrt(sensorValue/ 500)) * voltsporUnidade; //FINALIZA O CALCULO DA MÉDIA QUADRÁTICA E AJUSTA O VALOR LIDO PARA VOLTS
 currentValue = (sensorValue/0.066); //CALCULA A CORRENTE CONSIDERANDO A SENSIBILIDADE DO SENSOR (66 MV POR AMPÉRE)

 //-->TRATAMENTO PARA OCORRÊNCIA DE RUÍDO<--
 //O ACS71230A É PROJETADO PARA FAZER LEITURA
 //DE VALORES DE CORRENTE ACIMA DE 0.250A ATÉ 30A
 //PORTANTO É NORMAL OCORRER RUÍDOS DE ATÉ 0.200A
 if(currentValue <= 0.200){
    currentValue = 0;
 }
 potenciaAprox = tensaoRede * currentValue; //FÓRUMLA DE CÁLCULO DA POTÊNCIA
 
 //MOSTRA AS INFORMAÇÕES NA JANELA SERIAL
 Serial.print("Corrente medida: " );
 Serial.print(currentValue, 3);
 Serial.print("A / ");
 Serial.print("Potencia (Consumo): " );
 Serial.print(potenciaAprox, 3);
 Serial.println("W");
 delay(150); //INTERVALO DE 150 MILISEGUNDOS
}
