# Relógio com o Integrado DS3231 (RTC) - Arduino UNO

## Descrição do Projeto

Este projeto utiliza o módulo RTC (Real Time Clock) DS3231 para manter e exibir a data e hora. O Arduino UNO é utilizado para ler e exibir esses valores no monitor serial. O DS3231 é um módulo RTC preciso que pode continuar a contar o tempo mesmo quando o Arduino está desligado, graças a uma bateria de backup.

## Funcionamento do Código

### Declaração e Inicialização

- **`#include <DS3231.h>`**: Inclui a biblioteca necessária para controlar o módulo DS3231.
- **`DS3231 rtc(SDA, SCL);`**: Inicializa o RTC utilizando os pinos SDA e SCL, que são os pinos padrão para comunicação I2C no Arduino.

### Função `setup()`

1. **Inicialização da Comunicação Serial**:
   - **`Serial.begin(9600);`**: Inicializa a comunicação serial com o computador a uma velocidade de 9600 bps. Isso permite que o Arduino envie dados para o monitor serial.

2. **Inicialização do RTC**:
   - **`rtc.begin();`**: Inicializa o módulo RTC.

3. **Configuração da Data e Hora**:
   - **`rtc.setDOW(MONDAY);`**: Define o dia da semana. Este valor deve ser atualizado conforme o dia da semana atual (em inglês).
   - **`rtc.setTime(15, 29, 0);`**: Define a hora inicial no formato 24 horas (HH:MM:SS).
   - **`rtc.setDate(20, 3, 2017);`**: Define a data inicial (dia, mês, ano). Essas linhas são utilizadas para configurar a data e hora no primeiro upload do código. Após a configuração, o RTC mantém o tempo atualizado automaticamente.

### Função `loop()`

A função `loop()` é responsável por ler e exibir continuamente a data e hora no monitor serial. 

1. **Leitura do Dia da Semana**:
   - **`Serial.print("Dia da semana: ");`**
   - **`Serial.println(rtc.getDOWStr());`**: Lê e exibe o dia da semana no monitor serial.

2. **Leitura da Data**:
   - **`Serial.print("Data: ");`**
   - **`Serial.println(rtc.getDateStr());`**: Lê e exibe a data no formato "DD/MM/AAAA".

3. **Leitura da Hora**:
   - **`Serial.print("Horas: ");`**
   - **`Serial.println(rtc.getTimeStr());`**: Lê e exibe a hora no formato "HH:MM:SS".

4. **Atraso entre Leitura**:
   - **`delay(1000);`**: Aguarda 1 segundo antes de realizar a próxima leitura, para que a hora seja atualizada a cada segundo.

## Conclusão

Este código permite que o Arduino UNO utilize o módulo DS3231 para manter e exibir a hora e a data. 
