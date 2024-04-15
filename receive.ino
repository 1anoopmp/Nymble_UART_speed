
/*Code to receive and print data stored in Arduino EEPROM on to PC screen with real time data transfer speed*/

#include <EEPROM.h>

int counter=0;
long currenttime=0;

void setup() {
  // Initialize serial communication
  Serial.begin(2400);
}

void loop() 
{
  // Read data from EEPROM and print to Serial Monitor
  for (int address=0; address < EEPROM.length(); address++) 
  {
    char data = EEPROM.read(address);
    Serial.print(data);
    counter++;
    if((millis()-currenttime)>=1000)
    {
      currenttime=millis();
      float rate=(counter*8);
      Serial.println();
      Serial.print(rate);
      Serial.println("bps");
      counter=0;
      
    }
  }
  delay(1000);
}
