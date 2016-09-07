#include "SHT21P.h"

SHT21P::SHT21P(int pwr, int sda, int scl) {
  pPWR = pwr;
  pSDA = sda;
  pSCL = scl;

  pinMode(pSCL, OUTPUT);
  pinMode(pPWR, OUTPUT);
  pinMode(pSDA, INPUT);
}

float SHT21P::readTemp() {
  digitalWrite(pSCL, LOW);
  delay(1200);
  
  int16_t t_low = -1;
  t_low = pulseIn(pSDA, LOW, 20000);
  int16_t t_high = -1;
  t_high = pulseIn(pSDA, HIGH, 20000);
  float t_period = t_low + t_high;

  if(t_low <= 0) return -100;
  if(t_high <= 0) return -100;

  return -46.85 + 175.72 * t_high/t_period;
}

float SHT21P::readRH() {
  digitalWrite(pSCL, HIGH);
  delay(1200);
  
  int16_t t_low = -1;
  t_low = pulseIn(pSDA, LOW, 20000);
  int16_t t_high = -1;
  t_high = pulseIn(pSDA, HIGH, 20000);
  float t_period = t_low + t_high;

  if(t_low <= 0) return -100;
  if(t_high <= 0) return -100;

  return -6.0 + 125.0*t_high/t_period;
}

void SHT21P::powerUp() {
  pinMode(pPWR, OUTPUT);
  digitalWrite(pPWR, HIGH);
  delay(150);
}

void SHT21P::powerDown() {
  digitalWrite(pPWR, LOW);
}
