#ifndef  _NEX_COMPONENT_H_
#define  _NEX_COMPONENT_H_

#include "Nextion.h"
#include "Arduino_HW.h"
#include "utypedef.h"

extern NexDSButton b1;
extern NexDSButton b2;
extern NexDSButton b3;
extern NexDSButton b4;
extern NexDSButton b5;
extern NexDSButton b6;
extern NexDSButton b7;
extern NexDSButton b8;
extern NexDSButton b9;
extern NexDSButton b10;
extern NexDSButton b11;
extern NexDSButton b12;
extern NexDSButton b13;
extern NexDSButton b14;
extern NexDSButton b15;
extern NexDSButton b16;
extern NexDSButton b17;
extern NexDSButton b18;
extern NexDSButton b19;
extern NexDSButton b20;
extern NexDSButton b21;
extern NexDSButton b22;
extern NexDSButton b23;
extern NexDSButton b24;
extern NexDSButton b25;
extern NexDSButton b26;
extern NexDSButton b27;
extern NexDSButton b28;
extern NexDSButton b29;
extern NexDSButton b30;
extern NexDSButton b31;
extern NexDSButton b32;
extern NexDSButton b33;
extern NexDSButton b34;
extern NexDSButton b35;
extern NexDSButton b36;
extern NexDSButton b37;
extern NexDSButton b38;
extern NexDSButton b39;
extern NexDSButton b40;

extern NexButton r1;
extern NexButton c1;
extern NexButton r2;
extern NexButton c2;
extern NexButton r3;
extern NexButton c3;

extern NexNumber n20;
extern NexNumber n21;
extern NexNumber n22;
extern NexNumber n23;
extern NexNumber n30;
extern NexNumber n31;
extern NexNumber n32;
extern NexNumber n33;
extern NexNumber n40;
extern NexNumber n41;
extern NexNumber n42;
extern NexNumber n43;

extern NexNumber num;

extern NexGauge g2;
extern NexGauge g3;
extern NexGauge g4;
extern NexGauge g5;
extern NexProgressBar pB20;
extern NexProgressBar pB30;
extern NexProgressBar pB40;
extern NexProgressBar pB50;

extern NexText t21;
extern NexText t31;
extern NexText t41;
extern NexText t51;

extern NexText t22;
extern NexText t24;
extern NexText t25;
extern NexText t26;
extern NexText t27;

extern NexText t32;
extern NexText t34;
extern NexText t35;
extern NexText t36;
extern NexText t37;

extern NexText t42;
extern NexText t44;
extern NexText t45;
extern NexText t46;
extern NexText t47;

extern NexTouch *nex_listen_list[];

extern void b1PushCallback(void *ptr);
extern void b2PushCallback(void *ptr);
extern void b3PushCallback(void *ptr);
extern void b4PushCallback(void *ptr);
extern void b5PushCallback(void *ptr);
extern void b6PushCallback(void *ptr);
extern void b7PushCallback(void *ptr);
extern void b8PushCallback(void *ptr);
extern void b9PushCallback(void *ptr);
extern void b10PushCallback(void *ptr);
extern void b11PushCallback(void *ptr);
extern void b12PushCallback(void *ptr);
extern void b13PushCallback(void *ptr);
extern void b14PushCallback(void *ptr);
extern void b15PushCallback(void *ptr);
extern void b16PushCallback(void *ptr);
extern void b17PushCallback(void *ptr);
extern void b18PushCallback(void *ptr);
extern void b19PushCallback(void *ptr);
extern void b20PushCallback(void *ptr);
extern void b21PushCallback(void *ptr);
extern void b22PushCallback(void *ptr);
extern void b23PushCallback(void *ptr);
extern void b24PushCallback(void *ptr);
extern void b25PushCallback(void *ptr);
extern void b26PushCallback(void *ptr);
extern void b27PushCallback(void *ptr);
extern void b28PushCallback(void *ptr);
extern void b29PushCallback(void *ptr);
extern void b30PushCallback(void *ptr);
extern void b31PushCallback(void *ptr);
extern void b32PushCallback(void *ptr);
extern void b33PushCallback(void *ptr);
extern void b34PushCallback(void *ptr);
extern void b35PushCallback(void *ptr);
extern void b36PushCallback(void *ptr);
extern void b37PushCallback(void *ptr);
extern void b38PushCallback(void *ptr);
extern void b39PushCallback(void *ptr);
extern void b40PushCallback(void *ptr);

extern void nexRegisterCbk( void );

#endif