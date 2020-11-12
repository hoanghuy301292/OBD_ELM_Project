#include "NexComponent.h"
#include "NexWriteData.h"
#include "GlobalVar.h"
// Nextion Objects
// (page id, component id, component name)
NexDSButton b1  = NexDSButton(2,  1,  "cb1");
NexDSButton b2  = NexDSButton(2,  2,  "cb2");
NexDSButton b3  = NexDSButton(2,  3,  "cb3");
NexDSButton b4  = NexDSButton(2,  4,  "cb4");
NexDSButton b5  = NexDSButton(2,  5,  "cb5");
NexDSButton b6  = NexDSButton(2,  6,  "cb6");
NexDSButton b7  = NexDSButton(2,  7,  "cb7");
NexDSButton b8  = NexDSButton(2,  8,  "cb8");
NexDSButton b9  = NexDSButton(2,  9,  "cb9");
NexDSButton b10 = NexDSButton(2, 10, "cb10");
NexDSButton b11 = NexDSButton(2, 11, "cb11");
NexDSButton b12 = NexDSButton(2, 12, "cb12");
NexDSButton b13 = NexDSButton(2, 13, "cb13");
NexDSButton b14 = NexDSButton(2, 14, "cb14");
NexDSButton b15 = NexDSButton(2, 15, "cb15");
NexDSButton b16 = NexDSButton(2, 16, "cb16");
NexDSButton b17 = NexDSButton(3,  1, "cb17");
NexDSButton b18 = NexDSButton(3,  2, "cb18");
NexDSButton b19 = NexDSButton(3,  3, "cb19");
NexDSButton b20 = NexDSButton(3,  4, "cb20");
NexDSButton b21 = NexDSButton(3,  5, "cb21");
NexDSButton b22 = NexDSButton(3,  6, "cb22");
NexDSButton b23 = NexDSButton(3,  7, "cb23");
NexDSButton b24 = NexDSButton(3,  8, "cb24");
NexDSButton b25 = NexDSButton(3,  9, "cb25");
NexDSButton b26 = NexDSButton(3, 10, "cb26");
NexDSButton b27 = NexDSButton(3, 11, "cb27");
NexDSButton b28 = NexDSButton(3, 12, "cb28");
NexDSButton b29 = NexDSButton(3, 13, "cb29");
NexDSButton b30 = NexDSButton(3, 14, "cb30");
NexDSButton b31 = NexDSButton(3, 15, "cb31");
NexDSButton b32 = NexDSButton(3, 16, "cb32");
NexDSButton b33 = NexDSButton(4,  1, "cb33");
NexDSButton b34 = NexDSButton(4,  2, "cb34");
NexDSButton b35 = NexDSButton(4,  3, "cb35");
NexDSButton b36 = NexDSButton(4,  4, "cb36");
NexDSButton b37 = NexDSButton(4,  5, "cb37");
NexDSButton b38 = NexDSButton(4,  6, "cb38");
NexDSButton b39 = NexDSButton(4,  7, "cb39");
NexDSButton b40 = NexDSButton(4,  8, "cb40");

NexButton r1 = NexButton(2, 17, "r1");
NexButton c1 = NexButton(2, 18, "c1");
NexButton r2 = NexButton(3, 17, "r2");
NexButton c2 = NexButton(3, 18, "c2");
NexButton r3 = NexButton(4,  9, "r3");
NexButton c3 = NexButton(4, 10, "c3");

NexNumber n20 = NexNumber(2, 24, "n0");
NexNumber n21 = NexNumber(2, 28, "n1");
NexNumber n22 = NexNumber(2, 32, "n2");
NexNumber n23 = NexNumber(2, 26, "n3");
NexNumber n30 = NexNumber(3, 25, "n0");
NexNumber n31 = NexNumber(3, 26, "n1");
NexNumber n32 = NexNumber(3, 31, "n2");
NexNumber n33 = NexNumber(3, 32, "n3");
NexNumber n40 = NexNumber(4, 17, "n0");
NexNumber n41 = NexNumber(4, 18, "n1");
NexNumber n42 = NexNumber(4, 23, "n2");
NexNumber n43 = NexNumber(4, 21, "n3");

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
  &r1,
  &r2,
  &r3,
  &c1,
  &c2,
  &c3,
  NULL
};

void b1PushCallback(void *ptr) {
    uint32 value;
    b1.getValue(&value);
    digitalWrite(PIN_CB1, value);
}

void b2PushCallback(void *ptr) {
    uint32 value;
    b2.getValue(&value);
    digitalWrite(PIN_CB2, value);
}

void b3PushCallback(void *ptr) {
    uint32 value;
    b3.getValue(&value);
    digitalWrite(PIN_CB3, value);
}

void b4PushCallback(void *ptr) {
    uint32 value;
    b4.getValue(&value);
    digitalWrite(PIN_CB4, value);
}

void b5PushCallback(void *ptr) {
    uint32 value;
    b5.getValue(&value);
    digitalWrite(PIN_CB5, value);
}

void b6PushCallback(void *ptr) {
    uint32 value;
    b6.getValue(&value);
    digitalWrite(PIN_CB6, value);
}

void b7PushCallback(void *ptr) {
    uint32 value;
    b7.getValue(&value);
    digitalWrite(PIN_CB7, value);
}

void b8PushCallback(void *ptr) {
    uint32 value;
    b8.getValue(&value);
    digitalWrite(PIN_CB8, value);
}

void b9PushCallback(void *ptr) {
    uint32 value;
    b9.getValue(&value);
    digitalWrite(PIN_CB9, value);
}

