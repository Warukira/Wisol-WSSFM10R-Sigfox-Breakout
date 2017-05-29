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

  pinMode(12,OUTPUT);//I am using pin 12 to do the Sleep
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
  mySerial.write("AT$I=10\r\n");// Command to get ID
  delay(100);
 Serial.println("ID");

 if (mySerial.available()>0) 
  {
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get  the PAC number 
              }
     Serial.println("");
  }

  delay(5);
  mySerial.write("AT$I=11\r\n");;// Command to get PAC
  delay(100);
  Serial.println("PAC");


 if (mySerial.available()>0) 
  {
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get  the ID number 
              }
     Serial.println("");
  }


delay(5);
mySerial.write("AT$T?\r\n");;// Command to get Temperature
delay(100);
Serial.println("Temperature");

 if (mySerial.available()>0) 
  {
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get  the Temperature.
              }
     Serial.println("");
  }  

delay(5);
mySerial.write("AT$SL=AABBCCDDEEFFAABBCCDDEEFF\r\n");;// Command to send a Local Message to other Wisol Module for Testing
delay(100);
if (mySerial.available()>0) 
  {
          while(mySerial.available()>0)
              {//We read from the sigfox module and put what it was read on the pc serial port
                Serial.write(mySerial.read());// we should get  OK after sendin local loop
              }
     Serial.println("");
  }  


  


 //Lets put it to sleep
  delay(500);
  Serial.println("Sleep");
  mySerial.println("AT$P=2");
  delay(4000);//Sleeps for 4 seconds
  
  digitalWrite(12,LOW);//It wakes up when the pin 12 is pull low
  delay(1000);
  digitalWrite(12,HIGH);//We pull it back to high
  
  Serial.println("Sigfox module is AWAKE");

  //loop Repeats.
  
}
