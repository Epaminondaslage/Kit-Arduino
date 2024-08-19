# Medição de Corrente e Potência com Sensor ACS712 - Arduino UNO

## Descrição do Projeto

Este projeto utiliza o sensor de corrente ACS712 para medir a corrente consumida por um dispositivo e calcular a potência aproximada com base na tensão da rede elétrica. Os valores são exibidos em tempo real no monitor serial do Arduino UNO.

## Descrição do Sensor ACS712

O **ACS712** é um sensor de corrente baseado no efeito Hall que pode medir correntes AC e DC. Ele está disponível em diferentes versões para medir até 5A, 20A, ou 30A, dependendo do modelo. O sensor gera uma saída analógica proporcional à corrente que está sendo medida. Para correntes positivas, a saída do sensor aumenta acima da tensão de referência (tipicamente 2,5V), e para correntes negativas, a saída diminui abaixo desta referência. Ele é comumente utilizado em projetos de eletrônica para monitoramento de corrente, proteção contra sobrecorrente, e para medir o consumo de energia em circuitos.

### Características principais do ACS712:
- **Faixa de medição**: Disponível em versões de 5A, 20A, e 30A.
- **Saída**: Sinal analógico proporcional à corrente medida.
- **Precisão**: Alta precisão devido à tecnologia de efeito Hall.
- **Isolamento**: Oferece isolamento galvânico entre o circuito de medição e o sistema de controle.

## Conexões do Sensor ACS712 ao Arduino

Para conectar o sensor ACS712 ao Arduino, siga estas instruções:

- **VCC**: Conecte ao pino **5V** do Arduino.
- **GND**: Conecte ao pino **GND** do Arduino.
- **OUT**: Conecte ao pino analógico **A0** do Arduino (conforme o código).
- **IP+ e IP-**: Estes pinos são para a corrente que você deseja medir. Conecte o dispositivo cuja corrente você quer medir entre esses dois pinos.

## Funcionamento do Código

### Declaração e Inicialização

- **`const int scAnalog = A0;`**: Define a porta analógica A0 como a entrada para o sensor de corrente.
- **`float sensorValue_aux = 0;`**: Variável auxiliar para armazenar leituras temporárias do sensor.
- **`float sensorValue = 0;`**: Armazena a média das leituras do sensor.
- **`float currentValue = 0;`**: Armazena o valor da corrente calculada em amperes.
- **`float voltsporUnidade = 0.0048828125;`**: Fator de conversão de volts por unidade (5V/1023).
- **`int tensaoRede = 127;`**: Define a tensão da rede elétrica (pode ser 127V ou 220V).
- **`float potenciaAprox = 0;`**: Armazena o valor da potência aproximada em watts.

### Função `setup()`

- **`Serial.begin(9600);`**: Inicializa a comunicação serial para exibir os dados no monitor serial.

### Função `loop()`

A função `loop()` realiza a medição da corrente e o cálculo da potência, exibindo os resultados no monitor serial a cada 150 milissegundos.

1. **Inicialização das Variáveis**:
   - **`currentValue = 0;`**: Reinicia o valor da corrente.
   - **`sensorValue = 0;`**: Reinicia o valor da leitura do sensor.

2. **Leitura e Processamento dos Dados**:
   - **`for(int i = 500; i > 0; i--){ ... }`**: Realiza 500 leituras do sensor para maior precisão.
   - **`sensorValue_aux = (analogRead(scAnalog) - 510);`**: Lê o valor analógico e ajusta para corrente zero.
   - **`sensorValue += pow(sensorValue_aux, 2);`**: Soma os quadrados das leituras para cálculo da média quadrática.
   - **`sensorValue = (sqrt(sensorValue / 500)) * voltsporUnidade;`**: Calcula o valor médio quadrático e converte para volts.
   - **`currentValue = (sensorValue / 0.066);`**: Converte o valor para corrente em amperes, com base na sensibilidade do sensor (66 mV/A).

3. **Tratamento de Ruído**:
   - **`if(currentValue <= 0.200){ currentValue = 0; }`**: Ignora valores de corrente abaixo de 0,200A, que são considerados ruídos.

4. **Cálculo da Potência**:
   - **`potenciaAprox = tensaoRede * currentValue;`**: Calcula a potência em watts com base na tensão da rede e na corrente medida.

5. **Exibição dos Resultados**:
   - **`Serial.print("Corrente medida: ");`**: Exibe a corrente medida no monitor serial.
   - **`Serial.print(currentValue, 3);`**: Exibe o valor da corrente com três casas decimais.
   - **`Serial.print("A / Potencia (Consumo): ");`**: Exibe o texto "Potencia (Consumo): ".
   - **`Serial.print(potenciaAprox, 3);`**: Exibe o valor da potência calculada com três casas decimais.
   - **`Serial.println("W");`**: Adiciona a unidade "W" e quebra de linha.

6. **Delay**:
   - **`delay(150);`**: Aguarda 150 milissegundos antes de realizar uma nova leitura.

## Conclusão

Este projeto oferece uma solução prática para medir corrente e calcular a potência elétrica utilizando o sensor ACS712 e o Arduino UNO. A integração com o monitor serial permite que esses valores sejam exibidos em tempo real, proporcionando uma ferramenta eficaz para monitorar o consumo de energia em diversos dispositivos. 

A precisão do sensor ACS712, combinada com a capacidade do Arduino de processar e exibir dados, torna este projeto ideal para aplicações que exigem monitoramento de corrente e potência, como sistemas de automação residencial, gerenciamento de energia, e estudos de eficiência energética.

Além disso, o código é modular e pode ser facilmente adaptado para outras faixas de corrente ou diferentes configurações de tensão da rede elétrica, o que amplia as possibilidades de aplicação em diversos contextos.
