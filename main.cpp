#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "SerialPort.h"

using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM12";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

int main()
{
  SerialPort arduino(port_name);
  if (arduino.isConnected()){
  	cout << "Connection Established" << endl;
  	MessageBox( 0, "Connection with arduino is Established", "Connection Established", 0 );
  } 
  else{
	  cout << "ERROR, check port name";
	  MessageBoxW(NULL, L"Connection Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
 }
  
  while (arduino.isConnected()){
    //Check if data has been read or not
    int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
    //prints out data
    puts(incomingData);
    //wait a bit
    Sleep(1000);
  }
}
