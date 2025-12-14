#include "4887766_MD4_Task2_Sensor.h"
#include "4887766_MD4_Task2_Logger.h"

// logger functions implementation
void logSensorByRef(Sensor &s)
{
    std::cout << "\nCall By Lvalue Reference:\n";
    s.print();
}

void logSensorByRRef(Sensor &&s)
{
    std::cout << "\nCall By Rvalue Reference:\n";
    s.print();
}

void logSensorByPtr(Sensor *s)
{
    std::cout << "\nCall By Pointer:\n";
    s->print();
}

int main()
{
    Sensor sensors[3]{
        {201, "Temperature", 1.05, 0.2, State::CALIBRATED},
        {202, "Pressure", 0.98, -0.1, State::UNCALIBRATED},
        {203, "Humidity", 1.00, 0.0, State::ERROR}};

    std::cout << "\n------------Initial Details-----------------\n";
    for (auto &s : sensors)
    {
        s.print();
    }

    // applying calibration
    sensors[0].applyCalibration(1.00, -0.1);

    // setting state
    sensors[0].setState(State::UNCALIBRATED);

    std::cout << "\n------------Details after update-----------------\n";
    for (auto &s : sensors)
    {
        s.print();
    }

    // logging details
    std::cout << "\n------------Logger Functions-----------------\n";
    logSensorByRef(sensors[0]);
    logSensorByRRef(std::move(sensors[2]));
    logSensorByPtr(&sensors[1]);

    // lambda function
    auto isCritical = [](Sensor &s) -> bool
    {
        return (s.getGain() > 1.0 || s.getState() == State::ERROR);
    };

    // storing lambda results
    Sensor critical[3];
    int count = 0;
    for (auto &s : sensors)
    {
        if (isCritical(s))
        {
            critical[count++] = s;
        }
    }

    std::cout << "\n------------Filtered Sensors-----------------\n";
    for (int i = 0; i < count; i++)
    {
        critical[i].print();
    }

    return 0;
}