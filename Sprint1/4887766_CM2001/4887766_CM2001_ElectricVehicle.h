#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H
#include "4887766_CM2001_ElectricMotor.h"
#include <iostream>
#include <string>

class ElectricVehicle{
    private:
    std::string m_vehicleID;
    std::string m_vehicleModel;
    float m_batteryCapacity;
    ElectricMotor electricMotor;

    public:
    //parameterized constructor
    ElectricVehicle(std::string vehicleID_ = "", std::string vehicleModel_ = "", float batteryCapacity_ = 0.0, ElectricMotor m = ElectricMotor());

    //getters
    std::string getVehicleID() const;
    std::string getVehicleModel() const;
    float getBatteryCapacity() const;
    ElectricMotor getMotor() const { return electricMotor; }

    //setters
    void setVehicleID(std::string vehicleID_);
    void setVehicleModel(std::string vehicleModel_);
    void setBatteryCapacity(float batteryCapacity_);

    //<< overload
    friend std::ostream& operator<<(std::ostream& os, const ElectricVehicle& eV);

    float operator+(const ElectricVehicle& other);
};

#endif