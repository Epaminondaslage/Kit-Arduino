# Verificação de Senha com Teclado Matricial 4x4 - Arduino UNO (Mensagens em Português)

## Descrição do Projeto

Este projeto utiliza um teclado matricial 4x4 conectado a um Arduino UNO para permitir a entrada de uma senha. O código compara a senha digitada com uma senha pré-definida ("1234") e fornece feedback ao usuário através do monitor serial. As mensagens do programa estão traduzidas para português.

## Funcionamento do Código

### Declaração e Inicialização

- **`#include <Password.h>`**: Inclui a biblioteca `Password` para manipulação de senhas.
- **`Password password = Password("1234");`**: Define a senha correta como "1234".
- **`byte currentLength = 0;`**: Variável que armazena o tamanho atual da entrada da senha.

### Função `setup()`

1. **Inicialização da Comunicação Serial**:
   - **`Serial.begin(9600);`**: Inicializa a comunicação serial com o computador a uma velocidade de 9600 bps.
   - **`Serial.println("Tente adivinhar a senha!");`**: Exibe uma mensagem de boas-vindas no monitor serial.
   - **`Serial.println("Resete com ! e avalie com ?");`**: Instruções para resetar ou avaliar a senha.
   - **`Serial.print("Digite a senha: ");`**: Solicita ao usuário a entrada da senha.

### Função `loop()`

A função `loop()` é responsável por capturar e avaliar as entradas do usuário através do teclado matricial, fornecendo feedback visual no monitor serial.

1. **Leitura de Dados da Serial**:
   - **`if (Serial.available()){ char input = Serial.read(); }`**: Verifica se há dados disponíveis na porta serial e armazena o caractere digitado.

2. **Avaliação da Entrada**:
   - **`case '!':`**: Reseta a senha digitada:
     - **`password.reset();`**: Reseta o estado atual da senha.
     - **`currentLength = 0;`**: Reseta o comprimento da entrada.
     - **`Serial.println("\tSenha foi resetada!");`**: Notifica o usuário de que a senha foi resetada.
     
   - **`case '?':`**: Avalia a senha digitada:
     - **`if (password.evaluate()){ ... } else { ... }`**: Compara a senha digitada com a senha correta.
     - **`Serial.println("\tVocê acertou a senha!");`**: Notifica sucesso se a senha estiver correta.
     - **`Serial.println("\tVocê não acertou a senha!");`**: Notifica falha se a senha estiver incorreta.

   - **`default:`**: Adiciona o caractere digitado à senha:
     - **`password.append(input);`**: Adiciona o caractere à senha atual.
     - **`currentLength++;`**: Incrementa o comprimento da entrada.
     - **`Serial.print("Digite a senha: ");`**: Solicita nova entrada de senha.
     - **`for (byte i = 0; i < currentLength; i++){ Serial.print('*'); }`**: Exibe asteriscos para cada caractere digitado, mantendo a senha oculta.
     - **`Serial.println();`**: Quebra de linha para a próxima entrada.

## Conclusão

Este código permite ao usuário digitar uma senha através de um teclado matricial 4x4 conectado ao Arduino UNO e verificar se a senha está correta.
