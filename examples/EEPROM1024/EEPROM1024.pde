#include <WProgram.h>
#include <Wire.h>
#include <E24C1024.h>

unsigned long val;
unsigned long time;
unsigned long finishTime;
uint16_t errors = 0;

// generally this would be 0 to start at the beginning of the address space
#define MIN_ADDRESS 0

// up to 131072 (1 chip), 262144 (2), 393216 (3), 524288 (4)
#define MAX_ADDRESS 131072

// 1-255, determines the data that's written 
#define LOOP_SIZE 25

void setup()
{
  Serial.begin(9600);

  Serial.println();
  Serial.println("AT24C1024 Benchmark Sketch");
  Serial.println();

  writeByByteTest();
  readByByteTest();
}

void loop()
{
}

void writeByByteTest()
{
  Serial.println("--------------------------------");
  Serial.println("Write By Byte Test:");
  Serial.println();

  Serial.print("Writing data:");
  time = millis();

  for (unsigned long address = MIN_ADDRESS; address < MAX_ADDRESS; address++)
  {
    EEPROM1024.write(address, (uint8_t)(address % LOOP_SIZE));
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
  unsigned long errors = 0;
  uint8_t data;

  Serial.println("--------------------------------");
  Serial.println("Read By Byte Test:");
  Serial.println();

  Serial.print("Reading data:");
  time = millis();

  for (unsigned long address = MIN_ADDRESS; address < MAX_ADDRESS; address++)
  {
    data = EEPROM1024.read(address);
    if (data != (uint8_t)(address % LOOP_SIZE)) 
    {
      Serial.println();
      Serial.print("Address: ");
      Serial.print(address);
      Serial.print(" Should be: ");
      Serial.print((uint8_t)(address % LOOP_SIZE), DEC);
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

