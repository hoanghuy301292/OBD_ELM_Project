#include "Nextion_screen.h"

// Nextion Objects
// (page id, component id, component name)
NexButton b1  = NexButton(2,  1,  "cb1");
NexButton b2  = NexButton(2,  2,  "cb2");
NexButton b3  = NexButton(2,  3,  "cb3");
NexButton b4  = NexButton(2,  4,  "cb4");
NexButton b5  = NexButton(2,  5,  "cb5");
NexButton b6  = NexButton(2,  6,  "cb6");
NexButton b7  = NexButton(2,  7,  "cb7");
NexButton b8  = NexButton(2,  8,  "cb8");
NexButton b9  = NexButton(2,  9,  "cb9");
NexButton b10 = NexButton(2, 10, "cb10");
NexButton b11 = NexButton(2, 11, "cb11");
NexButton b12 = NexButton(2, 12, "cb12");
NexButton b13 = NexButton(2, 13, "cb13");
NexButton b14 = NexButton(2, 14, "cb14");
NexButton b15 = NexButton(2, 15, "cb15");
NexButton b16 = NexButton(2, 16, "cb16");
NexButton b17 = NexButton(3,  1, "cb17");
NexButton b18 = NexButton(3,  2, "cb18");
NexButton b19 = NexButton(3,  3, "cb19");
NexButton b20 = NexButton(3,  4, "cb20");
NexButton b21 = NexButton(3,  5, "cb21");
NexButton b22 = NexButton(3,  6, "cb22");
NexButton b23 = NexButton(3,  7, "cb23");
NexButton b24 = NexButton(3,  8, "cb24");
NexButton b25 = NexButton(3,  9, "cb25");
NexButton b26 = NexButton(3, 10, "cb26");
NexButton b27 = NexButton(3, 11, "cb27");
NexButton b28 = NexButton(3, 12, "cb28");
NexButton b29 = NexButton(3, 13, "cb29");
NexButton b30 = NexButton(3, 14, "cb30");
NexButton b31 = NexButton(3, 15, "cb31");
NexButton b32 = NexButton(3, 16, "cb32");
NexButton b33 = NexButton(4,  1, "cb33");
NexButton b34 = NexButton(4,  2, "cb34");
NexButton b35 = NexButton(4,  3, "cb35");
NexButton b36 = NexButton(4,  4, "cb36");
NexButton b37 = NexButton(4,  5, "cb37");
NexButton b38 = NexButton(4,  6, "cb38");
NexButton b39 = NexButton(4,  7, "cb39");
NexButton b40 = NexButton(4,  8, "cb40");


NexNumber num = NexNumber(2, 25, "n0"); 

// Register objects to the touch event list
NexTouch *nex_listen_list[] = {
  &b1,
  &b2,
  &b3,
  &b4,
  &b5,
  &b6,
  &b7,
  &b8,
  &b9,
  &b10,
  &b11,
  &b12,
  &b13,
  &b14,
  &b15,
  &b16,
  &b17,
  &b18,
  &b19,
  &b20,
  &b21,
  &b22,
  &b23,
  &b24,
  &b25,
  &b26,
  &b27,
  &b28,
  &b29,
  &b30,
  &b31,
  &b32,
  &b33,
  &b34,
  &b35,
  &b36,
  &b37,
  &b38,
  &b39,
  &b40,
  NULL
};

void b1PushCallback(void *ptr) {
  digitalWrite(PIN_CB1, ON);
}

void b2PushCallback(void *ptr) {
  digitalWrite(PIN_CB2, ON);
}

void b3PushCallback(void *ptr) {
  digitalWrite(PIN_CB3, ON);
}

void b4PushCallback(void *ptr) {
  digitalWrite(PIN_CB4, ON);
}

void b5PushCallback(void *ptr) {
  digitalWrite(PIN_CB5, ON);
}

void b6PushCallback(void *ptr) {
  digitalWrite(PIN_CB6, ON);
}

