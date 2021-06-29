#ifndef NEX_ELM_COMBINE_
#define NEX_ELM_COMBINE_
#include "Arduino.h"
#include "PID.h"
#include "elm327.h"
#include "NexWriteData.h"

extern String str_rpm;
extern String str_engTemp;
extern String str_batVol;
extern String str_throttle;
extern ELM327 myELM;

void readElmPIDs(String &str_rpm, String &str_engTemp, String &str_throttle, String &str_batVol);
void nexUpdateDataDisplay(void);
void nexUpdateReadDTCs(void);
void nexClearAndUpdateReadDTCs(void);

#endif