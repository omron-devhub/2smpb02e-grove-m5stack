#include <driver/dac.h>
#include <M5Stack.h>
#include "Omron2SMPB02E.h"

Omron2SMPB02E prs;
// Omron2SMPB02E prs(0); // in case of SDO=0 configuration

void setup()
{
  M5.begin();
  dac_output_disable(DAC_CHANNEL_1);
  prs.begin();
  Serial.begin(9600);
  prs.set_mode(MODE_NORMAL);
  delay(300);
}

void loop()
{
  delay(2000);
  float temp = prs.read_temp();
  float pressure = prs.read_pressure();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Temperature:\r\n%f[degC]\r\n\r\n", temp);
  M5.Lcd.printf("Pressure:\r\n%f[Pa]\r\n", pressure);
}