void b7PushCallback(void *ptr) {
  digitalWrite(PIN_CB7, ON);
}

void b8PushCallback(void *ptr) {
  digitalWrite(PIN_CB8, ON);
}

void b9PushCallback(void *ptr) {
  digitalWrite(PIN_CB9, ON);
}

void b10PushCallback(void *ptr) {
  digitalWrite(PIN_CB10, ON);
}

void b11PushCallback(void *ptr) {
  digitalWrite(PIN_CB11, ON);
}

void b12PushCallback(void *ptr) {
  digitalWrite(PIN_CB12, ON);
}

void b13PushCallback(void *ptr) {
  digitalWrite(PIN_CB13, ON);
}

void b14PushCallback(void *ptr) {
  digitalWrite(PIN_CB14, ON);
}

void b15PushCallback(void *ptr) {
  digitalWrite(PIN_CB15, ON);
}

void b16PushCallback(void *ptr) {
  digitalWrite(PIN_CB16, ON);
}

void b17PushCallback(void *ptr) {
  digitalWrite(PIN_CB17, ON);
}

void b18PushCallback(void *ptr) {
  digitalWrite(PIN_CB18, ON);
}

void b19PushCallback(void *ptr) {
  digitalWrite(PIN_CB19, ON);
}

void b20PushCallback(void *ptr) {
  digitalWrite(PIN_CB20, ON);
}

void b21PushCallback(void *ptr) {
  digitalWrite(PIN_CB21, ON);
}

void b22PushCallback(void *ptr) {
  digitalWrite(PIN_CB22, ON);
}

void b23PushCallback(void *ptr) {
  digitalWrite(PIN_CB23, ON);
}

void b24PushCallback(void *ptr) {
  digitalWrite(PIN_CB24, ON);
}

void b25PushCallback(void *ptr) {
  digitalWrite(PIN_CB25, ON);
}

void b26PushCallback(void *ptr) {
  digitalWrite(PIN_CB26, ON);
}

void b27PushCallback(void *ptr) {
  digitalWrite(PIN_CB27, ON);
}

void b28PushCallback(void *ptr) {
  digitalWrite(PIN_CB28, ON);
}

void b29PushCallback(void *ptr) {
  digitalWrite(PIN_CB29, ON);
}

void b30PushCallback(void *ptr) {
  digitalWrite(PIN_CB30, ON);
}

void b31PushCallback(void *ptr) {
  digitalWrite(PIN_CB31, ON);
}

void b32PushCallback(void *ptr) {
  digitalWrite(PIN_CB32, ON);
}

void b33PushCallback(void *ptr) {
  digitalWrite(PIN_CB33, ON);
}

void b34PushCallback(void *ptr) {
  digitalWrite(PIN_CB34, ON);
}

void b35PushCallback(void *ptr) {
  digitalWrite(PIN_CB35, ON);
}

void b36PushCallback(void *ptr) {
  digitalWrite(PIN_CB36, ON);
}

void b37PushCallback(void *ptr) {
  digitalWrite(PIN_CB37, ON);
}

void b38PushCallback(void *ptr) {
  digitalWrite(PIN_CB38, ON);
}

void b39PushCallback(void *ptr) {
  digitalWrite(PIN_CB39, ON);
}

void b40PushCallback(void *ptr) {
  digitalWrite(PIN_CB40, ON);
}

void b1PopCallback(void *ptr) {
  digitalWrite(PIN_CB1, OFF);
}

void b2PopCallback(void *ptr) {
  digitalWrite(PIN_CB2, OFF);
}

void b3PopCallback(void *ptr) {
  digitalWrite(PIN_CB3, OFF);
}

void b4PopCallback(void *ptr) {
  digitalWrite(PIN_CB4, OFF);
}

void b5PopCallback(void *ptr) {
  digitalWrite(PIN_CB5, OFF);
}

void b6PopCallback(void *ptr) {
  digitalWrite(PIN_CB6, OFF);
}

