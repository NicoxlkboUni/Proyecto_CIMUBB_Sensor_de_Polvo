#define RXD2 17 //Pin 17 del ESP32
#define TXD2 16 //Pin 16 del ESP32
// Archivo encargado de recibir los datos recopilados por el sensor de polvo
enum pms5003_status {
  PMS_ERROR,
  PMS_OK
};

struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
struct pms5003data data;

void pms_init() {
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}
boolean readPMSdata(Stream *s) {
  delay(200);

  if (! s->available()) {
    Serial.println("No data available");
    return PMS_ERROR;
  }
  if (s->peek() != 0x42) {
    s->read();
    // Serial.println("Invalid start byte");
    return PMS_ERROR;
  }
  if (s->available() < 0) {//32
    Serial.println("NoBytes");
    return PMS_ERROR;
  }
  
  // Serial.println("speek->"+s->peek());
  // Serial.println("Sspeek->"+String(s->peek()));
  // Serial.println("savailable->"+s->available());
  // Serial.println("Ssavailable->"+String(s->available()));
  
  uint8_t buffer[32];
  uint16_t sum = 0;
  s->readBytes(buffer, 32);

  // Serial.println("readBytes->"+s->readBytes(buffer, 32));
  // Serial.println("SreadBytes->"+String(s->readBytes(buffer, 32)));

  for (uint8_t i = 0; i < 30; i++) {
    sum += buffer[i];
  }
  uint16_t buffer_u16[15];
  for (uint8_t i = 0; i < 15; i++) {
    buffer_u16[i] = buffer[2 + i * 2 + 1];
    buffer_u16[i] += (buffer[2 + i * 2] << 8);
  }

  memcpy((void *)&data, (void *)buffer_u16, 30);

  if (sum != data.checksum) {
    Serial.println("Cargando...");
    return PMS_ERROR;
  }

  return PMS_OK;
}
