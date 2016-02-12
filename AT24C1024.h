#ifndef AT24C1024_h
#define AT24C1024_h
/*
  AT24C1024.cpp
  AT24C1024 EEPROM Library for Arduino 
  http://www.arduino.cc/playground/Code/I2CEEPROM24C1024
*/

#ifdef ARDUINO >= 100
#include "Arduino.h"
#else
extern "C" {
#include "WConstants.h"
}
#endif

#include <Wire.h>

#define FULL_MASK 0x7FFFF
#define DEVICE_MASK 0x7F0000
#define WORD_MASK 0xFFFF

class AT24C1024
{
  public:
    AT24C1024();
    static void write(unsigned long, uint8_t);
    static uint8_t read(unsigned long);
};

extern AT24C1024 EEPROM1024;

#endif