void b7PopCallback(void *ptr) {
  digitalWrite(PIN_CB7, OFF);
}

void b8PopCallback(void *ptr) {
  digitalWrite(PIN_CB8, OFF);
}

void b9PopCallback(void *ptr) {
  digitalWrite(PIN_CB9, OFF);
}

void b10PopCallback(void *ptr) {
  digitalWrite(PIN_CB10, OFF);
}

void b11PopCallback(void *ptr) {
  digitalWrite(PIN_CB11, OFF);
}

void b12PopCallback(void *ptr) {
  digitalWrite(PIN_CB12, OFF);
}

void b13PopCallback(void *ptr) {
  digitalWrite(PIN_CB13, OFF);
}

void b14PopCallback(void *ptr) {
  digitalWrite(PIN_CB14, OFF);
}

void b15PopCallback(void *ptr) {
  digitalWrite(PIN_CB15, OFF);
}

void b16PopCallback(void *ptr) {
  digitalWrite(PIN_CB16, OFF);
}

void b17PopCallback(void *ptr) {
  digitalWrite(PIN_CB17, OFF);
}

void b18PopCallback(void *ptr) {
  digitalWrite(PIN_CB18, OFF);
}

void b19PopCallback(void *ptr) {
  digitalWrite(PIN_CB19, OFF);
}

void b20PopCallback(void *ptr) {
  digitalWrite(PIN_CB20, OFF);
}

void b21PopCallback(void *ptr) {
  digitalWrite(PIN_CB21, OFF);
}

void b22PopCallback(void *ptr) {
  digitalWrite(PIN_CB22, OFF);
}

void b23PopCallback(void *ptr) {
  digitalWrite(PIN_CB23, OFF);
}

void b24PopCallback(void *ptr) {
  digitalWrite(PIN_CB24, OFF);
}

void b25PopCallback(void *ptr) {
  digitalWrite(PIN_CB25, OFF);
}

void b26PopCallback(void *ptr) {
  digitalWrite(PIN_CB26, OFF);
}

void b27PopCallback(void *ptr) {
  digitalWrite(PIN_CB27, OFF);
}

void b28PopCallback(void *ptr) {
  digitalWrite(PIN_CB28, OFF);
}

void b29PopCallback(void *ptr) {
  digitalWrite(PIN_CB29, OFF);
}

void b30PopCallback(void *ptr) {
  digitalWrite(PIN_CB30, OFF);
}

void b31PopCallback(void *ptr) {
  digitalWrite(PIN_CB31, OFF);
}

void b32PopCallback(void *ptr) {
  digitalWrite(PIN_CB32, OFF);
}

void b33PopCallback(void *ptr) {
  digitalWrite(PIN_CB33, OFF);
}

void b34PopCallback(void *ptr) {
  digitalWrite(PIN_CB34, OFF);
}

void b35PopCallback(void *ptr) {
  digitalWrite(PIN_CB35, OFF);
}

void b36PopCallback(void *ptr) {
  digitalWrite(PIN_CB36, OFF);
}

void b37PopCallback(void *ptr) {
  digitalWrite(PIN_CB37, OFF);
}

void b38PopCallback(void *ptr) {
  digitalWrite(PIN_CB38, OFF);
}

void b39PopCallback(void *ptr) {
  digitalWrite(PIN_CB39, OFF);
}

void b40PopCallback(void *ptr) {
  digitalWrite(PIN_CB40, OFF);
}

