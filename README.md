# Arduino AT24C1024 EEPROM Library
This is a library to support the AT24C1024 EEPROM. Up to 4 of these devices may be chained together to provide 128-512 kilobytes of EEPROM storage.

The usage is based on the Arduino EEPROM library and two I2C EEPROM libraries. If you're familiar with how that works, using this library should be pretty straightforward. Basically just substitute EEPROM1024 where you were using EEPROM.

**For example, this:**
```
EEPROM.write(address, value);
```
**becomes:**
```
EEPROM1024.write(address, value);
```

[AT24C1024 Library Project Home at the Arduino Playground](http://playground.arduino.cc/Code/I2CEEPROM24C1024)

## Credits
This library is based on several projects:
* [The Arduino EEPROM library](https://www.arduino.cc/en/Reference/EEPROM)
* [The 24C256 library](http://playground.arduino.cc/Code/I2CEEPROM)
* [The 24C512 library](http://playground.arduino.cc/Code/I2CEEPROM24LC512)

## Install
* Unzip the download into your Arduino library directory
* If the Arduino IDE is already running then exit and restart the Arduino IDE

## Examples
* [AT24C1024_EEPROM_Benchmark.ino](https://github.com/jwhiddon/arduino-at24c1024/blob/master/examples/)

## Releases

### 1.0.2 - Feb 12, 2016
* Update example sketch filename extensions to .ino
* Change library name to match chipset name
* More Arduino IDE compatibility changes 

### 1.0.0 - Feb 12, 2016
* Updated to support Arduino 1.0.0+
* Migrate to github

### 0.5.0 - Dec 8, 2009
* Initial Release
