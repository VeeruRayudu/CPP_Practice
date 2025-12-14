#include "Sensor.h"
#include "Logger.h"
#include <array>

void logSensorByRef(Sensor& s) {
    std::cout << "\nCall By Lvalue Reference:\n";
    s.print();
}

void logSensorByRRef(Sensor&& s) {
    std::cout << "\nCall By Rvalue Reference:\n";
    s.print();
}

void logSensorByPtr(Sensor* s) {
    std::cout << "\nCall By Pointer:\n";
    if (s) {
        s->print();
    } else {
        std::cout << "Null pointer sensor.\n";
    }
}

int main() {
    std::array<Sensor, 3> sensors = {
        Sensor{201, "Temperature", 1.05f, 0.2f, State::CALIBRATED},
        Sensor{202, "Pressure", 0.98f, -0.1f, State::UNCALIBRATED},
        Sensor{203, "Humidity", 1.00f, 0.0f, State::ERROR}
    };

    std::cout << "\n------------Initial Details-----------------\n";
    for (const auto& s : sensors) {
        s.print();
    }

    sensors[0].applyCalibration(1.00f, -0.1f);
    sensors[0].setState(State::UNCALIBRATED);

    std::cout << "\n------------Details after update-----------------\n";
    for (const auto& s : sensors) {
        s.print();
    }

    std::cout << "\n------------Logger Functions-----------------\n";
    logSensorByRef(sensors[0]);
    logSensorByRRef(std::move(sensors[2]));
    logSensorByPtr(&sensors[1]);

    auto isCritical = [](const Sensor& s) {
        return s.getGain() > 1.0f || s.getState() == State::ERROR;
    };

    std::array<Sensor, 3> critical{};
    int count = 0;
    for (const auto& s : sensors) {
        if (isCritical(s)) {
            critical[count++] = s;
        }
    }

    std::cout << "\n------------Filtered Sensors-----------------\n";
    for (int i = 0; i < count; ++i) {
        critical[i].print();
    }

    return 0;
}