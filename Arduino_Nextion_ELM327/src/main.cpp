#include "NexComponent.h"

void setup() {
  pinModeTotal();
  nexInit();
  elmSerial.begin(38400);
  nexRegisterCbk();
}

void loop() {

  nexLoop(nex_listen_list);

}