/*
  AT24C1024_EEPROM_Benchmark.ino
  AT24C1024 EEPROM Benchmark Sketch 
  http://playground.arduino.cc/Code/I2CEEPROM24C1024
*/

#include <Wire.h>
#include <AT24C1024.h>

unsigned long time;
unsigned long finishTime;
unsigned long errors = 0;
unsigned long address = 0;
byte loop_size;

// Set to a higher number if you want to start at a higher address. 
#define MIN_ADDRESS 0

// Upper boundary of the address space.  Choose one.
#define MAX_ADDRESS 131072 // 1 device
//#define MAX_ADDRESS 262144 // 2 devices
//#define MAX_ADDRESS 393216 // 3 devices
//#define MAX_ADDRESS 524288 // 4 devices

void setup()
{
  // Make sure we aren't reading old data
  randomSeed(analogRead(0));
  loop_size = random(1, 100);
  Serial.begin(9600);
  Serial.println();
  Serial.println("AT24C1024 EEPROM Library Benchmark Sketch");
  Serial.println();
  writeByByteTest();
  readByByteTest();
}

void loop()
{
}

void writeByByteTest()
{
  time = millis();
  errors = 0;
  Serial.println("--------------------------------");
  Serial.println("Write By Byte Test:");
  Serial.println();
  Serial.print("Writing data:");
  for (address = MIN_ADDRESS; address < MAX_ADDRESS; address++)
  {
    EEPROM1024.write(address, (uint8_t)(address % loop_size));
    if (!(address % 5000)) Serial.print(".");
  }
  finishTime = millis() - time;
  Serial.println("DONE");
  Serial.print("Total Time (seconds): "); 
  Serial.println((unsigned long)(finishTime / 1000));
  Serial.print("Write operations per second: "); 
  Serial.println((unsigned long)(MAX_ADDRESS / (finishTime / 1000))); 
  Serial.println("--------------------------------");   
  Serial.println();
}

void readByByteTest()
{
  time = millis();
  errors = 0;
  Serial.println("--------------------------------");
  Serial.println("Read By Byte Test:");
  Serial.println();
  Serial.print("Reading data:");
  for (address = MIN_ADDRESS; address < MAX_ADDRESS; address++)
  {
    uint8_t data;
    data = EEPROM1024.read(address);
    if (data != (uint8_t)(address % loop_size)) 
    {
      Serial.println();
      Serial.print("Address: ");
      Serial.print(address);
      Serial.print(" Should be: ");
      Serial.print((uint8_t)(address % loop_size), DEC);
      Serial.print(" Read val: ");
      Serial.println(data, DEC);
      errors++;
    }
    if (!(address % 5000)) Serial.print(".");
  }
  finishTime = millis() - time;
  Serial.println("DONE");
  Serial.println();
  Serial.print("Total Test Time (secs): "); 
  Serial.println((unsigned long)(finishTime / 1000));
  Serial.print("Read operations per second: "); 
  Serial.println((unsigned long)(MAX_ADDRESS / (finishTime / 1000))); 
  Serial.print("Total errors: "); 
  Serial.println(errors);   
  Serial.println("--------------------------------");
  Serial.println();
}
