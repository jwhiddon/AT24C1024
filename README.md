Overview

This is a library to support the AT24C1024 EEPROM. Up to 4 of these devices may be chained together to provide 128-512 kilobytes of EEPROM storage.

AT24C1024 Library Project Home at the Arduino Playground

The usage is based on the Arduino EEPROM library and two I2C EEPROM libraries. If you're familiar with how that works, using this library should be pretty straightforward. Basically just substitute EEPROM1024 where you were using EEPROM.

For example:

EEPROM.write(address, value);

becomes:

EEPROM1024.write(address, value);

Credits

This library is based on several projects:

The Arduino EEPROM library found here: https://www.arduino.cc/en/Reference/EEPROM

The 24C256 library found here: http://playground.arduino.cc/Code/I2CEEPROM

The 24C512 library found here: http://playground.arduino.cc/Code/I2CEEPROM24LC512

Download

https://github.com/jwhiddon/arduino-at24c1024

Installing

Unzip the download into your Arduino-00xx/hardware/libraries directory. If the Arduino IDE is already running then exit and restart the Arduino IDE.

