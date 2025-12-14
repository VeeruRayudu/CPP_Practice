#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

enum class Status
{
    OK,
    WARN,
    FAIL
};

class Vehicle
{
private:
    int m_id{};
    std::string m_model{};
    double m_temperature{};
    double m_voltage{};
    Status m_status{Status::OK};

public:
    // constructor
    Vehicle() = default;
    Vehicle(int id_, std::string model_, double temperature_, double voltage_, Status status_);

    // update functions
    void updateTemperature(double temp);
    void updateVoltage(double volt);

    // status setter
    void setStatus(Status &&ref);
    void setStatus(const Status&) = delete;

    // getter
    double getTemperature() const { return m_temperature; }
    double getVoltage() const { return m_voltage; }

    void print() const;
};

// global functions
void logVehicleByValue(Vehicle v);
void logVehicleByRef(Vehicle &v);
void logVehicleByRRef(Vehicle &&v);
void logVehicleByPtr(Vehicle *v);

#endif