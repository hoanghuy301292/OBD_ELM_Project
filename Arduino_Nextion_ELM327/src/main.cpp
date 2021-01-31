#include "NexComponent.h"
#include "elm327.h"

#define TEST_LIB

ELM327 myELM;
char b;
String a;

void setup() {

  pinModeTotal();
  nexInit();
  nexRegisterCbk();
  myELM.ELM327_init();
}

void loop() {

  nexLoop(nex_listen_list);

#ifdef TEST_LIB
/************************ This is for testing input command by typing (+ ELM lib) **********************/
  if (Serial.available())
  {
    b = Serial.read();
    if(b != char(13)){
      a = a + b;
    }
    else{
      // Serial.println(a);
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