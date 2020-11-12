#include "NexComponent.h"
#include "elm327.h"

ELM327 myELM;

void setup() {

  pinModeTotal();
  nexInit();
  nexRegisterCbk();
  myELM.ELM327_init();
  Serial.println(myELM.get("ati"));
}

void loop() {

  nexLoop(nex_listen_list);

}