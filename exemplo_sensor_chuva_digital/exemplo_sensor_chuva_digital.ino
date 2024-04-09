/*
Nesse código a função setup( ) ativa a porta serial em 9600 bits/s e a função loop( ) fica transmitin- do a frase ‘Hello World!’ pela porta serial a cada 2 segundos.
*/
void setup( ) {
Serial.begin(9600);
} 
void loop( )  {
Serial.println(“ Hello World! “);
delay(2000);
}
