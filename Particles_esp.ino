// Zona de uso todos los archivos .h, ejecutar los archivos y usar sus funciones creadas.
#include "pms5003.h"
#include "ds18b20.h"
#include "lm35.h" //AÑADIDA
#include "print_data.h"
#include "microsd.h"
#include "bluetooth.h"
#include "rtc.h"

void setup() {
  Serial.begin(115200);
  SD_init();
  RTC_init();
  DS18B20_init();
  BT_init();
  pms_init();
}

void loop() {
  if (readPMSdata(&Serial2)) {
    Serial.println("_____________________Data received successfully_____________________");
    float temperatura = getTempe(); //AÑADIDO
    float temp = getTemperatura();
    String fecha = getDate();
    printData(temp, fecha, &data);
    printDataBT(temp, &data);
    logSDCard(temp, fecha, &data);
    delay(350);
  }
}
