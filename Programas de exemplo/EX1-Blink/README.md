# Exemplo Blink (Piscar) com Arduino

Este projeto demonstra o exemplo básico de piscar o LED embutido na placa Arduino. O código faz o LED piscar continuamente em intervalos de um segundo.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino com um LED embutido)
- Cabo USB para programação e alimentação

## Como Funciona

O código utiliza o pino `LED_BUILTIN`, que está conectado ao LED embutido na maioria das placas Arduino. No `setup()`, o pino é configurado como saída. No `loop()`, o LED é aceso (`HIGH`), a execução é pausada por um segundo, o LED é apagado (`LOW`), e a execução é novamente pausada por um segundo. Esse ciclo se repete indefinidamente.

### Explicação do Código

- **Função `setup()`**: Executada uma vez no início, configura o pino `LED_BUILTIN` como uma saída.
- **Função `loop()`**: Executada repetidamente, controla o ciclo de acender e apagar o LED com um intervalo de um segundo entre cada ação.

## Personalização

- **Intervalo de Piscar**: O tempo que o LED permanece aceso ou apagado pode ser ajustado modificando o valor de `delay(1000)` no `loop()`.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Após carregar o código, o LED embutido na placa começará a piscar em intervalos de um segundo.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