void b10PushCallback(void *ptr) {
    uint32 value;
    b10.getValue(&value);
    digitalWrite(PIN_CB10, value);
}

void b11PushCallback(void *ptr) {
    uint32 value;
    b11.getValue(&value);
    digitalWrite(PIN_CB11, value);
}

void b12PushCallback(void *ptr) {
    uint32 value;
    b12.getValue(&value);
    digitalWrite(PIN_CB12, value);
}

void b13PushCallback(void *ptr) {
    uint32 value;
    b13.getValue(&value);
    digitalWrite(PIN_CB13, value);
}

void b14PushCallback(void *ptr) {
    uint32 value;
    b14.getValue(&value);
    digitalWrite(PIN_CB14, value);
}

void b15PushCallback(void *ptr) {
    uint32 value;
    b15.getValue(&value);
    digitalWrite(PIN_CB15, value);
}

void b16PushCallback(void *ptr) {
    uint32 value;
    b16.getValue(&value);
    digitalWrite(PIN_CB16, value);
}

void b17PushCallback(void *ptr) {
    uint32 value;
    b17.getValue(&value);
    digitalWrite(PIN_CB17, value);
}

void b18PushCallback(void *ptr) {
    uint32 value;
    b18.getValue(&value);
    digitalWrite(PIN_CB18, value);
}

void b19PushCallback(void *ptr) {
    uint32 value;
    b19.getValue(&value);
    digitalWrite(PIN_CB19, value);
}

void b20PushCallback(void *ptr) {
    uint32 value;
    b20.getValue(&value);
    digitalWrite(PIN_CB20, value);
}

void b21PushCallback(void *ptr) {
    uint32 value;
    b21.getValue(&value);
    digitalWrite(PIN_CB21, value);
}

void b22PushCallback(void *ptr) {
    uint32 value;
    b22.getValue(&value);
    digitalWrite(PIN_CB22, value);
}

void b23PushCallback(void *ptr) {
    uint32 value;
    b23.getValue(&value);
    digitalWrite(PIN_CB23, value);
}

void b24PushCallback(void *ptr) {
    uint32 value;
    b24.getValue(&value);
    digitalWrite(PIN_CB24, value);
}

void b25PushCallback(void *ptr) {
    uint32 value;
    b25.getValue(&value);
    digitalWrite(PIN_CB25, value);
}

void b26PushCallback(void *ptr) {
    uint32 value;
    b26.getValue(&value);
    digitalWrite(PIN_CB26, value);
}

void b27PushCallback(void *ptr) {
    uint32 value;
    b27.getValue(&value);
    digitalWrite(PIN_CB27, value);
}

void b28PushCallback(void *ptr) {
    uint32 value;
    b28.getValue(&value);
    digitalWrite(PIN_CB28, value);
}

void b29PushCallback(void *ptr) {
    uint32 value;
    b29.getValue(&value);
    digitalWrite(PIN_CB29, value);
}

void b30PushCallback(void *ptr) {
    uint32 value;
    b30.getValue(&value);
    digitalWrite(PIN_CB30, value);
}

void b31PushCallback(void *ptr) {
    uint32 value;
    b31.getValue(&value);
    digitalWrite(PIN_CB31, value);
}

void b32PushCallback(void *ptr) {
    uint32 value;
    b32.getValue(&value);
    digitalWrite(PIN_CB32, value);
}

void b33PushCallback(void *ptr) {
    uint32 value;
    b33.getValue(&value);
    digitalWrite(PIN_CB33, value);
}

void b34PushCallback(void *ptr) {
    uint32 value;
    b34.getValue(&value);
    digitalWrite(PIN_CB34, value);
}

void b35PushCallback(void *ptr) {
    uint32 value;
    b35.getValue(&value);
    digitalWrite(PIN_CB35, value);
}

void b36PushCallback(void *ptr) {
    uint32 value;
    b36.getValue(&value);
    digitalWrite(PIN_CB36, value);
}

void b37PushCallback(void *ptr) {
    uint32 value;
    b37.getValue(&value);
    digitalWrite(PIN_CB37, value);
}

void b38PushCallback(void *ptr) {
    uint32 value;
    b38.getValue(&value);
    digitalWrite(PIN_CB38, value);
}

void b39PushCallback(void *ptr) {
    uint32 value;
    b39.getValue(&value);
    digitalWrite(PIN_CB39, value);
}

void b40PushCallback(void *ptr) {
    uint32 value;
    b40.getValue(&value);
    digitalWrite(PIN_CB40, value);
}

void r1PushCallback(void *ptr) {
    NexWriteData(g_n0Val, g_n1Val, g_n2Val, g_n3Val);
}

void r2PushCallback(void *ptr) {
    NexWriteData(g_n0Val, g_n1Val, g_n2Val, g_n3Val);
}

void r3PushCallback(void *ptr) {
    NexWriteData(g_n0Val, g_n1Val, g_n2Val, g_n3Val);
}

void c1PopCallback(void *ptr) {
  Serial.println("clear1");
}

void c2PopCallback(void *ptr) {
  Serial.println("clear2");
}

void c3PopCallback(void *ptr) {
  Serial.println("clear3");
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

  r1.attachPush(r1PushCallback, &r1);
  r2.attachPush(r2PushCallback, &r2);
  r3.attachPush(r3PushCallback, &r3);
  c1.attachPop(c1PopCallback, &c1);
  c2.attachPop(c2PopCallback, &c2);
  c3.attachPop(c3PopCallback, &c3);

}