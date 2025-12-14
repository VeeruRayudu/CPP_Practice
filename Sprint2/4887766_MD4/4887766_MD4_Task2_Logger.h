#ifndef LOGGER_H
#define LOGGER_H
#include "4887766_MD4_Task2_Sensor.h"

void logSensorByRef(Sensor& s);
void logSensorByRRef(Sensor&& s);
void logSensorByPtr(Sensor* s);

#endif