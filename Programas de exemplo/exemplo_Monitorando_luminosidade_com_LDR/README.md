# Controle de Lâmpada com LDR no Arduino UNO

## Descrição do Projeto
Este projeto utiliza um Arduino UNO e um sensor LDR (Light Dependent Resistor) para controlar automaticamente uma lâmpada com base na luminosidade do ambiente. A lâmpada é conectada ao pino digital 8 do Arduino. O LDR é conectado ao pino analógico A0.

## Funcionamento
O código funciona da seguinte forma:

1. No **`setup`**, o pino digital 8 é configurado como saída para controlar a lâmpada, e a comunicação serial é inicializada com uma taxa de 19200 bps.
2. No **`loop`**, o código realiza 50 leituras consecutivas do valor analógico fornecido pelo LDR. Esses valores são somados e, em seguida, a média é calculada dividindo o valor total por 50.
3. Com a média calculada, o valor é comparado com o limiar de 400:
   - Se o valor médio lido for maior ou igual a 400, a lâmpada é ligada.
   - Se o valor médio for menor que 400, a lâmpada é desligada.
4. O valor médio lido pelo LDR é exibido no monitor serial, permitindo o acompanhamento do funcionamento em tempo real.

## Pinos Utilizados
- **LAMP**: Pino 8 - Conectado à lâmpada (saída).
- **LDR**: Pino A0 - Conectado ao sensor LDR (entrada).

## Considerações
- O valor de 400 como limiar para ligar ou desligar a lâmpada pode ser ajustado de acordo com a sensibilidade desejada ou as condições de iluminação do ambiente.
- A taxa de comunicação serial é definida como 19200 bps, mas pode ser ajustada conforme necessário.

