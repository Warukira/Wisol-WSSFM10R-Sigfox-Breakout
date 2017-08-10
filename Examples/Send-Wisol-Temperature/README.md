## This program will send the Temperatue of the Wisol sensor over Sigfox

Some things to know:
* Always use this command AT$RC and wait for the OK before sending the Sigfox frame.
* The wisol module receives bytes formated as string AT$SF=AA 
* The Temperatues is received as Chars so we need to convert it to an Int so you can send the data in 2 bytes
* I use ATOI to make the conversion.
* To add the Integer to a string I use String(data,HEX) to put the integer into a byte string.
