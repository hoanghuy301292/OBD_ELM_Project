#include "NexComponent.h"

void NexWriteData(uint32 data0, uint32 data1, uint32 data2, uint32 data3)
{
    n20.setValue(data0);
    n21.setValue(data1);
    n22.setValue(data2);
    n23.setValue(data3);
    n30.setValue(data0);
    n31.setValue(data1);
    n32.setValue(data2);
    n33.setValue(data3);
    n40.setValue(data0);
    n41.setValue(data1);
    n42.setValue(data2);
    n43.setValue(data3);
}