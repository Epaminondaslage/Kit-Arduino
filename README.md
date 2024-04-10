<td style="width: 20%;"><img src="img/titulo.png" width="100%" /></td>

# Objetivo Geral  
O objetivo do curso é auxiliar os alunos do primeiro ano do curso de Eletrotécnica a compreender e aplicar os fundamentos da eletrônica e da programação por meio da plataforma Arduino. Ao final do curso, os alunos deverão ser capazes de desenvolver projetos que integrem conhecimentos teóricos e práticos ao problemas reais. 

# Objetivos Específicos  

* **Fundamentos de eletrônica:** Proporcionar aos alunos uma compreensão dos conceitos básicos de eletrônica, desde a teoria dos componentes elétricos básicos, à análise de circuitos simples, até as aplicações das leis da eletricidade. 

* **Introdução à programação:** Ajudar os alunos a se familiarizarem com conceitos básicos de programação, introduzindo estruturas de controle, variáveis básicas e funções através da linguagem C/C++ utilizando a IDE Arduino.  

* **Explorar o Arduino:** Capacitar os alunos a manusear o Arduino e demais componentes, entender sua arquitetura, periféricos e ambiente de desenvolvimento integrado (IDE), para dar-lhes autonomia na implementação de projetos.  

* **Desenvolvimento de projetos:** Orientar os alunos na concepção e implementação de projetos utilizando Arduino, como controle de LED (diodos emissores de luz), controle de motores DC, utilização de sensores analógicos e digitais, entre outros projetos.  

* **Interação com ambientes reais:** Permitir que os alunos explorem a conexão entre o Arduino e o mundo real, utilizando entradas e saídas digitais e analógicas para controlar dispositivos externos assim como coletar dados do ambiente.  

* **Resolução de Problemas:** Desenvolver habilidades de resolução de problemas, permitindo que os alunos identifiquem e resolvam desafios comuns ao desenvolver um projeto Arduino.  

* **Projeto Final Integrado:** Estimular a criatividade e a aplicação prática dos conhecimentos adquiridos através da elaboração e implementação de um projeto final que inclui vários conceitos estudados ao longo do curso.  

# Metodologia 

* Aulas expositivas para apresentação de conceitos teóricos básicos. 

* Atividades práticas de laboratório para aplicar conhecimentos aprendidos e desenvolver habilidades técnicas. 

* Uso de material educacional adicional, como tutoriais on-line e documentação oficial do Arduino, para apoiar o aprendizado.  

# Avaliação

* A avaliação baseia-se na participação nas aulas, realização de atividades práticas e teóricas. 

* Avaliação do projeto final, levando em consideração critérios como originalidade, aplicação dos conceitos aprendidos e funcionalidade do projeto.

# Repositórios complementares

* https://github.com/Epaminondaslage/Kit-IoT
*
*
*

# kit Arduino Básico

# Sensores para Arduino

Sensores para Arduino são dispositivos que permitem ao Arduino detectar e medir o ambiente ao seu redor. Eles podem capturar uma variedade de informações, como temperatura, umidade, luz, movimento, som, distância, entre outros. Esses sensores são conectados ao Arduino através de pinos digitais ou analógicos e fornecem dados que podem ser utilizados para tomar decisões ou controlar dispositivos conectados ao Arduino. Existem muitos tipos diferentes de sensores disponíveis para Arduino, cada um com sua função específica e método de operação. Eles são fundamentais para a criação de projetos interativos e inteligentes usando a plataforma Arduino.

Veja os principais sensores utilizados no nosso KIT Arduino:

   https://github.com/Epaminondaslage/Kit-IoT/tree/master/sensores

# Programas de exemplos

Neste repositorio estão disponibilizados inúmeros programas de exemplo de de skets básicos para arduino . O Blink é o programa básico de “Hello, World!” para Arduino, onde você faz um LED piscar em intervalos regulares. colie e cole na IDE  do Arduino. Compile o código e transfira para a placa.

'''
void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
        }
        void loop() {
           digitalWrite(LED_BUILTIN, HIGH);
           delay(1000);
           digitalWrite(LED_BUILTIN, LOW);
           delay(1000);
         }

'''
# Apresentações dos slides das aulas

A ementa do curso de Arduino básico e os slides encontram-se no link abaixo para download :

https://github.com/Epaminondaslage/Kit-IoT/tree/master/material_didatico/ppt_de_aulas

# Aulas práticas

* 01- Ajustando o brilho de um LED por PWM com Arduino https://github.com/Epaminondaslage/Kit-IoT/blob/master/material_didatico/guia_de_aulas/01_Ajustando%20o%20brilho%20de%20um%20LED%20por%20PWM%20com%20Arduino.docx
* 02- Comunicação pela rede com o Módulo Ethernet ENC28J60
* 03- Monitorando Temperatura e Umidade com o sensor DHT11
* 04- Mostrando a temperatura no LCD 16×2 com o sensor DHT11
* 05- Sensor de chuva YL
* 06- Display 7 segmentos
* 07- Controle de Acesso usando Leitor RFID com Arduino
* 08 -Ligando um Display LCD 16 x 2 com Arduino
* 09- Shield LCD 16x2 com Keypad 
* 10- Multifunction Shield
* 11- TM1637.docx
* 12- Módulo RTC DS3231 
* 13- Módulo ESP8266 
* 14- Módulo Wireless ESP8266 
* 15- Shield LCD 16x2 e sensor de nivel
* 16- Tutorial Módulo Wireless ESP8266 com Arduino 
* 17- Monitorando Luz com LDR e acionando relé
