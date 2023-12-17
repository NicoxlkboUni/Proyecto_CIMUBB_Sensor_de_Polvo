int outputpin = 4;

float getTemperatura(){
  int analogValue = analogRead(outputpin);
  float millivolts = (analogValue/1023.0) * 3300; //3300 es el voltaje recibido
  float celsius = millivolts/100;
  // Serial.print("in DegreeC= ");
  // Serial.print(celsius);
  // Serial.println("ºC");
  return celsius;
  delay(1000);
}