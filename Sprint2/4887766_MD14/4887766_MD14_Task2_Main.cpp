#include "4887766_MD14_Task2_SensorData.h"

int main()
{
    SensorData d1("ENG_TEMP", 92.5f);
    SensorData d2("TYRE_PRESSURE", 32);
    SensorData d3("SYS_STATUS", "OK");

    displaySensorInfo(d1);
    displaySensorInfo(d2);
    displaySensorInfo(d3);

    d1.processReading();
    d2.processReading();
    d3.processReading();

    return 0;
}