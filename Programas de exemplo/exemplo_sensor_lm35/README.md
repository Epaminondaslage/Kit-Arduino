# Medição de Temperatura com Sensor LM35 e Arduino

## Descrição do Projeto

Este projeto utiliza um sensor de temperatura LM35 conectado ao pino A0 de um Arduino para medir a temperatura ambiente. A temperatura medida é exibida no monitor serial a cada segundo.

## Funcionamento do Código

### Declaração de Variáveis

- **`float temp;`**: Esta variável é utilizada para armazenar o valor da temperatura medida pelo sensor.
- **`const int sensorPin = A0;`**: Esta constante define o pino analógico A0 como o pino onde o sensor LM35 está conectado.

### Função `setup()`

- **`Serial.begin(9600);`**: A função `setup()` inicializa a comunicação serial a uma velocidade de 9600 bauds. Isso permite que o Arduino envie dados para o computador, que podem ser visualizados no monitor serial.

### Função `loop()`

A função `loop()` é responsável por realizar a leitura do sensor, converter o valor lido em temperatura e exibir o resultado no monitor serial. O processo é repetido indefinidamente.

1. **Leitura do Sensor**:
   - **`temp = analogRead(sensorPin);`**: A leitura do pino analógico A0 é realizada, e o valor é armazenado na variável `temp`. O valor lido é um número entre 0 e 1023, representando a tensão recebida pelo pino (de 0 a 5V).

2. **Conversão da Leitura em Temperatura**:
   - **`temp = temp * 0.48828125;`**: O valor lido é multiplicado por uma constante (0,48828125) para converter a leitura em uma temperatura em graus Celsius. Esta constante é específica para o sensor LM35, que fornece 10mV por grau Celsius.

3. **Exibição da Temperatura**:
   - **`Serial.print("Temperatura: ");`**: O texto "Temperatura: " é exibido no monitor serial.
   - **`Serial.print(temp);`**: A temperatura medida, armazenada na variável `temp`, é exibida no monitor serial.
   - **`Serial.print("°C");`**: O texto "°C" é adicionado após o valor da temperatura, indicando que a medida está em graus Celsius.
   - **`Serial.println();`**: Esta função adiciona uma nova linha no monitor serial, preparando-o para a próxima leitura.

4. **Atraso entre Leitura**:
   - **`delay(1000);`**: O código espera 1 segundo antes de repetir o processo, garantindo que a temperatura seja atualizada no monitor serial a cada segundo.

## Conclusão

Este código permite que o Arduino leia a temperatura ambiente através do sensor LM35 e exiba o valor no monitor serial. É uma solução simples e eficaz para monitorar a temperatura em tempo real.
