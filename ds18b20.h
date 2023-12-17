/* VCC
   SEÑAL --  26
   GND
*/
// Archivo encargado de recibir los datos de temperatura del dispositivo ds18b20
#define pinTemp 25 // Pin 25 del ESP32
/* Includes ------------------------------------------------------------------*/
#include <OneWire.h>
#include <DallasTemperature.h>
/* Instances -----------------------------------------------------------------*/
OneWire oneWireSensor(pinTemp);
DallasTemperature sensorDS18B20(&oneWireSensor);
/* Functions -----------------------------------------------------------------*/
void DS18B20_init() {
  sensorDS18B20.begin();
}
float getTempe() {
  sensorDS18B20.requestTemperatures();
  float temp = sensorDS18B20.getTempCByIndex(0);
  temp = temp == -127 ? 0 : temp;
  return temp;
}
