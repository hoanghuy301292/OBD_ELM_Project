#include "NexComponent.h"
#include "Nex_ELM_Combine.h"
#include "TimerOne.h"

#define TEST_LIB 
#define TIME_INTERVAL 5000
char b;
String a;
unsigned long current_millis = 0;
bool b_readingDTC = false;
bool b_clearingDTC = false;
bool b_updatingScreen = false;
volatile bool b_readDTCRequest = false;
volatile bool b_clearDTCRequest = false;

void setup() {
  pinModeTotal();
  nexInit();
  nexRegisterCbk();
  myELM.ELM327_init();

}

void loop() {

  nexLoop(nex_listen_list);

  if((unsigned long)(millis() - current_millis) > TIME_INTERVAL )
  {
    nexUpdateDataDisplay();
    current_millis = millis();
  }

  if(b_readDTCRequest)
  {
    nexUpdateReadDTCs();
    b_readDTCRequest = false;
  }

  if(b_clearDTCRequest)
  {
    nexClearAndUpdateReadDTCs();
    b_clearDTCRequest = false;
  }

  

#ifndef TEST_LIB
/************************ This is for testing input command by typing (+ ELM lib) **********************/
  if (Serial.available())
  {
    b = Serial.read();

    if(b != char(13))
    {
      a = a + b;
    }
    else
    {
      if(a == FIND_DTCs)
      {
        Serial.println("Find DTC");
        Serial.println(myELM.getDTCs());
      }
      else if(a == "a")
      {
        nexUpdateDataDisplay();
        nexUpdateReadDTCs();
      }
      else
      {
        Serial.println(myELM.get(a));
      }
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
  elmSerial.flush();
  if (elmSerial.available()>0)
  {
    Serial.print(char(elmSerial.read()));
  }
/************************ This is for testing input command by typing **********************/
#endif
}