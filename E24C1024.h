#ifndef E24C1024_h
#define E24C1024_h

#include <WConstants.h>
#include <Wire.h>

/*

This is based on the Arduino EEPROM library.  

The AT24C1024B provides 1,048,576 bits of serial electrically 
erasable and programmable read only memory (EEPROM) organized 
as 131,072 words of 8 bits each. The device’s cascadable 
feature allows up to four devices to share a common two-wire 
bus.

http://www.atmel.com/dyn/resources/prod_documents/doc5194.pdf

Digikey page:
http://search.digikey.com/scripts/DkSearch/dksus.dll?Detail&name=AT24C1024B-PU25-ND

*/

#define FULL_MASK 0x7FFFF
#define DEVICE_MASK 0x7F0000
#define WORD_MASK 0xFFFF

class E24C1024
{
  public:
    E24C1024();
    void write(unsigned long, uint8_t);
    uint8_t read(unsigned long);
};

extern E24C1024 EEPROM1024;

#endif
