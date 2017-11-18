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

#define Wreset 4

void setup() {

  pinMode(Wreset,OUTPUT);//I am using pin 4 to do the Sleep
  Serial.begin(9600);// Configuring the PC serial port

  mySerial.begin(9600);//Configuring the Sigfox Module software serial port

  while (!Serial) {
    
  }

  Serial.println("INITIALIZING PROGRAM");  
 
  }

void loop() {
  
 if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  
}
