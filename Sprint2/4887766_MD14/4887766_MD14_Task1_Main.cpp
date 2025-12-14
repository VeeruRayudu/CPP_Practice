#include "4887766_MD14_Task1_SensorReading.h"

int main(){
    SensorReading s1("Temp", 36);
    SensorReading s2("Speed", 88.5f);
    SensorReading s3("Status", "OK");

    printSensorReading(s1);
    printSensorReading(s2);
    printSensorReading(s3);

    s2.updateValue(90.0f);
    printSensorReading(s2);
}