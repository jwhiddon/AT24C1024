/*
  AT24C1024.cpp
  AT24C1024 EEPROM Library for Arduino 
  http://www.arduino.cc/playground/Code/I2CEEPROM24C1024
*/

#include <Wire.h>

#ifdef ARDUINO >= 100
#include "Arduino.h"
#else
extern "C" {
#include "WConstants.h"
}
#endif

#include "AT24C1024.h"

AT24C1024::AT24C1024(void)
{
   Wire.begin();
}

void AT24C1024::write(unsigned long dataAddress, uint8_t data)
{
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.write((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.write((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.write(data);
   Wire.endTransmission();
   delay(5);
}

uint8_t AT24C1024::read(unsigned long dataAddress)
{
   uint8_t data = 0x00;
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.write((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.write((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.endTransmission();
   Wire.requestFrom((uint8_t)((0x500000 | dataAddress) >> 16),1);
   if (Wire.available()) data = Wire.peek();
   return data;
}

AT24C1024 EEPROM1024;
