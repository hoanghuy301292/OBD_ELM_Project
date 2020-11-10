#ifndef  _NEXTION_SCREEN_H
#define  _NEXTION_SCREEN_H

#include "Nextion.h"
#include "Arduino_HW.h"

extern NexButton b1;
extern NexButton b2;
extern NexButton b3;
extern NexButton b4;
extern NexButton b5;
extern NexButton b6;
extern NexButton b7;
extern NexButton b8;
extern NexButton b9;
extern NexButton b10;
extern NexButton b11;
extern NexButton b12;
extern NexButton b13;
extern NexButton b14;
extern NexButton b15;
extern NexButton b16;
extern NexButton b17;
extern NexButton b18;
extern NexButton b19;
extern NexButton b20;
extern NexButton b21;
extern NexButton b22;
extern NexButton b23;
extern NexButton b24;
extern NexButton b25;
extern NexButton b26;
extern NexButton b27;
extern NexButton b28;
extern NexButton b29;
extern NexButton b30;
extern NexButton b31;
extern NexButton b32;
extern NexButton b33;
extern NexButton b34;
extern NexButton b35;
extern NexButton b36;
extern NexButton b37;
extern NexButton b38;
extern NexButton b39;
extern NexButton b40;


extern NexNumber num;

// Register objects to the touch event list
extern NexTouch *nex_listen_list[];


void b0PushCallback(void *ptr);
void b1PushCallback(void *ptr);

void nexRegisterCbk( void );

#endif