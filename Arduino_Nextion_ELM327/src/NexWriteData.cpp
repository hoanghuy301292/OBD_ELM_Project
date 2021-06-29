#include "NexComponent.h"

static uint32 nexConvertRPMtoGaugeVal(uint32 ul_rpm);

void nexWriteData(String str_rpm, String str_engineTemp, String str_throttle, String str_batVolt)
{
    uint32 ul_rpm = strtol(str_rpm.c_str(), NULL, 10);
    uint32 ul_gaugeVal = nexConvertRPMtoGaugeVal(ul_rpm);
    uint32 ul_engineTemp = strtol(str_engineTemp.c_str(), NULL, 10);
    uint32 ul_throttle = strtol(str_throttle.c_str(), NULL, 10);
    const char *c_batVolt = str_batVolt.c_str();

    g2.setValue(ul_gaugeVal);
    g3.setValue(ul_gaugeVal);
    g4.setValue(ul_gaugeVal);

    n21.setValue(ul_engineTemp);
    n31.setValue(ul_engineTemp);
    n41.setValue(ul_engineTemp);

    n22.setValue(ul_throttle);
    n32.setValue(ul_throttle);    
    n42.setValue(ul_throttle);

    pB30.setValue(ul_throttle);
    pB20.setValue(ul_throttle);
    pB40.setValue(ul_throttle);    
    
    n20.setValue(ul_rpm);
    n30.setValue(ul_rpm);
    n40.setValue(ul_rpm);

    t21.setText(c_batVolt);
    t31.setText(c_batVolt);
    t41.setText(c_batVolt);
}

void nexWriteDTCs(String str_DTCs)
{
    uint8 uc_numOfDTCs;
    String str_DTC1 ="";
    String str_DTC2 ="";
    String str_DTC3 ="";

    uc_numOfDTCs = str_DTCs.length() / 5;

    if(uc_numOfDTCs <= 3)
    {
        for (uint8 i = 0; i < uc_numOfDTCs; i++)
        {
            str_DTC1 = str_DTC1 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != uc_numOfDTCs - 1)
            {
                str_DTC1 = str_DTC1 + ", ";
            }
        }
    }
    else if(uc_numOfDTCs <= 6)
    {
        for (uint8 i = 0; i < 3; i++)
        {
            str_DTC1 = str_DTC1 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != 3 - 1)
            {
                str_DTC1 = str_DTC1 + ", ";
            }
        }

        for (uint8 i = 0; i < uc_numOfDTCs; i++)
        {
            str_DTC2 = str_DTC2 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != uc_numOfDTCs - 1)
            {
                str_DTC2 = str_DTC2 + ", ";
            }
        }
    }
    else if(uc_numOfDTCs <= 9)
    {
        for (uint8 i = 0; i < 3; i++)
        {
            str_DTC1 = str_DTC1 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != 3 - 1)
            {
                str_DTC1 = str_DTC1 + ", ";
            }
        }

        for (uint8 i = 0; i < 6; i++)
        {
            str_DTC2 = str_DTC2 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != 6 - 1)
            {
                str_DTC2 = str_DTC2 + ", ";
            }
        }

        for (uint8 i = 0; i < uc_numOfDTCs; i++)
        {
            str_DTC3 = str_DTC3 + str_DTCs.substring(5*i, 5*(i+1));
            if (i != uc_numOfDTCs - 1)
            {
                str_DTC3 = str_DTC3 + ", ";
            }
        }
    }
    t22.setText(str_DTC1.c_str());
    t24.setText(str_DTC2.c_str());
    // t25.setText(str_DTC3.c_str());
    // t26.setText("");
    // t27.setText("");

    t32.setText(str_DTC1.c_str());
    t34.setText(str_DTC2.c_str());
    // t35.setText(str_DTC3.c_str());
    // t36.setText("");
    // t37.setText("");

    t42.setText(str_DTC1.c_str());
    t44.setText(str_DTC2.c_str());
    // t45.setText(str_DTC3.c_str());
    // t46.setText("");
    // t47.setText("");
}

static uint32 nexConvertRPMtoGaugeVal(uint32 ul_rpm)
{
uint32 ul_gaugeVal = 0;

    if(1200 >= ul_rpm)
    {
        ul_gaugeVal = uint32(map(ul_rpm, 0, 1200, 310, 360));
    }
    else if( (1200 < ul_rpm) && (9000 >= ul_rpm))
    {
        ul_gaugeVal = uint32(map(ul_rpm, 1201, 9000, 0, 225));
    }
    else
    {
        ul_gaugeVal = uint32(225);
    }
    return ul_gaugeVal;
}