
#include <AltSoftSerial.h>
#include <stdio.h>
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
// 


AltSoftSerial mySerial;

#define Wreset 4
String rx_wisol;


int temperaturewisol;
char wtemp[]="11111";


void setup() {

  pinMode(Wreset,OUTPUT);              //I am using pin 12 to do the Sleep
  digitalWrite(Wreset,HIGH);           //We pull it back to high


  Serial.begin(57600);                // Configuring the PC serial port
  mySerial.begin(9600);               //Configuring the Sigfox Module software serial port

  

  Serial.println("INITIALIZING PROGRAM");

  
}




void loop()
{
    //---Send AT Command
    Serial.println("Send AT Command ");
    ATcmd();                               //call AT function
    
    ReadWisol(rx_wisol);                   //Read Wisol Serial Port
    Serial.println("Wisol Response");
    Serial.print(rx_wisol);               //Print sigfox data on PC Serial port

    Serial.println("Send ID Command ");
    ATgetid();                            //call ID function
    
    ReadWisol(rx_wisol);
    Serial.println("Wisol Response");
    Serial.print(rx_wisol);

    Serial.println("Send PAC Command ");
    ATgetpac();                           //call PAC function

    ReadWisol(rx_wisol);
    Serial.println("Wisol Response");
    Serial.print(rx_wisol);


    Serial.println("******Wisol temp******");
    ATtemp();                            //call ATtemp
    ReadWisolTemp();                     //i use a different function to read the temperature                                   
    Serial.println("Wisol Response");
    Serial.println(wtemp);               //Temperature as Char array

    temperaturewisol=atoi(wtemp);        //Char to Int Conversion

    Serial.println("Send Sigfox");    
    ATsendsigfoxint(temperaturewisol);  // Function to send a Sigfox Integer     

    delay(10);
    ReadWisolTx(rx_wisol);              // call different function to read wisol serial after sigfox transmision
                                        // we will wait for the transmission to complete
    delay(50);
    Serial.print(rx_wisol);
    Serial.println("");
    Serial.println("");
    delay(100);

    Serial.println("Send AT Command ");
    ATcmd();
    delay(100);
    ReadWisol(rx_wisol);
    Serial.println("Wisol Response");
    Serial.print(rx_wisol);


  // Apply the desired delay after sending
    delay(10000);
    delay(10000);
    delay(10000);
    delay(10000);
    delay(10000);
    delay(10000);
    delay(10000);


}

//+++++++++FUNCTIONS++++++++++++++++++++++++++++++
void ATtemp()
{

  delay(5);
  mySerial.println("AT$T?");// Command to get Temperature
  delay(100);



}



void ATgetid()
{

  delay(5);
  mySerial.println("AT$I=10");// Command to get ID
  delay(100);

}


void ATgetpac()
{

  delay(5);
  mySerial.println("AT$I=11");// Command to get PAC
  delay(100);


}

void ATcmd()
{

  mySerial.println("AT");// writing AT command
  delay(100);

}

void ATsendlocal()
{
mySerial.println("AT$SL=AABBCCDDFF11228899");
}



void ATsendsigfoxint(int data)
{
  //To transmit the wisol modules need to have the byte complete
  // on the int to string conversion if number is 3 digit the function will not
  //add the 0 on the left for example 258 decimal is 102 on HEX, but the module with  give you 
  // a parse error if you try to send AT$SF=102.. the correct way is AT$SF=0102
  // on the switch function  we detect the lenght of the conversion and add the zeroes to the left.
  
  String Sigfox="AT$SF="; 
  String tempdata=String(data,HEX);

  switch(tempdata.length())
  {
    case 1:
            Sigfox+="000"+String(data,HEX);
            break;
    case 2:
            Sigfox+="00"+String(data,HEX);
            break;
    case 3:
            Sigfox+="0"+String(data,HEX);
            break;
    case 4:
            Sigfox+=String(data,HEX);
            break;
    default:
            // no match
            break;
      
  }
  
  Serial.println("Data to send to sigfox "+Sigfox);
  
  mySerial.println(Sigfox);
  delay(100);

}
void ATsendsigfox()
{
mySerial.println("AT$SF=AABBCCDDEEFFAABBCCDDEEFF");
}


void ReadWisol(String &dest)
{
   char inData[20]; // Allocate some space for the string
   char inChar; // Where to store the character read
   byte index = 0; // Index into array; where to store the character


      delay(200);
     if (mySerial.available()>0)
      {
              while(mySerial.available()>0)
                  {

                      inChar = mySerial.read(); // Read a character
                      inData[index] = inChar; // Store it
                      index++; // Increment where to write next
                     // inData[index] = '\0'; // Null terminate the string

                    //We read from the sigfox module and put what it was read on the pc serial port
                    //Serial.write(mySerial.read());// we should get an OK,
                  }


     }
     dest=inData;




}

void ReadWisolTx(String &dest)
{
   char inData[20]; // Allocate some space for the string
   char inChar; // Where to store the character read
   byte index = 0; // Index into array; where to store the character

   while(mySerial.available()==0)
                  {
                     // we loop in here until the sigfox transmission ends.
                  }


      delay(200);
     if (mySerial.available()>0)
      {
              while(mySerial.available()>0)
                  {

                      inChar = mySerial.read(); // Read a character
                      inData[index] = inChar; // Store it
                      index++; // Increment where to write next
                     // inData[index] = '\0'; // Null terminate the string

                    //We read from the sigfox module and put what it was read on the pc serial port
                    //Serial.write(mySerial.read());// we should get an OK,
                  }


     }
     dest=inData;




}
void ReadWisolTemp()
{
  //same function but on this one we put the temperature data on the variable
  //wtemp at the end.
   char inData[5]; // Allocate some space for the string
   char inChar; // Where to store the character read
   static char tempchar[5];
   byte index = 0; // Index into array; where to store the character


   delay(200);

     if (mySerial.available()>0)
      {
              while(mySerial.available()>0)
                  {

                      inChar = mySerial.read(); // Read a character
                      inData[index] = inChar; // Store it
                      index++; // Increment where to write next
                      delay(3);

                  }


     }


     strncpy(wtemp,inData,5);// put temp data on wtemp variable.


}
