#include <SoftwareSerial.h>
SoftwareSerial mySerial(D2  , D3);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
 
if (Serial.available()>0)
  switch(Serial.read())
  {
   case 's':
      SendMessage();
      delay(1000);
      StartCall();
      delay(1000);
      break;
    case 'r':
      RecieveMessage();
     break;
     case 'c':
      StartCall();
     break;
 }
 

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  Serial.println("AT+CMGF=1"); 
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918767968868\"\r"); // Replace x with mobile number  make a variable for phone number
  delay(1000);
  mySerial.println("TEST");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 

void StartCall()
{
  mySerial.print("ATD+918767968868;");

  delay(1000);
}

 void RecieveMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  Serial.println("AT+CMGF=1"); 
  mySerial.println("AT+CMGL=\"ALL\""); // AT Command to receive a live SMS
  delay(1000);
 }
