#ifndef LOOKUP_DTC_H
#define LOOKUP_DTC_H

#include "Arduino.h"

#define SIZE_OF_DTC_CONVERT_TABLE 16
typedef struct DTC_CONV_TBL
{
  String a;
  String b;
}DTC_CONV_TBL;

const DTC_CONV_TBL mSt_DtcConvertTable [SIZE_OF_DTC_CONVERT_TABLE]={
  {"0", "P0"},
  {"1", "P1"},
  {"2", "P2"},
  {"3", "P3"},
  {"4", "C0"},
  {"5", "C1"},
  {"6", "C2"},
  {"7", "C3"},
  {"8", "B0"},
  {"9", "B1"},
  {"A", "B2"},
  {"B", "B3"},
  {"C", "U0"},
  {"D", "U1"},
  {"E", "U2"},
  {"F", "U3"}
};

// void convertDTC(String *str_DTC);

void convertDTC(String &str_DTC);

#endif