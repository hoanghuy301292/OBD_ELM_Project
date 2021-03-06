/*
  ELM327.cpp - Library communicating with an ELM327 device over serial
  Created by Evan d'Entremont, March 2016
*/

#include "elm327.h"

String ELM327::getDTCs(void)
{
  String str_rawDTCs = "";
  String str_resultDTCs = "";
  
  uint8 uc_lenOfRawDTCs = 0;
  uint8 uc_numOfDTCs = 0;

  str_rawDTCs = get(FIND_DTCs);
  // Serial.println("Do dai Ma loi sau khi xu li lan 1:");
  // Serial.println(str_rawDTCs.length());
  if(str_rawDTCs.length() < 6)
  {
      str_resultDTCs = str_rawDTCs;
  }
  else
  {
      uc_lenOfRawDTCs = str_rawDTCs.length();
      uc_numOfDTCs = uc_lenOfRawDTCs / 4;

      String *p_strDTC = new String[uc_numOfDTCs];

      for(uint8 i = 0; i < uc_numOfDTCs; i++)
      {
        p_strDTC[i] = str_rawDTCs.substring(4*i, 4*(i+1));
        convertDTC((p_strDTC[i]));
        str_resultDTCs = str_resultDTCs + p_strDTC[i];
      }

      delete p_strDTC;
  }

  return str_resultDTCs;
}

void ELM327:: ELM327_init(void)
{
  String result;

  elmSerial.begin(38400);
  delay(TIME_FOR_CONNECTION);

Retry:
  result = query("ATI");
  // Should abstract this.
  if ( strstr(result.c_str(), "ELM327"))
  {
    // Great. We're connected.
    Serial.println("ELM connected");
  }
  else{
    delay(TIME_FOR_CONNECTION);
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

  if (command == FIND_DTCs || command == CLEAR_DTCs)
  {
    delay(500);
  }
  else{
    delay(100);
  }
  // Spinlock's are perfectly valid :D
  while(spinlock){
    if(millis() > (time + TIME_OUT)){
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
    inData = elmSerial.read();
    inChar = char(inData);
    inString = inString + inChar;
    delay(2);
    if ( strstr(inString.c_str(),"SEARCHING") != '\0' && firstDelayFlag == TRUE ){
      delay(TIME_FOR_SEARCHING);
      firstDelayFlag = FALSE;
    }
  }
  /* Just for debugging: print the whole response for a query - Serial.println(inString); */
  // Serial.println(inString);
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

  if (command == CLEAR_DTCs)
  {
    inString ="";
  }

/* Below code is used for testing data extraction from response message */
/* Remove this when testing with a real car*/
#if 0
  if ((String)PID_RPM == command)
  {
    inString = "     ....01 0C41 0C 1E FF >";
  }
  else if ((String)PID_COOLANT_TEMP == command)
  {
    inString = "  ...    01 0541 05 5C >   ";
  }
  else if ((String)PID_THROTTLE == command)
  {
    inString = "..    ..** 01 1141 11 30 ....>";
  }
  else if ((String)PID_FUEL_INJECTION_TIMING == command)
  {
    inString = "01 5D41 5D 10 30 >";
  }
  else if ((String)FIND_DTCs == command)
  {
    inString = "   ...0747 10 23 43 10 C1 79 >";
  }
    else if ((String)PID_BAT_VOL == command)
  {
    inString = "13.1 V";
  }
  else
  {

  }
#endif
  
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

  if(strstr(result.c_str(), "UNABLE TO CONNECT"))
  {
    return "UNABLE TO CONNECT";
  }

  //Check which OBD Command was sent and calculate VALUE
  //Calculate RPM I.E Returned bytes wil be 41 0C 1B E0
  if (command == PID_RPM)
  {
    pos = 0;
    pos = result.indexOf(RES_PID_RPM, pos);
    result = result.substring(pos + 6, result.length());

    WorkingString = result.substring(0, 2);
    A = strtol(WorkingString.c_str(), NULL, 16);

    WorkingString = result.substring(3, 5);
    B = strtol(WorkingString.c_str(), NULL, 16);
   
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
  else if (command == FIND_DTCs)
  {
    pos = 0;
    pos = result.indexOf(RES_FIND_DTCs, pos);
    result = result.substring(pos + 5, result.length());
    result.replace(" ","");
    result.replace(">","");
    return result; 
  }

  else{
    return "Not Implemented";
  }


}
