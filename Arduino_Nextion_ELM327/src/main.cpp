#include "NexComponent.h"
#include "ELMduino.h"

// #define TEST_LIB
#define ELM_PORT  Serial3

ELM327 myELM327;

uint32_t rpm = 0;

char b;
String a;

void printError();

void setup() {

  pinModeTotal();
  nexInit();
  nexRegisterCbk();
  
  ELM_PORT.begin(38400);
  if (!myELM327.begin(ELM_PORT))
  {
    Serial.println("Couldn't connect to OBD scanner");
    while (1);
  }

  Serial.println("Connected to ELM327");
}

void loop() {

  nexLoop(nex_listen_list);

  float tempRPM = myELM327.rpm();

  if (myELM327.status == ELM_SUCCESS)
  {
    rpm = (uint32_t)tempRPM;
    Serial.print("RPM: "); Serial.println(rpm);
  }
  else
    printError();

#ifdef TEST_LIB
/************************ This is for testing input command by typing (+ ELM lib) **********************/
  if (Serial.available())
  {
    b = Serial.read();
    if(b != char(13)){
      a = a + b;
    }
    else{

      Serial.println(myELM.get(a));
      a = "";
    }
  }
/************************ This is for testing input command by typing **********************/
#else
/************************ This is for testing input command by typing (without ELM lib) **********************/
  if (Serial.available())
  {
    b = Serial.read();
    if(b != char(13)){
      a = a + b;
    }
    else{
      Serial.println(a);
      elmSerial.println(a);
      a = "";
    }
  }

  if (elmSerial.available()>0)
  {
    Serial.print(char(elmSerial.read()));
  }
/************************ This is for testing input command by typing **********************/
#endif
}

void printError()
{
  Serial.print("Received: ");
  for (byte i = 0; i < myELM327.recBytes; i++)
    Serial.write(myELM327.payload[i]);
  Serial.println();
  
  if (myELM327.status == ELM_SUCCESS)
    Serial.println(F("\tELM_SUCCESS"));
  else if (myELM327.status == ELM_NO_RESPONSE)
    Serial.println(F("\tERROR: ELM_NO_RESPONSE"));
  else if (myELM327.status == ELM_BUFFER_OVERFLOW)
    Serial.println(F("\tERROR: ELM_BUFFER_OVERFLOW"));
  else if (myELM327.status == ELM_UNABLE_TO_CONNECT)
    Serial.println(F("\tERROR: ELM_UNABLE_TO_CONNECT"));
  else if (myELM327.status == ELM_NO_DATA)
    Serial.println(F("\tERROR: ELM_NO_DATA"));
  else if (myELM327.status == ELM_STOPPED)
    Serial.println(F("\tERROR: ELM_STOPPED"));
  else if (myELM327.status == ELM_TIMEOUT)
    Serial.println(F("\tERROR: ELM_TIMEOUT"));
  else if (myELM327.status == ELM_TIMEOUT)
    Serial.println(F("\tERROR: ELM_GENERAL_ERROR"));

  delay(100);
}

