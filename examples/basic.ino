#include <SHT21P.h>

SHT21P sensor(5,4,3);

long ts = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("millis, temp, rh");

  sensor.powerUp();
}

void loop() {
  if(millis() - ts >= 3000) {
    ts = millis();
    Serial.print(ts);
    Serial.print(", ");
    Serial.print(sensor.readTemp(), 1);
    Serial.print(", ");
    Serial.println(sensor.readRH(), 0);
  }
}