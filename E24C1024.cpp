
#include <Wire.h>
#include "E24C1024.h"

E24C1024::E24C1024(void)
{
   Wire.begin();
}

void E24C1024::write(unsigned long dataAddress, uint8_t data)
{
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.send((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.send((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.send(data);
   Wire.endTransmission();
   delay(5);
}

uint8_t E24C1024::read(unsigned long dataAddress)
{
   uint8_t data = 0x00;
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.send((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.send((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.endTransmission();
   Wire.requestFrom(0x50,1);
   if (Wire.available()) data = Wire.receive();
   return data;
}

E24C1024 EEPROM1024;
