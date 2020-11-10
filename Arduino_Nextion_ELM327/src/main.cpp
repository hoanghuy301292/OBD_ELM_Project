#include "Nextion_screen.h"

void setup() {
  pinModeTotal();
  nexInit();
  elmSerial.begin(38400);
  nexRegisterCbk();
}

void loop() {

  nexLoop(nex_listen_list);

  if(elmSerial.available()>0)
  {
    Serial.print(char(elmSerial.read()));
  }
}