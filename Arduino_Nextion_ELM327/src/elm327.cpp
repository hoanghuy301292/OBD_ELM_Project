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
  if (result.substring(0,6)=="ELM327"){
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
  }

  inString.replace(command,"");
  inString.replace(">","");
  inString.replace("OK","");

  // Some of these look like errors that ought to be handled..
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
//   int ByteCount=0;
  long A;
  int B;
  String WorkingString="";

  //Check which OBD Command was sent and calculate VALUE
  //Calculate RPM I.E Returned bytes wil be 41 0C 1B E0
  if (command == PID_RPM){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    WorkingString = result.substring(11,13);
    B = strtol(WorkingString.c_str(),NULL,0);

   DisplayValue = ((A * 256)+B)/4;
   return String(DisplayValue) + " rpm";
  }

  //Calculate Vehicle speed
  // I.E Returned bytes wil be 41 0C 1B E0
  else if (command == PID_SPEED){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " km/h";
  }

  //Coolant Temp
  else if (command == PID_COOLANT_TEMP){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " C";
  }

  //IAT Temp
  else if (command == PID_IAT_TEMP){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " C";
  }

  //Air flow Rate
  else if (command == PID_AIR_FLOW_RATE){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    WorkingString = result.substring(11,13);
    B = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = ((A * 256)+B)/100;
    return String(DisplayValue) + " g/s";
  }

  //Ambient Temp
  else if (command == PID_AMBIENT_TEMP){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " C";
  }

  //Throttle position
  else if (command == PID_THROTTLE){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " %";
  }

  //Barometric pressure
  else if (command == PID_BAROMETRIC_PRESSURE){
    WorkingString = result.substring(7,9);
    A = strtol(WorkingString.c_str(),NULL,0);
    DisplayValue = A;
    return String(DisplayValue) + " kpa";
  }

  else{
    return "Not Implemented";
  }


}
