
/*Code to transfer data from PC to Arduino UNO with real time data transmission speed being printed*/

#include <EEPROM.h>

const int EEPROM_SIZE = 1024; //  size of EEPROM

int counter=0;
long currenttime=0;

void setup() 
{
  Serial.begin(2400); // Initialize serial communication
  Serial.setTimeout(1000);  // Set timeout for serial read
}

void loop() {
  if (Serial.available() > 0) 
  {
    // Read incoming byte from serial
    char receiveddata = Serial.read();
    
    // Write the byte to EEPROM
    static int address = 0;
    if (address < EEPROM_SIZE) 
    {
      EEPROM.write(address, receiveddata);    //EEPROM.write() takes 3.3ms to write a value to its address, since the given paragraph has 1000bytes 
                                              //it takes approximately 4s to complete data transfer and we get transmission speed accordingly
      address++;
      counter++;
      if((millis()-currenttime)>=1000)
      {
        currenttime=millis();
        float rate=(counter*8);
        Serial.print(rate);
        Serial.println("bps");
        counter=0;
      }
    } 
  }
}
