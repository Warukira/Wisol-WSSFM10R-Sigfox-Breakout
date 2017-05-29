#include <AltSoftSerial.h>
// AltSoftSerial always uses these pins:
//
// Board          Transmit  Receive   PWM Unusable
// -----          --------  -------   ------------
// Teensy 3.0 & 3.1  21        20         22
// Teensy 2.0         9        10       (none)
// Teensy++ 2.0      25         4       26, 27
// Arduino Uno        9         8         10
// Arduino Leonardo   5        13       (none)
// Arduino Mega      46        48       44, 45
// Wiring-S           5         6          4
// Sanguino          13        14         12

// I am using Arduino Pro Mini which will be Arduino Uno Equivalent
AltSoftSerial mySerial;



void setup() {

  pinMode(12,OUTPUT);//I am using pin 12 to do the Sleep(RST on the Wisol Module)
  Serial.begin(57600);// Configuring the PC serial port

  mySerial.begin(9600);//Configuring the Sigfox Module software serial port

  while (!Serial) {
    
  }

  Serial.println("Passed Setup");  
 
  }

void loop() {
  
  delay(100);
  mySerial.println("AT");// writing AT command
  delay(5);
  Serial.println("AT");//Display on PC
  delay(5);
  
  if (mySerial.available()>0) 
  {
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get an OK, 
              }
     Serial.println("");
  }
  delay(5);
  mySerial.write("AT$RL\r\n");// Command to put the wisol modul on RX mode
  delay(100);
 Serial.println("Wisol Waiting for RX");

while(true){//loops in here

 if (mySerial.available()>0) 
  {       Serial.println("Wisol Received Data");
          delay(200);//waiting for RX buffer to fill up
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get  the Data Frame received 
              }
     Serial.println("");
     delay(5);
    mySerial.write("AT$RL\r\n");// Command to put the wisol modul on RX mode again
    delay(100);
    Serial.println("Waiting for Data");
  }

}
  
  
}
