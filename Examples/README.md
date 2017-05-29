
# Arduino Examples
I use this code to test the boards. 

We use the PC serial port on the normal arduino UART pins and for the AltSoftSerial we use 9 for TX and 8 for RX

I am using the [AltSoftSerial Library](https://github.com/PaulStoffregen/AltSoftSerial), please use that one because it is already tested

The first file called Wisol_Software_Serial_Local is a simple program with the following functionality  :
-Get ID
-Get PAC
-Get Temperatue
-Send a Local frame
-Sleep
-Wake up and Loop


The next file called Wisol_Software_Serial_Local_RX is used to test the RX function. The program will just wait for incoming messages and display them on the PC Serial Port
