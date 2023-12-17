// Archivo encargado de ordenar los archivos recopilados por el pms5003 (Sensor de polvo) y enviarlos por bluethooth
/* Includes ----------------------------------------------------------------*/
#include <BluetoothSerial.h>
/* Instances ----------------------------------------------------------------*/
BluetoothSerial SerialBT;
/* Functions -----------------------------------------------------------------*/
void BT_init() {
  SerialBT.begin("Particulas");
  Serial.println("El dispositivo se ha iniciado, ahora puedes emparejarlo");
}
void printDataBT(float temperatura, pms5003data* data) {
  String datosBT =  "Tempe.: " + String(temperatura)            + "\n" +
                    "PM 1.00: " + String(data->pm10_env)        + "\n" +
                    "PM 2.50: " + String(data->pm25_env)        + "\n" +
                    "PM 10.0: " + String(data->pm100_env)       + "\n" +
                    "0.30um: " + String(data->particles_03um)   + "\n" +
                    "0.50um: " + String(data->particles_05um)   + "\n" +
                    "1.00um: " + String(data->particles_10um)   + "\n" +
                    "2.50um: " + String(data->particles_25um)   + "\n" +
                    "5.00um: " + String(data->particles_50um)   + "\n" +
                    "10.0um: " + String(data->particles_100um)  + "\n" +
                    "----------------------------------------"  + "\n";
  SerialBT.print(datosBT);
}
