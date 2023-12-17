// Archivo encargado de escribir los datos por pantalla
void printData(float temperatura, String fecha, pms5003data* data) {
Serial.println("---------------------------------------");
  Serial.println("Temperatura: " + String(temperatura));
  Serial.println("Fecha: " + String(fecha));
  Serial.println("---------------------------------------");
  Serial.println("Temperatura: " + String(temperatura) + "°C");
  Serial.println("---------------------------------------");
  Serial.println("Unidades de concentración (ambiental)");
  Serial.println("PM 1.00: " + String(data->pm10_env) + " ug/m3");
  Serial.println("PM 2.50: " + String(data->pm25_env) + " ug/m3");
  Serial.println("PM 10.0: " + String(data->pm100_env) + " ug/m3");
  Serial.println("---------------------------------------");
  Serial.println("Particulas > 0.30um / 0.1L aire: " + String(data->particles_03um));
  Serial.println("Particulas > 0.50um / 0.1L aire: " + String(data->particles_05um));
  Serial.println("Particulas > 1.00um / 0.1L aire: " + String(data->particles_10um));
  Serial.println("Particulas > 2.50um / 0.1L aire: " + String(data->particles_25um));
  Serial.println("Particulas > 5.00um / 0.1L aire: " + String(data->particles_50um));
  Serial.println("Particulas > 10.0um / 0.1L aire: " + String(data->particles_100um));
}
