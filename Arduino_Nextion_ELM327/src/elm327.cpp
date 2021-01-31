/*
  ELM327.cpp - Library communicating with an ELM327 device over serial
  Created by Evan d'Entremont, March 2016
*/

#include "elm327.h"

void ELM327:: ELM327_init(void)
{
  String result;

  elmSerial.begin(38400);
  delay(DELAYLENGTH);

Retry:
  result = query("ATI");
  // Should abstract this.
  if ( strstr(result.c_str(), "ELM327"))
  {
    // Great. We're connected.
    Serial.println("ELM connected");
  }
  else{
    delay(DELAYLENGTH);
    // This really ought to return on failure.
    goto Retry;
  }
}

// This is a wrapper around querying the device and
// processing the result.
String ELM327::get(String command){
  return process(command, query(command));
}

String ELM327::query(String command){
  String inString = "";
  byte inData = 0;
  char inChar = 0;
  bool spinlock = true;
  unsigned long time;
  elmSerial.println(command);
  time = millis();
  bool firstDelayFlag = TRUE;

  // Spinlock's are perfectly valid :D
  while(spinlock){
    if(millis() > (time + 4000)){
      // TODO: Handle this condition in process();
      return "Timeout";
    }
    else if(elmSerial.available()){
      spinlock = false;
    }
  }
  while(elmSerial.available() > 0){
    inData = 0;
    inChar = 0;
    byte inData = elmSerial.read();
    char inChar = char(inData);
    inString = inString + inChar;
    delay(2);
    if ( strstr(inString.c_str(),"SEARCHING") != '\0' && firstDelayFlag == TRUE ){
      delay(2000);
      firstDelayFlag = FALSE;
    }
  }
  Serial.println(inString);
  inString.replace(command,"");
  inString.replace(">","");
  inString.replace("OK","");

  // Some of these look like errors that ought to be handled..
  inString.replace("...","");
  inString.replace("STOPPED","");
  inString.replace("SEARCHING","");
  inString.replace("NO DATA","");
  inString.replace("?","");
  inString.replace(",","");

  return inString;
}

// TODO move this into it's own class, PID's arent inherently ELM327 related.
// Should be removing spaces and removing the first 4 characters first. 
// the 41 0C for example.. is the CAN bus ID
String ELM327::process(String command, String result){

  long DisplayValue;
  long A;
  int B;
  String WorkingString="";
  size_t pos;

  //Check which OBD Command was sent and calculate VALUE
  //Calculate RPM I.E Returned bytes wil be 41 0C 1B E0
  if (command == PID_RPM)
  {
    pos = 0;
    pos = result.indexOf(RES_PID_RPM, pos);
    result = result.substring(pos + 6, result.length());

    WorkingString = result.substring(0, 2);
    // Serial.println(WorkingString);
    A = strtol(WorkingString.c_str(), NULL, 16);
    // Serial.println(A);

    WorkingString = result.substring(3, 5);
    // Serial.println(WorkingString);
    B = strtol(WorkingString.c_str(), NULL, 16);
    // Serial.println(B);
   
    DisplayValue = ( ( A * 256 ) + B ) / 4;
    return String(DisplayValue) + " rpm";
  }
  //Coolant Temp
  else if (command == PID_COOLANT_TEMP)
  {
    pos = 0;
    pos = result.indexOf(RES_PID_COOLANT_TEMP, pos);
    result = result.substring(pos + 6, result.length());

    WorkingString = result.substring(0, 2);
    A = strtol(WorkingString.c_str(), NULL, 16) ;
    DisplayValue = A - 40;
    return String(DisplayValue) + " C";
  }
  //Throttle position
  else if (command == PID_THROTTLE)
  {
    pos = 0;
    pos = result.indexOf(RES_PID_THROTTLE, pos);
    result = result.substring(pos + 6, result.length());

    WorkingString = result.substring(0, 2);
    A = strtol(WorkingString.c_str(), NULL, 16);
    DisplayValue = ( 100 * A ) / 255;
    return String(DisplayValue) + " %";
  }
  //Fuel injection timing
  else if (command == PID_FUEL_INJECTION_TIMING)
  {
    pos = 0;
    pos = result.indexOf(RES_PID_FUEL_INJECTION_TIMING, pos);
    result = result.substring(pos + 6, result.length());

    WorkingString = result.substring(0, 2);
    A = strtol(WorkingString.c_str(), NULL, 16);

    WorkingString = result.substring(3, 5);
    B = strtol(WorkingString.c_str(), NULL, 16);

    DisplayValue = ( 256 * A + B ) / 128 - 210;
    return String(DisplayValue);
  }
  //Batery voltage
  else if (command == PID_BAT_VOL)
  {
    return result;
  }

  else{
    return "Not Implemented";
  }


}
