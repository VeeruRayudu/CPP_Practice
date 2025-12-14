#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

enum class Status {
    OK,
    WARN,
    FAIL
};

class Vehicle {
private:
    int m_id{};
    std::string m_model{};
    double m_temperature{};
    double m_voltage{};
    Status m_status{Status::OK};

public:
    Vehicle() = default;
    Vehicle(int id, std::string model, double temperature, double voltage, Status status);

    void updateTemperature(double temp);
    void updateVoltage(double volt);

    void setStatus(Status&& status);
    void setStatus(const Status&) = delete;

    double getTemperature() const { return m_temperature; }
    double getVoltage() const { return m_voltage; }

    void print() const;
};

void logVehicleByValue(Vehicle v);
void logVehicleByRef(Vehicle& v);
void logVehicleByRRef(Vehicle&& v);
void logVehicleByPtr(Vehicle* v);

#endif // VEHICLE_H