# Oxímetro utilizando Arduíno
Esse projeto tem como objetivo possibilitar a utilização do Arduíno para desenvolver um oxímetro de baixo custo.

## Componentes necessários para desenvolver o projeto

Esse projeto foi prototipado utilizando os seguintes componentes:
1. Arduíno Uno R3
2. Sensor Batimento Cardíaco e Oxímetro MAX30100
3. Resistores 10k
4. Display LCD 20x4 *

* O display LCD poderá ser trocado por um componente mais barato, como por exemplo por um Módulo 74HC595 com Display 4 Digitos, ou outros. Para isso o código submetido nesse projeto deverá ser modificado para adaptar aos novos componentes.

## Protótipo

### Sobre o Sensor Batimento Cardíaco e Oxímetro MAX30100
Nos artigos falando a respeito do funcionamento desse sensor, indicava retirar os resistores da placa e utilizar o resistor de 10K externo (conforme o circuito abaixo). Os artigos indicam que esse sensor tem um bug de fabricação e a retirada deles não afetará o funcionamento.

No protótipo desenvolvido nesse projeto, os resistores foram retirados da placa. Vale resaltar que essa retirada tem o risco de danificar o sensor.

Referências: 
https://autocorerobotica.blog.br/como-fazer-um-oximetro-com-arduino/
https://www.teachmemicro.com/max30100-arduino-heart-rate-sensor/

### Ligando os componentes
![alt text](https://github.com/prifigueredo/arduino-oximetro/blob/master/oximetro-circuito.png)


### Bibliotecas 
Para esse projeto, foram utilizadas as seguintes bibliotecas:
- MAX30100_PulseOximeter - https://github.com/oxullo/Arduino-MAX30100/
- LiquidCrystal - disponível pela admistração de bibliotecas da IDE

