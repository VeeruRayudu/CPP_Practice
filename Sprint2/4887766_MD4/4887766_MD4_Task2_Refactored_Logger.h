#ifndef LOGGER_H
#define LOGGER_H

#include "Sensor.h"

void logSensorByRef(Sensor& s);
void logSensorByRRef(Sensor&& s);
void logSensorByPtr(Sensor* s);

#endif // LOGGER_H