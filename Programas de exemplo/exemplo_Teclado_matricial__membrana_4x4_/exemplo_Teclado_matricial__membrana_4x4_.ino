/**************************************************************************
 *                 Placa de desenvolvimento Arduino Uno                   *
 *                           Teclado Matricial 4x4                        *
 * Fonte: http://blogmasterwalkershop.com.br/                             *
 * Adaptação : Epaminondas Souza Lage                                     *
 **************************************************************************/

#include <Password.h> // Inclui a biblioteca para manipulação de senhas

Password password = Password("1234"); // Define a senha correta como "1234"

byte currentLength = 0; // Variável que armazena o tamanho atual da entrada

void setup(){
  Serial.begin(9600); // Inicializa a comunicação serial
  Serial.println("Tente adivinhar a senha!"); // Exibe a mensagem de boas-vindas
  Serial.println("Resete com ! e avalie com ?"); // Instruções para resetar ou verificar a senha
  Serial.print("Digite a senha: "); // Solicita a entrada da senha
}

void loop(){
  if (Serial.available()){ // Verifica se há dados disponíveis na serial
    char input = Serial.read(); // Lê o caractere digitado
    switch (input){
      case '!': // Reseta a senha digitada
        password.reset(); // Reseta o estado atual da senha
        currentLength = 0; // Reseta o comprimento da entrada
        Serial.println("\tSenha foi resetada!"); // Notifica que a senha foi resetada
      break;
      
      case '?': // Avalia a senha digitada
        if (password.evaluate()){ // Verifica se a senha digitada é a correta
          Serial.println("\tVocê acertou a senha!"); // Notifica sucesso
        } else {
          Serial.println("\tVocê não acertou a senha!"); // Notifica falha
        }
      break;
      
      default: // Adiciona o caractere digitado à senha, caso não seja '!' nem '?'
        password.append(input); // Adiciona o caractere à senha atual
        currentLength++; // Incrementa o comprimento da entrada
        
        // Exibe feedback visual com asteriscos para cada caractere digitado
        Serial.print("Digite a senha: ");
        for (byte i = 0; i < currentLength; i++){
          Serial.print('*'); // Exibe um asterisco para cada caractere
        }
        Serial.println(); // Quebra de linha para a próxima entrada
    }
  }
}
