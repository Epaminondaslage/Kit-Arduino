# Controle de LEDs e Buzzer com Botões no Arduino

Este projeto demonstra como controlar três LEDs e um buzzer utilizando três botões conectados a um Arduino. Quando um botão é pressionado, o LED correspondente acende e o buzzer toca uma nota específica.

## Componentes Necessários

- Arduino UNO (ou qualquer outra placa Arduino)
- 3 LEDs
- 3 Resistores (220Ω a 1kΩ) para os LEDs
- 3 Botões
- 3 Resistores (10kΩ) para os botões (caso não utilize o pull-up interno)
- 1 Buzzer
- Jumpers e Protoboard

## Como Funciona

O código utiliza três botões conectados aos pinos 2, 3 e 4 para acionar três LEDs conectados aos pinos 11, 12 e 13, respectivamente. Quando um botão é pressionado, o LED correspondente acende e uma nota musical (C4, E4, G4) é tocada pelo buzzer conectado ao pino 9. O buzzer e o LED permanecem ativos enquanto o botão estiver pressionado.

### Explicação do Código

- **Função `setup()`**: Configura os pinos dos LEDs como saídas e os pinos dos botões como entradas com pull-up interno. Também configura o pino do buzzer como saída.
- **Função `loop()`**: Verifica continuamente o estado dos botões. Quando um botão é pressionado, o LED correspondente acende e o buzzer toca a nota associada. Quando o botão é solto, o LED apaga e o som do buzzer para.

## Personalização

- **Notas Musicais**: As notas tocadas pelo buzzer podem ser alteradas modificando os valores no array `notes[]`.
- **Pinos de Conexão**: Os pinos dos LEDs, botões e buzzer podem ser alterados conforme necessário.

## Como Carregar o Código

1. Abra a IDE do Arduino.
2. Copie e cole o código no editor.
3. Selecione a placa "Arduino UNO" (ou a placa que você estiver utilizando) e a porta correta.
4. Carregue o código na placa Arduino.

## Uso

1. Conecte os LEDs, botões e o buzzer ao Arduino conforme as instruções.
2. Após carregar o código, pressione os botões para acionar os LEDs e tocar as notas correspondentes no buzzer.

## Licença

Este projeto é de código aberto e está licenciado sob a [MIT License](LICENSE).

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou relatar problemas na página de issues.

## Créditos

Projeto elaborado/adaptado por Epaminondas Lage.
