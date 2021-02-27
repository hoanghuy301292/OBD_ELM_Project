#include "LookupDTC.h"

void convertDTC(String &str_DTC)
{
  for(int i = 0; i < SIZE_OF_DTC_CONVERT_TABLE; i++ )
  {
    if (mSt_DtcConvertTable[i].a == str_DTC.substring(0,1))
    {
      str_DTC = mSt_DtcConvertTable[i].b + str_DTC.substring(1,4);
      break;
    }
  }
}