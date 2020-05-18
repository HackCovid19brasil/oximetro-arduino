#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <LiquidCrystal.h>

#define REPORTING_PERIOD_MS     1000

//definição das saídas LCD
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

PulseOximeter pox;

uint32_t tsLastReport = 0;


void setup()
{
    //definindo porta serial
    Serial.begin(115200);

    //verificando oximetro
    Serial.print("Inicializando oxímetro..");
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
    
    //informa quando detecta batimento cardíaco
    pox.setOnBeatDetectedCallback(onBeatDetected);

    //inicialização do LCD
    lcd.begin(20, 4);
    lcd.clear();
}

void loop()
{ 
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        //imprime na porta serial
        printSerial(pox.getSpO2(), pox.getHeartRate());
        //imprime do LCD
        printDisplay(pox.getSpO2(), pox.getHeartRate());
        
        tsLastReport = millis();
    }
}

void printSerial(int o2, float pr)
{
  Serial.print("Batimento cardíaco:");
  Serial.print(pox.getHeartRate());
  Serial.print("bpm / O2:");
  Serial.print(pox.getSpO2());
  Serial.println("%");
}

void printDisplay(int o2, float pr)
{
  //limpa tela
  lcd.clear();

  //imprime O2
  lcd.setCursor(0,0);
  lcd.print("O2:");
  lcd.setCursor(5,0);
  lcd.print(o2);
  lcd.setCursor(10,0);
  lcd.print("%");
  lcd.setCursor(20,0);

  //imprime batimento cardíaco
  lcd.setCursor(0,1);
  lcd.print("PR:");
  lcd.setCursor(5,1);
  lcd.print(pr,0  );
  lcd.setCursor(10,1);
  lcd.print("bpm");
  lcd.setCursor(20,1);
}

void onBeatDetected()
{
    Serial.println("Beat!");
}
