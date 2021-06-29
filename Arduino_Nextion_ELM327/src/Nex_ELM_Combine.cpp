#include "Nex_ELM_Combine.h"

extern bool b_readingDTC;
extern bool b_clearingDTC;
extern bool b_updatingScreen;
extern volatile bool b_readDTCRequest;
extern volatile bool b_clearDTCRequest;

String str_rpm;
String str_engTemp;
String str_batVol;
String str_throttle;
ELM327 myELM;

void readElmPIDs(String &str_rpm, String &str_engTemp, String &str_throttle, String &str_batVol)
{
  str_rpm      = myELM.get(PID_RPM);
  str_engTemp  = myELM.get(PID_COOLANT_TEMP);
  str_throttle = myELM.get(PID_THROTTLE);
  str_batVol   = myELM.get(PID_BAT_VOL);
}

void nexUpdateDataDisplay(void)
{
  readElmPIDs(str_rpm, str_engTemp, str_throttle, str_batVol);
  nexWriteData(str_rpm, str_engTemp, str_throttle, str_batVol);
}

void nexUpdateReadDTCs(void)
{
    String str_DTCs = myELM.getDTCs();
    nexWriteDTCs(str_DTCs);
}

void nexClearAndUpdateReadDTCs(void)
{
    ( void ) myELM.get(CLEAR_DTCs);
}