void nexRegisterCbk( void )
{
  // Register the push/pop event callback function
  b1.attachPush(b1PushCallback, &b1);
  b2.attachPush(b2PushCallback, &b2);
  b3.attachPush(b3PushCallback, &b3);
  b4.attachPush(b4PushCallback, &b4);
  b5.attachPush(b5PushCallback, &b5);
  b6.attachPush(b6PushCallback, &b6);
  b7.attachPush(b7PushCallback, &b7);
  b8.attachPush(b8PushCallback, &b8);
  b9.attachPush(b9PushCallback, &b9);
  b10.attachPush(b10PushCallback, &b10);
  b11.attachPush(b11PushCallback, &b11);
  b12.attachPush(b12PushCallback, &b12);
  b13.attachPush(b13PushCallback, &b13);
  b14.attachPush(b14PushCallback, &b14);
  b15.attachPush(b15PushCallback, &b15);
  b16.attachPush(b16PushCallback, &b16);
  b17.attachPush(b17PushCallback, &b17);
  b18.attachPush(b18PushCallback, &b18);
  b19.attachPush(b19PushCallback, &b19);
  b20.attachPush(b20PushCallback, &b20);
  b21.attachPush(b21PushCallback, &b21);
  b22.attachPush(b22PushCallback, &b22);
  b23.attachPush(b23PushCallback, &b23);
  b24.attachPush(b24PushCallback, &b24);
  b25.attachPush(b25PushCallback, &b25);
  b26.attachPush(b26PushCallback, &b26);
  b27.attachPush(b27PushCallback, &b27);
  b28.attachPush(b28PushCallback, &b28);
  b29.attachPush(b29PushCallback, &b29);
  b30.attachPush(b30PushCallback, &b30);
  b31.attachPush(b31PushCallback, &b31);
  b32.attachPush(b32PushCallback, &b32);
  b33.attachPush(b33PushCallback, &b33);
  b34.attachPush(b34PushCallback, &b34);
  b35.attachPush(b35PushCallback, &b35);
  b36.attachPush(b36PushCallback, &b36);
  b37.attachPush(b37PushCallback, &b37);
  b38.attachPush(b38PushCallback, &b38);
  b39.attachPush(b39PushCallback, &b39);
  b40.attachPush(b40PushCallback, &b40);

  b1.attachPop(b1PopCallback, &b1);
  b2.attachPop(b2PopCallback, &b2);
  b3.attachPop(b3PopCallback, &b3);
  b4.attachPop(b4PopCallback, &b4);
  b5.attachPop(b5PopCallback, &b5);
  b6.attachPop(b6PopCallback, &b6);
  b7.attachPop(b7PopCallback, &b7);
  b8.attachPop(b8PopCallback, &b8);
  b9.attachPop(b9PopCallback, &b9);
  b10.attachPop(b10PopCallback, &b10);
  b11.attachPop(b11PopCallback, &b11);
  b12.attachPop(b12PopCallback, &b12);
  b13.attachPop(b13PopCallback, &b13);
  b14.attachPop(b14PopCallback, &b14);
  b15.attachPop(b15PopCallback, &b15);
  b16.attachPop(b16PopCallback, &b16);
  b17.attachPop(b17PopCallback, &b17);
  b18.attachPop(b18PopCallback, &b18);
  b19.attachPop(b19PopCallback, &b19);
  b20.attachPop(b20PopCallback, &b20);
  b21.attachPop(b21PopCallback, &b21);
  b22.attachPop(b22PopCallback, &b22);
  b23.attachPop(b23PopCallback, &b23);
  b24.attachPop(b24PopCallback, &b24);
  b25.attachPop(b25PopCallback, &b25);
  b26.attachPop(b26PopCallback, &b26);
  b27.attachPop(b27PopCallback, &b27);
  b28.attachPop(b28PopCallback, &b28);
  b29.attachPop(b29PopCallback, &b29);
  b30.attachPop(b30PopCallback, &b30);
  b31.attachPop(b31PopCallback, &b31);
  b32.attachPop(b32PopCallback, &b32);
  b33.attachPop(b33PopCallback, &b33);
  b34.attachPop(b34PopCallback, &b34);
  b35.attachPop(b35PopCallback, &b35);
  b36.attachPop(b36PopCallback, &b36);
  b37.attachPop(b37PopCallback, &b37);
  b38.attachPop(b38PopCallback, &b38);
  b39.attachPop(b39PopCallback, &b39);
  b40.attachPop(b40PopCallback, &b40);
}