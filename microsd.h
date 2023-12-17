/* VCC
   MISO --  19
   MOSI --  23
   SCK  --  18
   GND
*/
// Archivo encargado de escribir en la tarjeta sd incluida en el datalogguer
/* Includes ------------------------------------------------------------------*/
#include <FS.h>
#include <SD.h>
#include <SPI.h>
/* Functions -----------------------------------------------------------------*/
void writeFile(fs::FS &fs, const char *path, const char *message) {
  File file = fs.open(path, FILE_WRITE);
  Serial.println(!file ? "Archivo no se pudo abrir" : "Archivo abierto");
  Serial.println(file.print(message) ? "Archivo escrito" : "No se ha podido escribir");
  file.close();
}
void appendFile(fs::FS &fs, const char *path, const char *message) {
  File file = fs.open(path, FILE_APPEND);
  Serial.println(!file ? "Archivo no se pudo abrir" : "Archivo abierto");
  Serial.println(file.print(message) ? "Archivo añadido" : "No se ha podido añadir");
  file.close();
}
void SD_init() {
  Serial.println(!SD.begin() ? "No se puede encontrar la SD" : "Se encontro la SD");
  File file = SD.open("/particulas.txt");
  Serial.println(!file ? "El archivo no existe, se creara uno" : "El archivo ya existe");
  if (!file) {
    writeFile(SD, "/particulas.txt", "-WPMS5003\r\n");
  } else if (file) {
    appendFile(SD, "/particulas.txt", "-APMS5003\r\n");
  }
  file.close();
}
void logSDCard(float temperatura, String fecha, pms5003data *data) {
  String datosSD = 
    "--------------------------------------\n" + 
    String(fecha) + "\n" + 
    "PM 1.00: " + String(data->pm10_env) + "\n" + 
    "PM 2.50: " + String(data->pm25_env) + "\n" + 
    "PM 10.0: " + String(data->pm100_env) + "\n" + 
    "0.30um: " + String(data->particles_03um) + "\n" + 
    "0.50um: " + String(data->particles_05um) + "\n" + 
    "1.00um: " + String(data->particles_10um) + "\n" + 
    "2.50um: " + String(data->particles_25um) + "\n" + 
    "5.00um: " + String(data->particles_50um) + "\n" + 
    "10.0um: " + String(data->particles_100um) + "\n" + 
    String("Temperatura: ") + String(temperatura) + "ºC\r\n";
  appendFile(SD, "/particulas.txt", datosSD.c_str());
}
